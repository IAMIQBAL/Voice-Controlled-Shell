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
    } else if (strstr(command, "network information")){
        status = execlp("ifconfig", "ifconfig", (char *)NULL);
    } else if (strstr(command, "change directory")){
        status = execlp("cd", "cd", "../", (char *)NULL);
    } else if (strstr(command, "make file named")){
        char *word = strrchr(command, ' ') + 1;
        status = execlp("touch", "touch", word, (char *)NULL);
    } else if (strstr(command, "find")){
        char *word = strrchr(command, ' ') + 1;
        status = execlp("find", "find", "/home/", "-type", "f", "-iname", word, (char *)NULL);
    } else if (strstr(command, "restart")){
        status = execlp("shutdown", "shutdown", "-r", "now", (char *)NULL);
    } else if (strstr(command, "shutdown")){
        status = execlp("shutdown", "shutdown", "now", (char *)NULL);
    } else if (strstr(command, "remove file named")){
        char *word = strrchr(command, ' ') + 1;
        status = execlp("rm", "rm", "-rf", word, (char *)NULL);
    } else if (strstr(command, "go to")){
        char *word = strrchr(command, ' ') + 1;
        status = execlp("firefox", "firefox", "-new-tab", word, (char *)NULL);
    } else if (strstr(command, "search")){
        char *word = strrchr(command, ' ') + 1;
        char *site = "http://www.google.com/search?q=";
        char *result = malloc(strlen(word) + strlen(site) + 1);
        strcpy(result, site);
        strcat(result, word);
        status = execlp("firefox", "firefox", "-new-tab", result, (char *)NULL);
    } else if (strstr(command, "get username")){
        char *word = strrchr(command, ' ') + 1;
        status = execlp("Scripts/getuname.sh", "Scripts/getuname.sh", word, (char *)NULL);
    } else if (strstr(command, "uptime")){
        status = execlp("uptime", "uptime", "-p", (char *)NULL);
    } else if (strstr(command, "users currently logged in")){
        status = execlp("who", "who", (char *)NULL);
    } else if (strstr(command, "current user")){
        status = execlp("whoami", "whoami", (char *)NULL);
    } else if (strstr(command, "print the date")){
        status = execlp("date", "+%c", (char *)NULL);
    } else if (strstr(command, "gedit")){
        char *word = strrchr(command, ' ') + 1;
        status = execlp("gedit", word, (char *)NULL);
    }

    return status;
}