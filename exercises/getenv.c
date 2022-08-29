#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int main (void) {

	char *_getenv(const char *name)
	{
		printf("PATH : %s\n", _getenv("PATH"));
		return (0);
	}
}
