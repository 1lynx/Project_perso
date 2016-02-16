#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "conio.h"
#include <time.h>
#define X_SIZE 10
#define Y_SIZE 20
#define X_PLC 9


int alea_num(void)
{
  int nu = 0;
  srand( time(NULL));
  nu = rand();
  return(nu);

}

void modify_tab(char grille[X_SIZE][Y_SIZE], int y)
{
  grille[X_PLC][y] = '=';
  grille[X_PLC][y + 1] = '=';
}

void mover(char grille[X_SIZE][Y_SIZE], char c, int *y)
{
  if (c == 'l' && *y != 18)
  {
    grille[X_PLC][*y] = '.';
    grille[X_PLC][*y + 1] = '.';
    modify_tab(grille, (*y + 1));
    *y = *y + 1;
  }
  if (c == 'k' && *y != 0)
  {
    grille[X_PLC][*y] = '.';
    grille[X_PLC][*y + 1] = '.';
    modify_tab(grille, (*y - 1));
    *y = *y - 1;
  }
}


void make_tab(char grille[X_SIZE][Y_SIZE])
{
  int y = 0;
  int x = 0;
  while(x < X_SIZE)
  {
    y = 0;
    while(y < Y_SIZE)
    {
      printf("%c", grille[x][y]);
      printf(" ");
      y++;
    }
    printf("\n");
    x++;
  }
  printf("\n");
}

void map_maker(char grille[X_SIZE][Y_SIZE])
{
  int i = 0;
  int j = 0;
  while(i < X_SIZE)
  {
    j = 0;
    while(j < Y_SIZE)
    {
      grille[i][j] = '.';
      j++;
    }
    i++;
  }
}

int main(int argc, char const *argv[])
{
  char grille[X_SIZE][Y_SIZE];
  char move;
  int i = 0;
  int y = 10;
  map_maker(grille);

  while (i < 50)
  {
    i++;
    make_tab(grille);
    printf("%d\n", (50 - i));
    move = getch();
    mover(grille, move, &y);
    system("clear");
  }

  make_tab(grille);

  return 0;
}
