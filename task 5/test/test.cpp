#include "graphics.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <stdio.h>
int i, j = 0, gd = DETECT, gm;
int rect,rect2,score=0;//This set the score at 0 to start.
const int Width = 800;//This  the width of the window. 
const int Height = 600;//This  the Height of the window. 
int g_offSet = 170;//This is offset from the right of the window. 
int g_offSet2 = 170;//This is offset from the bottom of the window. 
typedef int Radius;//This adds additional name for the int data type

struct Point//This creates a struct for points.
{
    double x;
    double y;
    Point() {}
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
};
template <typename A>
Point convertPixel(A &x, A &y)//Adds Offsets and inverts x,y coordinates.
{
     x = -x;//inverts x
    x += Width - g_offSet2;//Adds Offset to x.
    y = -y;// inverts y 
    y += Height - g_offSet;//Adds Offset to y.
    return {x, y};
}
void drawPixel(double x, double y, int color)//Draws a pixel at x,y.
{
    convertPixel(x, y);// Calls the convertPixel function and passes it x,y.
    putpixel(x, y, color);// Calls the convertPixel function and passes it x,y and the colour of the pixel.
}

void fill(double x, double y, int color)// Fills a space at x,y with a colour.
{
    convertPixel(x, y);// Calls the convertPixel function and passes it x,y.
    floodfill(x,y,color);// Calls the floodfill function of graphics.h and passes it x,y and the colour to fill a shape. 
}
void draw_line_DDA(Point a, Point b, int color)//Draws a line from point A to point B .
{
    double x0 = a.x, y0 = a.y, x1 = b.x, y1 = b.y;//Sets x,y coordinates.
    double dx = x1 - x0;//Sets x,y coordinates.
    double dy = y1 - y0;//Sets x,y coordinates.

    double steps = std::max(abs(dx), abs(dy));//Finds the length of the line.

    double Xinc = dx / steps;//Sets the x path of the line.
    double Yinc = dy / steps;//Sets the y path of the line.
    for (int i = 0; i < steps; i++)//Draws pixel at x0,y0 and then moves its location along the line for length of the line(steps).
    {
        drawPixel(x0, y0, color);// Calls the drawPixel function and passes it x,y and the colour of the pixel.
        x0 += Xinc;//Moves x by the path of the line.
        y0 += Yinc;//Moves x by the path of the line.
    }
}
void triangle()//Draws a triangle.
{
    draw_line_DDA({1 , 20}, {150 , 300}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({150 , 300}, {300 , 20}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({1 , 20}, {300 , 20}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    fill(50,50,WHITE);// Calls the fill  function and passes it x,y and the colour to be filled.
}
void square()//Draws a square.
{
    draw_line_DDA({1 , 1}, {1 , 300}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({1 , 1}, {300 , 1}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({300 , 1}, {300 , 300}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({1 , 300}, {300 , 300}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
   fill(50,50,WHITE);// Calls the fill  function and passes it x,y and the colour to be filled.
}
void Rectangle(int rectHeight,int rectwidth)//Draws a Rectangle with random length sides.
{
    draw_line_DDA({1 , 1}, {1 , rectHeight}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({1 , 1}, {rectwidth , 1}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({rectwidth , 1}, {rectwidth , rectHeight}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    draw_line_DDA({1 , rectHeight}, {rectwidth , rectHeight}, WHITE);// Calls the draw_line_DDA function and passes it point A & B and the colour of the line.
    fill((rectwidth-5),(rectHeight -5),WHITE);// Calls the fill function and passes it x,y and the colour to be filled.
}

void Other()//Draws a random other shape.
{
    srand(time(nullptr)); //seeds the random number generator.
    int shapeimp = rand()%5+1,size;//generates a random number between 5 & 1.
    switch (shapeimp)//Draws a random shape corresponding to shapeimp.
    {
         case 1://Draws a pentagon.
            {
             int  otherShape[]={200,0, 105,69, 141,181 ,259,181, 295,69, 200,0};//Fills array with coordinates for a pentagon.

                for (int s = 1; s <= 12; s++)//Adds Offsets and inverts x,y coordinates.
                {
                    if (s%2 ==0)
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts y.
                        otherShape[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.
                       
                    }
                    else
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts x.
                        otherShape[(s-1)] +=Width -g_offSet  ;//Adds Offset to x.
                       
                    }
                    
                }
                
             drawpoly(6,otherShape);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a pentagon. 
            }
            break;
         case 2://Draws a heptagon.
            {
              int  otherShape[]={200,50, 83,106, 54,233, 135,335, 265,335, 346,233, 317,106, 200,50};//Fills array with coordinates for a heptagon.

                for (int s = 1; s <= 16; s++)//Adds Offsets and inverts x,y coordinates.
                {
                    if (s%2 ==0)
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts y.
                        otherShape[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.
                       
                    }
                    else
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts x.
                        otherShape[(s-1)] +=Width -g_offSet ;//Adds Offset to x.
                       
                    }
                    
                }
                
             drawpoly(8,otherShape);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a heptagon. 
            }
            break;
             case 3://Draws a decagon.
            {
             int  otherShape[]={131,5, 69,5, 19,41, 0,100, 19,159, 69,195, 131,195, 181,159, 200,100, 181,41 ,131,5};//Fills array with coordinates for a decagon.

                for (int s = 1; s <= 22; s++)//Adds Offsets and inverts x,y coordinates.
                {
                    if (s%2 ==0)
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts y.
                        otherShape[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.
                       
                    }
                    else
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts x.
                        otherShape[(s-1)] +=Width -g_offSet ;//Adds Offset to x.
                       
                    }
                    
                }
                
             drawpoly(11,otherShape);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a decagon.
            }
            
            break;
             case 4://Draws a star of david with two triangles.
            {
             int  otherShape[]={100,0, 13,150, 187,150, 100,0};//Fills array with coordinates for a triangle one.
              int  otherShape2[]={100,200, 187,50, 13,50, 100,200};//Fills array with coordinates for a triangle two.
                for (int s = 1; s <= 8; s++)//Adds Offsets and inverts x,y coordinates.
                {
                    if (s%2 ==0)
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts y.
                        otherShape[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.

                        otherShape2[(s-1)] = -otherShape2[(s-1)] ;//Inverts y.
                        otherShape2[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.
                    }
                    else
                    {
                        otherShape[(s-1)] = -otherShape[(s-1)] ;//Inverts x.
                        otherShape[(s-1)] +=Width -g_offSet ;//Adds Offset to x.
                        
                        otherShape2[(s-1)] = -otherShape2[(s-1)] ;//Inverts x.
                        otherShape2[(s-1)] +=Width -g_offSet ;//Adds Offset to x.
                       
                    }
                    
                }
                 drawpoly(4,otherShape);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a triangle one.
             drawpoly(4,otherShape2);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a triangle two.
            }
            
            break;
             case 5://Draws a star of pentagram with four triangles.
            {
                int  otherShape1[]={105,69, 295,69, 200,0, 105,69};//Fills array with coordinates for a triangle one.
                int  otherShape2[]={141,181, 200,0, 295,69, 141,181};//Fills array with coordinates for a triangle two.
                int  otherShape3[]={259,181, 295,69, 200,0, 259,181};//Fills array with coordinates for a triangle three.
                int  otherShape4[]={105,69, 141,181, 259,181, 105,69};//Fills array with coordinates for a triangle four.
                for (int s = 1; s <= 8; s++)
                {
                    if (s%2 ==0)
                    {
                        otherShape4[(s-1)] = -otherShape4[(s-1)] ;//Inverts y.
                        otherShape4[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.

                        otherShape3[(s-1)] = -otherShape3[(s-1)] ;//Inverts y.
                        otherShape3[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.

                        otherShape2[(s-1)] = -otherShape2[(s-1)] ;//Inverts y.
                        otherShape2[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.

                        otherShape1[(s-1)] = -otherShape1[(s-1)] ;//Inverts y.
                        otherShape1[(s-1)] +=Height -g_offSet2 ;//Adds Offset to y.
                    }
                    else
                    {
                        otherShape4[(s-1)] = -otherShape4[(s-1)] ;//Adds Offset to x.
                        otherShape4[(s-1)] +=Width -g_offSet ;//Adds Offset to x.

                        otherShape3[(s-1)] = -otherShape3[(s-1)] ;//Adds Offset to x.
                        otherShape3[(s-1)] +=Width -g_offSet ;//Adds Offset to x.

                        otherShape2[(s-1)] = -otherShape2[(s-1)] ;//Adds Offset to x.
                        otherShape2[(s-1)] +=Width -g_offSet ;//Adds Offset to x.
                        
                        otherShape1[(s-1)] = -otherShape1[(s-1)] ;//Adds Offset to x.
                        otherShape1[(s-1)] +=Width -g_offSet ;//Adds Offset to x.
                       
                    }
                    
                }
             drawpoly(4,otherShape1);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a triangle one.
             drawpoly(4,otherShape2);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a triangle two.
             drawpoly(4,otherShape3);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a triangle three.
             drawpoly(4,otherShape4);// Calls the drawpoly function of graphics.h and the number of points, and the othershape array with the points for a triangle four.
            }
            break;
     default:
        break;
    }
   
}

int MainMenu()//This is the main menu
{
    void FinalScore();//initializes the final score  function so it can call it  
    int main();//initializes the main function so it can call it  
    char MenuImp;// Holds user input.
    do
    {
        outtextxy(20, 170, "Press {A} For Play");//Calls the outtextxy function of graphics.h and draws text at x,y.
        outtextxy(20, 190, "Press {B} For Final Score");//Calls the outtextxy function of graphics.h and draws text at x,y.
        outtextxy(20, 210, "Press {C} To Exit");//Calls the outtextxy function of graphics.h and draws text at x,y.
       MenuImp = (char) getch( );//Takes a input from the user.
        
        switch (MenuImp)
        {
            case 'a':
            {
             main();//Calls the main function .
            }
            break;
            case 'b':
            {
                FinalScore();//Calls the final score function.
            }
            break;
            case 'c':
            {
                exit(0);//Exits the program.
            }
            break;
        
            default:
            {
             outtext( "Invaild Input");//Calls the outtextxy function of graphics.h and draws text at the top of the viewport .
             delay(1000);//Delay the next line by a set number of milliseconds
             clearviewport();
            }
            break;
        }


    } while (true);//loops the function.
    
  leave:return 0;
}
void CalculateScore()
{
 score += 10;

 clearviewport( );
 std::string output = "the score is : ";
 std::string scoreImp = std::to_string(score); 
 output.append(scoreImp);
 std::string Str17 = output;
 char *Fixer = new char[Str17.length()+1];
  strcpy(Fixer,Str17.c_str());
    outtextxy(20, 70,Fixer);
     delay(1000);
    delete [] Fixer;
     clearviewport( );
   MainMenu();
  
}
void FinalScore()
{
    clearviewport( );
 std::string output = "the score is : ";
 std::string scoreImp = std::to_string(score); 
 output.append(scoreImp);
 std::string Str7 = output;
 char *Fixer = new char[Str7.length()+1];
  strcpy(Fixer,Str7.c_str());
    outtextxy(20, 70,Fixer);
    delete [] Fixer;
   MainMenu();
}
int main()
{
 
    srand(time(nullptr));
    char c,Cs;
    initwindow(Width,Height,"task5");
      clearviewport( );
    rect = rand() %300+25;
    rect2 = rand() %300+25;
    
    int shape =  rand()%4+1;
    switch (shape)
    {
        case 1:
            {
                triangle();
                Cs ='b';
            }
            break;
            case 2:
            {
                Rectangle(rect,rect2);
                Cs ='a';
               
            }
            break;
            case 3:
            {
             square();
             Cs ='c';
            }
            break;
            case 4:
            {
                Other();
                Cs ='d';
            }
            break;
            
    
     default:
        break;
    }
    
    outtextxy(20, 130, "Identify the Shapes");
    outtextxy(20, 150, "What Is the Current shape ?");
    outtextxy(20, 170, "Press {A} if it is a Rectangle");
    outtextxy(20, 190, "Press {B} if it is a Triangle");
    outtextxy(20, 210, "Press {C} if it is a Square");
    outtextxy(20, 230, "Press {D} if it is None of the above");
    do
    {
        c = (char) getch( );
        if (c == Cs )
        {

            std::cout << "vitory " << (int) c << std::endl;
            c=0,Cs=0;
            CalculateScore();
        } 
            else
            {   clearviewport( );
            outtextxy(20, 130, "Identify the Shapes");
            outtextxy(20, 150, "INCORECT SHAPE try again");
            main();
            }
    }   while ((c != 'x') && (c != 'X'));
    getchar();
    
    return 0;
}

