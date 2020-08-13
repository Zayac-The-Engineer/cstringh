#ifndef STR_Z
#define STR_Z

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string
{
	size_t capacity;
	size_t len;
	char* data;
};
typedef struct string string;

string* str_create(const char* str);

char* str_get_data(const string* s);

void str_push_back(string* s, char c);

string* str_join(const string* s, const char* c);

string* str_input();

void str_destroy(string* s);

//char str_get_element(const string* s, const size_t i);

#endif
