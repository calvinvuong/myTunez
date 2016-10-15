#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_list.h"

song_node * insert_front(song_node *list, char name[], char artist[]) {
  song_node *new = (song_node *) malloc(sizeof(song_node));;
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = list;

  return new;
}

//song_node * insert_alphabet(song_node *list, song_node new);

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


void print_list( song_node *list ) {
  while ( list != NULL ) { // while there is still a next element
    printf( "%s - %s, ", list->artist, list->name );
    list = list->next;
  }
  printf("\n");
  
  }

int main() {
  song_node *list = insert_alphabet(NULL, "Highway to Hell", "AC/DC");
  list = insert_alphabet(list, "Everlong", "Foo Fighters");
  list = insert_alphabet(list, "Hips Don't Lie", "Shakira");
  list = insert_alphabet(list, "Something Good Can Work", "Two Door Cinema Club");
  list = insert_alphabet(list, "American Idiot", "Green Day");
  
  print_list(list);
  printf("Finding Everlong: %s\n", find_node_name(list, "Everlong")->name);
  printf("Finding first song by foo fighters: %s\n", find_node_artist(list, "Foo Fighters")->name);
  list = free_list(list);
  print_list(list);
  return 0;
}

