//4. Rewrite the program in Listing 12.5. This time put a string of characters, I like
//C!, on the screen.


#include <stdio.h>

 main()
{
char array_ch[15] = "I like C!";
int i;
/* array_ch[i] in logical test */
for (i=0; array_ch[i]; i++)
printf("%c", array_ch[i]);

printf("\n");
return 0;
 }
