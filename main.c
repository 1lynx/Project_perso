#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "conio.h"


void ft_putchar(char c)
{
    write(1, &c, 1);
}

typedef struct s_list
{
  int x;
  int y;
}              coord;

void analysis(int grille[4][4], coord *stru)
{
  int x = 0;
  int y = 0;
  while (x <= 4)
  {
    y = 0;
    while(y <= 4)
    {
      if (grille[x][y] == 1)
      {
        stru->x = x + 1;
        stru->y = y + 1;
      }
      y++;
    }
    x++;
  }

}
void modify_tab(int grille[10][10], int x, int y)
{
  grille[x][y] = 1;
}


void make_tab(int grille[10][10])
{
  int y = 0;
  int x = 0;
  while(x < 10)
  {
    y = 0;
    while(y < 10)
    {
      printf("%d", grille[x][y]);
      printf(" ");
      y++;
    }
    printf("\n");
    x++;
  }
  printf("\n");
}

void mover(char c, int grille[10][10], int *x, int *y)
{

  if (c == 'i')
  {
    modify_tab(grille, (*x - 1), *y);
    grille[*x][*y] = 0;
    *x = *x - 1;
  }
  if (c == 'k')
  {
    modify_tab(grille, (*x + 1), *y);
    grille[*x][*y] = 0;
    *x = *x + 1;
  }
  if (c == 'j')
  {
    modify_tab(grille, *x, (*y - 1));
    grille[*x][*y] = 0;
    *y = *y - 1;
  }
  if (c == 'l')
  {
    modify_tab(grille, *x, (*y + 1));
    grille[*x][*y] = 0;
    *y = *y + 1;
  }
}

int main(int ac, char **str)
{
  struct s_list *stru;
  char move;
  int x;
  int y;
  x = 0;
  y = 0;
  int grille[10][10] =
{
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},

};
    //make_tab(grille);
    while (grille[9][9] == 0)
    {
      make_tab(grille);
      move = getch();
      mover(move, grille, &x, &y);
      system("clear");
    }



    // system("clear");
    // modify_tab(grille, 0, 2);
    // make_tab(grille);













  // make_tab(grille);
  // printf("\n");
  // modify_tab(grille, 0, 2);
  // analysis(grille, x);
  // printf("%d\n", x->x);
  // printf("%d\n", x->y);
  // make_tab(grille);

  return(0);
}
