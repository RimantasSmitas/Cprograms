//5. Rewrite the program in Listing 7.6. This time, use a while loop as the outer loop,
//and a do-while loop as the inner loop.
#include <stdio.h>
main()
{
int i=1, j;
/* outer loop */
while (i<=3){
i++;
printf("The start of iteration %d of the outer loop.\n", i);


do {
printf(" Iteration %d of the inner loop.\n", j);
printf("The end of iteration %d of the outer loop.\n", i);
j++;
}
while (j<=4);
/* inner loop */
}
return 0;
}
