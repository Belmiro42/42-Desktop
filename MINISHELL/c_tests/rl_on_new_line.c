#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>

// Global flag to indicate if the program should exit
volatile sig_atomic_t exit_flag = 0;

void handle_signal(int signal) {
    if (signal == SIGINT) {
        // Set the exit flag to indicate that the program should exit
        exit_flag = 1;
        // Print a new line to move the cursor to the next line
        printf("\n");
        // Reset the input line and redisplay the prompt
        rl_replace_line("", 0);
        rl_redisplay();
		exit(EXIT_FAILURE);
    }
}

int main(void) {
    // Register the signal handler for SIGINT
    signal(SIGINT, handle_signal);

    char *user_input;
    while (!exit_flag && (user_input = readline("WHATCHU WANT DADDY:\t")) != NULL) {
        if (*user_input) {  // Add non-empty input to history
            add_history(user_input);
        }
        printf("You entered: %s\n", user_input);
        free(user_input);  // Free the user input after use
    }

    rl_clear_history();  // Clear the history to avoid memory leaks
    printf("Exiting program\n");
    return 0;
}


/* NOTES

gcc readline.c -lreadline

*/