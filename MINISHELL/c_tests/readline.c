#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
	char *user_input;

	user_input = readline("WHATCHU WANT DADDY:\t");
    add_history(user_input);
	free(user_input);
	rl_clear_history();
	return(1);
}

/* NOTES

gcc readline.c -lreadline

*/