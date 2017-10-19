#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "linked_list.h"

struct song_node *insert_front(struct song_node *front, char name[], char artist[]) {
    srand(time(NULL));
    lowerfy(name);
    lowerfy(artist);
    //printf("Inserting %s -- \"%s\"\n", name, artist);
    struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    new->next = front;
    return new;
}

struct song_node *insert_order(struct song_node *front, char name[], char artist[]) {
    /* Loop through the artist names. If the new song's artist already has songs in the
    linked list, loop through the song names too. */
    lowerfy(name);
    lowerfy(artist);
    // base case, front is null
    if (!front) return insert_front(0, name, artist);
    // front is not null
    struct song_node *prev = front;
    struct song_node *loop = front->next;
    // loop through authors, stop at the one before the new song's
    while (loop && strcmp(artist, loop->artist) > 0) {
        //printf("%s goes after %s\n", artist, prev->artist);
        prev = prev->next;
        loop = loop->next;
    }
    // loop through songs if necessary
    while (loop && !strcmp(artist, loop->artist) && strcmp(name, loop->name) > 0) {
        //printf("%s goes after %s\n", artist, prev->artist);
        prev = prev->next;
        loop = loop->next;
    }
    // artist precedes front
    if (prev == front && strcmp(artist, front->artist) < 0) {
        return insert_front(front, name, artist);
    }
    // name precedes front
    /*if (prev == front && strcmp(artist, front->artist) == 0 && strcmp(name, front->name) < 0) {
        return insert_front(front, name, artist);
    }*/
    prev->next = insert_front(loop, name, artist);
    prev->next->next = loop;
    //printf("%s -- \"%s\" goes after %s -- \"%s\"\n", artist, name, prev->artist, prev->name);
    return front;
}

void print_node(struct song_node *song) {
    if (!song) {
        printf("NO SONG DETECTED\n");
        return;
    }
    printf("%s -- \"%s\"\n", song->artist, song->name);
}

void print_list(struct song_node *front) {
    if (!front) return;
    struct song_node *loop = front;
    while (loop->next) {
        //print_song(loop);
        printf("%s -- \"%s\" | ", loop->artist, loop->name);
        loop = loop->next;
    }
    printf("%s -- \"%s\"\n", loop->artist, loop->name);
}

struct song_node *find_node(struct song_node *front, char name[], char artist[]) {
    lowerfy(name);
    lowerfy(artist);
    //printf("Finding %s -- \"%s\"\n", name, artist);
    struct song_node *loop = find_artist_node(front, artist);
    while (loop && strcmp(name, loop->name)) {
        loop = loop->next;
    }
    return loop;
}

struct song_node *find_artist_node(struct song_node *front, char artist[]) {
    lowerfy(artist);
    //printf("Finding first song by %s\n", artist);
    struct song_node *loop = front;
    while (loop && strcmp(artist, loop->artist)) {
        loop = loop->next;
    }
    return loop;
}

struct song_node *find_random_node(struct song_node *front) {
    if (!front) return NULL;
    
    struct song_node *loop = front;
    int i = 0;
    while (loop) {
        i ++;
        loop = loop->next;
    }
    
    loop = front;
    int j = rand() % i;
    while (j) {
        j --;
        loop = loop->next;
    }
    return loop;
}

struct song_node *remove_node(struct song_node *front, char name[], char artist[]) {
    lowerfy(name);
    lowerfy(artist);
    //printf("Removing \"%s\" by %s\n", name, artist);
    if (front == find_node(front, name, artist)) {
        struct song_node *new_front = front->next;
        free(front);
        front = 0;
        return new_front;
    }
    struct song_node *prev = front;
    struct song_node *loop = prev->next;
    while (loop && strcmp(name, loop->name)) {
        prev = prev->next;
        loop = loop->next;
    }
    if (loop && !strcmp(name, loop->name)) {
        prev->next = loop->next;
        free(loop);
        loop = 0;
    }
    return front;
}

struct song_node *free_list(struct song_node *front) {
    struct song_node *loop = front;
    while (loop) {
        struct song_node *temp = loop->next;
        free(loop);
        loop = temp;
    }
    front = 0;
    return front;
}

char *lowerfy(char str[]) {
    int i;
    for (i = 0; str[i]; i ++) {
        str[i] = tolower(str[i]);
    }
    return str;
}
