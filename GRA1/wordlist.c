/*worldlist.c*/
#include <stdio.h>
#include <string.h>
int main()
{
char worldlist[32][10];
char buf[32];
int index, size, x;
FILE *fd;
index = 0;
fd = fopen ("wordlist.txt", "r");
if (!fd)
{
        fprintf(stderr, "No such file\n");
        return -1;
}
while (fgets(buf, 31, fd))
{
        size = strlen(buf) - 1;
        buf[size] = 0;
        strncpy(worldlist[index], buf, 31);
        index++;
}
fclose(fd);
for (x=0; x<index; x++)
        printf("%s\n", worldlist[x]);
return 0;
}
