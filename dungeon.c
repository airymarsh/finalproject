#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



//declarations of methods
void clearScreen(void);
int winGame(void);
int HouseOfStrange(int nVariable, int nQuestion);
bool gamePlay(void);



//structure for my user
struct User{

    //this is the weapon name and attribute
    char weaponPower[50];
    char weaponType[50];

}newUser;

int answerQ(void){
     int answerV;
     scanf("%d", &answerV);
     getchar();

     return answerV;
    }

//this will execute the game
bool dungeonGame(void){

    return gamePlay();

}

//variable declaration
int nUser;

//this is the game code
bool gamePlay(void){
        srand(time(0));     //this is for the random operator
    int nChamber;
    char nReady[50];
    int numFalse;
    int numOfTurn;
    int nQuestionS;
    char weaponPower[50];
    char weaponType[50];
    char weaponP[50];
    char weaponT[50];
    struct User newUser;
    int nQuestion;

    int nVariable;

    nQuestion=1;
    numOfTurn=1;

    printf("Welcome to the Dungeon!!!");
    printf("Trivia of Death ...");

    printf("\nCan you survive my torture chamber?");
    printf("\n0=no; 1=yes\n");
    scanf("%d", &nChamber);
    getchar();

    //this is just fun for me...
    switch(nChamber)
    {
        case 0:
            printf("\nI promise this will be quick and painless... x_x");
            break;
        case 1:
            printf("\nHaha Your confidence will be your downfall... ^_^");
            break;
        default:
            printf("\nYou can not run from this torture chamber... \n");
            printf("Spineless decisions will not help you.");
    }

    printf("\nYou will be given a series of questions.\n");
    printf("\nIf you answer them all correctly and win your freedom, \nyou will be given the ultimate prize!!!\n");
    printf("\nAnswer some of them wrong and still win your freedom, \nyour weapon will be mediocre at best...\n");
    printf("\nAnswer some of them wrong and lose, I get your life. ");

    clearScreen();

    printf("\nAre you ready? (Yes or NO)\n");
    scanf("%s", &nReady);
    getchar();


    //I do care, don't listen to this guy..
    printf("\nFoolish mortal, I am not concerned with your well-being.. \n");


    //This is the loop that run the game method House of Strange
    do{

        //variables that will pick the category and the question, respectively.
        //nVariable = rand()%5+1;
        //nQuestionS= rand()%3+1;

        nVariable = rand()%5+1;
        nQuestionS= rand()%3+1;
        //execute game
        HouseOfStrange(nVariable, nQuestionS);

        //loop arguments
        nQuestion++;
        numOfTurn++;

    }while(nQuestion!=5);

    //this will give the user his result depending on how he did on his quest.
    if(nUser<3){
        printf("\nYour efforts have failed!");

        strcpy(newUser.weaponPower, "No weapon.. No Power");
        strcpy(newUser.weaponType, "You do not recieve a weapon from the dungeon");

        printf("%d", newUser.weaponPower);
        printf("%d", newUser.weaponType);
        return false;

    }else if(nUser==5){
        printf("\nYou are worthy to pass. May you be favored on your journey.");
        printf("\nHaha I hope your jack NdaBox helps hahahhaah!!!!");

        strcpy(newUser.weaponPower, "This weapon is level 1");
        strcpy(newUser.weaponType, "You have recieved a jack NdaBoX");

        printf("%d", newUser.weaponPower);
        printf("%d", newUser.weaponType);
        return true;
    }else{
        printf("\nYou have prevailed, Now go before I change my mind..");
        printf("\nTake your BullHORN and leave...");

        strcpy(newUser.weaponPower, "This weapon is level 2");
        strcpy(newUser.weaponType, "You have recieved a BullHORN");

        printf("%d", newUser.weaponPower);
        printf("%d", newUser.weaponType);
        return false;
    }

    return 0;
}

//this will clear tlear the screen
void clearScreen(void){
    int x;
    for( x = 0; x<4; x++){
        printf("\n");
    }
}

//this will automatically win game
int winGame(){
    return 5;
}

