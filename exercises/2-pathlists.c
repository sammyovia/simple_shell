#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "main.h" 



typedef struct Node
{
    char *str;
    struct Node *next;
} Node_p;

/* To tokenize the pathname*/

char *strtok(char *str, const char *delim)
{
	char stn[] = {_getenv("PATH")};
	const char s[] = ":";
	char *tok; 

	tok = strtok(stn, s);

	while (tok != NULL)
	{
		tok = strtok(NULL, s);
	}
	return (0);
}


/* To creste the linked list from the tokenized path*/

Node_p *_pathlist(char *path)
{
	char *token = NULL;
	Node_p *head;
	Node_p *pathnode;

	if (path == NULL)
		return (NULL);

	head = NULL;
	pathnode = malloc(sizeof(Node_p));
	if (pathnode == NULL)
		return (NULL);

	token = _strtok();
	pathnode->str = token;
	pathnode->next = head;
	head = pathnode;

	while (token != NULL)
	{
		pathnode = malloc(sizeof(Node_p)); 
        if (pathnode == NULL) 
            return (NULL);
        pathnode->str = token; 
        pathnode->next = head;
        head = pathnode;
    }
    return (head);
	
}


/* print the list*/

#include<stdio.h>
        #include<stdlib.h>

        int main ()
        {
                char * ptr_path;
                ptr_path = _getenv("PATH");

                if (ptr_path!=NULL)
                        printf ("The set PATH is: %s\n",ptr_path);
                else
                        printf("Nothing to show\n");

                return 0;
        }
