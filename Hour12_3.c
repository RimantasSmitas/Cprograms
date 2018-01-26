//3. Given this two-dimensional unsized array:
//char list_ch[][2] = {
//‘1’, ‘a’,
//‘2’, ‘b’,
//‘3’, ‘c’,
//‘4’, ‘d’,
//‘5’, ‘e’,
//‘6’, ‘f’};
//write a program to measure the total bytes taken by the array, and then print out all
//elements of the array

#include<stdio.h>
main(){

char list_ch[][2] = {
'1', 'a',
'2', 'b',
'3', 'c',
'4', 'd',
'5', 'e',
'6', 'f'};


int i, j,total= 0;

for (i=0; i<3; i++){
printf("\n");
for (j=0; j<2; j++)
total = total + sizeof(list_ch[i][j]);
}
printf("total size of the array is equal to %d",total);

}
