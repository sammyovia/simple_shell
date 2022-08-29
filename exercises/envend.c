



char **pp = environ;
for( ; *pp; pp++) {
   printf("%s\n", *pp);
} 
printf("The end of environ is %p\n", pp);
