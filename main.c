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

  //Octant I
  //Left to right
  draw_line(0, 250, 500, 250, s, c);
  draw_line(0, 0, 500, 500, s, c);
  draw_line(0, 0, 500, 300, s, c);
  draw_line(0, 0, 500, 350, s, c);
  //Right to left
  draw_line(500, 400, 0, 0, s, c);
  draw_line(500, 450, 0, 0, s, c);

  //Octant II
  //Left to right
  draw_line(0, 0, 250, 500, s, c);
  draw_line(0, 0, 300, 500, s, c);
  draw_line(0, 0, 350, 500, s, c);
  //Right to left
  draw_line(400, 500, 0, 0, s, c);
  draw_line(450, 500, 0, 0, s, c);

  //Octant VIII
  //Left to right
  draw_line(0, 500, 500, 0, s, c);
  draw_line(0, 500, 500, 200, s, c);
  draw_line(0, 500, 500, 150, s, c);
  //Right to left
  draw_line(500, 100, 0, 500, s, c);
  draw_line(500, 50, 0, 500, s, c);

  //Octant VII
  //Left to right
  draw_line(0, 500, 250, 0, s, c);
  draw_line(0, 500, 300, 0, s, c);
  draw_line(0, 500, 350, 0, s, c);
  //Right to left
  draw_line(400, 0, 0, 500, s, c);
  draw_line(450, 0, 0, 500, s, c);


  //Vertical Lines
  //Up down
  draw_line(0, 0, 0, 500, s, c);
  draw_line(150, 0, 150, 500, s, c);
  draw_line(200, 0, 200, 500, s, c);
  //Down up
  draw_line(50, 500, 50, 0, s, c);
  draw_line(100, 500, 100, 0, s, c);
  draw_line(250, 500, 250, 0, s, c);


  display(s);
  save_extension(s, "lines.png");
}  
