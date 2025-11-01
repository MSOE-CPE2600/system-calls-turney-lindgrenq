/**
 * Filename: info.c
 * Assignment: Lab 9
 * Section: 111 
 * Author: Quinn Lindgren
 * Date: 10/30/25
 */

#include <stdio.h>
#include <time.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    long long nanotime = (time.tv_sec * 1E9) + time.tv_nsec;
    printf("Time in nanoseconds: %lld\n", nanotime);

    struct utsname uname_data;
    uname(&uname_data);
    printf("Network name: %s\n", uname_data.nodename);
    printf("OS name: %s\n", uname_data.sysname);
    printf("OS release: %s\n", uname_data.release);
    printf("OS version: %s\n", uname_data.version);
    printf("Hardware type: %s\n", uname_data.machine);

    printf("Proccessors: %d\n", get_nprocs());

    long long total_mem = sysconf(_SC_PAGESIZE) * sysconf(_SC_PHYS_PAGES);
    printf("Total memory: %lld bytes\n", total_mem);
    long long free_mem = sysconf(_SC_PAGESIZE) * sysconf(_SC_AVPHYS_PAGES);
    printf("Free memory: %lld bytes\n", free_mem);
    return 0;
}