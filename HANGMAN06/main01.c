#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[]) {
	
	MY_STRING hMy_string = NULL;

	/*
	FILE* fp;

	hMy_string = my_string_init_default();
	
	fp = fopen("simple.txt", "r");

	while (my_string_extraction(hMy_string, fp)) {
		
		if (my_string_get_size(hMy_string) == 29) {
			my_string_insertion(hMy_string, stdout);
			printf("\n");
		}
		
		my_string_insertion(hMy_string, stdout);
		printf("\n");
		if(fgetc(fp) == ' ') {
			printf("Found a space after the string\n");
		}
	}
	*/

	hMy_string = my_string_init_c_string("this_is_string.");

	my_string_push_back(hMy_string, 't');

	my_string_push_back(hMy_string, 'o');

	my_string_push_back(hMy_string, '.');

	char* str = my_string_c_str(hMy_string);

	printf("my_string_c_str(): %s\n", str);

	str = NULL;

	printf("length: %d\n", my_string_get_size(hMy_string));
	my_string_pop_back(hMy_string);
	printf("length: %d\n", my_string_get_size(hMy_string));
	my_string_pop_back(hMy_string);
	printf("length: %d\n", my_string_get_size(hMy_string));

	my_string_push_back(hMy_string, 'i');
	my_string_push_back(hMy_string, 'n');
	my_string_push_back(hMy_string, '.');

	char* new_string = my_string_c_str(hMy_string);

	printf("my_string_c_str(): %s\n", new_string);

	char* c = my_string_at(hMy_string, 2);

	printf("my_string_at(): %c\n", c[0]);

	MY_STRING hMy_string01 = my_string_init_c_string("hello");
	MY_STRING hMy_string02 = my_string_init_c_string(", world!");

	char* str01 = my_string_c_str(hMy_string01);
	char* str02 = my_string_c_str(hMy_string02);

	printf("string01 is \"%s\"\n", str01);
	printf("string02 is \"%s\"\n", str02);

	my_string_concat(hMy_string01, hMy_string02);

	printf("concat called!\n");

	char* str03 = my_string_c_str(hMy_string01);

	printf("string01 is \"%s\"\n", str03);

	printf("length of string01: %d\n", my_string_get_size(hMy_string01));

	MY_STRING hMy_string03 = my_string_init_default();

	printf("is string03 empty?\n");

	if (my_string_empty(hMy_string03) == TRUE) printf("YES\n");
	else printf("NO\n");

	// free(str);

	// free(new_string);

	// free(c);

	// free(str01);
	// free(str02);
	// free(str03);

	my_string_destroy(&hMy_string);
	my_string_destroy(&hMy_string01);
	my_string_destroy(&hMy_string02);
	my_string_destroy(&hMy_string03);
	// fclose(fp);

	return 0;
}
