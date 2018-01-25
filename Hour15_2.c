//Declare and define a function, called MultiTwo(), that can perform multiplication
//on two integer variables. Call the MultiTwo() function from the main() function
//and pass two integers to MultiTwo(). Then print out the result returned by the
//MultiTwo() function on the screen.


#include<stdio.h>

main(){
int a,b;
a = 10;
b = 60;
MultiTwo(a,b);
}

MultiTwo(int a,int  b){
int result = a *b;
Print(a,b,result);
}


Print(int a, int b, int result)
{printf("The result of multipliyng %d and %d is equal to %d.\n",a,b,result);}
