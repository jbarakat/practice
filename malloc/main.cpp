/* malloc example: random string generator 
 * This program generates a string of the length specified by the user and fills it with alphabetic characters. The possible length of this string is only limited by the amount of memory available to malloc 
 * For reference, go to http://www.cplusplus.com/reference/cstdlib/malloc/ 
 */
#include <stdio.h>	// printf, scanf, NULL
#include <stdlib.h>	// malloc, free, rand

int main(){
  int i,n;
  char * buffer;

  printf ("How long do you want the string? ");
  scanf ("%d", &i);

  buffer = (char*) malloc (i+1); // allocate memory block
  if (buffer==NULL) exit (1);

  for (n=0; n<i; n++)
    buffer[n]=rand()%26+'a';
  buffer[i]='\0';

  printf ("Random string: %s\n",buffer);
  free (buffer); // deallocate memory block

  return 0;
}
