#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "my_string.h"

struct my_string {
	int size;
	int capacity;
	char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void) {
	My_string* pString = (My_string*)malloc(sizeof(My_string));
	if (pString != NULL) {
		pString->size = 0;
		pString->capacity = 7;
		pString->data = (char*)malloc(sizeof(char) * pString->capacity);
		if (pString->data == NULL) {
			free(pString->data);
			free(pString);
			return NULL;
		}
	}
	return (MY_STRING)pString;
}

MY_STRING my_string_init_c_string(const char* c_string) {
	My_string* pString = (My_string*)malloc(sizeof(My_string));
	if (c_string) {
		// good
	} else {
		exit(EXIT_FAILURE);
	}
	if (pString != NULL) {
		int i = 0;
		while (c_string[i] != '\0') {
			i++;
		}
		// printf("size is %d\n", i);
		pString->size = i;
		pString->capacity = i + 1;
		// printf("c string index 0 is %c\n", c_string[0]);
		pString->data = (char*) malloc(sizeof(char) * pString->capacity);
		// pString->data = c_string; // this works
		
		for (int j = 0; j < i; j++) {
			pString->data[j] = c_string[j];
		}

		// printf("pString data is %s\n", pString->data);
		if (pString->data == NULL) {
			printf("data is null\n");
			free(pString->data);
			free(pString);
			return NULL;
		}
	}
	return (MY_STRING)pString;
}

/*
void my_string_destroy(MY_STRING* phMy_string) {
	// printf("in my string destroy\n");
	// check precondition !
	if (phMy_string) {
		// good
		My_string* pString = (My_string*)*phMy_string;
		free(pString->data);
		free(pString);
		*phMy_string = NULL;
	} else {
		// bad
	}
}
*/

void my_string_destroy(Item* pItem) {
	if (pItem) {
		// good
		My_string* pString = (My_string*)*pItem;
		free(pString->data);
		free(pString);
		*pItem = NULL;
	} else {
		// bad
	}
}

int my_string_get_capacity(MY_STRING hMy_string) {
	// check precondition !
	if (hMy_string) {
		// good
	} else {
		exit(EXIT_FAILURE);
	}
	My_string* pString = (My_string*)hMy_string;
	return pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string) {
	// check precondition !
	if (hMy_string) {
		// good
	} else {
		exit(EXIT_FAILURE);
	}
	My_string* pString = (My_string*)hMy_string;
	return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
	if (hLeft_string && hRight_string) {
		// good
	} else {
		exit(EXIT_FAILURE);
	}
	My_string* pStringL = (My_string*)hLeft_string;
	My_string* pStringR = (My_string*)hRight_string;
	int pStringLsize = pStringL->size;
	int pStringRsize = pStringR->size;
	return pStringLsize - pStringRsize;
}

Status my_string_push_back(MY_STRING hMy_string, char item) {
	if (hMy_string) {
		// good
		My_string* pString = (My_string*)hMy_string;
		if (pString->size >= pString->capacity) {
			// Array is full
			char* temp = (char*)malloc(sizeof(char) * (pString->capacity * 2));
			if (temp == NULL) {
				return FAILURE;
			}
			for (int i = 0; i < pString->size; i++) {
				temp[i] = pString->data[i];
			}
			free(pString->data);
			pString->data = temp;
			pString->capacity *= 2;
		}
		pString->data[pString->size] = item;
		pString->size++;
		return SUCCESS;
	} else {
		return FAILURE;
	}
}

Status my_string_pop_back(MY_STRING hMy_string) {
	if (hMy_string) {
		My_string* pString = (My_string*)hMy_string;
		if (pString->size <= 0) return FAILURE;
		pString->size--;
		return SUCCESS;
	}
	
	return FAILURE;
}

