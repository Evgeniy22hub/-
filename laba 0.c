#include<stdio.h>

int y = 1;

int main(void){
  int x = 4;

  printf("Адрес переменной y: %i \n", &y);
  printf("Адрес переменной x: %i \n", &x);

  return 0;
}