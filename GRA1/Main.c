// Grupparb. 1


int main()
{
// Funktioner:
      option()
      {
        printf("Welcome to Hangman, choose option:\n");
        printf("1.Play game\n2. Use custom word\n3. List words\n 4.Display toplist\n);
        scanf("%d", &opt);
      switch(opt)
       {
        case 1:
          PlayGame()
          break;
        case 2:
          CustomWord()
          break;
        case 3:
          List()
          break;
        case 4:
          TopList()
          break;
        }
      }
}
