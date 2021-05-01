#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <zmq.h>
#include <assert.h>
#include "backend.h"

int main(void){

    void *context = zmq_ctx_new();
    void *responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");
    assert(rc == 0);
    
    while (1){
        
        // Receive Length of command
        int lenBuffer[1];
        zmq_recv(responder, lenBuffer, 1, 0);
        printf("Length: %d\n", lenBuffer[0]);
        int len = lenBuffer[0];
        memset(lenBuffer, 0, 1);
        sleep(1);
        zmq_send(responder, "Length Received", 15, 0);

        // Receive Command
        char commandBuffer[len];
        zmq_recv(responder, commandBuffer, len, 0);
        printf("Command: %s\n", commandBuffer);
        zmq_send(responder, "Command Received", 16, 0);
        
        char path[9] = "/usr/bin/";
        int commandStatus;

        if (!fork()){
            // commandStatus = execlp(commandBuffer, commandBuffer, /*"-l", "-a",*/ "/home/", (char *)NULL);
            commandStatus = execute(commandBuffer);
            exit(0);
        }
        wait(NULL);
        memset(commandBuffer, 0, len);
        printf("Command Status: %d\n", commandStatus);

    }
    return 0;
}

char* getCommand(){
    
}