/**
 * Filename: pinfo.c
 * Assignment: Lab 9
 * Section: 111
 * Author: Quinn Lindgren
 * Date: 10/30/25
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    errno = 0;
    if(argc == 2){
        pid_t pid = atoi(argv[1]);
        int prio = getpriority(PRIO_PROCESS, pid);
        if(errno == 0){
            printf("Process identifier: %d\n", pid);
            printf("Process priority: %d\n", prio);
            int method = sched_getscheduler(pid);
            printf("Scheduling method: ");
            switch (method) {
                case SCHED_OTHER:
                    printf("SCHED_OTHER\n");
                    break;
                case SCHED_FIFO:
                    printf("SCHED_FIFO\n");
                    break;
                case SCHED_RR:
                    printf("SCHED_RR\n");
                    break;
                default:
                    printf("Unknown (%d)\n", method);
                    break;
            }
        } else{
            fprintf(stderr, "invalid process identifier\n");
        }
    } else if(argc == 1){
        pid_t pid = getpid();
        printf("Process identifier: %d\n", pid);
        printf("Process priority: %d\n", getpriority(PRIO_PROCESS, pid));
        int method = sched_getscheduler(pid);
        printf("Scheduling method: ");
        switch (method) {
            case SCHED_OTHER:
                printf("SCHED_OTHER\n");
                break;
            case SCHED_FIFO:
                printf("SCHED_FIFO\n");
                break;
            case SCHED_RR:
                printf("SCHED_RR\n");
                break;
            default:
                printf("Unknown (%d)\n", method);
                break;
        }
    } else{
        fprintf(stderr, "too many arguments\n");
    }
    return 0;
}