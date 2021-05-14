#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


int carac_to_int(char carac)
{
    int res;
    if(carac == ' ' || carac == '\n')
        res = 0;
    else
        res = (int)carac - 48;

    return res;
}

int main()
{

  FILE *fp;
  char result[50];
  char Pchaine[4];
  int Percentage;
  while(1)
  {
      fp = popen("acpi -b", "r");
      if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
      }

      /* Read the output a line */
      fgets(result, sizeof(result), fp);
      /* close */
      pclose(fp);

      if(result[11] == 'D')
      {
          memcpy(Pchaine, &result[23], 3);
          Pchaine[3] = '\0';
          Percentage = carac_to_int(Pchaine[0])*pow(10, 2) + carac_to_int(Pchaine[1])*pow(10, 1) + carac_to_int(Pchaine[2]);

          if(Percentage <= 20)
              system("notify-send -t 5000 -u critical \"ATTENTION BATTERIE FAIBLE !\"");
      }

      sleep(60);
   }

   return 0;
}
