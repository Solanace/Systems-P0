struct song_node {
    char name[256];
    char artist[256];
    struct song_node *next;
};
struct song_node *table[26];
void *add_song(char name[], char artist[]);
struct song_node *find_song(char name[], char artist[]);
struct song_node *find_artist(char artist[]);
void print_letter(char c);
void print_artist(char artist[]);
void print_library();
void shuffle();
void delete_song(char name[], char artist[]);
void delete_library();
