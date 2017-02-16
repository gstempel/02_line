#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

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

  //printf("X: %d\n", x);
  //printf("X1: %d\n", x1);

  //Octant I
  if(slope <= 1 && slope >=0) {
    d = 2*A + B;
    if(x < x1) { //Left to right
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
    else if(x > x1){ //Right to left
      while(x >= x1) {
	plot(s, c, x, y);
	if (d < 0) {
	  y--;
	  d+=(2*B);
	}
	x--;
	d+=(2*A);
      }
    }
  }

  //Octant II
  if(slope > 1) {
    d = A + 2*B;
    if (x < x1) { //Left to right
      while(y <= y1){
	plot(s, c, x, y);
	if(d < 0) {
	  x++;
	  d+=(2*A);
	}
	y++;
	d+=(2*B);
      }
    }
    else if (x > x1) { //Right to left
      while(y >= y1){
	plot(s, c, x, y);
	if(d > 0) {
	  x--;
	  d+=(2*A);
	}
	y--;
	d+=(2*B);
      }
    }
  }

  //Octant VIII
  if (slope < 0 && slope >=-1) {
    d = 2*A - B;
    if (x < x1) { //Left to right
      while(x <= x1) {
	plot(s, c, x, y);
	if (d < 0) {
	  y--;
	  d += -(2*B);
	}
	x++;
	d+= 2*A;
      }
    }
    else if (x > x1) { //Right to left
      while(x >= x1) {
	plot(s, c, x, y);
	if (d > 0) {
	  y++;
	  d += -(2*B);
	}
	x--;
	d+= 2*A;
      }
    }
  }

  //Octant VII
  if (slope < -1) {
    d = A - 2*B;
    if (x < x1) { //Left to right
      while(y > y1) {
	plot(s, c, x, y);
	if (d > 0) {
	  x++;
	  d+= 2*A;
	}
	y--;
	d-= 2*B;
      }
    }
    else if (x > x1) { //Right to left
      while(y < y1) {
	plot(s, c, x, y);
	if (d < 0) {
	  x--;
	  d+= 2*A;
	}
	y++;
	d-= 2*B;
      }
    }
  }

  //Vertical Lines
  if (x == x1) {
    if (y < y1) { //Down up
      while(y < y1) {
	plot(s, c, x, y);
	y++;
      }
    }
    else if (y > y1) { //Up Down
      while(y > y1) {
	plot(s, c, x, y);
	y--;
      }
    }
  }
}
