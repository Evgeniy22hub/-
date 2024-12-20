#include<stdio.h>

void modificate(int *ram, int *latency){
  *ram = *ram - 1;
  *latency = *latency + 1;
}


void main(){
   int ram = 32;
   int latency = -64;

  modificate(&ram, &latency);
  printf("%i %i\n", ram, latency);
}