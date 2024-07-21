#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>

/*int main() {
    char *input;
    input = readline("Enter a line of text: ");
    printf("You entered: %s\n", input);
    rl_replace_line("This is the new line", 0);
	usleep(1000000);
    rl_redisplay();
	usleep(1000000);
    input = readline("Enter another line of text: ");
    printf("You entered: %s\n", input);
    return 0;
}
*/

#include <stdio.h>
#include <readline/readline.h>

int main() {
    char *input = "";
    char *new_line = "This is the new line content";

    // get initial input
    input = readline("Enter some text: ");
    printf("Original input: %s\n", input);

    // replace the current line with new content
    rl_replace_line(new_line, 0);
    printf("New input: %s\n", rl_line_buffer);

    return 0;
}


/* NOTES

gcc readline.c -lreadline

*/