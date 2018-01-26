//3. Given a character variable ch and ch = ‘A’, write a program to update the value of
//ch to decimal 66 by using a pointer
#include<stdio.h>


main (){
char number, *ptr_n;
int  number2,*ptr_n2;
number = 'A';
number2 = 66;
ptr_n = &number;
ptr_n2 = &number2;
*ptr_n=*ptr_n2;
printf("the number is %d.\n",number);
}
