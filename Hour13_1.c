/*1. Given a character array in the following statement,
char str1[] = “This is Exercise 1.”;
write a program to copy the string from str1 to another array, called str2.
*/
#include<string.h>
#include<stdio.h>
main(){

char str1[] = "This is Exercise 1.";
char str2[20];
char str3[20];
strcpy(str2, str1);
int i;
for (i=0; str1[i]; i++)
	str3[i] = str1[i];
str3[i] = '\0';

printf("Srting 1:%s\nString 2:%s\nString 3:%s\n",str1,str2,str3);
}
