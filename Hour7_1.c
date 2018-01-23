//1. What is the difference between the following two pieces of code?
//for (i=0, j=1; i<8; i++, j++)
//printf(“%d + %d = %d\n”, i, j, i+j);
//for (i=0, j=1; i<8; i++, j++);
//printf(“%d + %d = %d\n”, i, j, i+j);


#include<stdio.h>

main (){

int i,j;
for (i=0, j=1; i<8; i++, j++)
{printf("first");
printf("%d + %d = %d\n", i, j, i+j);
}
for (i=0, j=1; i<8; i++, j++);
//semicolon  Stops the loop from running normaly 
{printf("second");
printf("%d + %d = %d\n", i, j, i+j);
}
}
