#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
int main()
{
    int gdriver=DETECT,gmode,errorcode;
    int x=160,y=40;
    int level;
    int i;
    initgraph(&gdriver,&gmode,"egavga.bgi");  errorcode=graphresult();
    if (errorcode!=grOk)
    {cout<<"Pomulka "<<grapherrormsg(errorcode);
        cout<<"\n Natusnit Enter";
        getch();
        exit(1);
    }
    setbkcolor(0);
    setcolor(4);
    line(x,y,x+300,y);//verhnja osnova
    line(x,y,x+140,y+150);//liva poxula verh
    line(x+300,y,x+155,y+150);//prava poxula verh
    line(x+155,y+150,x+305,y+295);//prava poxula nuz
    line(x+305,y+295,x,y+295);//nuz osnova
    line(x+140,y+150,x,y+295);//liva poxula nuz
    getch();
    setfillstyle(SOLID_FILL, CYAN);
    line(x+1, y+1, x+300-1, y+1);
    line(x+1, y+1, x+147, y+150);
    line(x+300-1, y+1, x+147, y+150);
    floodfill(x+150, y+140, 4);
    getch();
    for (i=1; i<150; i++){
        delay(50);
        setcolor(0);
        line(x+i, y+i, x+300-i, y+i);
        setcolor(CYAN);
        line(x+i, y+295-i, x+305-i, y+295-i);
    }
    closegraph();
    return 0;
}