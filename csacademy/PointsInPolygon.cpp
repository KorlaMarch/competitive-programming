#include "stdio.h"
#include "algorithm"
#include "vector"
#include "math.h"

#define EPSI 0.00000001

typedef std::pair<double, double> Point;

struct Line{
	Point a,b;
	Line(){}
	//Line
	Line(Point _a, Point _b){
		if(_a<_b){
			a = _a;
			b = _b;
		}else{
			a = _b;
			b = _a;
		}
	}

	double findY(double x){
		return a.second+(x-a.first)*(b.second-a.second)/(b.first-a.first);
	}

	bool operator==(const Line& li){
		return li.a==a&&li.b==b;
	}
	bool operator!=(const Line& li){
		return !(*this==li);
	}
};

struct Event{
	Point p;
	// -1 -> start
	// 0 -> end
	// 1 -> point
	char evtype;
	Line data;

	Event(){}
	Event(Point _p, char _type) : p(_p), evtype(_type) {}
	Event(Point _p, char _type, Line& _data) : p(_p), evtype(_type), data(_data) {}

	bool operator < (const Event& e){
		if(p==e.p) return evtype < e.evtype;
		return p < e.p;
	}
};

int n,m,co;
Point p;
Point ver[2005];
Point que[2005];
std::vector<Line> active;
std::vector<Event> ev;

bool cmp(Line a, Line b, double x){
	return true;
}

int main(){
	const double cos1 = cos(1.005);
	const double sin1 = sin(1.005);

	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%lf%lf",&p.first,&p.second);
		//rotate
		ver[i].first = p.first*cos1 - p.second*sin1;
		ver[i].second = p.first*sin1 + p.second*cos1;
		if(i){
			Line li(ver[i-1],ver[i]);
			ev.push_back(Event(li.a , -1 , li));
			ev.push_back(Event(li.b , 0 , li));
		}
	}

	Line li(ver[0],ver[n-1]);
	ev.push_back(Event(li.a , -1 , li));
	ev.push_back(Event(li.b , 0 , li));

	for(int i = 0; i < m; i++){
		scanf("%lf%lf",&p.first,&p.second);
		//rotate
		que[i].first = p.first*cos1 - p.second*sin1;
		que[i].second = p.first*sin1 + p.second*cos1;

		ev.push_back(Event(que[i] , 1));
	}

	std::sort(ev.begin(),ev.end());

	for(Event& e : ev){
		if(e.evtype==1){
			//check
			bool isIn = false;
			unsigned int i;
			for(i = 0; i < active.size() && !isIn; i++){
				double ly = active[i].findY(e.p.first);
				//printf("CMP %.4f %.4f\n",ly,e.p.second);
				if(fabs(ly-e.p.second)<=EPSI){
					isIn = true;
				}else if(ly>e.p.second){
					break;
				}
			}
			//printf("GET %d %d\n",isIn,i);
			if(isIn||i%2){
				co++;
			}
		}else if(e.evtype==0){
			//delete
			unsigned int i;
			//printf("DEL %.4f %.4f %.4f %.4f\n",e.data.a.first,e.data.a.second,e.data.b.first,e.data.b.second);
			for(i = 0; i < active.size() && active[i] != e.data; i++);
			for(; i+1 < active.size(); i++){
				std::swap(active[i],active[i+1]);
			}
			active.pop_back();
		}else{
			//add
			active.push_back(e.data);
			for(int i = active.size()-1; i > 0; i--){
				if(active[i].findY(e.p.first) < active[i-1].findY(e.p.first) ||
					(active[i].findY(e.p.first) == active[i-1].findY(e.p.first)&&
						active[i].findY(e.p.first+1) < active[i-1].findY(e.p.first+1) ) ){
					std::swap(active[i],active[i-1]);
				} 
			}
		}
	}

	printf("%d\n",co);
}