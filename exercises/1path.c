#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    char *path = _getenv("PATH");
    int i, length = strlen(path) -1;
    for(i=0;i<=length;i++){
        if (path[i] == ':')
            path[i] = '\n';
        printf("%c",path[i]);
    }
    printf("\n");
    return 0;
}
