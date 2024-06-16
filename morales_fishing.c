//Antonio Morales
//N01551618
//March 1st, 2024
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int GoFish(int); //function prototype

int main()
{
    //Seeding RNG
    srand(time(NULL));
    //Initializing and Declaring variables
    int sessionTime = 720, balance = 0, baitChoice, caughtFish;
    printf("Welcome to the fishing Simulator!\n");
    //MAIN GAME LOOP (GAMESTATE)
    while(sessionTime > 0)
    {
        printf("What type of bait will you use?\n1 = Worms\n2 = Jig\n3 = Chum\n-1 = Leave Early\n");
        scanf("%d", &baitChoice);
        if(baitChoice == -1)
            break;
        switch(baitChoice)
        {
        case 1:
            caughtFish = GoFish(baitChoice);
            break;
        case 2:
            caughtFish = GoFish(baitChoice);
            break;
        case 3:
            caughtFish = GoFish(baitChoice);
            break;
        default:
            printf("Invalid Selection!\n");
            break;
        }
        if(caughtFish == 3)
        {
            sessionTime -= 60;
            balance += 1000;
            printf("Caught a Shark!\n");
        } else if(caughtFish == 2)
        {
            sessionTime -= 20;
            balance += 250;
            printf("Caught a Red Snapper!\n");
        } else if(caughtFish == 1)
        {
            sessionTime -= 10;
            balance += 100;
            printf("Caught a Flounder!\n");
        } else
        {
            sessionTime -= 5;
            printf("Caught nothing...\n");
        }
        printf("Remaining time: %d\nCurrent Wallet Size: %d\n", sessionTime, balance);
    }
    printf("Thank you for fishing.\nFinal wallet size: %d\n", balance);
    return 0;
}

int GoFish(int baitChoice)
{
    //Generate a random number from 1 - 100 (Inclusive)
    int rndVal = (rand() % 100) + 1;
    //returnFish table: (3 is shark), (2 is Red Snapper), (1 is Flounder), (0 is nothing)
    int returnFish;
    switch(baitChoice)
    {
    case 1:
        if(rndVal == 1) // 1% for Shark
            returnFish = 3;
        else if(rndVal >= 2 && rndVal <=15) // 14% for Snapper
            returnFish = 2;
        else if(rndVal >= 16 && rndVal <= 40) // 25% for Flounder
            returnFish = 1;
        else // 60% for Nothing
            returnFish = 0;
        break;
    case 2:
        if(rndVal <= 5) // 5% for Shark
            returnFish = 3;
        else if(rndVal >= 6 && rndVal <= 25) // 20% for Snapper
            returnFish = 2;
        else if(rndVal >= 26 && rndVal <= 30) // 5% for Flounder
            returnFish = 1;
        else // 70% for Nothing
            returnFish = 0;
        break;
    case 3:
        if(rndVal <= 15) // 15% for Shark
        {
            returnFish = 3;
        } else if(rndVal >= 16 && rndVal <= 20) //5% for Flounder OR Red Snapper
        {
            int halfRnd = rand() % 2; // Generate a 50% probability for either fish (2.5% TOTAL probability)
            if(halfRnd == 0)
                returnFish = 2;
            else // 80% for Nothing
                returnFish = 1;
        } else
        {
            returnFish = 0;
        }
        break;
    }
    return returnFish;
}
