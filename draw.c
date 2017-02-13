#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int x, y, d, A2, B;
  A2 = 2*(y1 - y0); //2A = 2(dy)
  B = -(x1-x0); //B = -(dx)
  x = x0;
  y = y0;
  d = A2 + B;

  while(x <= x1) {
    plot(s, c, x, y);
    if (d > 0) {
      y++;
      d+=(2*B);
    }
    x++;
    d+=A2;
  }

}
