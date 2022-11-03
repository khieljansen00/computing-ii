#include <stdio.h>
#include <stdlib.h>

// #include "generic.h"
#include "generic_vector.h"
#include "my_string.h"
#include "status.h"

// void (*fpAssignment)(ITEM* pLeft, ITEM right)
void assignment(ITEM* pLeft, ITEM right);

// void (*fpDestroy)(ITEM* phItem)
void destroy(ITEM* phItem);

// bool (*fpCriteria)(ITEM hItem)
bool criteria(MY_STRING my_string);

int main(int argc, const char* argv[]) {

    printf("side-main.c\n");

    GENERIC_VECTOR dictionary[30] = { NULL };

    // array of Vectors holds 30 vectors from word length 1 to 29
    // so word length 1 starts at index 0
    // and word length 29 starts at index 28
    // nah or stick to length equals index 1
    // for (int i = 0; i <= 28; i++) {
    //     dictionary[i] = generic_vector_init_default(void (*assignment)(MY_STRING* hString, char* string),
    //                                                 void (*destroy)(MY_STRING* hString));
    // }

    // void (*assignmentO)(MY_STRING*, MY_STRING) = &assignment;

    // these for loops cause the zsh: abort error
    // make sure the arrays are resizing properly
    // it's because size of array[30] is from 0 to 29...
    for (int i = 0; i < 30; i++) {
        dictionary[i] = generic_vector_init_default(&assignment,
                                                    &destroy);
    }

    for (int i = 0; i < 30; i++) {
        printf("size of [%d] array is: %d\n", i, generic_vector_get_size(dictionary[i]));
    }

    // check if my_string_assignment is operating

    // MY_STRING my_string01 = my_string_init_default();

    MY_STRING my_string01 = my_string_init_c_string("hi");

    MY_STRING my_string02 = my_string_init_c_string("hello there.");

    printf("strings made.\n");

    my_string_assignment((Item*)&my_string01, (Item)my_string02);

    printf("check c_str of assigned my_string: %s\n", my_string_c_str(my_string01));

    // assignment function works!
    // and the check works
    // works for both init_default() and init_c_string() as first parameter
    // when pLeft = null, check = null

    my_string_destroy((Item*)&my_string01);
    my_string_destroy((Item*)&my_string02);

    // *****

    // now the main thing
    // i need to somehow initialize dictionary[i]'s data
    // dictionary is an array
    // example: dictionary[0] is a generic vector
    // and so, dictionary[0] has a data that must be initialized with init_default

    MY_STRING my_string = my_string_init_c_string("hello world");

    generic_vector_push_back(dictionary[0], (Item)my_string);

    // GENERIC_VECTOR vector_c = dictionary[0];
    ITEM string_c = generic_vector_at(dictionary[0], 0);

    printf("size is: %d\n", generic_vector_get_size(dictionary[0]));

    printf("problem check: %s\n", my_string_c_str((MY_STRING)string_c));

    my_string_destroy((Item*)&my_string);

    // // WORKS !!!

    // *****

    MY_STRING my_extract_string = my_string_init_default();

    FILE* fp;
    Status status;

    fp = fopen("dictionary.txt", "r");

    while (my_string_extraction(my_extract_string, fp)) {
        // my_string_insertion(my_extract_string, stdout);
		// printf("\n");

        int i = my_string_get_size(my_extract_string);
        status = generic_vector_push_back(dictionary[i], (Item)my_extract_string);
        if (status == FAILURE) {
            printf("failure...\n");
            return -1;
        }
	}

    ITEM dictionary_string_c = generic_vector_at(dictionary[28], 0);

    printf("size is: %d\n", generic_vector_get_size(dictionary[0]));

    printf("problem check: %s\n", my_string_c_str((MY_STRING)dictionary_string_c));

    for (int i = 0; i < 30; i++) {
        int count = generic_vector_count(dictionary[i], &criteria);
        printf("[%d] : %d\n", i, count);
    }

    my_string_destroy((Item*)&my_extract_string);

    return 0;
}

// Important: bring these functions back and make sure their parameters are same as the ones in generic_vector functions
// then cast them as my_string objects inside the function and assign and destroy

void assignment(ITEM* pLeft, ITEM right) {
    MY_STRING my_string = my_string_init_default();
    Item* item_string = (Item*)my_string;
    *pLeft = item_string;
    my_string_assignment(pLeft, right);
}

void destroy(ITEM* phItem) {
    my_string_destroy(phItem);
}

bool criteria(MY_STRING my_string) {
    if (my_string) return true;
    else return false;
}