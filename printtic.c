#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printt(int tic[3][3])
{
int test = 1;
for(int y = 0; y< 3; y = y + 1)
{
printf(" -------\n");
printf("%d", test); //prints out test
for(int x = 0; x< 3; x = x + 1) //this will print x for 1's and O for 0's
{
printf("|");
if(tic[y][x] == 0)
printf("O");
else
if(tic[y][x] == 1)
printf("X");
else
printf(" ");
}
printf("|%d\n", test +2); //increments test
test = test + 3;
}
printf(" -------\n");

}

int choice(int tic[3][3])
{
	int ok = 0;
	int test[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //create array for choice
	for(int y = 0; y< 3; y = y + 1)
	{
		for(int x = 0; x< 3; x = x + 1)
		{
		if(tic[y][x] == 0 || tic[y][x] == 1) //basically if it is -1000 it won't be chosen
			test[ok] = -1000;
		ok = ok + 1;
		}
	}
	//the following code checks the state of the board and assigns value to the test array based on the state of the board
	if(test[0] != -1000) //first
		{
			if ((tic[0][1] == 1 && tic[0][2] == 1) || (tic[1][0] == 1 && tic[2][0] == 1) || (tic[1][1] == 1 && tic[2][2] == 1))
				test[0] = 10000000;
			else
			{
				if ((tic[0][1] == 0 && tic[0][2] == 0) || (tic[1][0] == 0 && tic[2][0] == 0) || (tic[1][1] == 0 && tic[2][2] == 0))
				test[0] = 100000;
				else
				{
					test[0] = 10;
				}
			}
		}
	if(test[1] != -1000) //second
		{
			if ((tic[0][0] == 1 && tic[0][2] == 1) || (tic[1][1] == 1 && tic[2][1] == 1))
				test[1] = 10000000;
			else
			{
				if ((tic[0][0] == 0 && tic[0][2] == 0) || (tic[1][1] == 0 && tic[2][1] == 0))
				test[1] = 100000;
				else
				{
					test[1] = 10;
				}
			}
		}
	if(test[2] != -1000)  //third
		{
			if ((tic[0][1] == 1 && tic[0][0] == 1) || (tic[1][2] == 1 && tic[2][2] == 1) || (tic[1][1] == 1 && tic[2][0] == 1))
				test[2] = 10000000;
			else
			{
				if ((tic[0][0] == 0 && tic[0][1] == 0) || (tic[1][1] == 0 && tic[2][0] == 0) || (tic[1][2] == 0 && tic[2][2] == 0))
				test[2] = 100000;
				else
				{
					test[2] = 10;
				}
			}
		}
	if(test[3] != -1000) //fourth
		{
			if ((tic[0][0] == 1 && tic[2][0] == 1) || (tic[1][1] == 1 && tic[1][2] == 1))
				test[3] = 10000000;
			else
			{
				if ((tic[0][0] == 0 && tic[2][0] == 0) || (tic[1][1] == 0 && tic[1][2] == 0))
				test[3] = 100000;
				else
				{
					test[3] = 10;
				}
			}
		}
	if(test[4] != -1000) //fifth
		{
			if ((tic[0][0] == 1 && tic[2][2] == 1) || (tic[0][2] == 1 && tic[2][0] == 1) || (tic[0][1] == 1 && tic[2][1] == 1) || (tic[1][0] == 1 && tic[1][2] == 1))
				test[4] = 10000000;
			else
			{
				if ((tic[0][0] == 0 && tic[2][2] == 0) || (tic[0][2] == 0 && tic[2][0] == 0) || (tic[0][1] == 0 && tic[2][1] == 0) || (tic[1][0] == 0 && tic[1][2] == 0))
				test[4] = 100000;
				else
				{
					test[4] = 50;
				}
			}
		}
	if(test[5] != -1000) //sixth
		{
			if ((tic[0][2] == 1 && tic[2][2] == 1) || (tic[1][0] == 1 && tic[1][1] == 1))
				test[5] = 10000000;
			else
			{
				if ((tic[0][2] == 0 && tic[2][2] == 0) || (tic[1][0] == 0 && tic[1][1] == 0))
				test[5] = 100000;
				else
				{
					test[5] = 10;
				}
			}
		}
	if(test[6] != -1000) //seventh
		{
			if ((tic[0][0] == 1 && tic[0][1] == 1) || (tic[1][1] == 1 && tic[0][2] == 1) || (tic[2][1] == 1 && tic[2][2] == 1))
				test[6] = 10000000;
			else
			{
				if ((tic[0][0] == 0 && tic[0][1] == 0) || (tic[1][1] == 0 && tic[0][2] == 0) || (tic[2][1] == 0 && tic[2][2] == 0))
				test[6] = 100000;
				else
				{
					test[6] = 10;
				}
			}
		}
	if(test[7] != -1000) //eighth
		{
			if ((tic[2][0] == 1 && tic[2][2] == 1) || (tic[1][1] == 1 && tic[0][1] == 1))
				test[7] = 10000000;
			else
			{
				if ((tic[2][0] == 0 && tic[2][2] == 0) || (tic[1][1] == 0 && tic[0][1] == 0))
				test[7] = 100000;
				else
				{
					test[7] = 10;
				}
			}
		}
	if(test[8] != -1000) //nineth
		{
			if ((tic[2][0] == 1 && tic[2][1] == 1) || (tic[0][2] == 1 && tic[1][2] == 1) || (tic[1][1] == 1 && tic[0][0] == 1))
				test[8] = 10000000;
			else
			{
				if ((tic[2][0] == 0 && tic[2][1] == 0) || (tic[0][2] == 0 && tic[1][2] == 0) || (tic[1][1] == 0 && tic[0][0] == 0))
				test[8] = 100000;
				else
				{
					test[8] = 10;
				}
			}
		} //end of choice logic
	int max = 0;
	int ret = 0;

	for(int x = 0; x < 10; x++)
	{
		if(test[x] > max) //finds the biggest value and saves the index
		{
			max = test[x];
			ret = x + 1;
		}
	}
	return ret; //returns the index+1 for the placement logic
}

void place(int x, int y, int tic[3][3])
{
switch(x) //places it in the correct space
{
case 1:
tic[0][0] = y;
break;
case 2:
tic[0][1] = y;
break;
case 3:
tic[0][2] = y;
break;
case 4:
tic[1][0] = y;
break;
case 5:
tic[1][1] = y;
break;
case 6:
tic[1][2] = y;
break;
case 7:
tic[2][0] = y;
break;
case 8:
tic[2][1] = y;
break;
case 9:
tic[2][2] = y;
break;
default:
printf("Please enter a valid number.\n");
break;
}
}

bool check(int x, int tic[3][3])
{
switch(x) //checks if the space is -1 or taken and returns true for -1 and false for taken
{
case 1:
if (tic[0][0] == -1)
return true;
else
return false;
break;
case 2:
if (tic[0][1] == -1)
return true;
else
return false;
break;
case 3:
if (tic[0][2] == -1)
return true;
else
return false;
break;
case 4:
if (tic[1][0] == -1)
return true;
else
return false;
break;
case 5:
if (tic[1][1] == -1)
return true;
else
return false;
break;
case 6:
if (tic[1][2] == -1)
return true;
else
return false;
break;
case 7:
if (tic[2][0] == -1)
return true;
else
return false;
break;
case 8:
if (tic[2][1] == -1)
return true;
else
return false;
break;
case 9:
if (tic[2][2] == -1)
return true;
else
return false;
break;
default:
return false;
break;
}
}

bool victory(int x, int tic[3][3])
{ //this code checks for the possible 8 victory conditions and returns true for victory and false for no win
if(tic[0][0] == x && ((tic[0][1] == x && tic[0][2] == x) || (tic[1][0] == x && tic[2][0] == x) || (tic[1][1] == x && tic[2][2] == x)))
return true;
if(tic[1][1] == x && ((tic[0][1] == x && tic[2][1] == x) || (tic[0][2] == x && tic[2][0] == x) || (tic[1][0] == x && tic[1][2] == x)))
return true;
if(tic[2][2] == x && ((tic[0][2] == x && tic[1][2] == x) || (tic[2][0] == x && tic[2][1] == x)))
return true;

return false; //defaut no win
}

bool toe()
{
int vic = 0;
int los = 0;
while(true)
{
int tic[3][3]= {-1,-1,-1,-1,-1,-1,-1,-1,-1}; //default board
if(vic == 4 || los == 4)
	break;

int x = -1;
int turns = 1;
bool valid = false;
bool wincon = false;
printt(tic); //prints the board
while(wincon == false)
{

	bool valid = false; // make sure valid number
	while(!valid)
	{
	printf("Please enter a valid number: \n");
	scanf("%d", &x); //scan in a number
	valid = check(x, tic); //checks the number for valid
	}
	turns = turns + 1; //turn counter
	place(x, 0, tic); //places it on the board
	printt(tic); // prints board
	wincon = victory(0, tic); //check victory

if (wincon == true)
	{
	vic = vic+1; //victory counter
	printf("Impossible!  I won't accept this, again!\n");
	break; //ends current loop
	}
if(turns != 10)
	{
	turns = turns + 1; //inc turn
	x = choice(tic); //decide what index to choose
	place(x, 1, tic); //places it into the board
	printt(tic); //prints the board
	wincon = victory(1, tic); //checks victory
	if (wincon == true)
		{
		los = los+1; //lose counter
		if(los != 4) //choice for game over
		printf("HaHaHa...I win this round, but I'll give you another chance.\n");
		break;
		}
	}
if(turns == 10) //if no winner and tie
	{
	printf("A tie, eh? Play again!\n"); //All moves have been made
	break;
	}
}
}
if(vic== 4) //four wins
{
printf("As he was challenging me again, cracks started to form on the knight and he shattered into millions of little pieces.\nGeez, to break after four losses, what a two-bit knight!\nAnd thus I gained access to Strange Manor.\n");
return true;
}
if(los==4) //four
{
printf("After losing four times, my confidence is shattered and I could no longer go on and ran away with all my strength.\nI was never seen again.");
return false;
}
}
