#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == '\t' || c == ' ');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return !space_char(c);
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
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

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
 start:
  if(*token != '\0'){
    token++;
    goto start;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
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

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
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

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
   tokens[0] = "hello"
   tokens[1] = "world"
   tokens[2] = "string" 
   tokens[3] = 0
*/
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

/* Prints all tokens. */
void print_tokens(char **tokens) {
  int i = 0;
  while(tokens[i] != NULL) {
    printf("tokens[%d] = %s\n",i ,tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    int i = 0;
    while(tokens[i] != NULL){
      free(tokens[i]);
      i++;
    }
    free(tokens);
}
