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

    printf("Connected to VCS Server...\n");
    
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

        if (strstr(commandBuffer, "exit")){
            break;
        }

        if (!fork()){
            commandStatus = execute(commandBuffer);
            if (commandStatus == -1){
                printf("Command not found\n");
            }
            exit(0);
        }

        wait(NULL);
        memset(commandBuffer, 0, len);

    }
    return 0;
}