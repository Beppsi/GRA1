#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main()
{
  int index, size, v, i, l, score;
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
  }

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
  W = word[v];

 for (i=0;i<W.length; i++)
        {
         printf("enter letter\n:");
        scanf("%c", l);
         if (strcmp(l, W[i]) == 0))
         {
           printf("correct\n");
           score ++;
         }
         else if (strcmp(l, W[i]) !== 0))
         {
           printf("Wrong\n");
         }

      }

 return 0;
}
