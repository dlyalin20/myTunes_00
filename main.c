#include "library.h"
#include "lists.h"

int main() {
    
    printf("LINKED LIST TESTS\n====================================\n\n");

    struct song_node *front = NULL;
    front = insert_song(front, "ac/dc", "thunderstruck");
    front = insert_song(front, "pink floyd", "time");
    front = insert_song(front, "pearl jam", "even flow");
    front = insert_song(front, "pearl jam", "yellow ledbetter");
    front = insert_song(front, "radiohead", "street spirit (fade out)");
    front = insert_song(front, "pearl jam", "alive");
    front = insert_song(front, "radiohead", "paranoid android");

    printf("Testing print_song:\n");
    print_song(front);
    printf("\n====================================\n\n");

    printf("Testing print_list; also tests generating a library, inserting songs, comes_before, and insert_helper:\n");
    // ac/dc, thunderstruck} | {pearl jam, alive} | {pearl jam, even flow} | {pearl jam, yellow ledbetter} | {pink floyd, time} | {radiohead, paranoid android} | {radiohead, street spirit (fade out)
    print_list(front); 
    printf("====================================\n\n");

    printf("Testing insert front: \n");
    front = insert_front(front, "the rolling stones", "paint it black");
    print_list(front);
    printf("====================================\n\n");

    printf("Testing find node: \n");
    find_node(front, "pearl jam", "even flow");
    find_node(front, "pearl jam", "daughter");
    printf("====================================\n\n");

    printf("Testing find artist: \n");
    find_artist(front, "pearl jam");
    find_artist(front, "tame impala");
    printf("====================================\n\n");

    printf("Testing random:\n");
    srand( time(NULL) );
    int counter;
    for (counter = 0; counter < 4; counter++) {
        random_song(front);
        printf("\n");
    }
    printf("====================================\n\n");

    printf("Testing remove:\n");
    front = remove_song(front, "pearl jam", "alive");
    print_list(front);
    front = remove_song(front, "pearl jam", "yellow ledbetter");
    print_list(front);
    front = remove_song(front, "pink floyd", "alive");
    print_list(front);
    printf("====================================\n\n");

    printf("Testing free_list:\n");
    front = free_list(front);
    printf("list after free_list: ");
    print_list(front);
    printf("====================================\n\n");

    printf("LIBRARY LIST TESTS\n====================================\n\n");

    struct song_node **library = create_library();
    library = add_song(library, "pearl jam", "yellow ledbetter");
    library = add_song(library, "radiohead", "paranoid");
    library = add_song(library, "pearl jam", "alive");
    library = add_song(library, "presidents of the united states of america", "peaches");
    library = add_song(library, "ac/dc", "thunderstruck");
    library = add_song(library, "pearl jam", "even flow");
    library = add_song(library, "radiohead", "street spirit (fade out)");
    library = add_song(library, "pink floyd", "time");
    library = add_song(library, "9 inch nails", "closer");
    printf("Testing generating library; also tests adding songs and alphabetizing them: \n");
    print_library(library);
    printf("====================================\n\n");

    printf("Testing finding songs in library: \n");
    find_song(library, "pearl jam", "alive");
    find_song(library, "pearl jam", "time");
    printf("====================================\n\n");

    printf("Testing finding artists in library: \n");
    find_artist_library(library, "pearl jam");
    find_artist_library(library, "pink floyd");
    find_artist_library(library, "bob dylan");
    printf("====================================\n\n");

    printf("Testing print_letter: \n");
    print_letter(library, 'p');
    printf("====================================\n\n");

    printf("Testing print artist: \n");
    print_artist(library, "pearl jam");
    print_artist(library, "ac/dc");
    printf("====================================\n\n");

    printf("Testing shuffle, and shuffle_helper: \n");
    shuffle(library);
    printf("\n");
    printf("====================================\n\n");

    printf("Testing remove song: \n");
    library = remove_song_library(library, "pearl jam", "alive");
    print_library(library);
    library = remove_song_library(library, "pearl jam", "yellow ledbetter");
    print_library(library);
    printf("====================================\n\n");

    printf("Testing free library: \n");
    library = free_library(library);
    printf("Printing library: \n");
    print_library(library);

    return 0;
}