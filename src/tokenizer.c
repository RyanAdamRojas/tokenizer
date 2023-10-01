#include <stdio.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return (c == '\t' || c == ' ');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return !space_char(c);
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
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
char *token_terminator(char *token)
{
 start:
  if(*token != '\0'){
    token++;
    goto start;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
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
char *copy_str(char *inStr, short len)
{
  char newString[len * sizeof(char)];
  char *p_newStringBeginning = NULL;
  char *p_newString = NULL;
  p_newString = newString;
 start:
  p_newString = inStr;
  p_newString++;
  inStr++;
  if(*inStr == '\0')
    goto end;
 end:
  return p_newStringBeginning;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
   tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  return NULL; // DELETEME
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{

}
