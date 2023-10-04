#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  return (c == '\t' || c == ' ');
}

int non_space_char(char c){
  return !space_char(c);
}

char *token_start(char *str){
 start:
  if(*str == ' '){
    str++;
    goto start; // Iterates
  }
  
  if(*str == '\0')
    return NULL; // EOF

  return str;
}

char *token_terminator(char *token){
 start:
  if(*token != '\0'){
    token++;
    goto start;
  }
  return token;
}

int count_tokens(char *str){
  int count = 0;
  
 start:
  if(*str == ' ')
    count++;
  else if(*str == '\0')
    goto end; // EOF
  else
    goto start;

 end:
  return ++count;  
}

char *copy_str(char *inStr, short len){
  // Declare output string with zero termination
  char *outString = (char*) malloc((len+1) * sizeof(char));
  char *p_outStringStart = outString;
  char *p_outString = outString;
  // Build output string by copying input string
 start:
  *p_outString = *inStr;
  p_outString++;
  inStr++;
  // End of loop, add zero termination
  if(*inStr == '\0'){
    *p_outString = '\0';
    goto end;
  }
 end:
  return p_outStringStart;
}

char **tokenize(char* str) {
  // Create array
  char **tokens = (char **)malloc((count_tokens(str) + 1) * sizeof(char *));
  
  // Populate an array of pointers by slicing str
  char *slicedStr = token_start(str);
  tokens[0] = str;
  for(int i = 1; i < count_tokens(str); i++){
    tokens[i] = token_start(slicedStr);
    slicedStr = token_start(slicedStr);
  }
  return tokens;
  }

void print_tokens(char **tokens) {
  int i = 0;
  while(tokens[i] != NULL) {
    printf("tokens[%d] = %s\n",i ,tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens){
    int i = 0;
    while(tokens[i] != NULL){
      free(tokens[i]);
      i++;
    }
    free(tokens);
}
