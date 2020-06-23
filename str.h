#ifndef STR_Z
#define STR_Z

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
	size_t capacity;
	size_t len;
	char* data;
} string;

string* str_create(const char* str)
{
	string* s = malloc(sizeof(string));

	size_t strLength = 0;

	if (str!=NULL)
	{
		size_t strLength = strlen(str);
		memcpy(s->data, str, strLength);
	}
	s->capacity = strLength + 1;
	s->data = (char*)malloc(s->capacity);
	s->data[strLength] = '\0';
	s->len = 0;

	return s;
}

char* str_get_data(const string* s)
{
	return s->data;
}

char* str_realloc(string* s)
{
	s->capacity *= 2;
	char* newdata = (char*)malloc(s->capacity);
	memcpy(newdata, s->data, s->len);
	if(s->data != NULL)
	{
		free(s->data);
	}
	s->data = newdata;

	return newdata;
}

void str_push_back(string* s, char c)
{
	char* data = (strlen(s->data)+1 != sizeof(s)) ? s->data : str_realloc(s);
	data[s->len++] = c;
	data[s->len] = '\0';
}

string* str_join(const string* s, char* c)
{
	string* result = str_create(NULL);
	result->data = strcat(s->data, c);

	return result;
}

string* str_input()
{
	char i;
	string* s = str_create(NULL);
	while(i!='\n')
	{
		i=getchar();
		str_push_back(s, i);
	}
	return s;
}
#endif
