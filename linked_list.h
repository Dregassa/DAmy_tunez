struct song_node{
	char name[256];
	char artist[256];
	struct song_node * next;
};

int getsize(struct song_node * list);

struct song_node * insert_front(struct song_node * list, struct song_node * newnode);

struct song_node * insert(struct song_node * list, struct song_node * newnode);

void print_list(struct song_node * list);

struct song_node * find_song(struct song_node * list, char * artist, char * song);

struct song_node * find_first_song(struct song_node * list, char * artist);

struct song_node * random_node(struct song_node * list);

struct song_node * delete_node(struct song_node * list ,struct song_node * deathrow);//Get it? cause its about to be executed lol

void free_list(struct song_node * list);
