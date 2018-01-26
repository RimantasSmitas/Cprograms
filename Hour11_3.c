//3. Given a character variable ch and ch = ‘A’, write a program to update the value of
//ch to decimal 66 by using a pointer
#include<stdio.h>


main (){
char number;
int  *ptr_n,number2;
number = 'A';
number2  = 66;
ptr_n = &number2;
*ptr_n = number;
printf("the number is %d.\n",number);
}
