/* Programed by Maayan Chechik
   26/1/2020
   This program receives file names in the command line.
   Each file includes a line of numbers ranging from 0 to 28.
   The program prints for each number, in what files it was 
   writen and how many times.
 */

#define _GNU_SOURCE
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 28
#define ERROR_CODE_OK 0
#define ERROR_CODE_FILE_DOESNOT_OPEN 1
#define ERROR_CODE_NO_FILES_GIVEN 2

int process_file(char* file_name, Node** hash_table);
void add_file_to_num(int num, Node** hash_table, char* file_name);
void print_table(Node** hash_table);

/* This function receives the file name and the array hash_table.  It
   reads the given file, assuming that it only contains a single line
   of numbers. For each number in the file, it calls add_file_to_num
   to update hash_table. The function returns wheather it was able to
   open the file, and if not it prints an error message.*/
int process_file(char* file_name, Node** hash_table){
  char* str_num;
  int num;
  char* non_digit;
  char *line_buf = NULL;
  size_t line_buf_size = 0;
  FILE* fp = fopen(file_name, "r");
  if (fp == NULL){
    printf("Error: the file [%s] cannot be opened for reading.\n", file_name);
    return ERROR_CODE_FILE_DOESNOT_OPEN;
  }
  /* The file is expected to contain a single line. */
  getline(&line_buf, &line_buf_size, fp);
  while ((str_num = strtok_r(line_buf, " \t\n", &line_buf))){
    num = strtol(str_num, &non_digit, 10);
    add_file_to_num(num, hash_table, file_name);
  }
  fclose(fp);
  return ERROR_CODE_OK;
}

/* This function receives a number, the array hash_table and a file
   name.  If the number has appeared in a given file already, the
   function increases the counter for that file. Otherwise, it inserts
   a new node with the given file name. */
void add_file_to_num(int num, Node** hash_table, char* file_name){
  /* If the array in the index num is NULL, then the number doesn't
     have a head to it's linked list yet, so we cannot compare file
     names.*/
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

/* This function recieves the array hash_table. For each number that
   appears in file, the function prints a summary containing the files
   in which it appeared and the number of times it appeared in each
   file.  The function uses the print_list function from the
   linked_list.c functions*/
void print_table(Node** hash_table){
  int i;
  for(i = 0; i<RANGE+1; i++){
    if(hash_table[i] != NULL){
      printf("%d appears in ",i);
      print_list(hash_table[i]);
    }
  }
}

/* Main receives a list of files in argv. If no files are given, it
   prints an error message and exits. Otherwise, it processes each
   file. The program exists with the following error codes: 
   0 - Program completed as expected.
   1 - No files were provided in the arugment list.
   2 - A given file cannot be opened.
*/
int main(int argc, char *argv[]){
  Node* hash_table[RANGE+1];
  int i;
  if(argc == 1){
    printf("Error: no arguments provided.\n");
    return ERROR_CODE_NO_FILES_GIVEN;
  }
  for(i=0;i<RANGE+1;i++){
    hash_table[i] = NULL;
  }
  for (i=argc-1; i>0; i--) {
    if(process_file(argv[i],hash_table)==ERROR_CODE_FILE_DOESNOT_OPEN)
      return ERROR_CODE_FILE_DOESNOT_OPEN;
  }
  print_table(hash_table);
  return ERROR_CODE_OK;
}


