#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "start.h"
#include "playerDeath.c"
#include "printtic.c"
#include "slider.c"
#include "bedroom.c"
#include "dungeon.c"
#include "kitchen.c"


//Final Version: Denzel Young
//Several structs were deemed unnecessary or a waste of memory, so only the Room struct remains.
//The Room struct contains two boolean values, success and visited.
//Success tells if the player won the room.
//Visited tells if the player has at least been to the room.

/*int climaticBattle(int inventory[4])
{
    int userchoice; //This is the User's Choice
    int strangechoice; //This is the boss's choice
    int atk, def, matk, damage, strangedamage, strangeatk, strangedef, strangematk;
    int matk2;
    int atk2;
    int answer; //Answer for the do-while loop in case they want to start all over again
    int strangehp; //The boss's HP
    time_t t; //This decides who goes first. If it is 1, then the player goes first. If it is 0, then the boss goes first.
    srand((unsigned) time(&t));
    t = rand()%2; //A random integer between 0 and 1.

    if (t == 1){
            do
            {
                int hp = 10000;//The player's hp
                int mp = 150; //The player's mp
                strangehp = 50000;//The boss's hp
        printf("You can start! Its your turn...........this time! \n");
        while(hp > 0 && mp > 0 && strangehp > 0) {
            printf("Which action would you like to use against Dr. Strange? Choose carefully.\n");
            printf("1 -> Sword Attack \n 2 -> Magic Attack \n 3 -> Defend Yourself! \n");
            scanf("%d", &userchoice);
            if(userchoice > 3 || userchoice < 1){
                printf("Please Enter the correct number between 1 and 3, please! (YOU FOOLISH MORTAL)!");
                return 0;
            }
            switch(userchoice){//Switch statements based on the user's choice
                case 1:
                if(inventory[1]==1)
                {

                    printf("You attack Doctor Strange with your Powerful Sword!");
                    damage = 400 + (rand() % 61);

                }
                else{
                    printf("You ATTACK DR. STRANGE WITH YOUR CRAPPY SWORD!!!!!");
                    damage = 50 + (rand() % 121);
                }
                break;         //If sword equals crappy sword, then it deals less damage.
            //If sword equals good sword, then it deals more damage
                case 2:
                if(inventory[2]==1 && mp > 0)
                {

                    printf("You attack Doctor Strange with your Banshee Megaphone!");
                    damage = 600 + (rand() % 81);
                    mp = mp - 25;

                }
                else if(inventory[2] == 0 && mp > 0){
                    printf("You ATTACK DR. STRANGE WITH YOUR Astonishing Jack-In-Box!!!!!");
                    damage = 100 + (rand() % 121);
                    mp = mp - 10;
                }
                else{
                    printf("You have no MP DUMBASS!");
                }
             //If weapon equals Jack-in-the-Box, then it deals less damage.
            //If weapon equals BullHorn, then it deals more damage
                break;
                case 3:
                    if(strangechoice==2){


                    if(inventory[0]==1 && inventory[3]==1){
                    printf("YOU DEFENDED YOURSELF WITH THE AMAZING ARMOR!!!! STRANGE'S ATTACK IS HALVED \n");
                    printf("THE STRANGE MAGIC, APOKAYPSE IS REFLECTED RIGHT BACK AT HER!!! HOORAH!!!!! \n");
                    int strangedamage = strangedamage/2;
                    int strangematk= strangematk/2;
                    //matk2 = damage;

                    }
                    else if(inventory[0]==1 && inventory[3]==0){
                    printf("YOU DEFENDED YOURSELF WITH THE AMAZING ARMOR!!!! STRANGE'S ATTACK IS HALVED \n");
                    printf("THE STRANGE MAGIC, APOKAYPSE IS REFLECTED RIGHT BACK AT HER!!! but its weak as hell!!! \n");
                    int strangedamage = strangedamage/2;
                    int strangematk= strangematk - (strangematk/3);
                    }
                    else if(inventory[0]== 0 && inventory[3]==1){
                    printf("YOU DEFENDED YOURSELF WITH THE CRAPPY ARMOR!!!! STRANGE'S ATTACK IS SLIGHTLY LOWER!!!!!  \n");
                    printf("THE STRANGE MAGIC, APOKAYPSE IS REFLECTED RIGHT BACK AT HER!!! HOORAH!!!!! \n");
                    int strangedamage = strangedamage - (strangedamage/3);
                    int strangematk= (strangematk/2);
                    }
                    else if(inventory[0]==0 && inventory[3]==0){
                    printf("YOU DEFENDED YOURSELF WITH THE AMAZING ARMOR!!!! STRANGE'S ATTACK IS SLIGHTLY LOWER!!!!! \n");
                    printf("THE STRANGE MAGIC, APOKAYPSE IS REFLECTED RIGHT BACK AT HER!!! but its weak as hell!!! \n");
                    int strangedamage = strangedamage/2;
                    int strangematk= strangematk - (int)(strangematk*0.33);
                    }
                    } else if(strangechoice==1){
                        if(inventory[3]==1){
                    printf("YOU DEFENDED YOURSELF WITH THE AMAZING ARMOR!!!! STRANGE'S ATTACK IS HALVED \n");
                    int strangedamage = strangedamage/2;
                    //matk2 = damage;

                    }
                    else if(inventory[3]==0){
                    printf("YOU DEFENDED YOURSELF WITH THE CRAPPY ARMOR!!!! STRANGE'S ATTACK IS SLIGHTLY LOWER!!!!! \n");
                    int strangedamage = strangedamage/2;
                    //matk2 = damage;

                    }
                    }
             //If weapon equals Jack-in-the-Box, then it deals less damage.
            //If weapon equals BullHorn, then it deals more damage
                    break;

            }
                strangechoice = 1 + (rand() % 3);//Switch Statement based on the boss's choice
                switch(strangechoice){
                case 1:
                printf("Dr. Strange attacks you with her sharp claws!!!! \n");
                strangedamage = 80 + (rand() % 41);
                break;
                case 2:
                printf("Dr. Strange casts her most powerful and ultimate spell, Apocalypse on you!!!!");
                strangedamage = 80 + (rand() % 151);
                break;
                case 3: //The boss will reflect the attack back at the player
                if(userchoice==2)
                {
                    printf("DR STRANGES MAGICAL ARMOR REFLECTS BACK AGAINST YOU!!!!! \n");
                    int matk2= matk/2;
                    //strangehp = strangehp-matk2;
                }
                else if(userchoice==1){
                    printf("DR STRANGE IS DEFENDING HERSELF!!!!!!!!! \n");

                    int atk2 = atk/2;

                    //strangehp = strangehp-atk2;
                //hp = hp-strangedamage;
                //strangehp = strangehp-matk2;
                }
                }
                break;
        }
                 if(strangechoice==3 && userchoice==2){
                    strangehp = strangehp-matk2;
                } else if(strangechoice==3 && userchoice==1){
                    strangehp= strangehp-atk2;
                }
                strangehp = strangehp-damage;// Again, I was testing it but the values will be set once the items are in place
                printf("You damaged Dr. Strange!!!!! HOW DARE YOU!!!! YOU WILL BE TREATED WITH GRAVE REPERKUSSIONS!!!!!! \n");

            if(strangehp < 1) {//If the player wins!
                printf("YOU KILLED DR. STRANGE!!!!!!!! YAY!!!!!! CONGRATULATIONS!!!!! NOW YOU ARE THE");
                printf("NEW SORCERESS/SORCERER OF COMPUTER SCIENCE!!!!!!!!! GO OUT THERE AND CONQUER THE WORLD!!!!!! \n");
                return 0;
            }
        printf("DR. STRANGE IS STILL ALIVE!!!!!!! SHE HAS ");//If the player has successively damaged Dr. Strange, this happens
        printf("%c", &strangehp);
        printf(" LEFT!!!! KILL HER!!!!!!");
        printf("RELEASE THE KRAKEN FROM DEEP WITHIN YOUR SOUL AND SHOW YOUR TRUE POTENTIAL!!!!! \n");
        if(strangechoice==3 && userchoice==2){
                    hp = hp-matk2;
                } else{
        hp = hp-strangedamage;
                }
        printf("DR. STRANGE DAMAGED YOU AND STOLE SOME OF YOUR LIFEFORCE!!!!!!! \n");//This is what happens when the boss hurts you
        printf("SHE STOLE ");
        printf("%c", &strangedamage);
        printf(" FROM YOU! YOU STILL HAVE ");
        printf("%c", &hp);
        printf(" HP LEFT TO KILL HER AND ");
        printf("STOP HER TERRIBLE REIGN!!!!!!!!! \n");

        if(hp < 1) {//If you lose the battle
            printf("YOU ARE DEFINITELY THE WORST SORCERER'S APPRENTICE TO EVER WALK AMONGST THE EARTH!!!!! \n");
            printf("YOU'RE GOING TO LET DR. STRANGE RULE THE UNIVERSE?!?!?!?!?! THIS IS ALL OF YOUR FAULT!!!! \n");
            printf("YOU SHOULD FEL ASHAMED OF YOURSELF!!!!! YOU FAILED US ALL \n");
            printf("AS A RESULT DR. STRANGE LAUGHS AT YOU AND BANISHED YOU TO NO-TIME!!!!! \n");
            printf("'Dr.Strange: I BANISH YOU TO NO-TIME WITH MY TIME KOMPRESSION!!!!'' \n");
            printf("'Dr.Strange: SAY YOUR PRAYERS!!!!!!!' \n");
            do{//do-while loop if the player wants to try again
                printf("DO YOU WANT TO RISK YOUR LUCK AND TRY AGAIN?!?!?!?! \n");
                printf("FACE YOUR FEARS AND DEFEAT THE STRANGE TEACHER AND COME OUT ON TOP!!!! \n");
                printf("RELEASE YOUR KRAKEN!!!! AHHHHHHHHHHHH!!!!!!!! \n");
                printf("Press Y or N if you want to play again!!!!!! \n");

            }
             while(answer != 'Y' && answer != 'N');//It will keep asking them until they say Y or N
             return 0;
        }

    }while(answer == 'Y'); //If then answer Y which is Yes, then they start all over again
            printf("THANKS FOR PLAYING!!!!!!! HAVE A STRANGE DAY AND BE AS STRANGE AS YOU CAN BE!!!!!!!");
    }else if (t == 0){//This is what happens when Dr. Strange goes first

        do
        {
            int hp = 10000;
            int mp = 150;
            strangehp = 50000;
        printf("DR. STRANGE GOES FIRST BECUASE SHE IS TOTALLY ASWEOME, INTELLIGENT, AND A BADASS OF COMPUTER SCIENCE AND SORCERY!!!! \n");
        strangechoice = 1 + (rand() % 3);
                switch(strangechoice){//Switch statement for the boss
                case 1:
                printf("Dr. Strange attacks you with her sharp claws!!!! \n");
                strangedamage = 80 + (rand() % 41);
                break;
                case 2:
                printf("Dr. Strange casts her most powerful and ultimate spell, Apokalypse on you!!!!");
                strangedamage = 80 + (rand() % 151);
                break;
                case 3:
                 if(userchoice==2)
                {
                    printf("DR STRANGES MAGICAL ARMOR REFLECTS BACK AGAINST YOU!!!!! \n");
                    int matk2= matk/2;
                    //strangehp = strangehp-matk2;
                }
                else if(userchoice==1){
                    printf("DR STRANGE IS DEFENDING HERSELF!!!!!!!!! \n");

                    int atk2 = atk/2;

                    //strangehp = strangehp-atk2;
                //hp = hp-strangedamage;
                //strangehp = strangehp-matk2;
                }
                }
                break;
                if(strangechoice==3 && userchoice==2){
                    strangehp = strangehp-matk2;
                } else if(strangechoice==3 && userchoice==1){
                    strangehp= strangehp-atk2;
                }
                strangehp = strangehp-damage;//Damaged the boss
                printf("You damaged Dr. Strange!!!!! HOW DARE YOU!!!! YOU WILL BE TREATED WITH GRAVE REPERKUSSIONS!!!!!! \n");

            if(strangehp < 1) {//What happens when you killed the boss
                printf("YOU KILLED DR. STRANGE!!!!!!!! YAY!!!!!! CONGRATULATIONS!!!!! NOW YOU ARE THE");
                printf("NEW SORCERESS/SORCERER OF COMPUTER SCIENCE!!!!!!!!! GO OUT THERE AND CONQUER THE WORLD!!!!!! \n");
                return 0;
            }//How much hp the boss has left
        printf("DR. STRANGE IS STILL ALIVE!!!!!!! SHE HAS ");
        printf("%c", &strangehp);
        printf(" LEFT!!!! KILL HER!!!!!!");
        printf("RELEASE THE KRAKEN FROM DEEP WITHIN YOUR SOUL AND SHOW YOUR TRUE POTENTIAL!!!!! \n");
        if(strangechoice==3 && userchoice==2){
                    hp = hp-matk2;
                } else{
        hp = hp-strangedamage;
                }
        printf("DR. STRANGE DAMAGED YOU AND STOLE SOME OF YOUR LIFEFORCE!!!!!!! \n");
        printf("SHE STOLE ");
        printf("%c", &strangedamage);
        printf("FROM YOU! YOU STILL HAVE ");
        printf("%c", &hp);
        printf("HP LEFT TO KILL HER AND ");
        printf("STOP HER TERRIBLE REIGN!!!!!!!!! \n");

        if(hp < 1) {//What happens when you lose
            printf("YOU ARE DEFINITELY THE WORST SORCERER'S APPRENTICE TO EVER WALK AMONGST THE EARTH!!!!! \n");
            printf("YOU'RE GOING TO LET DR. STRANGE RULE THE UNIVERSE?!?!?!?!?! THIS IS ALL OF YOUR FAULT!!!! \n");
            printf("YOU SHOULD FEL ASHAMED OF YOURSELF!!!!! YOU FAILED US ALL \n");
            printf("AS A RESULT DR. STRANGE LAUGHS AT YOU AND BANISHED YOU TO NO-TIME!!!!! \n");
            printf("'Dr.Strange: I BANISH YOU TO NO-TIME WITH MY TIME KOMPRESSION!!!!'' \n");
            printf("'Dr.Strange: SAY YOUR PRAYERS!!!!!!!' \n");
            do{//do-while loop which asks for user-input
                printf("DO YOU WANT TO RISK YOUR LUCK AND TRY AGAIN?!?!?!?! \n");
                printf("FACE YOUR FEARS AND DEFEAT THE STRANGE TEACHER AND COME OUT ON TOP!!!! \n");
                printf("RELEASE YOUR KRAKEN!!!! AHHHHHHHHHHHH!!!!!!!! \n");
                printf("Press Y or N if you want to play again!!!!!! \n");

            } while(answer != 'Y' && answer != 'N');//keeps asking them if they enter the wrong input
            return 0;

        }
            }while(answer == 'Y'); //If the answer is Y, then they will start all over again

    printf("THANKS FOR PLAYING!!!!!!! HAVE A STRANGE DAY AND BE AS STRANGE AS YOU CAN BE!!!!!!! \n");
    printf("YOU ARE A SUPERHERO!! GOOD JOB!!!!!! I WISH YOU LUCK WITH YOUR FUTURE!!!!!! \n");
    printf("HUGS AND KISSES, BABY!!!!! SMOOCH!!!! LOVE YOU!!!!!!! \n");
        return 0;
    }
}
*/

