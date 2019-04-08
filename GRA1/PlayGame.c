#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main()
{
  int index, size, v, i, l, score, length;
  srand(time(0));
  v = rand() % 10;
  char word[10][32]; //[row] [character]
  char buf[32];
  char W[32];
  FILE *fd;
  index = 0;

  fd = fopen("word.txt", "r");

  if (!fd) //If  word file doesn't exist
    {
      fprintf(stderr, "No such file\n");
      return -1;
    }//End of if

  while (fgets(buf, 31, fd))
    {
      size = strlen(buf) -1;
      buf[size] = 0;
      strncpy(word[index], buf, 31); //make array of word.txt
      index ++;
    }

  fclose(fd);
  printf("%d\n", index);

    printf("%s\n", word[v]);
  wo = word[v];
  lenght = strlen(wo)

void compare()
  {  //compare guess input with letters in word
    int right = 0; //Start with no right answers
    for (i=0; i<length; i++);  //For loop goes trough every letter in random word
      {
        if (strcmp(guess , word[i]) == 0)
          {
            right++; //Adds to right if guess is correct once
          }//End of if

       if (right > 0) //As long as there is one letter correct
         {
           printf("Correct");
         } //End of if

       else  //No letters correct
         {
           printf("Wrong guess");
         } //End of else

      }
    break;
  }//End of void compare()

   return 0;
  }