//game method
int HouseOfStrange( int nVariable, int nQuestion){
    int nAnswer;

    if(nVariable==1){
            printf("\nYour trivia section is SPORTS!");
            switch(nQuestion){
                case 1:
                    clearScreen();
                    printf("\nWho did Lebron lose to in the 2011 NBA Finals?\n");
                    printf("\n1) San Antonio\t\t2) Chicago Bulls\n");
                    printf("\n3) Oklahoma City Thunder\t\t4) Dallas Mavericks\n");
                    nAnswer = answerQ();


                    if(nAnswer<1||nAnswer>4){
                        printf("\nSince You do not like rules, INCORRECT!!!\n");
                        nUser+= 0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==3){
                        printf("\nYour attempt was futile!\n");
                        nUser+= 0;
                        return nUser;
                    }else{
                        printf("\nCelebrate your victory now, next time might not be so fortunate.\n");
                        nUser+= 1;
                        return nUser;
                    }
                    break;
                case 2:
                    clearScreen();
                    printf("\nWho was not apart of the \n2014 FIFA-Soccer US Men National Team?\n");
                    printf("\n1) Clint Dempsey\t\t2) London Donovan\n");
                    printf("\n3) Michael Bradley\t\t4) Jozy Altidore\n");
                    nAnswer = answerQ();

                    if(nAnswer<1||nAnswer>4){
                        printf("\nYour insolence is not amusing. INCORRECT!!!\n");
                        nUser += 0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==3||nAnswer==4){
                        printf("\nYou're not as clever as I hoped...\n");
                        nUser += 0;
                        return nUser;
                    }else{
                        printf("\nThe Gods have favored you upon this day.\n");
                        nUser += 1;
                        return nUser;
                    }
                    break;
                case 3:
                    clearScreen();
                    printf("\nWho was the QB of the Minnesota Vikings in 2014?\n");
                    printf("\n1) Tom Brady\t\t2) Jameis Winston\n");
                    printf("\n3) Johnny Manziel\t\t4) Teddy Bridgewater\n");
                    nAnswer = answerQ();

                    if(nAnswer<1||nAnswer>4){
                        printf("\nOh I hope you enjoy your demise!\n");
                        nUser += 0;
                        return nUser;
                    }else if(nAnswer==2||nAnswer==3||nAnswer==1){
                        printf("\nLife is not what you desire?\n");
                        nUser += 0;
                        return nUser;
                    }else{
                        printf("\nThat was easy.. I hope you know that.\n");
                        nUser += 1;
                        return nUser;
                    }
                    break;
            }
        }else if(nVariable==2){
            printf("\nYour Trivia section is ENTERTAINMENT!!");
		clearScreen();
            switch(nQuestion){
                case 1:
                    printf("Which movie is not a Kevin Hart movie?\n");
                    printf("\n1) Soul Plane\t\t2) Why Did I Get Married?\n");
                    printf("3) Wedding Ringer\t\t4) Get Hard\n");
                    nAnswer = answerQ();

                    if(nAnswer<1||nAnswer>4){
                        printf("\nHow does this answer accomplish anything?\n");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==3||nAnswer==4){
                        printf("\nYou're not as informed as I thought...\n");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nSociety has taught you well.\n");
                        nUser+=1;
                        return nUser;
                    }
                    break;
                case 2:
                    printf("Who became famous after their debut hit 'BABY'?\n");
                    printf("\n1) Robin Thicke\t\t2) One Direction\n");
                    printf("3) Justin Bieber\t\t4) Justin Timberlake\n");
                    nAnswer = answerQ();

                    if(nAnswer<1||nAnswer>4){
                        printf("\nYou are starting to bore me.\n");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==4){
                        printf("\nAre you not aware of the stars?\n");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nYou are a worthy opponent!\n");
                        nUser+=1;
                        return nUser;
                    }
                    break;
                case 3:
                    printf("What is the name of the dog in the Jetson cartoon?\n");
                    printf("\n1) Comet\t\t2) Galaxy\n");
                    printf("3) Star\t\t4) Astro\n");
                    nAnswer = answerQ();

                    if (nAnswer<1||nAnswer>4){
                        printf("\nThese childish antics must stop!!\n");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==3){
                        printf("\nI don't think you're smart enough for this...\n");
                        nUser +=0;
                        return nUser;
                    }else{
                        printf("\nYou have succeeded.. Finally!\n");
                        nUser+=1;
                        return nUser;
                    }
                    break;
            }
        }else if(nVariable==3){
            printf("\nYour trivia section is HISTORY!!!");
            switch(nQuestion){
                case 1:
                    clearScreen();
                    printf("Who was the 42nd President of the US?\n");
                    printf("\n1) Bill Clinton\t\t2) George W. Bush\n");
                    printf("3) John F. Kennedy\t\t4) Barack Obama\n");
                    nAnswer = answerQ();

                    if(nAnswer<1||nAnswer>4){
                        printf("\nYou are not very smart...\n");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==2||nAnswer==3||nAnswer==4){
                        printf("\nThat is not the correct answer.. smh!!!\n");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nThere's hope for you, I see.\n");
                        nUser+=1;
                        return nUser;
                    }
                    break;
                case 2:
                    clearScreen();
                    printf("What ended World War I?\n");
                    printf("\n1) Paris Peace Conference\t\t2) God\n");
                    printf("3) Treaty of Versailles\t\t4) NATO\n");
                    nAnswer = answerQ();

                    if(nAnswer<1||nAnswer>4){
                        printf("\nI do not see the point in your foolish antics.\n");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==4){
                        printf("\nIt looks like you are struggling... Too bad!\n");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nTake your life and run!!!\n");
                        nUser+=1;
                        return nUser;
                    }
                    break;
                case 3:
                    clearScreen();
                    printf("Who was the French Conqueror who almost took over the world?\n");
                    printf("\n1) Alexander The Great\t\t2) Hitler\n");
                    printf("3) Pope Francis\t\t4) Napoleon\n");
                    nAnswer = answerQ();


                    if(nAnswer<1||nAnswer>4){
                        printf("\nThis is not a game!");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==3){
                        printf("\nIt does not look too bright for your future...");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nYou are finally right.. Who cares!!");
                        nUser+=1;
                        return nUser;
                    }
                    break;
            }
        }else if(nVariable==4){
            printf("\nYour trivia section is COMPUTER ORGANIZATION AND ASSEMBLY LANGUAGE!!!!");
            switch(nQuestion){
                case 1:
                    clearScreen();
                    printf("Finish this quote: \n'The ________ a chip is, the more power it consumes.'");
                    printf("\n1) The bigger\t\t2) The wider\n");
                    printf("3) The faster\t\t4) The lighter\n");
                    nAnswer = answerQ();


                    if(nAnswer<1||nAnswer>4){
                        printf("\nWhy do you choose to be difficult?");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==4){
                        printf("\nSorry but you are still not good enough...");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nEven a blind squirrel can find a nut... proceed!");
                        nUser+=0;
                        return nUser;
                    }
                    break;
                case 2:
                    clearScreen();
                    printf("\nWhat are the set of instructions directly executed by a CPU called?");
                    printf("\n1) Assembly Language\t\t2) Python\n");
                    printf("3) High Level Language\t\t4) Machine Language");
                    nAnswer = answerQ();


                    if(nAnswer<1||nAnswer>4){
                        printf("\nI hope whatever you're trying to do, fails...");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==2||nAnswer==3){
                        printf("\nHow does it feel to constantly fail?");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nLook at that, you can get lucky!");
                        nUser+=1;
                        return nUser;
                    }
                    break;
                case 3:
                    clearScreen();
                    printf("\nWhat computing language did we study using MARS?");
                    printf("\n1) C++\t\t2) MIPS\n");
                    printf("3) Java\t\t4) AL");
                    nAnswer = answerQ();


                    if(nAnswer<1||nAnswer>4){
                        printf("\nWhy must we play this game?");
                        nUser+=0;
                        return nUser;
                    }else if(nAnswer==1||nAnswer==3||nAnswer==4){
                        printf("\nWrong once again... smh should have known");
                        nUser+=0;
                        return nUser;
                    }else{
                        printf("\nSuccess is feels good, does it not?");
                        nUser+=1;
                        return nUser;
                    }
                    break;
                }
        }else if(nVariable==5){
            printf("You have the chance to defeat me here and now.. Are you up for the challenge?");
            printf("\n1= No\t\t 2= Yes\n");
            nAnswer = answerQ();

            if(nAnswer<1||nAnswer>2){
                printf("\nIt must be hard living, knowing you have no SPINE!!!!");
                nUser+=0;
                return nUser;
            }else if(nAnswer==1){
                printf("\nIt must be hard living, knowing you have no SPINE!!!!");
                nUser+=0;
                return nUser;
            }else{
                printf("\nWhat is the name of the TA for Computer Organization and Assembly Language?");
                printf("\n1)John Wick\t\t2) Beyonce\n");
                printf("3) John Shrein\t\t4) Craig Davidson\n");
                nAnswer = answerQ();


                if(nAnswer<1||nAnswer>4){
                    printf("\nSince you want to play ...!!!");
                    nUser+=0;
                    return nUser;
                }else if(nAnswer==1||nAnswer==2||nAnswer==4){
                    printf("\nOh that is not the right answer, better luck next time!");
                    nUser+=0;
                    return nUser;
                }else{
                    printf("\nYou are correct, get your prize and leave.. ");

                    nQuestion=winGame();
                    return nUser;
                }
            }
        }
}