struct Room
{
	bool success;
	bool visited;
};

//Our five rooms are listed and declared here.
struct Room Entrance;
struct Room Bathroom;
struct Room Kitchen;
struct Room Dungeon;
struct Room Bedroom;

int anticlimaticBattle(int inventory[4])
{
	int total= 0;
	printf("Finally time to defeat the mad Dr. Strange!\nShe sealed off the awesome boss fight!\nDamn, now it's going to be anticlimatic!\n");
	for(int x=0; x<4; x++)
	{
		total = total + inventory[x];
	}
	if(total == 4)
	{
		printf("With your items, you've completely managed to stop Dr. Strange for good!\nCongrats!\n");
	}
	if(total <=3 && total >= 1)
	{
		printf("With your items, you've barely managed to beat Dr. Strange, but oh no, you've been taken over by her dark will!\nCongrats!\n");
	}
	if(total == 0)
	{
	printf("Your items couldn't stand up to one of Dr. Strange's spells and you are blown to oblivion!\nCongrats!\n");
	}
	return 0;
}

//GameTime is meant to initialize our values for use in the main function.
void gameTime()
{
    //As this is used to start up the game, all of the rooms are listed as false.
	Entrance.success = false;
	Entrance.visited = false;

	Bathroom.success = false;
	Bathroom.visited = false;

	Kitchen.success = false;
	Kitchen.visited = false;

	Dungeon.success = false;
	Dungeon.visited = false;

	Bedroom.success = false;
	Bedroom.visited = false;
}

