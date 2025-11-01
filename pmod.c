/**
 * Filename: pmod.c
 * Assignment: Lab 9
 * Section: 111
 * Author: Quinn Lindgren
 * Date: 10/30/25
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    nice(10);

    struct timespec req = {1, 837272638};
    struct timespec rem;
    nanosleep(&req, &rem);
    printf("goodbye\n");
    return 0;
}