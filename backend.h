#include <stdio.h>
#include <string.h>
#include <unistd.h>

int execute(char* command){
    int status = -1;
    if (strstr(command, "list files of current directory")){
        status = execlp("ls", "ls", ".", (char *)NULL);
    } else if (strstr(command, "list files of root directory")){
        status = execlp("ls", "ls", "/", (char *)NULL);
    } else if (strstr(command, "list files of home directory")){
        status = execlp("ls", "ls", "/home/", (char *)NULL);
    } else if (strstr(command, "disk usage")){
        status = execlp("df", "df", "-h", (char *)NULL);
    } else if (strstr(command, "open firefox")){
        status = execlp("firefox", "firefox", (char *)NULL);
    } else if (strstr(command, "")){

    } else if (strstr(command, "list")){

    } else if (strstr(command, "list")){

    } else if (strstr(command, "list")){

    } else if (strstr(command, "list")){

    } else if (strstr(command, "list")){

    }


    return status;
}