#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "playlist.h"

void add_song(char *song, char *artist){
  int i	= artist[0] - 'a';
  struct song_node *begin = table[i];
  struct song_node *add = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(add->name,song);
  strcpy(add->artist,artist);
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
  int i = letter[0] - 'a';
  struct song_node * begin = table[i];
  while (begin){
    printf("Artist: %s , Song: %s\n", begin->artist, begin->name);
    begin = begin->next;
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
int table_empty (){
	int i = 0;
	for (;i<26;i++){
		if (table[i]){return 0;}
	}
	return 1;

}
void shuffle(int num_songs){ //not even distribution by a long shot		
	if (table_empty()){
		printf("No songs in playlist");
		return;
	}

	for (;num_songs > 0; num_songs--){

		srand ( time(NULL) );
		int index = rand() % 26;	
		while( !table[index] ){ //find a non null pointer
			index = rand() % 26;	
		}
		printf("[%s : %s]", table[index] -> artist, table[index] -> name);

	}


}
