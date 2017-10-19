#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "linked_list.h"
#include "music_library.h"

int main() {
    srand(time(NULL));
    char name[256], artist[256];
    struct song_node *head = 0;
    
    printf("====================LINKED LIST TESTS\n");
    
    printf("====================\nTesting insert_order:\n--------------------\n");
    strcpy(name, "Electric Jazz");
    strcpy(artist, "Bobert");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    strcpy(name, "Frank");
    strcpy(artist, "Budding Soldier");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    strcpy(name, "Fright for Late Night");
    strcpy(artist, "Budding Soldier");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    strcpy(name, "The Swallow");
    strcpy(artist, "Ballast");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    strcpy(name, "Sing Me a Song");
    strcpy(artist, "Zharnach");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    strcpy(name, "Jill's Jibber-Jabber");
    strcpy(artist, "Bobert");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    strcpy(name, "My Mice");
    strcpy(artist, "Bobert");
    printf("Inserting %s -- \"%s\"\n", artist, name);
    head = insert_order(head, name, artist);
    
    printf("--------------------\nTesting print_list:\n--------------------\n");
    print_list(head);
    
    printf("--------------------\nTesting find_node and find_artist_node:\n--------------------\n");
    struct song_node *random = find_random_node(head);
    printf("Finding %s -- \"%s\" and printing nodes following it:\n", random->artist, random->name);
    print_list(find_node(head, random->name, random->artist));
    random = find_random_node(head);
    printf("Finding first node by %s and printing nodes following it:\n", random->artist);
    print_list(find_artist_node(head, random->artist));
    
    printf("--------------------\nTesting find_random_node:\n--------------------\n");
    print_node(find_random_node(head));
    print_node(find_random_node(head));
    print_node(find_random_node(head));
    
    printf("--------------------\nTesting remove_node:\n--------------------\n");
    random = find_random_node(head);
    printf("Removing %s -- \"%s\"\n", random->artist, random->name);
    head = remove_node(head, random->name, random->artist);
    printf("New linked list:\n");
    print_list(head);
    
    printf("--------------------\nTesting free_list:\n--------------------\n");
    head = free_list(head);
    printf("New linked list:\n");
    print_list(head);
    
    printf("====================\nMUSIC LIBRARY TESTS\n");
    
    printf("====================\nTesting add_song:\n--------------------\n");
    strcpy(name, "Son of a Sow");
    strcpy(artist, "Abby");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Kool Kat");
    strcpy(artist, "Abby");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Jalapeno Fred");
    strcpy(artist, "Abby");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "I Shot Hamilton");
    strcpy(artist, "Aaron Burr");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "The Bird Winged His Test");
    strcpy(artist, "Penn Wu");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Go France");
    strcpy(artist, "Pierre Vullon");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Shengrikuaile");
    strcpy(artist, "Zuni");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Electric Shock");
    strcpy(artist, "Zad");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Thiz Iz Crazy");
    strcpy(artist, "Zyster");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Synapse Relapse");
    strcpy(artist, "Zad");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Alphabet Soup");
    strcpy(artist, "Zad");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    
    printf("--------------------\nTesting find_song:\n--------------------\n");
    head = shuffle();
    strcpy(name, head->name);
    strcpy(artist, head->artist);
    printf("Finding %s -- \"%s\"\n", artist, name);
    print_node(find_song(name, artist));
    strcpy(name, "This Song Is Fake");
    printf("Finding %s -- \"%s\"\n", artist, name);
    print_node(find_song(name, artist));
    
    printf("--------------------\nTesting find_artist:\n--------------------\n");
    strcpy(artist, shuffle()->artist);
    printf("Finding %s\n", artist);
    print_list(find_artist(artist));
    
    printf("--------------------\nTesting print_letter:\n--------------------\n");
    print_letter(rand() % 26 + 97);
    
    printf("--------------------\nTesting print_artist:\n--------------------\n");
    strcpy(artist, shuffle()->artist);
    printf("Printing songs by %s\n", artist);
    print_artist(artist);
    
    printf("--------------------\nTesting print_library:\n--------------------\n");
    print_library();
    
    printf("--------------------\nTesting shuffle:\n--------------------\n");
    print_node(shuffle());
    print_node(shuffle());
    print_node(shuffle());
    
    printf("--------------------\nTesting delete_song:\n--------------------\n");
    head = shuffle();
    strcpy(name, head->name);
    strcpy(artist, head->artist);
    printf("Deleting %s -- \"%s\"\n", artist, name);
    delete_song(name, artist);
    printf("New playlist:\n");
    print_library();
    
    printf("--------------------\nTesting delete_library:\n--------------------\n");
    delete_library();
    printf("New playlist:\n");
    print_library();
    
    printf("====================\nCREATING NEW LIBRARY\n");
    
    printf("====================\nTesting add_song\n--------------------\n");
    strcpy(name, "The Room Where It Happens");
    strcpy(artist, "Miranda");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "My Shot");
    strcpy(artist, "Miranda");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "96,000");
    strcpy(artist, "Usnavi");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Stand");
    strcpy(artist, "Undulating Wave");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Little Lamb");
    strcpy(artist, "Mary");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Sam Had a Cat");
    strcpy(artist, "Dr. Seuss");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Baklava");
    strcpy(artist, "Dullest Tool in the Shed");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Eraser");
    strcpy(artist, "Stationery");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "My Shot");
    strcpy(artist, "Hamilton");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Cabinet Battle #1");
    strcpy(artist, "Hamilton and Jefferson");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    strcpy(name, "Cabinet Battle #2");
    strcpy(artist, "Hamilton and Jefferson");
    printf("Adding %s -- \"%s\"\n", artist, name);
    add_song(name, artist);
    
    printf("--------------------\nTesting find_song:\n--------------------\n");
    head = shuffle();
    strcpy(name, head->name);
    strcpy(artist, head->artist);
    printf("Finding %s -- \"%s\"\n", artist, name);
    print_node(find_song(name, artist));
    strcpy(name, "This Song Is Fake");
    printf("Finding %s -- \"%s\"\n", artist, name);
    print_node(find_song(name, artist));
    
    printf("--------------------\nTesting find_artist:\n--------------------\n");
    strcpy(artist, shuffle()->artist);
    printf("Finding %s\n", artist);
    print_list(find_artist(artist));
    
    printf("--------------------\nTesting print_letter:\n--------------------\n");
    print_letter(rand() % 26 + 97);
    
    printf("--------------------\nTesting print_artist:\n--------------------\n");
    strcpy(artist, shuffle()->artist);
    printf("Printing songs by %s\n", artist);
    print_artist(artist);
    
    printf("--------------------\nTesting print_library:\n--------------------\n");
    print_library();
    
    printf("--------------------\nTesting shuffle:\n--------------------\n");
    print_node(shuffle());
    print_node(shuffle());
    print_node(shuffle());
    
    printf("--------------------\nTesting delete_song:\n--------------------\n");
    head = shuffle();
    strcpy(name, head->name);
    strcpy(artist, head->artist);
    printf("Deleting %s -- \"%s\"\n", artist, name);
    delete_song(name, artist);
    printf("New playlist:\n");
    print_library();
    
    printf("--------------------\nTesting delete_library:\n--------------------\n");
    delete_library();
    printf("New playlist:\n");
    print_library();
    
    return 0;
}
