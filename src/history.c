#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history() {
  List *newList;
  return newList;
}

void add_history(List *list, char *str) {
  if (list->root != NULL){  // Base case
    Item *i = list->root;   // New pointer for traversing list
    while (i->next != NULL) // Traversing list with pointer
      i = i->next;          // Increment pointer
    i->id = *str;           // Assign value to node
  }
}

char *get_history(List *list, int id) {
  if (list->root != NULL){    // Base case  
    Item *i = list->root;     // New pointer for traversing list
    while (i->next != NULL){  // Traversing list with pointer
      if (i->id == id)
	return i->str;        // Item found
      i = i->next;            // Increment pointer
    }
  }
  return 0; // Not found
}

void print_history(List *list) {
  if (list->root != NULL){
    Item *i = list->root;
    while (i->next != NULL){
      printf("%d = %s", i->id, i->str);
      i = i->next;
    }
  }
}

void free_history(List *list) {
  if (list->root != NULL) {
    Item *i = list->root;
    while (i->next != NULL) {
      Item *temp = i;  // Grabbing current nodes address
      i = i->next;     // Moving to next pointer
      free(temp->str); // Freeing previously grabbed node string
      free(temp);      // Freeing previoudly grabbed node
    }
  }
}
