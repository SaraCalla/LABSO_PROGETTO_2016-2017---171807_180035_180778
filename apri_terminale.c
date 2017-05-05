    #define _XOPEN_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
   // #include "pwdblib.h"   /* include header declarations for pwdblib.c */
     #include <pwd.h>
     #include <unistd.h>
    #define _XOPEN_SOURCE       /* See feature_test_macros(7) */
    #include <unistd.h>



    /* Define some constants. */
    #define USERNAME_SIZE (32)
    #define NOUSER (-1)

  


    int main(int argc, char **argv)
    {
      char username[USERNAME_SIZE];
      char *inputpwd;
    int login = 0;
      int pwd_failed;       // Failed login counter
      int pwd_age;  // age of password counter

        
       
        pid_t pid;
        int status;

        pid = fork();

        if (pid==0)
         {
            /* This is the child process. Run an xterm window */
           execl("/usr/bin/gnome-terminal", "gnome-terminalx", "-e", "./patata", NULL);

            /* if child returns we must inform parent.
             * Always exit a child process with _exit() and not return() or exit().
             */
            _exit(-1);
        } else if (pid < 0) { /* Fork failed */
            printf("Fork faild\n");
            status = -1;
        } else {
            /* This is parent process. Wait for child to complete */
            if (waitpid(pid, &status, 0) != pid) {
            status = -1;
            }
        }

    }
