#include <stdio.h>

int inv[7];
int room();

int main()
{
	inv[1]= room();
	printf("\n%d", inv[1]);
	return 0;
}

int room()
{
	printf("Code for the room here!");
	return 1; /*one for good item, 2 for bad item*/
}
