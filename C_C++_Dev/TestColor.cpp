#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;


int main(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k;
    char c;
    int i;
    system("mode 80, 50");
    //SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, NULL);
    while(1){
            k = rand() % 256;
            SetConsoleTextAttribute(hConsole, k > 256 ? k % 16 : k);
            c = rand() % 223 + 32;
            cout << c;
            if(i >= 1200){
                i = 0;
                Beep(k*4 + 300, 150);
            }
            i++;
    }
    cin.get();
    return 0;
}
