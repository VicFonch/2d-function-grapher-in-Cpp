# 2D Function Grapher in C++

## Summary
This project aims to create a program in the language
C++ with which, given any function and a real interval, it is graphed
the same. The program has the property to zoom anywhere in
the window you click on. As a conclusion, the program will be evaluated with
three given functions.

## Brief introduction to the code

The libraries used were:
- `graphics.h`: To paint in a viewport
- `math.h`: To work with math functions by declaring the function
- `stdbool.h` To work with boolean values
- `stdio.h` To work with strings
The input of the program receives as an argument an interval, which is captured by the void IMPUT() function and stores the values $a$; $b$; $F(a)$. Then define a
window of size (side $x$ side) with side = 600. The process of
plotted by plotting the axes from the void Axes() function. Then it is defined
the scale (x_scale, y_scale) by which the function should be zoomed to
that is visible, since if an integer is defined per pixel, it would be taking
from one end of the window to the other, an interval from −300 to 300 and for
small values of $a$ and $b$ would not have a good visualization of the function in
a first instance. With these variables already calculated, the function is called
void graph() which is the one that is in charge of evaluating void Function() with
an increment of 0.01 and join the resulting points with lines.
Now it would be the turn of the zoom functionality. For this it is defined
an infinite loop in which it is detected if a right or left click is given. If it is
Left click recalculates the position of the origin of coordinates and draws
the new axes corresponding to the duplication of the image through the functions int x_axis_zoom() and int y_axis_zoom() that use void Axes() to
meet your goal.
1If right is given, the function is drawn without any zoom. always in the corner
right upwards you can see a number that indicates the position in the
where the cursor is, this is done with the void coordinates() function inside the
while loop

## Application of the code to the proposed functions

### graph of $f(x) = x^3 + x^2 + 1$

Only with a representative objective, the interval from −5 to 5 will be taken, since all the behaviors of interest, for the three functions, can be analyzed
over there. If you want to try another interval and any other function, I invite you to
run the program and test it.
When running the program, the console appears asking for the arguments $a$ and $b$ with
a space in between, where we will put −5 and 5 for all functions:

<image
  src="/Graphics/1.png"
  alt="Descripción de la imagen"
  caption="Leyenda de la imagen">
  
 ### graph of $f(x) = \sin(10x)$
  
 To analyze this function we will start from the origin, it grows until it reaches a
  local maximum at about $x = 0.157$ and then intersects the axis again
  $x$ at the approximate point $2 \cdot 0.157$ so it could be said that the function
  approximately has zeros at $\pm2 \cdot k \cdot 0.157$ and local maxima and minima at
  
 <image
  src="/Graphics/1a.png"
  alt="Descripción de la imagen"
  caption="Leyenda de la imagen">
  
### graph of $f(x) = \frac{1}{x + 1}$
   
   As you can see this function remains undefined for $x = -1$, in the which the program draws an asyndote. We will also perform the three zooms around the region from -2 to 0, to better observe the function at the point of indeterminacy -1
   
  <image
  src="/Graphics/1b.png"
  alt="Descripción de la imagen"
  caption="Leyenda de la imagen">
  
 ## How to use the program
    
To use the algorithm, first of all you must modify the function within the code and then execute the program. When the console appear you must enter the values of the interval $(a, b)$ in which you want to graph and followed by A window will appear in which you can see the graph of the function. To zoom you just have to left click on the screen where you want enlarge the graphic, if you touch it three times the graphic will appear with original resolution, the same happens if you right click
    
