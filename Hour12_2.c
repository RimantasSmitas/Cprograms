//2. Rewrite the program in Exercise 1, but this time use a for loop to initialize the
//character array with ‘a’, ‘b’, ‘c’, ‘d’, and ‘e’, and then print out the value of
//each element in the array.


#include<stdio.h>
main(){
char array_ch[5] = {};
int i;
for (i=0; i<5; i++)
array_ch[i] = i +97 ;

for (i=0; i<5; i++){
printf("list_int[%d] contains %c.\n", i, array_ch[i]);
}
return 0;
}

