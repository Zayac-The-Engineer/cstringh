#ifndef STR_Z
#define STR_Z

#include <stdlib.h>
#include <string.h>

typedef struct string
{
	size_t capacity;
	size_t len;
	char* data;
} string;

string* createString(const char* str)
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

char* getStrData(const string* s)
{
	return s->data;
}

char* strrealloc(string* s)
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

void strpush_back(string* s, char c)
{
	char* data = (strlen(s->data)+1 != sizeof(s)) ? s->data : strrealloc(s);
	data[s->len++] = c;
	data[s->len] = '\0';
}

string* strjoin(const string* s, char* c)
{
	string* result = createString(NULL);
	result->data = strcat(s->data, c);

	return result;
}

string* strinput(string* s)
{
	char i;
	while(i!='\n')
	{
		i=getchar();
		strpush_back(s, i);
	}
	return s;
}
#endif
