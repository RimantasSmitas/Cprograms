#include <stdio.h>

main()
{
int results = 0;
results = block();
printf("%d",results);
}


block(){
int x = 0;
int y = 0;
x = 3;
y = 5 + x;
return y;
}
