#include <stdio.h>
#include "tokenizer.h"

int areEqual(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0'){
        if (*str1 != *str2)
            return 0; // Not equal
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0'); // Equal if both strings ended
}

int main(void) {
  int looping = 1;
  char userInput[100];
  printf("Hello, friend. Welcome to TOKENIZER\n");

  while (looping == 1) {
      printf("Enter a string (type 'STOP' to exit): ");
      fgets(userInput, sizeof(userInput), stdin);
      if (areEqual(userInput, "STOP\n") == 1) {
	printf("Goodbye, friend\n");
        break; // Exit the loop
      }
      printf("You entered: %s\n", userInput);
    }
    return 0;
}

