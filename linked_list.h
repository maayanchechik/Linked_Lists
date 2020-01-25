#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct Nodes {
  struct Nodes* next;
  int counter;
  char* file_name;
}Node;

Node* create_node(int counter, char * file_name);

void insert(Node** ptr, int counter, char* file_name);

void increase_counter(Node* node_ptr);

void print_list(Node* node_ptr);

int equal_file_name(Node* node_ptr, char* name);

#endif
