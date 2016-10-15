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


void print_list( song_node *list ) {
  while ( list != NULL ) { // while there is still a next element
    printf( "%s - %s, ", list->artist, list->name );
    list = list->next;
  }
  printf("\n");
  
  }

int main() {
  song_node *list = insert_front(NULL, "Hips Don't Lie", "Shakira");
  
  list = insert_front(list, "Everlong", "Foo Fighters");
  
  list = insert_front(list, "Highway to Hell", "AC/DC");

  print_list(list);
  list = free_list(list);
  print_list(list);

  return 0;
}

