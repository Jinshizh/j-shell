#include "include/j-shell.h"
#include <sys/wait.h>

int
main(void)
{
    char buf[MAXSIZE];
    pid_t pid;
    int status;

    printf("$j$");
    while (fgets(buf,MAXSIZE,stdin) != NULL) {
        if (buf[strlen(buf)-1] == '\n') {
            buf[strlen(buf) -1] = 0;
        } 
        if (pid = fork() < 0) {
           err_sys("fork error");    
        } else if (pid == 0) {
            //child
            execlp(buf, buf, (char *)0);
            err_ret("exec err\n");
            exit(127);
        }
        //parent
        if (pid = waitpid(pid, &status, 0) < 0) {
            err_sys("wait err");
        }
        printf("$j$");
    }
}
