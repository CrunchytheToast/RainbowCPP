/* --------------------------------- About --------------------------------- *
|                                                                            |
| This code is free under the GNU GPL 3.0 license.                           |                                                               |
|                                                                            |
| This is a simple demonstration of the graphics capabilities of the classic |
| C/C++ IDE, Turbo C++.                                                      |
|                                                                            |
| This particular demonstration draws a rainbow on the screen by             |
| making use of the inbuilt graphics methods in VGA mode.                    |
* --------------------------------------------------------------------------*/

#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
 int gdriver = 9, gmode = 2; // set graphics mode to VGA - 640 x 480
 char path[] = "C:\\TURBOC3\\BGI"; // path might vary depending on your installation
 initgraph(&gdriver, &gmode, path);

 //coordinate variables
 int midx = getmaxx()/2, midy = getmaxy()/2;
 int xc = getmaxx()*0.5, yc = getmaxy()*2/3, radius = 24;

 // color data
 int col[] = {0, 13, 9, 11, 10, 14, 12, 4}, index = 0;

 // introduction
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(SIMPLEX_FONT, HORIZ_DIR, 5);
 setcolor(getmaxcolor());
 outtextxy(midx, midy-20, "Rainbow");
 outtextxy(midx, midy+20, "by Toast");
 delay(3000);
 cleardevice();

 // draw the rainbow
 while(radius <= 200)
 {
  radius++;
  setcolor(col[index]);
  arc(xc, yc, 0, 180, radius);
  delay(50);
  if(!(radius%25)) //change the colour every 25 radius incrememnts
  {
   index++;
   index %= 8;
   if(!index) break;
  }
 }
 delay(3000);

 // clear the rainbow slowly
 radius = 0;
 while(radius <= 200)
 {
  radius++;
  setcolor(0); // black
  arc(xc, yc, 0, 180, radius);
  delay(25);
 }
 delay(500);

 // thank you
 setcolor(getmaxcolor());
 outtextxy(midx, midy+20, "");
 outtextxy(midx, midy-20, "Thanks for watching!");

 settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2);
 outtextxy(midx, midy+50, "Source code is available at https://github.com/CrunchytheToast");
 delay(10000);

 closegraph();
}