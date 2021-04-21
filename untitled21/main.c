#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)

{
  printf("Enter number of options: ");

  int k = atoi(argv[1]);
  scanf_s("%d", &k);

  printf("Enter phone number: ");

  int x= atoi(argv[2]);

  scanf_s("%d", &x);

  int N;

  if(strlen(argv[2]) == 7 ){
      N = x % (k+1);
      printf("%d\n",N);
  } else {
      printf("Enter a seven-digit number! ");
  }

  return 0;

}

