#include "iostream"

using namespace std;

int *insert_array(int s[], int p, int len){
    int *temp = new int[len];
    //0 -> (p-1)
    for(int x = 0; x < p; x++){
        temp[x] = s[x + 1];
    }
    temp[p] = s[0];
    //p+1 -> max
    cout << len << endl;
    for(int x = p + 1; x < len; x++){
        temp[x] = s[x];
        cout << "x = " << x << endl;
    }
    return temp;

}

int main(){
    int a[5] = {1,2,3,4,5};
    cout << sizeof(a)/sizeof(a[0]) << endl;
    for(int x = 0; x < sizeof(a)/sizeof(a[0]); x++){
        cout << a[x] << " ";
    }
    cout << endl;
    int* new_a = insert_array(a, 2, sizeof(a)/sizeof(a[0]));
    for(int x = 0; x < sizeof(a)/sizeof(new_a[0]); x++){
        cout << new_a[x] << " ";
    }


}
