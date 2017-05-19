#include "stdio.h"
#include "algorithm"

struct Node{
	long long sum;
	int a[5];
	Node(long long _sum = 0) : sum(_sum){
		for(int i = 0; i < 5; i++) a[i] = 0;
	}
};

int n,q,t,a,b,c;
char str[100005];
long long inv[400005];
long long arr[400005][5];
int lazySet[400005];
bool isLazy[400005];

bool isIntersect(int x1, int y1, int x2, int y2){
	return (x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1)||(x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2);
}

void updateSeg(int no){
	for(int i = 0; i < 5; i++){
		arr[no][i] = arr[no*2+1][i] + arr[no*2+2][i];
	}
	inv[no] = inv[no*2+1]+inv[no*2+2];
	for(int i = 0; i < 5; i++){
		for(int j = i+1; j < 5; j++){
			inv[no] += arr[no*2+1][j]*(long long)arr[no*2+2][i];
		}
	}
}

void makeSeg(int no, int i, int j){
	if(i==j){
		arr[no][str[i]-'0'] = 1;
	}else{
		makeSeg(no*2+1,i,(i+j)/2);
		makeSeg(no*2+2,(i+j)/2+1,j);
		updateSeg(no);
		//printf("%lld\n",inv[no]);
	}
}

void addLazySet(int no, int v, int i, int j){
	isLazy[no] = true;
	lazySet[no] = v;
	for(int i = 0; i < 5; i++){
		arr[no][i] = 0;
	}
	inv[no] = 0;
	arr[no][v] = j-i+1;
}

void doLazy(int no, int i, int j){
	if(i!=j&&isLazy[no]){
		addLazySet(no*2+1,lazySet[no],i,(i+j)/2);
		addLazySet(no*2+2,lazySet[no],(i+j)/2+1,j);
		updateSeg(no);
	}
	isLazy[no] = false;
}

void setSeg(int no, int i, int j, int x, int y, int v){
	doLazy(no,i,j);
	if(x<=i&&j<=y){
		//subset
		addLazySet(no,v,i,j);
	}else if(isIntersect(i,j,x,y)){
		setSeg(no*2+1,i,(i+j)/2,x,y,v);
		setSeg(no*2+2,(i+j)/2+1,j,x,y,v);
		updateSeg(no);
	}
	//printf("NO %d %d %d : %lld\n:",no,i,j,inv);
	//for(int i = 0; i < 5; i++) printf("%d ",arr[no][i]);
	//printf("\n");
}

Node getSeg(int no, int i, int j, int x, int y){
	//printf("GET %d %d %d %d %d \n",no,i,j,x,y);
	Node re;
	doLazy(no,i,j);
	if(x<=i&&j<=y){
		//subset
		re.sum = inv[no];
		for(int i = 0; i < 5; i++){
			re.a[i] = arr[no][i];
		}
		return re;
	}else if(isIntersect(i,j,x,y)){
		Node a = getSeg(no*2+1,i,(i+j)/2,x,y);
		Node b = getSeg(no*2+2,(i+j)/2+1,j,x,y);
		re.sum = a.sum + b.sum;

		//cal inv
		for(int i = 0; i < 5; i++){
			for(int j = i+1; j < 5; j++){
				re.sum += a.a[j]*(long long)b.a[i];
			}
		}

		for(int i = 0; i < 5; i++){
			re.a[i] = a.a[i] + b.a[i];
		}

		return re;
	}

	re.sum = 0;
	for(int i = 0; i < 5; i++){
		re.a[i] = 0;
	}
	return re;
}

long long countInv(int a, int b){
	int co[5];
	long long sum = 0;
	for(int i = 0; i < 5; i++) co[i] = 0;
	for(int i = a; i <= b; i++){
		for(int j = str[i]-'0'+1; j < 5; j++){
			sum += co[j];
		}
		co[str[i]-'0']++;
	}
	return sum;
}

int main(){
	scanf("%d%d",&n,&q);
	scanf(" %s",str);
	if(n<=1000&&q<=2000){
		for(int i = 0; i < q; i++){
			scanf("%d",&t);
			if(t==3){
				//answer
				scanf("%d%d",&a,&b);
				printf("%lld\n",countInv(a-1,b-1));
			}else if(t==2){
				scanf("%d%d",&a,&b);
				a--,b--;
				for(int i = 0; a+i < b-i; i++) std::swap(str[a+i],str[b-i]);
			}else if(t==1){
				//set
				scanf("%d%d%d",&a,&b,&c);
				for(int i = a-1; i < b; i++) str[i] = c+'0';
			}
		}
		return 0;
	}
	makeSeg(0,0,n-1);
	for(int i = 0; i < q; i++){
		scanf("%d",&t);
		if(t==3){
			//answer
			scanf("%d%d",&a,&b);
			printf("%lld\n",getSeg(0,0,n-1,a-1,b-1).sum);
		}else if(t==2){
			scanf("%d%d",&a,&b);
			return -1;
		}else if(t==1){
			//set
			scanf("%d%d%d",&a,&b,&c);
			setSeg(0,0,n-1,a-1,b-1,c);
		}
	}
}