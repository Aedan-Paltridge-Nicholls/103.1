// identify the Shapes 
#include <iostream>
//#include <graphics.h>
char ltc = 201u;
char rtc = 187u;
char lbc = 200u;
char rbc = 188u;
char hdl = 205u;
char vdl = 186u;
char spa = 32;
char rdl = 92u;
char ldl = 92u;
char shl = 92u;
void square()
{

 std::cout <<ltc;
 for (int i = 0; i < 7; i++)
 {std::cout<<hdl ;}
 std::cout<<rtc <<std::endl;
 for (int i = 0; i < 3; i++)
 {
    std::cout <<vdl;
    for (int i = 0; i < 7; i++)
    {std::cout <<spa;}
    std::cout<< vdl<<std::endl;
 }
    std::cout <<lbc;
    for (int i = 0; i < 7; i++)
    {std::cout<<hdl ;}
    std::cout<<rbc <<std::endl; 

}
void triangle()
{
  std::cout<<ldl<<rdl <<std::endl; 
    
}
int main()
{
 square();
 triangle();

}