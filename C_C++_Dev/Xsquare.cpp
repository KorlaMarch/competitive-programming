#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x = 0;
    int y = 0;
    int size;
    int need = 1;
    
    while(need == 1){
    cout << "Enter size : ";
    cin >> size;
    y = size - 3;
    
    for(int i = 0; i < size; i++){
            cout << "*";
            }
    cout << endl;
    for(int a = 0; a < (size - 2); a++){
            cout << "*";
            for(int b = 0; b < (size - 2); b++){
                  if(x == b) cout << "*";
                       if(y == b && (a !=(int)(size/2 - 1) || 0 == size%2)) cout << "*";
                       if(x != b && y != b) cout << " ";
                    
            }
            cout << "*";
            x = x + 1;
            y = y - 1;
            cout << endl;
    }
    if(size != 1){
            for(int i = 0; i < size; i++){
                    cout << "*";
                    }
            cout << endl;
    }
    do {
    cout << "Need more? (1/0) : ";
    cin >> need;
    if(need != 1 && need != 0) cout << "Error" << endl;
    } while (need != 1 && need != 0);
    x = 0;
    y = 0;
}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
