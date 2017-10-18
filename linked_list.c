#include <string.h>
#include "linked_list.h"


song_node * find_song(song_node * begin, char * artist, char * song){
	
	song_node * search = find_first_song(begin, artist); 
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

song_node * find_first_song(song_node * begin, char * artist){

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
