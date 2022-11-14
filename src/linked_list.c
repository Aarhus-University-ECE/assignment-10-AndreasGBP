#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* Functions to create the lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* Free all the nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* Print the list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  if(p == NULL) //Base case
    return;
  printf("%d ", p -> value); //Prints element
  print_list(p -> next); //Recursive step
  // There is NO testcode for this
}

int sum = 0;

int sum_squares(node *p) {
  // Add your code for excercise 2 
  if(p == NULL) //base case
    return 0;
  return p->value * p->value + sum_squares(p -> next); //Recursive step
  // You can find the tests in tests.cpp
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 
  if(p == NULL) //Base case
    return 0;
  return make_node(f(p->value), map(p->next,f)); 
  //Recursive step: It creates a new linked list using the make_node function, and maps the values of "p" with the function "f"

}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }