#include "linked_list.h"

struct song_node * table[26];


void add_song(char *song, char *artist);

struct song_node * find_song(char *song);//you do this

struct song_node * find_artist(char *artist);//you do this

void print_songs(char *artist);

void print_letter(char);

void print_all();

void remove_song(char *song);//this should be easy for you to do if you do the other ones

void remove_all();
