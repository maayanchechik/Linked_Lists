/* This file includes functions of linked lists, used by hash.c*/
#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This function creates a new node with the received counter and file
   name, and returns a pointer to the new node.*/
Node* create_node(int counter, char * file_name){
  Node* ptr = (Node*) malloc(sizeof(Node));
  int length;
  if(ptr == NULL){
    printf("malloc has failed, for file name %s",file_name);
    return NULL;
  }
  ptr -> counter = counter;
  length = strlen(file_name);
  ptr -> file_name = (char*) malloc(length);
  strcpy(ptr->file_name, file_name);
  ptr -> next = NULL;
  return ptr;
}

/* This function inserts a new node, with the received counter and file
   name, before the received Node.*/
void insert(Node** ptr, int counter, char* file_name){
  Node* new_node = create_node(counter, file_name);
  if((*ptr) == NULL){
    (*ptr) = new_node;
    return;
  }
  new_node -> next = (*ptr);
  (*ptr) = new_node;
}

void increase_counter(Node* node_ptr){
  node_ptr->counter++;
}

int equal_file_name(Node* node_ptr, char* name){
  return !strcmp(node_ptr->file_name, name);
}

/* This function prints a summary of each Node in the linked list,
   starting with the recieved Node. The summary describes the file
   name and counter of each Node.*/
void print_list(Node* node_ptr){
  int i = 0;
  Node* current = node_ptr;
  Node* next = node_ptr->next;
  while(current != NULL){
    if(i>0){
      printf(", ");
    }
    if(current->counter == 1){
      printf("file %s - 1 time",current->file_name);
    }else{
      printf("file %s - %d times",current->file_name,current->counter);
    }
    current = next;
    if(current != NULL)
      next = current -> next;
    i++;
  }
  printf("\n");
}
