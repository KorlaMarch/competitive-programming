#include <windows.h>
#include <stdio.h>

int main(void)
{
 HANDLE hStdInput,hStdOutput;
 INPUT_RECORD ir[128];
 bool blnLoop=true;
 DWORD nRead;
 COORD xy;
 UINT i;

 hStdInput=GetStdHandle(STD_INPUT_HANDLE);
 hStdOutput=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleMode(hStdInput,ENABLE_MOUSE_INPUT|ENABLE_EXTENDED_FLAGS);   //<<<flags
 FlushConsoleInputBuffer(hStdInput);
 do
 {
   if(WaitForSingleObject(hStdInput,1000)==WAIT_TIMEOUT)
      break;
   else
   {
      ReadConsoleInput(hStdInput,ir,128,&nRead);
      for(i=0;i<nRead;i++)
      {
          switch(ir[i].EventType)
          {
           case KEY_EVENT:
             if(ir[i].Event.KeyEvent.wVirtualKeyCode==VK_ESCAPE)
                blnLoop=false;
             else
             {
                xy.X=0;xy.Y=0;
                SetConsoleCursorPosition(hStdOutput,xy);
                printf
                (
                 "AsciiCode = %d: symbol = %c\n",
                 ir[i].Event.KeyEvent.uChar.AsciiChar,
                 ir[i].Event.KeyEvent.uChar.AsciiChar
                );
             }
             break;
           case MOUSE_EVENT:
             xy.X=0, xy.Y=1;
             SetConsoleCursorPosition(hStdOutput,xy);
             printf
             (
              "%.3d\t%.3d\t%.3u",
              ir[i].Event.MouseEvent.dwMousePosition.X,
              ir[i].Event.MouseEvent.dwMousePosition.Y,
              (unsigned int)ir[i].Event.MouseEvent.dwButtonState & 0x07
             );
             break;
          }//end switch
      }//end for
   }//end if
 }//end do
 while(blnLoop==true);

 return 0;
}
