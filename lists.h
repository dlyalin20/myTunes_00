#ifndef MY_LISTS
#define MY_LISTS "defined lists"

// stdlibs
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

// Linked List Struct
struct song_node {
    char *name;
    char *artist;
    struct song_node *next;
};

// Function Declarations
void print_song(struct song_node *node);
void print_list(struct song_node *front);
struct song_node * free_list(struct song_node *front);
struct song_node * random_song(struct song_node *front);
struct song_node * create_song(char *name, char *artist);
int comes_before(struct song_node *a, struct song_node *b);
struct song_node * find_artist(struct song_node *front, char *artist);
struct song_node * find_node(struct song_node *front, char *artist, char *name);
struct song_node * insert_helper(struct song_node *front, struct song_node *node);
struct song_node * remove_song(struct song_node *front, char *artist, char *name);
struct song_node * insert_song(struct song_node *front, char *artist, char *name);
struct song_node * insert_front(struct song_node *front, char *name, char *artist);

#endif