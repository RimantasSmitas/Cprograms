//2. Write a program to update the value of the double variable flt_num from 123.45
//to 543.21 by using a double pointer


#include<stdio.h>
main (){
double number, *ptr_n;
number = 123.45;
ptr_n = &number;
*ptr_n=543.21;
printf("the number is %f.\n",number);
}
