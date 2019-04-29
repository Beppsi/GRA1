#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL)); //Sets standard random


	 //This function imports words from .txt file
	  char words[32][10];
	  char buf[32];
	  int index, size, x;
	  FILE *fd;
	  index = 0;
	  fd = fopen("words.txt", "r"); //Reads file

	  if (!fd)
	  {
	    fprintf(stderr, "No word file available\n");
	    return -1;
	  }

	  while (fgets(buf, 31, fd))
	  {
	    size = strlen(buf) -1;
	    buf[size] = 0;
	    strncpy(words[index], buf, 31);
	    index ++;
	  }

	  fclose(fd);
// End of import




	int Index = rand() % 20; //In a list of 20 words, this randomly picks one of them by row (Index)

	int numLives = 5;  /*Should i add dynamic difficulity??*/
	int RightAft = 0;
	int RightBef = 0;

	int Wlength = strlen(words[Index]); //


	int letterGuessed[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //create an array which changes for every correct guess, note im assuming there arent any words longer than 20 in the game.

	int end = 0;

	int loopIndex = 0;
	int reguessed = 0;

	char guess[16];
	char CharIn; //Letter input

    // game loop
	while ( RightAft < Wlength ) //While there are less correct guesses than letters left
	{

		printf("\n\nNew Turn....\nHangman Word:");

		for( loopIndex = 0; loopIndex < Wlength; loopIndex++) //For loop prints a "_" for every letter not found
		{

			if(letterGuessed[loopIndex] == 1)
			{
				printf("%c",words[Index][loopIndex]); //Prints found letter in its position of the word
			} else {
				printf("_"); //Prints _ for unfound letter
			}

		}

		printf("\n");

		printf("Correct guesses:%d of %d \n",RightAft, WLength); //Lets player know how many guesses are correct
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);

		if( strncmp(guess, "end", 4) == 0) { //If the player ends the game
			end = 1;
			break;
		}

		CharIn = guess[0];
		reguessed = 0;

		printf("You guessed:%c\n",CharIn);

		RightBef = RightAft;

		for( loopIndex = 0; loopIndex < Wlength; loopIndex++) {

			if(letterGuessed[loopIndex] == 1) {
				if(words[Index][loopIndex] == CharIn) {
					reguessed = 1;
					break;
				}
				continue;
			}

			if( CharIn == words[Index][loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				RightAft++;
			}

		}

		if( RightBef == RightAft && reguessed == 0) {
			numLives--;
			printf("Sorry, wrong guess\n");
			switch (numLives)
			{
				case 0:
				printf("\n ________\n|        | \n|        ( )\n|        /|\\ \n|         | \n|        / \\\n"); //5/5
				break;
				case 1:
				printf("\n ________\n|        | \n|        ( )\n|        /|\\ \n|          \n|        \n"); //4/5
				break;
				case 2:
				printf("\n ________\n|        | \n|        ( )\n|         |\n|          \n|        \n"); //3/5
				break;
				case 3:
				printf("\n ________\n|        | \n|        ( )\n|         \n|          \n|        \n"); //2/5
				break;
				case 4:
				printf("\n ________\n|        | \n|        \n|        \n|          \n        \n"); //1/5
				break;
			}
			if (numLives == 0)
      {
				break;
			}
		} else if( reguessed == 1)
    {
			printf("Already Guessed!!\n");
		} else {
			printf("Correct guess :)\n");
		}

	} // End of while loop

	if( end == 1 )
  {
		printf("\nthe user end early\n");
	}
  else if (numLives == 0)
  {
		printf("\nSorry you lose, the word was: %s\n",
		words[Index]);
	}
  else
  {
		printf("\nYOU WIN!!! :)\n");
	}


	return 0;
}
