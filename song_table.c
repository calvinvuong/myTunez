#include <stdlib.h>
#include <stdio.h>

#include "song_list.h"
#include "song_table.h"
#incldue "song_list.c"


song_node[] * add_song(song_node *table[], char name[], char artist[]) {
  int row = tolower(name[0]) % 'a';
  table[row] = insert_alphabet(table[row], name, artist);
  return table;
}






int main() {
  song_node *table[26];
  table = add_song(table, "Something Good Could Work", "Two Door Cinema Club");
  int i = 0;
  for ( i; i < 26; i++ ) {
    print_list(table[i]);

  }
  return 0;
}
