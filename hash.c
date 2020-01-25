#define _GNU_SOURCE

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 28
#define STOP 0

int process_file(char* file_name, Node** hash_table);
void add_file_to_num(int num, Node** hash_table, char* file_name);
void print_table(Node** hash_table);

int process_file(char* file_name, Node** hash_table){
  char* str_num;
  int num;
  char* non_digit;
  char *line_buf = NULL;
  size_t line_buf_size = 0;
  FILE* fp = fopen(file_name, "r");
  if (fp == NULL){
    printf("Error: the file %s can not open\n", file_name);
    return STOP;
  }
  getline(&line_buf, &line_buf_size, fp);
  while((str_num = strtok_r(line_buf, " \t", &line_buf))){
    num = strtol(str_num, &non_digit, 10);
    add_file_to_num(num, hash_table, file_name);
  }
  fclose(fp);
  return 1;
}

void add_file_to_num(int num, Node** hash_table, char* file_name){
  if (hash_table[num] == NULL){
    insert(&(hash_table[num]), 1, file_name);
    return;
  }
  if(equal_file_name(hash_table[num], file_name)){
    increase_counter(hash_table[num]);
  }else{
    insert(&(hash_table[num]), 1, file_name);
  }
}

void print_table(Node** hash_table){
  int i;
  for(i = 0; i<RANGE+1; i++){
    if(hash_table[i] != NULL){
      printf("%d appears in ",i);
      print_list(hash_table[i]);
    }
  }
}

int main(int argc, char *argv[]){
  Node* hash_table[RANGE+1];
  int i;
  if(argc == 1){
    printf("Error: no arguments provided.\n");
    return 0;
  }
  for(i=0;i<RANGE+1;i++){
    hash_table[i] = NULL;
  }
  for (i=argc-1; i>0; i--) {
    printf("argument %d is [%s]\n", i, argv[i]);
    if(process_file(argv[i],hash_table)==STOP)
      return 1;
  }
  print_table(hash_table);
  return 1;
}


