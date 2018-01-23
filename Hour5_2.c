//2. Display the two numbers 123 and 123.456 and align them at the left edge of the field.
#include <stdio.h>

main(){

int num = 123;
float num2 = 123.456;

printf("%-5d\n",num);
printf("%-5f\n",num2); return 0;
}
