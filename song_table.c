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
  add_song(table, "Hello", "Adele"); // why does this throw seg fault?
  
  
  //print_list(table[0]);
  for ( i = 0; i < 26; i++ ) 
    print_list(table[i]);
  
  return 0;
}
