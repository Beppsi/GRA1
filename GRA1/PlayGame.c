
#include <stdio.h>
#include <string.h>

int main()
{
  char word[10][32]; // 2D array, 32 tecken på 10 rader
  char buf[32];
  int index, size, x;
  FILE *fd; //File descriptor
  index = 0;
  fd = fopen("word.txt", "r");

  if (!fd) //Går det att öppna filen?
  {
    fprintf(stderr, "no such file\n");
    return -1;
  }

  while (fgets(buf, 31, fd)) //fgets, läser filer, loopar så länge det finns text i filen.
  {
    size = strlen(buf) -1;
    buf[size] = 0;
    strncpy(word[index], buf, 31); //Fyller array med innehåll från .txt
    index ++;
  }

  fclose(fd);

  for (i=0); i<index; i++)
  {
    printf("%s\n", word[i]);
    return 0;
  }
}
