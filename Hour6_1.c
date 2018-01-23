//1. Given x = 1 and y = 3, write a program to print out the results of these expressions:
//x += y, x += -y, x -= y, x -= -y, x *= y, and x *= -y.
#include <stdio.h>
main(){
int x=1, y=3;

printf("x = 1 y = 3 ");
printf("x+=y is : %d\n", x+=y);
printf("x+=-y is : %d\n", x+=-y);
printf("x-=y is : %d\n", x-=y);
printf("x-=-y is : %d\n",x-=-y);
printf("x*=y is : %d\n",x*=y);
printf("x*=-y is : %d\n",x*=-y);
}
