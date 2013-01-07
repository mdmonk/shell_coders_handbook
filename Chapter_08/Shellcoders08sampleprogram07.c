/*

The Shellcoder's Handbook: Discovering and Exploiting Security Holes
Jack Koziol, David Litchfield, Dave Aitel, Chris Anley, 
Sinan Eren, Neel Mehta, Riley Hassell
Publisher: John Wiley & Sons
ISBN: 0764544683

Chapter 8: Windows Overflows
Sample Program #7

Please send comments/feedback to jack@infosecinstitute.com or visit http://www.infosecinstitute.com 

*/

#include <stdio.h>
     #include <windows.h>

     int foo(char *buf);

     int main(int argc, char *argv[])
     {
            HMODULE l;
            l = LoadLibrary("msvcrt.dll");
            l = LoadLibrary("netapi32.dll");
            printf("\n\nHeapoverflow program.\n");
            if(argc != 2)
                    return printf("ARGS!");
            foo(argv[1]);                                             
            return 0;
     }

     int foo(char *buf)
     {
            HLOCAL h1 = 0, h2 = 0;
            HANDLE hp;

            hp = HeapCreate(0,0x1000,0x10000);
            if(!hp)
                    return printf("Failed to create heap.\n");
            h1 = HeapAlloc(hp,HEAP_ZERO_MEMORY,260);
            printf("HEAP: %.8X %.8X\n",h1,&h1);
            
            // Heap Overflow occurs here:
            strcpy(h1,buf);
            
            // We gain control of this second call to HeapAlloc
            h2 = HeapAlloc(hp,HEAP_ZERO_MEMORY,260);
            printf("hello");
            return 0;
     }
