// contains type definitions and function headers for a single linked list of songs

typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

// inserts new song node specifed by name + artist into the front of the linked list list points to 
song_node * insert_front(song_node *list, char name[], char artist[]);

// inserts new song node in order (alphabetically)
song_node * insert_alphabet(song_node *list, char name[], char artist[]);

// prints entire list of song nodes
void print_list(song_node *list);

// returns pointer to the song node that matches parameter string
song_node * find_node_name(song_node *list, char *name);

// returns pointer to first song of an artist that matches paramter string
song_node * find_node_artist(song_node *list, char *artist_name);

// returns a ponter to random song node in list
song_node * random_node(song_node *list);

// removes specified node from the list; returns pointer to first node in list
song_node * remove_node(song_node *list, char name[], char artist[]);

// frees entire list; returns pointer to beginning of list
song_node * free_list(song_node *list);
