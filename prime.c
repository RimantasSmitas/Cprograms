#include <stdio.h>




main()
{
int x,y;
x = 1;
for (x;x<1025;x++){
for (y=2;y<=x-1;y++){
	if(x%y==0)
	{printf("number is not prime %d\n",x);
	}
	}
printf("number is prime%d\n",x);}
}

