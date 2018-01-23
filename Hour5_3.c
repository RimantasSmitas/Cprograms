//3. Given three integers, 15, 150, and 1500, write a program that prints the integers on the screen in the hex format.
#include <stdio.h>

main()
{
int num1 = 15, num2 = 150, num3 = 1500;

printf("Hex(uppercase) Hex(lowercase) Decimal\n");
printf("%X %x %d\n", num1, num1, num1);
printf("%X %x %d\n", num2, num2, num2);
printf("%X %x %d\n", num3, num3, num3);
}
