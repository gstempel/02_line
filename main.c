#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);

  //Slope of -1
  draw_line(0, 500, 500, 0, s, c);

  //Slope of 1
  draw_line(0, 0, 500, 500, s, c);

  //Slope of 0
  draw_line(0, 250, 500, 250, s, c);

  //Octant I
  draw_line(250, 250, 500, 300, s, c);
  draw_line(250, 250, 500, 350, s, c);
  draw_line(250, 250, 500, 400, s, c);
  draw_line(250, 250, 500, 450, s, c);

  //Octant II
  draw_line(250, 250, 300, 500, s, c);
  draw_line(250, 250, 350, 500, s, c);
  draw_line(250, 250, 400, 500, s, c);
  draw_line(250, 250, 450, 500, s, c);

  display(s);
  save_extension(s, "lines.png");
}  
