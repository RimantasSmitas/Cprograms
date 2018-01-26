//4. Given that x=5 and y=6, write a program to calculate the multiplication of the two
//integers and print out the result, which is saved in x, all in the way of indirection
//(that is, using pointers).
#include<stdio.h>
main(){
int x = 5, *ptr_x,y = 6;
ptr_x = &x;
*ptr_x = multiply(x,y);
printf("The result of multipliyng is%d\n",x);



}
multiply(int x, int y){
return (x*y);


}
