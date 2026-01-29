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

// header files
#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
 // set graphics mode to VGA - 640 x 480 
 int gdriver = 9, gmode = 2;

 // path might vary depending on your installation
 char path[] = "C:\\TURBOC3\\BGI";

 // initialize the graphics mode
 initgraph(&gdriver, &gmode, path);

 //coordinate variables
 int midx = getmaxx()/2, midy = getmaxy()/2;
 int xc = getmaxx()*0.5, yc = getmaxy()*2/3, radius = 24;

 // color data
 int palette[] = {0, 13, 9, 11, 10, 14, 12, 4}, index = 0;

 // introduction
 // adjust text formatting and color
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(SIMPLEX_FONT, HORIZ_DIR, 5);
 setcolor(getmaxcolor());
 
 // print text
 outtextxy(midx, midy-20, "Rainbow");
 outtextxy(midx, midy+20, "by Toast");
 delay(3000); // wait 3 seconds
 cleardevice();

 // draw the rainbow
 while(radius <= 200)
 {
  radius++;
  setcolor(palette[index]);
  arc(xc, yc, 0, 180, radius); // draw an arc of 180 degrees
  delay(50); // wait 50 miilseconds
  if(!(radius%25)) // at every 25 radius incrememnts
  {
   index++; // change the color
   index %= 8; // stay within palette bounds
   if(!index) break;
  }
 }
 delay(3000); // wait 3 seconds

 // clear the rainbow slowly
 radius = 0;
 while(radius <= 200)
 {
  radius++;
  setcolor(0); // black
  arc(xc, yc, 0, 180, radius);
  delay(25); // wait 25 milliseconds
 }
 delay(500); // wait hallf a second

 // thank you
 setcolor(getmaxcolor());
 outtextxy(midx, midy+20, "");
 outtextxy(midx, midy-20, "Thanks for watching!");

 settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2);
 outtextxy(midx, midy+30, "Source code is available here:");
 outtextxy(midx, midy+55, "https://github.com/CrunchytheToast/RainbowCPP");
 delay(10000); // wait 10 seconds

 closegraph();

}