int main()
{
    //The gameOver boolean starts as false and ONLY changes when the game has ended, either in victory or death.
	bool gameOver = false;
	//X is used for our entrance game against the Knight as it allows us to track the valued entered after they
	//are asked to try again.
	int x = 0;

    //In each room, there is a chance to receive one of two items, so with 4 rooms, we are able to create
    //an inventory array of length 4. A value of 0 corresponds to an ineffective item that will hurt the player's chance of winning.
    //If the player won, the item is set to 1, indicating that a beneficial item is in that slot.
	int inventory[4];
	//GameTime and GameStart kick off the game by setting all values to the default and sending our player on their journey.
	gameTime();
	gameStart();

	while (!gameOver) //The game continues so long as this boolean is not set to true.
    {
        //To compile, add -std = c99 after gcc, but before naming what needs to be compiled.
        //Tic-tac-toe Entrance game
        Entrance.success = toe(); //The game method will return a boolean. True if victorious and False if defeated
        if (Entrance.success == false) //If defeated at the entrance way, the game ends.
        {
            x = badEnd();
            if (x == 1) //The player may try again by entering 1, which will run the main method again.
            {
                main();
            }
            else //Otherwise, any other entry will break the loop, ending the game.
            {
                break;
            }
        }

        //If the Knight is defeated, the player enters the house and can choose one of the four rooms we created.
        int roomSelect = 0;
        Entrance.visited = true; //Because the entrance counts as a "room," we can change this to true,
        //NOTE: The entrance doesn't reward an item upon victory or defeat, so the success variable is unchanged.
        printf("After defeating the knight, you enter a large hall with four doors.\n");
        printf("Each door has a number over it for some reason...\n");

        //While in the house, so long as at least 1 room hasn't been visited, the player can move about the hub.
        while (!Kitchen.visited || !Bathroom.visited || !Dungeon.visited || !Bedroom.visited)
        {
            printf("Which door do you wish to enter?\n");
            printf("1 - Bathroom\n");
            printf("2 - Kitchen\n");
            printf("3 - Dungeon\n");
            printf("4 - Bedroom\n");
            scanf("%d", &roomSelect);

            //Depending on the room selected, the player will face his/her trial within.
            //However, if the room has already been visited, then the player is sent back into the hub.
            switch (roomSelect)
            {
                case 1:
                    if (Bathroom.visited)
                    {
                        printf("I've already been here, the door is locked.");
                    }
                    else
                    {
                        printf("I entered a bathroom with a large mirror.\n");
                        Bathroom.visited = true;
                        Bathroom.success = slide();
                    }
                    break;
                case 2:
                    if (Kitchen.visited)
                    {
                        printf("I've already been here, the door is locked.");
                    }
                    else
                    {
                        Kitchen.visited = true;
                        Kitchen.success = kitchenGame();
                    }
                    break;
                case 3:
                    if (Dungeon.visited)
                    {
                        printf("I've already been here, the door is locked.");
                    }
                    else
                    {
                        Dungeon.visited = true;
                        Dungeon.success = dungeonGame();
                    }
                    break;
                case 4:
                    if (Bedroom.visited)
                    {
                        printf("I've already been here, the door is locked.");
                    }
                    else
                    {
                        Bedroom.visited = true;
                        Bedroom.success = quiz();
                    }
		break;
                default:
                    printf("I feel a little foolish as that number isn't over any of the doors.");
                    break;
            }
		
        }
	
        //As the climax of the game approaches, the items are allocated.
        //As I stated earlier, a 1 indicates a good item, whereas 0 indicates a bad one.
        if (Bathroom.success)
        {
            inventory[0] = 1;
        }
        if (Kitchen.success)
        {
            inventory[1] = 1;
        }
        if (Dungeon.success)
        {
            inventory[2] = 1;
        }
        if (Bedroom.success)
        {
            inventory[3] = 1;
        }
	int whoc = anticlimaticBattle(inventory);
        gameOver= true;
    }
}
