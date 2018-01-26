 //4. Given that x=5 and y=6, write a program to calculate the multiplication of the two
//integers and print out the result, which is saved in x, all in the way of indirection
//(that is, using pointers).
#include<stdio.h>
main(){

int x = 5,y = 6;
int *ptr_x,*ptr_y;
ptr_x=&x;
ptr_y=&y;
*ptr_x=(*ptr_x)*(*ptr_y);


printf("The result of multipliyng is%d\n",(*ptr_x));

}
