/*
Giovanni Topa and Calvin Vuong
MKS65 pd10
Project0: myTunez
10-20-2016
*/
#include "song_list.h"

#ifndef SONG_TABLE_H
#define SONG_TABLE_H
// contains type definitions and function headers for a table of linked lists

// adds song; returns pointer of the song table
void add_song(song_node *table[], char name[], char artist[]);

// searches for song based on name, returns pointer to the node of the song
song_node * find_song(song_node *table[], char name[]);

// searches for an artist and returns all songs by artist
song_node * find_artist(song_node *table[], char artist[]);

// print out all entries under a certain letter
void print_letter(song_node *table[], char letter);

// print out all entries by a certain artist
void print_artist(song_node *table[], char artist[]);

// prints out all the songs
void print_library(song_node *table[]);

// prints out list of randomly ordered songs
void shuffle_library(song_node *table[]);

// delete song; returns node of song deleted
void delete_song(song_node *table[], char name[]);

// delete all the song nodes
void delete_library(song_node *table[]);
 
#endif

