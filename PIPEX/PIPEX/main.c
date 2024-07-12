#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int fds[2];                      
  pipe(fds);                      
  pid_t pid = fork();              
  

  //TODO HIJO 
  if (pid == 0) 
  {                  
    dup2(fds[0], STDIN_FILENO);    
    close(fds[0]);                 
    close(fds[1]);                
    char *argv[] = {(char *)"sort", NULL};   
    if (execvp(argv[0], argv) < 0) exit(0);  
  }

 //TODO PADRE
  close(fds[0]);              
  const char *words[] = {"pear", "peach", "apple"};
  size_t numwords = sizeof(words)/sizeof(words[0]);
  for (size_t i = 0; i < numwords; i++) {
    dprintf(fds[1], "%s\n", words[i]); 
  }
  close(fds[1]); 
  int status;
  pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
  return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}

//Recebir Entrada!!
//file_not_found / Permisos
//command_not found
//Para uno commando. Y para 2 mas?
//Differencia execve???
//Salida Padre No
