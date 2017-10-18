struct song_node {
    char name[256];
    char artist[256];
    struct song_node *next;
};
struct song_node *insert_front(struct song_node *front, char name[], char artist[]);
struct song_node *insert_order(struct song_node *front, char name[], char artist[]);
void print_song(struct song_node *song);
void print_list(struct song_node *front);
struct song_node *find_song(struct song_node *front, char name[], char artist[]);
struct song_node *find_artist(struct song_node *front, char artist[]);
struct song_node *find_random_song(struct song_node *front);
struct song_node *remove_node(struct song_node *front, char name[], char artist[]);
struct song_node *free_list(struct song_node *front);
char *lowerfy(char str[]);
