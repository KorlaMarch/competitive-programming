#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
const int width = 80;
const int flipsPerLine = 5;
const int millisecondsOfSleep = 20;
int main() {
    srand(time_t(NULL));
    bool switches[width] = { true };
    const std::string garbage = "1234567890/*-+.,./;[]\\=_~`!@#$%^&*()";
    const int glen = garbage.size();
    while(true){
        for (int i = 0; i < width; i++) {
            if(switches[i]){
                std::cout << garbage[rand() % glen];
            }else{
                std::cout << ' ';
            }
        }
        //std::cout << std::endl;
        for(int i = 0; i != flipsPerLine; i++) {
            int x = rand() % width;
            switches[x] = !switches[x];
            // Was switches[x] = (switches[x]) ? false : true; thanks to Adrian Petrescu
            // Flipping switches
        }
        Sleep(millisecondsOfSleep);
    }
    return 0;
}
