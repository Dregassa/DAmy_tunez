#include "playlist.h"

void add_song(char *song, char *artist){
  int i	= artist[0] - 'a';
  struct song_node *begin = table[i];
  struct song_node *add = (struct song_node *)malloc(sizeof(struct song_node));
  add->name = song;
  add->artist =	artist;
  insert(begin,add);
}

struct song_node * find_in_table(char * artist, char * song){
	int index = artist[0]- 'a';
	return find_song(table[index], artist, song);
}

struct song_node * find_artist(char * artist){
	int index = artist[0] - 'a';
	return find_first_song(table[index], artist);

}


void print_songs(char *artist){
  int i = artist[0] - 'a';
  struct song_node * begin = table[i];
  while (begin){
    if (strcmp(begin->artist,artist)==0) printf("%s\n", begin->name);
  }
}


void print_letter(char *letter){
  int i = letter - 'a';
  struct song_node * begin = table[i];
  while (begin){
    printf("Artist: %s , Song: %s\n", begin->artist, begin->song);
    begin = negin->next;
  }
}


void print_all(){
  int i = 0;
  for (;i <26;i++){
    print_list(table[i]);
  }
}

struct song_node * remove_song(char * artist, char * song){
	struct song_node * search = find_in_table(artist, song);
       	int index = artist[0] - 'a';
	return delete_node(table[index], search);

}
