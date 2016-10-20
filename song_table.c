#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "song_list.h"
#include "song_table.h"

void add_song(song_node *table[], char name[], char artist[]) {
  int row = tolower(name[0]) % 'a';
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
  //  printf("---------------------------\n");
  printf("%c\n", letter);
  printf("---------------------------\n");
  print_list(table[row]);
}

void print_artist(song_node *table[], char artist[]) {
  int i;
  for ( i = 0; i < 26; i++ ) {
    song_node *ptr = table[i];
    
    while ( ptr != NULL ) {
      ptr = find_node_artist(ptr, artist);
      if ( ptr == NULL )
	break;
      printf("%s - %s, ", ptr->artist, ptr->name);
      ptr = ptr->next;
    }
  }
}

void shuffle_library(song_node *table[]) {
  srand(time(NULL));
  // loop through whole table
  int num_songs = 0;
  int i;
  for ( i = 0; i < 26; i++ ) {
    song_node *tmp1 = table[i];
    while(tmp1){
      num_songs++;
      tmp1 = tmp1->next;
    }
  }

  // copy pointers into songs
  song_node *songs[num_songs];
  int ctr = 0;
  for ( i = 0; i < 26; i++ ) {
    song_node *tmp2 = table[i];
    while(tmp2){
      songs[ctr]=tmp2;
      ctr++;
      tmp2=tmp2->next;
    }
  }
  
  // shuffle pointers
  for ( i = 0; i < num_songs; i++ ) {
    int rand_pos = rand() % num_songs;
    song_node *tmp = songs[i];
    // swap
    songs[i] = songs[rand_pos];
    songs[rand_pos] = tmp;
  }
  
  
  // print out stuff
  for ( i = 0; i < num_songs; i++ ) 
    printf( "%s - %s\n", songs[i]->artist, songs[i]->name);
  
}


void print_library(song_node *table[]) {
  int i;
  for ( i = 0; i < 26; i++ ) {
    if ( table[i] != NULL ) 
      print_letter(table, i+'a');
  }
}

// delete song; returns node of song deleted
void delete_song(song_node *table[], char name[]){
  int ctr=25;
  while(ctr >= 0){
    if(find_node_name(table[ctr], name)){
      table[ctr]=remove_node(table[ctr], name);
    }
    ctr--;
  }
}

// delete all the song nodes
void delete_library(song_node *table[]){
  int ctr=25;
  while(ctr >= 0){
    table[ctr-1]=free_list(table[ctr-1]);
    ctr--;
  }
}

/*
int main() {
  song_node *table[26];
  // must initialize values to zero
  int i;
  for ( i = 0; i < 26; i++ )
    table[i] = 0;
   
  add_song(table, "American Idiot", "Green Day");
  add_song(table, "All Star", "Smash Mouth");
  add_song(table, "Beverley Hills", "Weezer");
  add_song(table, "Island in the Sun", "Weezer");
  add_song(table, "When We Were Young", "Adele");
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
  printf("Finding 'Californication': \n %s\n\n", a);

  printf("Printing entire library: \n");
  print_library(table);

  printf("\nFinding all songs by Weezer: \n");
  print_artist(table, "Weezer");
  printf("\nFinding all songs by Adele: \n");
  print_artist(table, "Adele");
  printf("\nFinding all songs by Green Day: \n");
  print_artist(table, "Green Day");
  printf("\nFinding all songs by Lionel Richie: \n");
  print_artist(table, "Lionel Richie");
 
  printf("\nTesting delete:\n");
  printf("Printing a and h songs:\n");
  print_letter(table, 'a');
  print_letter(table, 'h');

  printf("\nDeleting Hello and printing a and h songs:\n");
  delete_song(table, "Hello");
  print_letter(table, 'a');
  print_letter(table, 'h');

  printf("\nPrinting entire library and a and h songs after deleting it:\n");
  delete_library(table);
  print_letter(table, 'a');
  print_letter(table, 'f');
  return 0;
}
*/
