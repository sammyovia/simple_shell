#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/**
 * @**lsh_split_line - Split a line into tokens
 * @line - The line.
 * @return - Null-terminated array of tokens.
 * @sh_loop - loops through the input cmds             * @line - collect line variable
 */
char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
/** getting executing input
 * @sh_loop - loops through the input cmds
 * @line - collect line variable
 */
void sh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("($) ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

char *lsh_read_line(void)
{                                                     #ifdef LSH_USE_STD_GETLINE                              char *line = NULL;
  ssize_t bufsize = 0; /* have getline allocate a buff
er for us*/
  if (getline(&line, &bufsize, stdin) == -1) {            if (feof(stdin)) {
      exit(EXIT_SUCCESS);  /* We received an EOF*/        } else  {                                               perror("lsh: getline\n");
      exit(EXIT_FAILURE);
    }
  }
  return line;
#else
#define LSH_RL_BUFSIZE 1024
int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }                                                                                                           while (1) {                                             /* Read a character*/
    c = getchar();

    if (c == EOF) {                                         exit(EXIT_SUCCESS);
    } else if (c == '\n') {                                 buffer[position] = '\0';                              return buffer;
    } else {
	    buffer[position] = c;
    }
    position++;
    /* If we have exceeded the buffer, reallocate.*/
    if (position >= bufsize)
    {
	    bufsize += LSH_RL_BUFSIZE;
	    buffer = realloc(buffer, bufsize);
	    if (!buffer)
	    {
		    fprintf(stderr, "lsh: allocation error\n");
		    exit(EXIT_FAILURE);
	    }
    }
  }
#endif
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/**
   @brief Split a line into tokens (very naively).
   @param line The line.
   @return Null-terminated array of tokens.
 */
char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {                                          fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {                              bufsize += LSH_TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
                free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
  /* Load config files, if any.*/

  /* Run command loop.*/
  sh_loop();

  /* Perform any shutdown/cleanup.*/

  return EXIT_SUCCESS;
}
