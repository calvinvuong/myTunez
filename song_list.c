#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_list.h"

song_node * insert_front(song_node *list, song_node new) {
  song_node *to_insert = (song_node *) malloc(sizeof(song_node));;
  strcpy(to_insert->name, new.name);
  strcpy(to_insert->artist, new.artist);
  to_insert->next = list;

  return to_insert;
}

song_node * insert_alphabet(song_node *list, song_node new);

song_node * free_list(song_node *list) {
  while ( list != NULL ) {
    song_node * tmp_ptr = list->next;
    free(list);
    list = tmp_ptr;
  }

  return NULL;
}

void print_list( song_node *list ) {
  printf("[");
  while ( list != NULL ) { // while there is still a next element
    printf( "%s - %s", list->artist, list->name );
    list = list->next;
  }
  printf("]\n");
  
}

int main() {
  song_node t1;
  song_node t2;
  song_node t3;
  song_node t4;
  
  char a[256] = "Hips Don't Lie";
  t1.name = a;
  //  t1.artist = "Shakira";

  char b[256] = "Everlong";
  t2.name = b;
  //  t2.artist = "Foo Fighters";

  char c[256] = "Highway to Hell";
  t3.name = c;
  //  t3.artist = "AC/DC";

  char d[256] = "Island in the Sun";
  t4.name = d;
  //  t4.artist = "Weezer";

  t1=insert_front(t1, t2);
  
  t1=insert_front(t1, t3);
  
  t1=insert_front(t1, t4);

  print_list(t1);
  t1 = free_list(t1);
  print_list(t1);

  return 0;
}

