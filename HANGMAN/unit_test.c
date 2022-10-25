#include <stdio.h>
#include "unit_test.h"

int main(int argc, const char* argv[]) {

    Status (*tests[])(char*, int) = {
        test_init_default_returns_nonNULL,
        test_get_size_on_init_default_returns_0,
        test_kmantill_init_default_destroy,
        test_kmantill_init_c_string_destroy,
        test_kmantill_init_c_string_returns_nonNULL,
        test_kmantill_init_c_string_correct_size_and_capacity,
        test_kmantill_init_default_my_string_compare_returns_0_if_strings_are_the_same,
        test_kmantill_init_default_push_back_my_string_compare_returns_0_if_strings_are_the_same,
        test_kmantill_init_default_push_back_my_string_compare_returns_pos_int,
        test_kmantill_init_default_push_back_my_string_compare_returns_negative_int,
        test_kmantill_init_c_string_my_string_compare_returns_0_if_strings_are_the_same,
        test_kmantill_init_c_string_my_string_compare_returns_pos_int_if_left_string_is_bigger,
        test_kmantill_init_c_string_my_string_compare_returns_negative_int_if_left_string_is_bigger,
        test_kmantill_init_default_push_back_returns_success,
        test_kmantill_init_default_pop_back_returns_failure,
        test_kmantill_init_c_string_push_back_returns_success,
        test_kmantill_init_c_string_pop_back_returns_success,
        test_kmantill_init_default_push_back_and_my_string_at_returns_correct_char,
        test_kmantill_init_default_push_back_and_my_string_at_returns_NULL_if_index_is_out_of_bounds,
        test_kmantill_init_default__my_string_at_returns_NULL_if_empty_data,
        test_kmantill_init_c_string_my_string_at_returns_correct_char,
        test_kmantill_init_c_string_my_string_at_returns_NULL_when_index_is_out_of_bounds,
        test_kmantill_init_default_push_back_and_my_string_c_str_returns_correct_string,
        test_kmantill_init_default_push_back_and_my_string_c_str_returns_correct_string_max_size,
        test_kmantill_init_default_my_string_c_str_returns_NULL_when_data_is_empty,
        test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty,
    };

    int number_of_functions = sizeof(tests) / sizeof(tests[0]);
    int i;
    char buffer[500];
    int success_count = 0;
    int failure_count = 0;

    for (i=0; i<number_of_functions; i++) {
        if(tests[i](buffer, 500) == FAILURE) {
            printf("FAILED: Test %d failed.\n", i);
            printf("%s\n", buffer);
            failure_count++;
        } else {
            printf("SUCCESS: Test %d succeeded.\n", i);
            printf("%s\n", buffer); success_count++;
        }
    }

    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
    return 0;
}