#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "linked_list.h"


int getsize(struct song_node * list){
	int size = 0;
	while (list){
		size++;
		list = list -> next;
	}
	return size;
}

struct song_node * find_song(struct song_node * list, char * artist, char * song){
	
	struct song_node * search = find_first_song(list, artist); 
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

struct song_node * find_first_song(struct song_node * list, char * artist){

	while(list){

		if (! strcmp(list -> artist, artist) ){ //if they are equivalent
			return list;
		}
		else {
			list = list ->next;
		}
	}

	return 0;
}

struct song_node * random_node(struct song_node * list){
	
	int size = getsize(list);

	if (size == 0){
		return NULL;
	}

	srand ( time(NULL) );

	int index = rand() % size;

	for(;index>0;index--){
		list = list -> next;
	}

	return list;
}

struct song_node * delete_node(struct song_node * list, struct song_node * deathrow){

	/*my intuition tells me there might be a cleaner way to code
	this, but I dont see it right now :( */

	if (list == deathrow){ 
		/*freeing the beginning node might cause issues when the fucntion is invoked externally
		e.g. song_node * original = delete_node(original, deathrow); would free original then try to 
		re-initialize it*/
		struct song_node * next_node = list -> next;
		free(deathrow);
		return next_node;
	}

	struct song_node * traverse = list;

	while(traverse -> next){
		if (traverse -> next == deathrow){
			traverse -> next = deathrow -> next;
			free(deathrow);
			return list;
		}

		traverse = traverse -> next;
	}

	return list; //deathrow not found in LL, should maybe throw an exception or at least put a print statement here



}

/*
void insert(struct song_node *begin, struct song_node *new){
  int counter = 0;
  struct song_node *placeholder = begin;//creates a placeholder so i dont lose original value of begin                                                                               

  while (begin && strcmp(new->artist,begin->artist) < 0){
    counter ++;
    begin = begin->next;
  }
  begin = placeholder;

  while (counter){
    if (counter == 1){
      new->next = begin->next;
      begin->next = new;
    }
    counter --;
    begin = begin->next;
  }
}
*/

struct song_node * insert(struct song_node * list, struct song_node * newnode){//list cannot be NULL
	if (!list){
		return insert_front(list,newnode);
	}
        struct song_node * begin = list; // keeps track of beginning
        struct song_node * prev;

        while ( list && (strcmp( list -> artist, newnode -> artist) < 0 )){//alphabetize by artist
                prev = list;
                list = list -> next;
        }

        if (strcmp(list -> artist, newnode -> artist) == 0){ // if artists are the same
                while ( list && (strcmp( list -> name, newnode -> name) < 0 )){// aplhabetize by song name
                        prev = list;
                        list = list -> next;
                }
        }
//------------------------------------------------------------------------
        if (list == begin){//if newnode goes at beginning
                return insert_front(list, newnode);
        }

        else{// if newnode goes in middle or end
                prev -> next = insert_front(list, newnode); // ... -> prev --> newnode --> begin -> ...
                return begin;
        }
}


/*
void insert_front(struct song_node *new,struct song_node *old){
  new->next = old;
}
*/

struct song_node * insert_front(struct song_node * list, struct song_node * newnode){
  newnode -> next = list;
  return newnode;
}



void print_list(struct song_node * list){
  while	(list){
    printf("Artist: %s\n Song: %s\n\n",	list -> artist, list -> name);
    list = list -> next;
  }
}



void free_list(struct song_node * list){
	struct song_node *prev;   
	while(list){
	    prev = list;
	    list ->next	= list;
	    free(prev);
	    prev = NULL;
	  }
}




