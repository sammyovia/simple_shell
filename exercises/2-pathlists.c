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


/* To creste the linked list from the tokenized path*/

Node_p *_pathlist(char *pathname, char  **pathcopy)
{
	char *token = NULL;
	Node_p *head;
	Node_p *pathnode;

	if (pathname == NULL)
		return (NULL);

	*pathcopy = strdup(pathname);

	head = NULL;
	pathnode = malloc(sizeof(Node_p));
	if (pathnode == NULL)
		return (NULL);

	token = strtok(*pathcopy, ":");
	pathnode->str = token;
	pathnode->next = head;
	head = pathnode;

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		if (token == NULL)
		{
			break;
		}
		pathnode = malloc(sizeof(Node_p)); 
        if (pathnode == NULL) 
            return (NULL);
        pathnode->str = token; 
        pathnode->next = head;
        head = pathnode;
    }
    return (head);
	
}

Node_p *displayList(char **pathcopy)
{
	char *getEnv;
    Node_p *pathDirs;

    getEnv = _getenv("PATH");
    pathDirs = _pathlist(getEnv, pathcopy);

    return (pathDirs);	

}

int main ()
        {
		char *pathcopy = getenv("PATH");
                Node_p *head;
                head = displayList(&pathcopy);

                if (head !=NULL)
		{
                        printf ("The Linked list is: %s\n", head->str);
			head = head->next;
		}
                else
                        printf("Nothing to show\n");

                return 0;
        }

