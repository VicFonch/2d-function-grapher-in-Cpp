# 2D Function Grapher-in C++

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


