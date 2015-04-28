#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>


//Put this code into your main method where you feel it should be.
int badEnd()
{
    int decision;

    printf("You've failed and darkness now rules the Earth\n");
    printf("Great job.\nNo.\nReally.\nJust fantastic work there buddy.\n");
    printf("So, ready to try again?\nHit 1 to try again, anything else to quit out.\n");
    scanf("%d", &decision);

    return decision;
}
