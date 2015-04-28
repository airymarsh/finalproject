#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void printsli(int sli[3][5])
{
printf("------------\n");
for (int x = 0; x < 3; x++)
{
	printf("|");
	for(int y = 0; y < 5 ; y++ )
{
	switch(sli[x][y])  //print based on what number is there
	{
		case 0:
			printf("  ");
			break;
		case 1:
			printf("|)");
			break;
		case 2:
			printf("_.");
			break;
		case 3:
			printf("._");
			break;
		case 4:
			printf("(|");
			break;
		case 5:
			printf("Z ");
			break;
		case 6:
			printf("(o");
			break;
		case 7:
			printf("^_");
			break;
		case 8:
			printf("_^");
			break;
		case 9:
			printf("o)");
			break;
		case 10:
			printf("Z7");
			break;
		case 11:
			printf("('");
			break;
		case 12:
			printf(",_");
			break;
		case 13:
			printf("_,");
			break;
		case 14:
			printf("')");
			break;
		default:
			break;
	}
}
printf("|\n");
}
printf("------------\n");
}

bool checksli(int sli[3][5])
{
int test = 0;
for (int x = 0; x < 3; x++)
{
	for(int y = 0; y < 5 ; y++ )
{
	if(sli[x][y] >= test) //this makes sure that every number before is less than the one after else returns false
		test= sli[x][y];
	else
		return false;
}
}
return true;
}

bool slide()
{
printf("As I walk up to the mirror and look into it , I can feel it looking into me.\nThe mirror begins to distort and an image begins to form.\nIt's my most feared creature, a creature so vile and hated that it must have been spawned in the depths of hell!\n");
int slid[3][5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
printsli(slid);
printf("The picture distorts and voice rings out telling to restore the picture.\n");
int sli[3][5] = {1, 6, 2, 4, 9, 10, 7, 8, 13, 3, 11, 5, 12, 14, 0};
char str;
printsli(sli);
int x = 2;
int y = 4;
int temp = 0;
bool truth = checksli(sli); //make sure game isn't already won
while(!truth)
{
	if(str != '\n')
{
	printf("Please enter a valid move(up = u down = d left = l right = r quit = q):\n");
	printsli(sli);

}
	scanf("%c", &str); //input character
	getchar();
	switch(str)
		{
			case 'u': //move up
				{
					if( x -1 < 0)
						printf("Please enter a valid move!\n");
					else
						{
							temp = sli[x][y]; //switches index
							sli[x][y] = sli[x - 1][y];
							sli[x - 1][y] = temp;
							x = x-1;
						}
					break;
				}
			case 'd': //move down
				{
					if( x + 1 > 2)
						printf("Please enter a valid move!\n");
					else
						{
							temp = sli[x][y]; //switches index
							sli[x][y] = sli[x + 1][y];
							sli[x + 1][y] = temp;
							x = x+1;
						}
					break;
				}
			case 'l':  //move left
				{
					if( y - 1 < 0) //invalid move
						printf("Please enter a valid move!\n");
					else
						{
							temp = sli[x][y]; //switches index
							sli[x][y] = sli[x][y - 1];
							sli[x][y - 1] = temp;
							y = y-1;
						}
					break;
				}
			case 'r':  //move right
				{
					if( y +1 > 4) //invalid move
						printf("Please enter a valid move!\n");
					else
						{
							temp = sli[x][y]; //switches index
							sli[x][y] = sli[x][y + 1];
							sli[x][y + 1] = temp;
							y = y + 1;
						}
					break;
				}
			case 'q': //give up
				{

					printf("I can't restore the picture of such a hideous beast.\nAs I turn to leave, something shoots out and hits me in the head!\nThe mirror is blank and nothing can be seen within.\nI put the item in my inventory.\nCongratulations, you got a Tainted Mirror.\n");
					return false;
					break;
				}

		}
	truth = checksli(sli);	//check for completion
}

printsli(sli);
printf("As I complete the puzzle, the mirror shines with a multi-colored light and floats off the wall.\nIt starts to shrink and take the shape of a shield.\nAfter it transforms, I put it in my inventory.\nCongratulations, you got the Mirror Shield!\n");
return true;

}
