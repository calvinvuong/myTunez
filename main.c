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

  return 0;
}
