#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "song_list.h"
#include "song_table.h"

void add_song(song_node *table[], char name[], char artist[]) {
  int row = tolower(name[0]) % 'a';
  printf("%d\n", row);
  table[row] = insert_alphabet(table[row], name, artist);
  //  return table;
}

song_node * find_song(song_node *table[], char name[]) {
  int row = tolower(name[0]) % 'a';
  return find_node_name(table[row], name);
}

song_node * find_artist(song_node *table[], char artist[]) {
  // loop through each row of table
  int i;
  for ( i = 0; i < 26; i++ ) {
    return find_node_artist(table[i], artist);
  }
  return NULL;
}

void print_letter(song_node *table[], char letter) {
  int row = tolower(letter) % 'a';
  printf("---------------------------\n");
  printf("%c\n", letter);
  printf("---------------------------\n");
  print_list(table[row]);
}

void print_artist(song_node *table[], char artist[]) {

}

void print_library(song_node *table[]) {

}

// delete song; returns node of song deleted
void delete_song(song_node *table[], char name[]){
  remove_node(table[name[0]-'a'], name);
}

// delete all the song nodes
void delete_library(song_node *table[]){
  int ctr=25;
  while(ctr){
    free_list(table[ctr]);
    ctr--;
  }
}

int main() {
  song_node *table[26];
  // must initialize values to zero
  int i;
  for ( i = 0; i < 26; i++ )
    table[i] = 0;
   
  add_song(table, "American Idiot", "Green Day");
  add_song(table, "All Star", "Smash Mouth");
  add_song(table, "Beverley Hills", "Weezer");
  add_song(table, "F Song", "some artist");
  add_song(table, "Hello", "Adele");

  song_node *a = find_song(table, "American Idiot"); 
  printf("Finding 'American Idiot': \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "All Star");
  printf("Finding 'All Star': \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "F Song");
  printf("Finding 'F Song': \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "Hello");
  printf("Finding 'Hello': \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "Californication");
  printf("Finding 'Californication': \n %s", a);
  print_letter(table, 'a');
  print_letter(table, 'f');
  
  return 0;
}
