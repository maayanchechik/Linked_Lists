#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Node* create_node(int counter, char * file_name){
  Node* ptr = (Node*) malloc(sizeof(Node));
  if(ptr == NULL){
    printf("malloc has failed, for file name %s",file_name);
    return NULL;
  }
  ptr -> counter = counter;
  int length = strlen(file_name);
  ptr -> file_name = (char*) malloc(length);
  strcpy(ptr->file_name, file_name);
  ptr -> next = NULL;
  return ptr;
}

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
/*int main(int argc, char *argv[]){
  int i;
  for (i=0; i<argc; i++) {
    printf("argument %d is [%s]\n", i, argv[i]);
  }
  char file1[] = "first_file";
  char file2[] = "second_file";
  char file3[] = "third_file";

  Node* head = create_node(1,file1);
  print_List(head);
  
  insert((&head),1,file2);
  print_List(head);
  
  insert((&head),2,file3);
  print_List(head);

  increase_counter(head);
  print_List(head);
  
  return 1;
*/

