#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int x, y, d, A, B;
  float slope;
  A = (y1 - y0); //A = (dy)
  B = -(x1-x0); //B = -(dx)
  x = x0;
  y = y0;
  slope = (y1-y0);
  slope = slope/(x1-x0);
  printf("Slope: %f\n", slope);

  //Octant I
  if(slope < 1) {
    d = 2*A + B;
    while(x <= x1) {
      plot(s, c, x, y);
      if (d > 0) {
	y++;
	d+=(2*B);
      }
      x++;
      d+=(2*A);
    }
  }

  //Octant II
  if(slope > 1) {
    d = A + 2*B;
    while(y <= y1){
      plot(s, c, x, y);
      if(d <0) {
	x++;
	d+=(2*A);
      }
      y++;
      d+=(2*B);
    }
  }

  //Slope = 1
  if (slope == 1) {
    while(x <= x1) {
      plot(s, c, x, y);
      x++;
      y++;
    }
  }

  //Slope = -1
  if (slope == -1) {
    printf("Drawing Slope = -1\n");
    if (x > x1) {
      while(x >= x1) {
	plot(s, c, x, y);
	x++;
	y--;
      }
    }
    else {
      while (x <= x1) {
	plot(s, c, x, y);
	x--;
	y++;
      }
    }
  }

  //Slope = 0
  if (slope == 0) {
    while(x <= x1) {
      plot (s, c, x, y);
      x++;
    }
  }
}
