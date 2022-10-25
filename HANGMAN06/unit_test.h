#pragma once
#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_kmantill_init_default_destroy(char* buffer, int length);
Status test_kmantill_init_c_string_destroy(char* buffer, int length);
Status test_kmantill_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_kmantill_init_c_string_correct_size_and_capacity(char* buffer, int length);
Status test_kmantill_init_default_my_string_compare_returns_0_if_strings_are_the_same(char* buffer, int length);
Status test_kmantill_init_default_push_back_my_string_compare_returns_0_if_strings_are_the_same(char* buffer, int length);
Status test_kmantill_init_default_push_back_my_string_compare_returns_pos_int(char* buffer, int length);
Status test_kmantill_init_default_push_back_my_string_compare_returns_negative_int(char* buffer, int length);
Status test_kmantill_init_c_string_my_string_compare_returns_0_if_strings_are_the_same(char* buffer, int length);
Status test_kmantill_init_c_string_my_string_compare_returns_pos_int_if_left_string_is_bigger(char* buffer, int length);
Status test_kmantill_init_c_string_my_string_compare_returns_negative_int_if_left_string_is_bigger(char* buffer, int length);
Status test_kmantill_init_default_push_back_returns_success(char* buffer, int length);
Status test_kmantill_init_default_pop_back_returns_failure(char* buffer, int length);
Status test_kmantill_init_c_string_push_back_returns_success(char* buffer, int length);
Status test_kmantill_init_c_string_pop_back_returns_success(char* buffer, int length);
Status test_kmantill_init_default_push_back_and_my_string_at_returns_correct_char(char* buffer, int length);
Status test_kmantill_init_default_push_back_and_my_string_at_returns_NULL_if_index_is_out_of_bounds(char* buffer, int length);
Status test_kmantill_init_default__my_string_at_returns_NULL_if_empty_data(char* buffer, int length);
Status test_kmantill_init_c_string_my_string_at_returns_correct_char(char* buffer, int length);
Status test_kmantill_init_c_string_my_string_at_returns_NULL_when_index_is_out_of_bounds(char* buffer, int length);
Status test_kmantill_init_default_push_back_and_my_string_c_str_returns_correct_string(char* buffer, int length);
Status test_kmantill_init_default_push_back_and_my_string_c_str_returns_correct_string_max_size(char* buffer, int length);
Status test_kmantill_init_default_my_string_c_str_returns_NULL_when_data_is_empty(char* buffer, int length);
Status test_kmantill_init_c_string_pop_all_chars_and_my_string_c_str_returns_NULL_when_data_is_empty(char* buffer, int length);
Status test_kmantill_100_elements_copied(char* buffer, int length);

#endif