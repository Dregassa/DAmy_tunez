struct song_node{
	char name[256];
	char artist[256];
	struct song_node * next;
};

// begin denotes the beginning of the linked list

int getsize(struct song_node * begin);

void insert_front(struct song_node * new, struct song_node * old);

void insert(struct song_node * begin, struct song_node * new);//why do you need begin???

void print_list(struct song_node * begin);

struct song_node * find_song(struct song_node * begin, char * artist, char * song);

struct song_node * find_first_song(struct song_node * begin, char * artist);

struct song_node * random_node(struct song_node * begin);//why would you need any parameters here?

struct song_node * delete_node(struct song_node * begin,struct song_node * deathrow);//Get it? cause its about to be executed lol

void free_list(struct song_node * begin);//dont need parameters because it just frees up the list which is the array and theres only one array
		 //free_node is a different function we will define later 

		 /*we're not freeing the array here, we're freeing a linked list, which there are 26 of
		  However, you bring up a good point when we get to the array. The question I asked
		  dw was whether or not we should write our program to be able to support only one array
		  or mulitiple ones. He said that was up to us. so if we choose to make it so that there
		  is only one array, then for the array function in the playlist.h file we wouldn't need any parameters.
		  * */
