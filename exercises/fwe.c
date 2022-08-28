
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

  

int main() 
{ 
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    for(int i=0;i<5;i++) // loop will run n times (n=5) 

    { 
 
        if(fork() == 0) 

        {
		execve(argv[0], argv, NULL);
		printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid()); 

            exit(0); 

        } 

    } 

    for(int i=0;i<5;i++) // loop will run n times (n=5) 

    wait(NULL); 

      
}
