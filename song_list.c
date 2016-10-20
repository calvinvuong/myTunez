/*
Giovanni Topa and Calvin Vuong
MKS65 pd10
Project0: myTunez
10-20-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "song_list.h"

song_node * insert_front(song_node *list, char name[], char artist[]) {
  song_node *new = (song_node *) malloc(sizeof(song_node));;
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = list;

  return new;
}

song_node * free_list(song_node *list) {
  while ( list != NULL ) {
    song_node * tmp_ptr = list->next;
    free(list);
    list = tmp_ptr;
  }
  return NULL;
}

song_node * find_node_name(song_node *list, char name[]){
  while ( list != NULL ) {
    if(!strcmp(list->name, name)){
      return list;
    }
    list=list->next;
  }
  return NULL;
}

song_node * find_node_artist(song_node *list, char artist[]){
  while ( list != NULL ) {
    if(!strcmp(list->artist, artist)){
      return list;
    }
    list=list->next;
  }
  return NULL;
}

song_node * insert_alphabet(song_node *list, char name[], char artist[]){
  // if list goes in front
  if ( list == NULL || strcmp(list->name, name) > 0 )
    return insert_front(list, name, artist);

  song_node *front = list;
  song_node *new = (song_node *) malloc(sizeof(song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);

  while ( list->next != NULL ) { 
    if ( strcmp(list->next->name, name) > 0 ) {
      song_node *tmp_ptr = list->next;
      new->next = tmp_ptr;
      list->next = new;
      return front;
    }
    list = list->next;
  } 
  // if while loop exists, song goes at the end
  list->next = new;
  new->next = NULL;
  
  return front;
}

song_node * random_song(song_node *list) {
  // count num of songs
  song_node *counter = list;
  int num = 0;
  while ( counter != NULL ) {
    counter = counter->next;
    num++;
  }
  // look into random number generator stuff
  srand(time(NULL));
  int r =  (rand())%num;
  while (r){
    list = list->next;
    r--;
  }
  return list;
}

song_node * remove_node(song_node *list, char name[]) {
  song_node *tmp_ptr = list;
  // if node to remove is first element
  if ( strcmp(tmp_ptr->name, name) == 0 ) {
    tmp_ptr = tmp_ptr->next;
    free(list);
    return tmp_ptr;
  }
  // if node to remove is not first element
  while ( tmp_ptr != NULL ) {
    if ( tmp_ptr->next != NULL && strcmp(tmp_ptr->next->name, name) == 0 ) { // found song to remove
      song_node *remove_node = tmp_ptr->next;
      tmp_ptr->next = tmp_ptr->next->next;
      free(remove_node);
      return list;
    }
    tmp_ptr = tmp_ptr->next;
  }
  return list; // runs if node to remove not found
}
    
void print_list( song_node *list ) {
  while ( list != NULL ) { // while there is still a next element
    printf( "%s - %s, ", list->artist, list->name );
    list = list->next;
  }
  printf("\n");
  
}

/*
int main() {
  song_node *list = insert_alphabet(NULL, "Highway to Hell", "AC/DC");
  list = insert_alphabet(list, "Everlong", "Foo Fighters");
  list = insert_alphabet(list, "Hips Don't Lie", "Shakira");
  list = insert_alphabet(list, "Something Good Can Work", "Two Door Cinema Club");
  list = insert_alphabet(list, "American Idiot", "Green Day");
  
  print_list(list);
  printf("Finding Everlong: %s\n", find_node_name(list, "Everlong")->name);
  printf("Finding first song by foo fighters: %s\n", find_node_artist(list, "Foo Fighters")->name);

  printf("Getting random song: %s\n", random_song(list)->name);

  printf("Removing 'Hips Don't Lie'...\n");
  list = remove_node(list, "Hips Don't Lie");
  print_list(list);

  printf("\nRemoving 'American Idiot'...\n");
  list = remove_node(list, "American Idiot");
  print_list(list);

  printf("\nRemoving 'Something Good Can Work'...\n");
  list = remove_node(list, "Something Good Can Work");
  print_list(list);
  
  printf("\nRemoving nonexistent song 'Hello'...\n");
  list = remove_node(list, "Hello");
  print_list(list);
  

  list = free_list(list);
  print_list(list);
  return 0;
}
*/

