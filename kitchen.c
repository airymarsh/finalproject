#include <stdio.h> // Standard IO
#include <stdlib.h> // other stuff
#include <time.h>
#include <string.h>
#include <stdbool.h>


int rand_i(int n)// random method for user and chef
{
	int rand_max = RAND_MAX - (RAND_MAX % n);
	int ret;
	while ((ret = rand()) >= rand_max);
	return ret/(rand_max / n);
}

int weighed_rand(int *tbl, int len)
{
	int i, sum, r;
	for (i = 0, sum = 0; i < len; sum += tbl[i++]);
	if (!sum) return rand_i(len);

	r = rand_i(sum) + 1;
	for (i = 0; i < len && (r -= tbl[i]) > 0; i++);
	return i;
}



bool kitchenGame()// main method
{
	char umove[10], cmove[10], line[255];
	int hero, chef, x=0;
	int tbl[]={0,0,0};
	int tbllen=3;
	printf("Welcome to Hell's Kitchen!!\n");// Rules and info
	printf(" The goal is to find the legendary Buster Sword.\n");
	printf("Time to battle the chef from Hell\n");
	printf("Find the location of the weapon and you win. ");
	printf("If the chef guesses it then you lose and get the bad weapon the Tonberry Knife!!");
mainloop:
	while(x<2) // condition to only get two guesses
	{
		printf("\n\nPlease type in 1 for Stove, 2 For Fridge, 3 for Cabinets, 4 to quit\n");
		srand(time(NULL));
		chef = (weighed_rand(tbl, tbllen) + 1) % 3;
		fgets(line, sizeof(line), stdin);
		while(sscanf(line, "%d", &hero) != 1 )//1 match of defined specifier on input line
		{
  			printf("You have not entered an integer.\n");
			fgets(line, sizeof(line), stdin);
		}
		if( (hero > 4) || (hero < 1) )
		{
			printf("Please enter a valid number!\n");
			continue;
		}
		switch (chef)// switch statements for  conditions/ search areas for chef
		{
			case 1 :
				strcpy(cmove, "Stove");
				break;
			case 2 :
				strcpy(cmove, "Fridge");
				break;
			case 3 :
				strcpy(cmove, "Cabinets");
				break;
			default :
				printf("Computer Error, set comp=1\n");
				chef=1;
				strcpy(cmove, "Stove");
				break;
		}
		switch (hero)// switch statements for  conditions/ search areas for hero
		{
			case 1 :
				strcpy(umove, "Stove");
				break;
			case 2 :
				strcpy(umove, "Fridge");
				break;
			case 3 :
				strcpy(umove, "Cabinets");
				break;
			case 4 :
				printf("Giving up already huh!n");
				return false;
			default :
				printf("Error, follow directions...");// Error checking
				goto mainloop;
		}
		if( (hero+1)%3 == chef )// condition for winning/losing
		{
			printf("Chef Played: %s\nYou Played: %s\nHa Ha Loser!!!\n", cmove, umove);
			return false;
		}
		else if(chef == hero)
		{
			printf("Chef Played: %s\nYou Played: %s\nYou Tied, but I win!! :p\n", cmove, umove);
			return false;
		}
		else
		{
			printf("Comp Played: %s\nYou Played: %s\nUggggghhhhhhh I can't believe this! You won!!\n", cmove, umove);
			return true;
		}
		tbl[hero-1]++;
		x++; // update statement for turns
	}
}
