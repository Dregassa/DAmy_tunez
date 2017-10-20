#include "linked_list.h"

void add_song(struct song_node * table[], char *song, char *artist);

struct song_node * find_in_table(struct song_node * table[], char * artist, char * song);//you do this

struct song_node * find_artist(struct song_node * table[], char *artist);//you do this

void print_songs(struct song_node * table[], char *artist);

void print_letter(struct song_node * table[], char *letter);

void print_all(struct song_node * table[]);

struct song_node * remove_song(struct song_node * table[], char * artist, char * song);//this should be easy for you to do if you do the other ones

void shuffle(struct song_node * table[], int num_songs);

void remove_all(struct song_node * table[]);
