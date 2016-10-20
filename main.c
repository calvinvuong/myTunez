#include <stdio.h>
#include <stdlib.h>

#include "song_list.h"
#include "song_table.h"


int main() {
  printf("Testing Linked List Functions: \n------------------------------------\n");
  printf("Inserting Songs Alphabetically (also tests insert_front())\n");
  printf("inserting: AC/DC - Highway to Hell\n");
  song_node *list = insert_alphabet(NULL, "Highway to Hell", "AC/DC");
  print_list(list);
  printf("inserting: Foo Fighters - Everlongl\n");
  printf("list: "); list = insert_alphabet(list, "Everlong", "Foo Fighters");
  print_list(list);
  printf("inserting: Shakira - Hips Don't Lie\n");
  printf("list: ");  list = insert_alphabet(list, "Hips Don't Lie", "Shakira");
  print_list(list);
  printf("inserting: Two Door Cinema Club - Something Good Can Work\n");
  printf("list: ");  list = insert_alphabet(list, "Something Good Can Work", "Two Door Cinema Club");
  print_list(list);
  printf("inserting: Green Day - American Idiot\n");
  printf("list: ");  list = insert_alphabet(list, "American Idiot", "Green Day");
  print_list(list);
  printf("inserting: Foo Fighters - Learn to Fly\n");
  printf("list: ");  list = insert_alphabet(list, "Learn to Fly", "Foo Fighters");
  print_list(list);

  
  printf("\n");
  printf("finding: Highway to Hell\n%s - %s\n", find_node_name(list, "Highway to Hell")->artist, find_node_name(list, "Highway to Hell")->name);
  printf("finding first song by: Foo Fighters:\n%s - %s\n\n", find_node_artist(list, "Foo Fighters")->artist, find_node_artist(list, "Foo Fighters")->name);

  song_node *random = random_song(list);
  printf("random song: \n%s - %s\n\n", random->artist, random->name);

  printf("removing: Hips Don't Lie\n");
  list = remove_node(list, "Hips Don't Lie");
  print_list(list);

  printf("removing: American Idiot\n");
  list = remove_node(list, "American Idiot");
  print_list(list);

  printf("removing: Something Good Can Work...\n");
  list = remove_node(list, "Something Good Can Work");
  print_list(list);
  
  printf("removing: Hello (nonexistent)\n");
  list = remove_node(list, "Hello");
  print_list(list);
  
  printf("\nremoving whole list:\n");
  list = free_list(list);
  print_list(list);

  /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
  printf("Testing Song Library Functions:\n");
  
  song_node *table[26];
  // must initialize values to zero
  int i;
  for ( i = 0; i < 26; i++ )
    table[i] = 0;

  printf("Adding songs: \n");
  printf("adding: American Idiot\n");
  add_song(table, "American Idiot", "Green Day");
  print_library(table);

  printf("\nadding: All Star\n");
  add_song(table, "All Star", "Smash Mouth");
  print_library(table);

  printf("\nadding: Beverley Hills\n");
  add_song(table, "Beverley Hills", "Weezer");
  print_library(table);

  printf("\nadding: Island in the Sun\n");
  add_song(table, "Island in the Sun", "Weezer");
  print_library(table);

  printf("\nadding: When We Were Young\n");
  add_song(table, "When We Were Young", "Adele");
  print_library(table);

  printf("\nadding: Hello");
  add_song(table, "Hello", "Adele");
  print_library(table);

  
  song_node *a = find_song(table, "American Idiot"); 
  printf("finding: American Idiot: \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "All Star");
  printf("finding: All Star: \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "Hello");
  printf("finding: Hello: \n %s - %s\n", a->artist, a->name);
  a = find_song(table, "Californication");
  printf("finding: Californication: \n %s\n\n", a);

  printf("Printing entire library: \n");
  print_library(table);

  printf("\n\nfinding: all by Weezer: \n");
  print_artist(table, "Weezer");
  printf("\nfinding: all by Adele: \n");
  print_artist(table, "Adele");
  printf("\nfinding: all by Green Day: \n");
  print_artist(table, "Green Day");
  printf("\nfinding: all by Lionel Richie: \n");
  print_artist(table, "Lionel Richie");

  printf("\nShuffling: \n");
  shuffle_library(table);
  printf("\n");

  printf("\nTesting delete and print_letter():\n");
  printf("printing: a and h songs:\n");
  print_letter(table, 'a');
  print_letter(table, 'h');

  printf("\ndeleting: All Star and printing: a and h songs:\n");
  delete_song(table, "All Star");
  print_letter(table, 'a');
  print_letter(table, 'h');

  printf("\nPrinting entire library and a and h songs after deleting it:\n");
  delete_library(table);
  print_letter(table, 'a');
  print_letter(table, 'b');


  return 0;
}
