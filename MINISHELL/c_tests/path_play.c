#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() 
{
// name of the environment
const char* env_variable = "PATH";
// Retrieve the value
char* value = getenv(env_variable);

if (value != NULL)
	printf("Variable = %s \n%s", env_variable, value);
else
	perror("");
return (0);
}
