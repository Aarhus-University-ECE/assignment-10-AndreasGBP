#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "btree.h"

// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
  /*
  node *ns = make_node(
        1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));
  node *new = map(ns, square);
  print_list(ns);
  printf("\n");
  print_list(new);
  printf("%d", sum_squares(ns));
  */
    struct tree_node *root = NULL;

  root = Initialize(root);
  root = Insert(20, root);
  root = Insert(5, root);
  root = Insert(1, root);
  root = Insert(15, root);
  root = Insert(9, root);
  root = Insert(7, root);
  root = Insert(12, root);
  root = Insert(30, root);
  root = Insert(25, root);
  root = Insert(40, root);
  root = Insert(45, root);
  root = Insert(42, root);

  root = Insert(3, root);

  root = Remove(3, root);
  root = Insert(-1, root);
  root = Insert(-1, root);
  root = Remove(-1, root);
  root = Remove(-1, root);
  root = Remove(45, root);
  root = Remove(42, root);
  root = Insert(16, root);
  root = Remove(7, root);

  root = Remove(1, root);
  root = Remove(7, root);
  root = Remove(12, root);
  root = Remove(9, root);
  root = Remove(15, root);
  root = Remove(5, root);
  root = Remove(42, root);
  root = Remove(45, root);
  root = Remove(25, root);
  root = Remove(40, root);
  root = Remove(30, root);
  root = Remove(20, root);
  root = Remove(16, root);
}