char* my_string_at(MY_STRING hMy_string, int index) {
	if (hMy_string) {
		My_string* pString = (My_string*)hMy_string;
		if (pString) {
			// maybe check if data is here
			if (index >= pString->size) return NULL;
			/*char* c = (char*)malloc(sizeof(char) * 1);
			c[0] = pString->data[index];
			printf("HAHA %s\n", c);
			return c;*/

			return &(pString->data[index]);
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}

char* my_string_c_str(MY_STRING hMy_string) {
	if (hMy_string) {
		My_string* pString = (My_string*)hMy_string;
		if (pString) {
			// maybe check if data is here
			/*
			char* str = (char*)malloc(sizeof(char) * pString->size + 1);
			int i;
			for (i = 0; i < pString->size; i++) {
				str[i] = pString->data[i];
				// printf("%c ", str[i]);
			}
			str[i + 1] = '\0';
			// printf("\n");
			return str;
			*/
			if (pString->size == 0) return NULL;
			if (pString->size == pString->capacity) {
				char* temp = (char*)malloc(sizeof(char) * (pString->capacity + 1));
				for (int i = 0; i < pString->size; i++) {
					temp[i] = pString->data[i];
				}
				temp[pString->size] = '\0';
				free(pString->data);
				pString->data = temp;
			} else {
				pString->data[pString->size] = '\0';
			}
			
			return &(pString->data[0]);
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
	if (hResult && hAppend) {
		My_string* pResult = (My_string*)hResult;
		My_string* pAppend = (My_string*)hAppend;
		if (pResult && pAppend) {
			int size = pResult->size + pAppend->size;
			char* string = (char*)malloc(sizeof(char) * size);
			for (int i = 0; i < pResult->size; i++) {
				string[i] = pResult->data[i];
			}
			for (int i = pResult->size; i < size; i++) {
				string[i] = pAppend->data[i - pResult->size];
			}
			free(pResult->data);
			pResult->data = string;
			pResult->size = pResult->size + pAppend->size;
			pResult->capacity = pResult->capacity + pAppend->capacity;

			return SUCCESS;
		}

		return FAILURE;
	}

	return FAILURE;
}

Boolean my_string_empty(MY_STRING hMy_string) {
	if (hMy_string) {
		My_string* pString = (My_string*)hMy_string;
		if (pString->size == 0) {
			return TRUE;
		}

		return FALSE;
	}

	return FALSE;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
	if (hMy_string) {
		// good
	} else {
		return FAILURE;
	}
	if (feof(fp)) {
		return FAILURE;
	}
	My_string* pString = (My_string*)hMy_string;
	// free data which is string
	if (pString) {
		if (pString->data) {
			free(pString->data);
			pString->data = (char*)malloc(sizeof(char) * pString->capacity);
			pString->size = 0;
		} else {
			return FAILURE;
		}
	} else {
		return FAILURE;
	}

	// grab a char from file
	char curr = fgetc(fp);

	// ignoring leading whitespace
	// while (curr == ' ' || curr == '\t' || curr == '\r' || curr == '\n' || curr == '\v' || curr == '\f') {
	while (isspace(curr) && curr) {
		// do nothing
		curr = fgetc(fp);
	}

	// found first non-whitespace char
	if (isalnum(curr) == 0) return FAILURE;
	// printf("%c", curr);
	Status status = my_string_push_back(pString, curr);
	if (status == FAILURE) return FAILURE;

	// get first char after first non-whitespace char
	curr = fgetc(fp);

	// get char from FILE* until whitespace char is found
	// check if current char is not whitespace AND if it is alphanumeric or if it is a comma, period, semicolon..
	while ((isspace(curr) == 0) && (isalnum(curr) || curr == ',' || curr == '.' || curr == ';') && curr) {
		// must check if curr is true
		if (curr) {
			// good
		} else if (curr == EOF) {
			break;
		} else {
			break;
		}
		// must check if curr is not an acceptable char
		if (isspace(curr) == 0 && (isalnum(curr) || curr == ',' || curr == '.' || curr == ';')) {
			// good
			status = my_string_push_back(pString, curr);
			if (status == FAILURE) return FAILURE;
		} else {
			return FAILURE;
		}
		// printf("%c", curr);
		curr = fgetc(fp);
	}

	ungetc(curr, fp);

	// printf("string is %s\n", pString->data);

	if (pString->data) {
		return SUCCESS;
	} else {
		return FAILURE;
	}
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
	if (hMy_string) {
		// good
	} else {
		return FAILURE;
	}
	My_string* pString = (My_string*)hMy_string;
	if (pString) {
		if (pString->data) {
			for (int i = 0; i < pString->size; i++) {
				/*
				if (isspace(pString->data[i]) == 0 && (isalnum(pString->data[i]) || pString->data[i] == ',' || pString->data[i] == '.' || pString->data[i] == ';')) {
					fputc(pString->data[i], fp);
				} else {
					return FAILURE;
				}
				*/
				fputc(pString->data[i], fp);
			}
		} else {
			return FAILURE;
		}
	} else {
		return FAILURE;
	}

	return SUCCESS;
}

void my_string_assignment(Item* pLeft, Item Right) {
	if ((*pLeft || *pLeft == NULL) && Right) {
		if (*pLeft == NULL) {
			My_string* pString = my_string_init_default();
			My_string* copy = (My_string*)Right;
			Status status;

			char* dataCopy = copy->data;
			// printf("%s\n", dataCopy);

			for (int i = 0; i < copy->capacity; i++) {
				status = my_string_push_back(pString, dataCopy[i]);
				if (status == FAILURE) break;
			}

			*pLeft = pString;
		} else {
			My_string* pString = (My_string*)*pLeft;
			My_string* copy = (My_string*)Right;
			Status status;

			char* dataCopy = copy->data;

			for (int i = 0; i < copy->capacity; i++) {
				status = my_string_push_back(pString, dataCopy[i]);
				if (status == FAILURE) break;
			}

			*pLeft = pString;
		}
	}
}

int order_str(MY_STRING hLeft_string, MY_STRING hRight_string) {
    My_string* leftString = (My_string*)hLeft_string;
    My_string* rightString = (My_string*)hRight_string;

    if (leftString && rightString) {
        char* leftChar = my_string_at(leftString, 0);
        char* rightChar = my_string_at(rightString, 0);

        int size1 = my_string_get_size(leftString);
        int size2 = my_string_get_size(rightString);

        int size;

        if (size1 > size2) size = size2;
        else size = size1;

        for (int i = 0; i < size; i++) {
            if (leftChar[i] != rightChar[i]) { // check if they are not the same
                return (int)leftChar[i] - (int)rightChar[i];
            }
        }

        // at this point, it's the same but a string could be longer
        if (size1 > size2) return 1;
        else if (size1 < size2)return -1;
        else return 0;
    }

    return 0;
}

int order_str_ignore_case(MY_STRING hLeft_string, MY_STRING hRight_string) {
    My_string* leftString = (My_string*)hLeft_string;
    My_string* rightString = (My_string*)hRight_string;

    if (leftString && rightString) {
        char* leftChar = my_string_at(leftString, 0);
        char* rightChar = my_string_at(rightString, 0);

        int size1 = my_string_get_size(leftString);
        int size2 = my_string_get_size(rightString);

        int size;

        if (size1 > size2) size = size2;
        else size = size1;

        for (int i = 0; i < size; i++) {
            char left = leftChar[i];
            char right = rightChar[i];
            if (isupper(left) != 0) left = (char)((int)left + 32);
            if (isupper(right) != 0) right = (char)((int)right + 32);
            if (left != right) { // check if they are not the same
                return (int)left - (int)right;
            }
        }

        // at this point, it's the same but a string could be longer
        if (size1 > size2) return 1;
        else if (size1 < size2)return -1;
        else return 0;
    }

    return 0;
}