#ifndef MY_LIBRARY
#define MY_LIBRARY "defined library"

// stdlib
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>

// custom h
#include "lists.h"

// Custom Functions
struct song_node ** create_library();
void shuffle(struct song_node **library);
void print_library(struct song_node **library);
void shuffle_helper(struct song_node **library);
void print_letter(struct song_node **library, char letter);
void print_artist(struct song_node **library, char *artist);
struct song_node ** free_library(struct song_node **library);
struct song_node * find_artist_library(struct song_node **library, char *artist);
struct song_node * find_song(struct song_node **library, char *artist, char *name);
struct song_node ** add_song(struct song_node **library, char *artist, char *name);
struct song_node ** add_song_node(struct song_node **library, struct song_node *node);
struct song_node ** remove_song_library(struct song_node **library, char *artist, char *name);

#endif