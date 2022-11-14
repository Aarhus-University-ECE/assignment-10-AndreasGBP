#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item "x" into the tree "t"
  tree_node *new_node = malloc(sizeof(tree_node));
  if(t == NULL) //Base case
  {
    t = new_node;
    t -> item = x;
    t -> left = NULL;
    t -> right = NULL;
  }
  else
  {
    if(x > t -> item) 
    {
      t->right = Insert(x, t -> right);
    }
    else
    {
      t->left = Insert(x, t -> left);
    }
  } //The two recursive steps for when "x" is going on the right side of tree, and when it is going on the left side
  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree "t"
  if(Contains(x,t) == 0)
  {
    return t;
  } //Checks if "x" is in the tree, returns "t" if not
  if(x == t -> item)
  {
    tree_node *temp = t;
    if(t -> right != NULL)
      temp = temp -> right; //Sets the pointer temp to right child, if it exists
    tree_node *temp2;
    if(t -> left == NULL && t -> right == NULL)
    {
      t = NULL;
      return t;
    } //If tree is empty besides root it sets root to NULL, back to initialized state
    while(temp -> left != NULL) 
      {
        temp2 = temp;
        temp = temp -> left; 
      } //Loops through the tree through left children, until end of sequence
      t -> item = temp -> item; //Sets root item to the lowest number, on the right side of the tree
      temp2 -> left = NULL;
      free(temp);
      return t;
  } //This case is for the when the root is the number to be removed
  
  tree_node *temp = t;
  int count = 0;
  tree_node *temp1;
  while(temp -> item != x)
  {
    temp1 = temp;
    if(x > (temp -> item))
    {
      temp = temp->right;
      count = 1;
    }
    else if((temp -> item) > x)
    {
      temp = temp->left;
      count = 0;
    }
  } //This loops through the tree, until temp -> item is equal to "x"
  

  if(temp -> left == NULL && temp -> right == NULL) //Special case if the number to be removed, is already a leaf
  {
    if(count == 1){
      temp1 -> right = NULL;
      free(temp);
    }
    else {
      temp1 -> left = NULL;
      free(temp);
    }
    return t;
  }

  tree_node *temp2 = temp;
  tree_node *temp3 = temp;
  if(x < t ->item){ //Case for when on the left side of root
    if(temp2 -> right != NULL)
    {
      temp2 = temp2 -> right;
      if(temp2 -> left == NULL) //Special case if temp -> Right is a leaf
      {
        temp -> item = temp2 -> item;
        temp3 -> right = NULL;
        free(temp2);
        return t;
      }
    } 
    while(temp2 -> left != NULL)
      {
        temp3 = temp2;
        temp2 = temp2 ->left;
      } //Loops through the tree via the left children
    temp3 -> left = NULL;
    temp -> item = temp2 -> item;
    free(temp2);
    return t;
  }
  else { //Case for when on the right side of tree
    if(temp2 -> left != NULL)
    {
      temp2 = temp2 -> left;
      if(temp2 -> left == NULL) //Special case if temp -> left is a leaf
      {
        temp -> item = temp2 -> item;
        temp3 -> left = NULL;
        free(temp2);
        return t;
      } 
    }
    while(temp2 -> right != NULL)
      {
        temp3 = temp2;
        temp2 = temp2 ->right;
      } //Loops through, via left children
    temp3 -> right = NULL;
    temp -> item = temp2 -> item;
    free(temp2);
    return t;
  }
}

int Contains(int x, struct tree_node *t) {

  // Return 1 if the tree "t" contains item "x". Return 0 otherwise.
  if(t == NULL) //Base case 0 if we hit leaf
    return 0;
  if(t -> item == x)//Base case 1 if x is found
    return 1;

  else if(x > t -> item) //Recursive step for x > item
    Contains(x, t -> right);
  else if(x < t -> item) //Recursive step for x < item
    Contains(x, t -> left);
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t = NULL;  
  return t;
}

int Empty(struct tree_node *t) {
  // Test if empty
  if(t == NULL)
    return 1;
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}