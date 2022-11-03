#include <stdio.h>
#include <stdlib.h>

// #include "generic.h"
#include "generic_vector.h"
#include "my_string.h"
#include "status.h"

// void (*fpAssignment)(ITEM* pLeft, ITEM right)
void assignment(MY_STRING* pLeft, MY_STRING pRight);

// void (*fpDestroy)(ITEM* phItem)
void destroy(MY_STRING* my_string);

// bool (*fpCriteria)(ITEM hItem)
bool criteria(MY_STRING my_string);

int main(int argc, const char* argv[]) {

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

    for (int i = 0; i < 30; i++) {
        dictionary[i] = generic_vector_init_default(&my_string_assignment,
                                                    &destroy);
    }

    for (int i = 0; i < 30; i++) {
        printf("size of [%d] array is: %d\n", i, generic_vector_get_size(dictionary[i]));
    }

    // check if my_string_assignment is operating

    // MY_STRING my_string = my_string_init_default();

    MY_STRING my_string = my_string_init_c_string("hello.");

    MY_STRING my_string01 = my_string_init_c_string("hello there.");

    printf("strings made.\n");

    my_string_assignment((Item*)&my_string, (Item)my_string01);

    printf("check: %s\n", my_string_c_str(my_string));

    // check done

    FILE* fp;
    Status status;

    fp = fopen("dictionary.txt", "r");

    while (my_string_extraction(my_string, fp)) {
        // printf("extraction.\n");
        my_string_insertion(my_string, stdout);
		printf("\n");

        int i = my_string_get_size(my_string);
        status = generic_vector_push_back(dictionary[i], my_string);
        if (status == FAILURE) {
            printf("failure...\n");
            return -1;
        }
	}

    my_string_destroy((Item*)&my_string);
    printf("while loop : done...\n");

    // check for a value
    GENERIC_VECTOR vector_check = dictionary[8];
    MY_STRING string_check = (MY_STRING)generic_vector_at(vector_check, 2000);

    printf("\ncheck--\n");
    printf("%s\n", my_string_c_str(string_check));
    printf("size: %d\n", my_string_get_size(string_check));
    printf("\n");

    for (int i = 0; i < 30; i++) {
        int count = generic_vector_count(dictionary[i], &criteria);
        printf("[%d] : %d\n", i, count);
    }

    return 0;
}

void assignment(MY_STRING* pLeft, MY_STRING pRight) {
    my_string_assignment((Item*)*pLeft, (Item)pRight);
}

void destroy(MY_STRING* my_string) {
    free(my_string);
}

bool criteria(MY_STRING my_string) {
    if (my_string) return true;
    else return false;
}