#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linked_list.h"


int getsize(struct song_node * begin){
	int size = 0;
	while (begin){
		size++;
		begin = begin -> next;
	}
	return size;
}

struct song_node * find_song(struct song_node * begin, char * artist, char * song){
	
	struct song_node * search = find_first_song(begin, artist); 
        /*taking advantage that the LL is alphabetized, we first find
	  the first song by an artist then linearly traverse from there*/	

	while(search){
		
		if( strcmp(search->artist, artist) ){ //if we have exhausted all the artist's songs, but have not found the song
			return 0;
		}

		else if (! strcmp(search->name, song)){ //if the strings are equivalent
			return search;
		}
		else {
			search = search->next;
		}


	}

	return 0;
}

struct song_node * find_first_song(struct song_node * begin, char * artist){

	while(begin){

		if (! strcmp(begin->artist, artist) ){ //if they are equivalent
			return begin;
		}
		else {
			begin = begin->next;
		}
	}

	return 0;
}

struct song_node * random_node(struct song_node * begin){
	
	int size = getsize(begin);

	srand ( time(NULL) );

	int index = rand() % size;

	for(;index>0;index--){
		begin = begin -> next;
	}

	return begin;
}

struct song_node * delete_node(struct song_node * begin, struct song_node * deathrow){

	/*my intuition tells me there might be a cleaner way to code
	this, but I dont see it right now :( */

	if (begin == deathrow){ 
		/*freeing the beginning node might cause issues when the fucntion is invoked externally
		e.g. song_node * original = delete_node(original, deathrow); would free original then try to 
		re-initialize it*/
		struct song_node * next_node = begin -> next;
		free(deathrow);
		return next_node;
	}

	struct song_node * traverse = begin;

	while(traverse -> next){
		if (traverse -> next == deathrow){
			traverse -> next = deathrow -> next;
			free(deathrow);
			return begin;
		}

		traverse = traverse -> next;
	}

	return begin; //deathrow not found in LL, should maybe throw an exception or at least put a print statement here



}
