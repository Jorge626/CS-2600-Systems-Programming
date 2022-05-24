/* 
Jorge Aranda
CS 2600
Homework 1: Nim
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Declaring 3 count variables to keep track of 3 different games
    // Program then asks to pick a number for each pile 10 - 100
    int count1, count2, count3;
    printf("Pick a number between 10 and 100 for pile 1: ");
    scanf("%d", &count1);

    // Checks if value is between 10 and 100, process is repeated for 3 piles
    if (count1 < 10 || count1 > 100) {
        while (count1 < 10 || count1 > 100) {
        printf("Error: Please enter a value between 10 and 100: ");
        scanf("%d", &count1);
        }
    }
    printf("Pick a number between 10 and 100 for pile 2: ");
    scanf("%d", &count2);
    if (count2 < 10 || count2 > 100) {
        while (count2 < 10 || count2 > 100) {
        printf("Error: Please enter a value between 10 and 100: ");
        scanf("%d", &count2);
        }
    }
    printf("Pick a number between 10 and 100 for pile 3: ");
    scanf("%d", &count3);
    if (count3 < 10 || count3 > 100) {
        while (count3 < 10 || count3 > 100) {
        printf("Error: Please enter a value between 10 and 100: ");
        scanf("%d", &count3);
        }
    }

    // Boolean decleration to help with determining when games are finished as well as who won each game
    bool isDone = false;
    bool playerWin1 = false, playerWin2 = false, playerWin3 = false;

    // Seed for random number generator used for program turn
    srand(time(NULL));

    // While loop that runs until all 3 games have finished
    while (!isDone) {
        // Integer declerations to keep track of which pile is being played, 
        // the largest value that can be played, and the number of marbles taken in a turn
        int pile;
        int largestValue;
        int marbles;
        printf("\nEnter which pile you would like to play: ");
        scanf("%d", &pile);

        // Switch statement helps with determining which pile is being played
        switch(pile) {
            case 1: 
                printf("The total number of marbles in pile 1 are: %d\n", count1);
                // If statements to determine wether the game has already ended
                if (count1 == 0) {
                    printf("Error: No more marbles in game 1!\n");
                    if (playerWin1)
                        printf("Player won game 1!\n");
                    else 
                        printf("Program won game 1!\n");
                    break;
                }
                // If there is only one marble left, the player must automatically take the last marble and loses
                else if (count1 == 1) {
                    printf("Only one marble left!\nPlayer must take the last marble\n");
                    count1 = 0;
                    printf("Player lost game 1!\n");
                    break;
                }
                // If there is still more than 1 marble the game continues as normal
                else {
                    largestValue = count1 / 2; 
                    printf("Enter a value between 1 and %d: ", largestValue);
                    scanf("%d", &marbles);
                    // Checks if the number of marbles chosen to be taken out is between 1 and half the total marbles
                    if (marbles < 1 || marbles > largestValue){
                        while (marbles < 1 || marbles > largestValue) {
                            printf("Error: Please enter a value between 1 and %d: ", largestValue);
                            scanf("%d", &marbles);
                        }
                    }
                    printf("You chose %d\n", marbles);
                    count1 = count1 - marbles;
                    printf("There are %d marbles left in pile 1\n", count1);
                }
                // Checks to see if there is only one marble after the players turn
                if (count1 == 1) {
                    // If there is only one marble, the program must take it and loses the game
                    printf("Only one marble left!\nProgram takes the last marble\n");
                    printf("Congratulations, you won!\n");
                    count1 = 0;
                    playerWin1 = true;
                    break;
                }
                // If previous if statement fails, there is more than one marble and the game can continue
                else {
                    largestValue = count1 / 2;
                    printf("Program is choosing a value between 1 and %d...\n", largestValue);
                    // Program chooses a random number between 1 and half the total marbles
                    marbles = rand() % largestValue + 1;
                    printf("Program chose: %d\n", marbles);
                    count1 = count1 - marbles;
                    printf("There are %d marbles left in pile 1\n", count1);
                }
                break;
                // This process is repeated for the other 2 games (A function would have made this a lot cleaner ...)
            case 2:
                printf("The total number of marbles in pile 2 are: %d\n", count2);
                if (count2 == 0) {
                    printf("Error: No more marbles in game 2!\n");
                    if (playerWin2)
                        printf("Player won game 2!\n");
                    else 
                        printf("Program won game 2!\n");
                    break;
                }
                else if (count2 == 1) {
                    printf("Only one marble left!\nPlayer must take the last marble\n");
                    count2 = 0;
                    printf("Player lost game 2!\n");
                    break;
                }
                else {
                    largestValue = count2 / 2; 
                    printf("Enter a value between 1 and %d: ", largestValue);
                    scanf("%d", &marbles);
                    if (marbles < 1 || marbles > largestValue){
                        while (marbles < 1 || marbles > largestValue) {
                            printf("Error: Please enter a value between 1 and %d: ", largestValue);
                            scanf("%d", &marbles);
                        }
                    }
                    printf("You chose %d\n", marbles);
                    count2 = count2 - marbles;
                    printf("There are %d marbles left in pile 2\n", count2);
                }
                if (count2 == 1) {
                    printf("Only one marble left!\nProgram takes the last marble\n");
                    printf("Congratulations, you won!\n");
                    count2 = 0;
                    playerWin2 = true;
                    break;
                }
                else {
                    largestValue = count2 / 2;
                    printf("Program is choosing a value between 1 and %d...\n", largestValue);
                    marbles = rand() % largestValue + 1;
                    printf("Program chose: %d\n", marbles);
                    count2 = count2 - marbles;
                    printf("There are %d marbles left in pile 2\n", count2);
                }
                break;
            case 3:
                printf("The total number of marbles in pile 3 are: %d\n", count3);
                if (count3 == 0) {
                    printf("Error: No more marbles in game 3!\n");
                    if (playerWin3)
                        printf("Player won game 3!\n");
                    else 
                        printf("Program won game 3!\n");
                    break;
                }
                else if (count3 == 1) {
                    printf("Only one marble left!\nPlayer must take the last marble\n");
                    count3 = 0;
                    printf("Player lost game 3!\n");
                    break;
                }
                else {
                    largestValue = count3 / 2; 
                    printf("Enter a value between 1 and %d: ", largestValue);
                    scanf("%d", &marbles);
                    if (marbles < 1 || marbles > largestValue){
                        while (marbles < 1 || marbles > largestValue) {
                            printf("Error: Please enter a value between 1 and %d: ", largestValue);
                            scanf("%d", &marbles);
                        }
                    }
                    printf("You chose %d\n", marbles);
                    count3 = count3 - marbles;
                    printf("There are %d marbles left in pile 3\n", count3);
                }
                if (count3 == 1) {
                    printf("Only one marble left!\nProgram takes the last marble\n");
                    printf("Congratulations, you won!\n");
                    count3 = 0;
                    playerWin3 = true;
                    break;
                }
                else {
                    largestValue = count3 / 2;
                    printf("Program is choosing a value between 1 and %d...\n", largestValue);
                    marbles = rand() % largestValue + 1;
                    printf("Program chose: %d\n", marbles);
                    count3 = count3 - marbles;
                    printf("There are %d marbles left in pile 3\n", count3);
                }
                break;
            default:
                // Default statement gives an error if the player chooses a pile that does not exist
                printf ("Error: Please enter a pile number 1 - 3\n");
                break;
        }
        // After the switch statement and right before the while loop finishes, it checks to see if all games have finished
        if (count1 == 0 && count2 == 0 && count3 == 0)
            isDone = true;
    }
    // Once all gaves have finished, it gives the results of each game
    printf("\nAll games have finished!\n");
    if (playerWin1)
        printf("Player won game 1!\n");
    else 
        printf("Program won game 1!\n");
    if (playerWin2)
        printf("Player won game 2!\n");
    else 
        printf("Program won game 2!\n");
    if (playerWin3)
        printf("Player won game 3!\n");
    else 
        printf("Program won game 3!\n");
    return 0;
}