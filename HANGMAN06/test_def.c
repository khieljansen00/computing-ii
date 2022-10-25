#include <stdio.h>
#include <string.h>

#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length) {
    MY_STRING hString = NULL;
    hString = my_string_init_default();

    if (hString == NULL) {
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default() returns NULL\n", length);
        return FAILURE;
    } else {
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if (my_string_get_size(hString) != 0) {
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n" "Did not receive 0 from get_size after init_default\n", length);
    } else {
        status = SUCCESS;
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_destroy(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    my_string_destroy((Item*)&hString);

    if (hString != NULL) {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_destroy\n" "string object is not destroyed by my_string_destroy()\n", length);
    } else {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_destroy\n", length);
    }
    return status;
}

Status test_kmantill_init_c_string_destroy(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");

    my_string_destroy((Item*)&hString);

    if (hString != NULL) {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_destroy\n" "string object is not destroyed by my_string_destroy()\n", length);
    } else {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_destroy\n", length);
    }
    return status;
}

Status test_kmantill_init_c_string_returns_nonNULL(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");

    if (hString == NULL) {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_returns_nonNULL\n" "my_string_init_c_string returns NULL\n", length);
    } else {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_returns_nonNULL\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_c_string_correct_size_and_capacity(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");

    if (my_string_get_size(hString) == 5 && my_string_get_capacity(hString) == 6) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_correct_size_and_capacity\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_correct_size_and_capacity\n" "incorrect size and capacity\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_my_string_compare_returns_0_if_strings_are_the_same(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_default();
    hString02 = my_string_init_default();

    if (my_string_compare(hString01, hString02) == 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n" "my_string_compare does not return 0 as the strings are the same\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy((Item*)&hString02);
    return status;
}

Status test_kmantill_init_default_push_back_my_string_compare_returns_0_if_strings_are_the_same(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_default();
    hString02 = my_string_init_default();

    my_string_push_back(hString01, 'a');
    my_string_push_back(hString02, 'a');

    if (my_string_compare(hString01, hString02) == 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n" "my_string_compare does not return 0 as the strings are the same\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy((Item*)&hString02);
    return status;
}

Status test_kmantill_init_default_push_back_my_string_compare_returns_pos_int(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_default();
    hString02 = my_string_init_default();

    my_string_push_back(hString01, 'a');

    if (my_string_compare(hString01, hString02) > 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n" "my_string_compare does not return a positive int value\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy((Item*)&hString02);
    return status;
}

Status test_kmantill_init_default_push_back_my_string_compare_returns_negative_int(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_default();
    hString02 = my_string_init_default();

    my_string_push_back(hString02, 'a');

    if (my_string_compare(hString01, hString02) < 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n" "my_string_compare does not return a negative int value\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy((Item*)&hString02);
    return status;
}

Status test_kmantill_init_c_string_my_string_compare_returns_0_if_strings_are_the_same(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_c_string("apple");
    hString02 = my_string_init_c_string("apple");

    if (my_string_compare(hString01, hString02) == 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_0_if_strings_are_the_same\n" "my_string_compare does not return 0 as the strings are the same\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy((Item*)&hString02);
    return status;
}

Status test_kmantill_init_c_string_my_string_compare_returns_pos_int_if_left_string_is_bigger(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_c_string("apple-pie");
    hString02 = my_string_init_c_string("apple");

    if (my_string_compare(hString01, hString02) > 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_pos_int_if_left_string_is_bigger\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_pos_int_if_left_string_is_bigger\n" "my_string_compare does not return a positive int if left string is bigger than right string\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy((Item*)&hString02);
    return status;
}

Status test_kmantill_init_c_string_my_string_compare_returns_negative_int_if_left_string_is_bigger(char* buffer, int length) {
    MY_STRING hString01 = NULL;
    MY_STRING hString02 = NULL;
    Status status;
    hString01 = my_string_init_c_string("apple");
    hString02 = my_string_init_c_string("apple-pie");

    if (my_string_compare(hString01, hString02) < 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_negative_int_if_left_string_is_bigger\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_my_string_compare_returns_negative_int_if_left_string_is_bigger\n" "my_string_compare does not return a negative int if left string is smaller than right string\n", length);
    }

    my_string_destroy((Item*)&hString01);
    my_string_destroy(&hString02);
    return status;
}

Status test_kmantill_init_default_push_back_returns_success(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    status = my_string_push_back(hString, 'a');

    if (status == SUCCESS) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_default_push_back_returns_success\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_default_push_back_returns_success\n" "push_back returns FAILURE\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_pop_back_returns_failure(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    Status status_of_function = my_string_pop_back(hString);

    if (status_of_function == FAILURE) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_pop_back_returns_failure\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_pop_back_returns_failure\n" "pop_back should return FAILURE if size is 0\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_c_string_push_back_returns_success(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");
    status = my_string_push_back(hString, 'a');

    if (status == SUCCESS) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_default_push_back_returns_success\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_default_push_back_returns_success\n" "push_back returns FAILURE\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_c_string_pop_back_returns_success(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");
    status = my_string_pop_back(hString);

    if (status == SUCCESS) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_default_push_back_returns_success\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_default_push_back_returns_success\n" "push_back returns FAILURE\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_push_back_and_my_string_at_returns_correct_char(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    status = my_string_push_back(hString, 'a');
    char* c = my_string_at(hString, 0);

    if (c[0] == 'a') {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_default_push_back_and_my_string_at_returns_correct_char\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_default_push_back_and_my_string_at_returns_correct_char\n" "my_string_at does not return the correct char\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_push_back_and_my_string_at_returns_NULL_if_index_is_out_of_bounds(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    status = my_string_push_back(hString, 'a');
    char* c = my_string_at(hString, 2);

    if (c == NULL) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_default_push_back_and_my_string_at_returns_NULL_if_index_is_out_of_bounds\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_default_push_back_and_my_string_at_returns_NULL_if_index_is_out_of_bounds\n" "my_string_at does not return NULL even though index is out of bounds\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default__my_string_at_returns_NULL_if_empty_data(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    char* c = my_string_at(hString, 0);

    if (c == NULL) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_default__my_string_at_returns_NULL_if_empty_data\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_default__my_string_at_returns_NULL_if_empty_data\n" "my_string_at does not return NULL if data is empty\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_c_string_my_string_at_returns_correct_char(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");
    char* c = my_string_at(hString, 3);

    if (c[0] == 'l') {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_my_string_at_returns_correct_char\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_my_string_at_returns_correct_char\n" "my_string_at does not return the correct char\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_c_string_my_string_at_returns_NULL_when_index_is_out_of_bounds(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("apple");
    char* c = my_string_at(hString, 11);

    if (c == NULL) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_my_string_at_returns_NULL_when_index_is_out_of_bounds\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_my_string_at_returns_NULL_when_index_is_out_of_bounds\n" "my_string_at does not return NULL even though index is out of bounds\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_push_back_and_my_string_c_str_returns_correct_string(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    status = my_string_push_back(hString, 'a');
    status = my_string_push_back(hString, 'p');
    status = my_string_push_back(hString, 'p');
    status = my_string_push_back(hString, 'l');
    status = my_string_push_back(hString, 'e');
    char* c = my_string_c_str(hString);

    if (strcmp(c, "apple") == 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_push_back_and_my_string_c_str_returns_correct_string\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_push_back_and_my_string_c_str_returns_correct_string\n" "my_string_c_str does not return the correct c-string\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_push_back_and_my_string_c_str_returns_correct_string_max_size(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    status = my_string_push_back(hString, 'a');
    status = my_string_push_back(hString, 'p');
    status = my_string_push_back(hString, 'p');
    status = my_string_push_back(hString, 'l');
    status = my_string_push_back(hString, 'e');
    status = my_string_push_back(hString, 's');
    status = my_string_push_back(hString, '.');
    char* c = my_string_c_str(hString);

    if (strcmp(c, "apples.") == 0) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_push_back_and_my_string_c_str_returns_correct_string_max_size\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_push_back_and_my_string_c_str_returns_correct_string_max_size\n" "my_string_c_str does not return the correct c-string\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_default_my_string_c_str_returns_NULL_when_data_is_empty(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    char* c = my_string_c_str(hString);

    if (c == NULL) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string__my_string_c_str_returns_NULL_when_data_is_empty\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string__my_string_c_str_returns_NULL_when_data_is_empty\n" "my_string_c_str does not return NULL when data is empty\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty(char* buffer, int length) {
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("a");
    status = my_string_pop_back(hString);
    char* c = my_string_c_str(hString);

    if (c == NULL) {
        status = SUCCESS;
        strncpy(buffer, "test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty\n", length);
    } else {
        status = FAILURE;
        strncpy(buffer, "test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty\n" "my_string_c_str does not return NULL when data is empty\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_kmantill_100_elements_copied(char* buffer, int length) {
    MY_STRING hString[100] = { NULL };
    Status status;

    hString[0] = my_string_init_c_string("COPY ME!");

    for (int i = 1; i < 100; i++) {
        my_string_assignment(&hString[i], hString[0]);
    }

    for (int i = 0; i < 100; i++) {
        status = my_string_insertion(hString[i], stdout);
        if (status == FAILURE) return FAILURE;
        my_string_destroy(&hString[i]);
    }

    for (int i = 0; i < 100; i++) {
        if (hString[i]) {
            status = FAILURE;
            strncpy(buffer, "test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty\n" "string is not destroyed\n", length);
            return status;
        }
    }

    status = SUCCESS;
    strncpy(buffer, "test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty\n", length);

    return status;
}
