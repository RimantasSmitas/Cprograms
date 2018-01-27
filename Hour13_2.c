/*Write a program to measure the length of a string by evaluating the elements in a
character array one by one until you reach the null character. To prove you get the
right result, you can use the strlen() function to measure the same string again.
*/
#include<stdio.h>
#include<string.h>
main(){

char measureThis[] = "I have a complicated relationship with C:|.";
int length;
length = 0;
while(measureThis[length]!=0){length++;}

printf("The String is :%s\n",measureThis);
printf("The length of a string\n%d characters\n",length);
printf("The length of a string\n%d characters\n",strlen(measureThis));


}
