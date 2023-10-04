#include "history.h"
#include <stdlib.h>
#include <stdio.h>

/* Initialize the linked list to keep the history. */
List* init_history() {
  List *newList;
  return newList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store */
void add_history(List *list, char *str) {
  if (list->root != NULL){  // Base case
    Item *i = list->root;   // New pointer for traversing list
    while (i->next != NULL) // Traversing list with pointer
      i = i->next;          // Increment pointer
    i->id = *str;           // Assign value to node
  }
}

/* Retrieve the string stored in the node where
   Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
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

/*Print the entire contents of the list. */
void print_history(List *list) {
  if (list->root != NULL){
    Item *i = list->root;
    while (i->next != NULL){
      printf("%d = %s", i->id, i->str);
      i = i->next;
    }
  }
}

/*Free the history list and the strings it references. */
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
