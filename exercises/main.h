#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

char *_getenv(const char *name);
char *_strtok(char *str, const char *delim);

#endif /* MAIN_H */
