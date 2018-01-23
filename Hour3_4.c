#include <stdio.h>

main()
{
int number1 = 6;
int number2 = 10;
int results = 0;
results = multiply(number1,number2);
printf("%d",results);
}

multiply(int a, int b){
int result = 0;
result=a*b;
return result;
}


