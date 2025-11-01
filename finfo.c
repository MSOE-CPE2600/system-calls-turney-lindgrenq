/**
 * Filename: finfo.c
 * Assignment: Lab 9
 * Section: 111
 * Author: Quinn Lindgren
 * Date: 10/30/25
 */

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if(argc == 2){
        struct stat info;
        printf("Type: ");
        if(stat(argv[1], &info) == 0){
            if (S_ISREG(info.st_mode)) {
                printf("regular file\n");
            } else if (S_ISDIR(info.st_mode)) {
                printf("directory\n");
            } else if (S_ISCHR(info.st_mode)) {
                printf("character device\n");
            } else if (S_ISBLK(info.st_mode)) {
                printf("block device\n");
            } else if (S_ISFIFO(info.st_mode)) {
                printf("FIFO\n");
            } else if (S_ISLNK(info.st_mode)) {
                printf("symbolic link\n");
            } else if (S_ISSOCK(info.st_mode)) {
                printf("socket\n");
            } else {
                printf("unknown type\n");
            }
            printf("Permissions: \n");
            if (info.st_mode & S_IRUSR){
                printf("    Owner has read permission\n");
            }
            if (info.st_mode & S_IWUSR){
                printf("    Owner has write permission\n");
            }
            if (info.st_mode & S_IXUSR){
                printf("    Owner has execute permission\n");
            }
            if (info.st_mode & S_IRGRP){ 
                printf("    Group has read permission\n");
            }
            if (info.st_mode & S_IWGRP){ 
                printf("    Group has write permission\n");
            }
            if (info.st_mode & S_IXGRP){ 
                printf("    Group has execute permission\n");
            }
            if (info.st_mode & S_IROTH){
                printf("    Others have read permission\n");
            }
            if (info.st_mode & S_IWOTH){ 
                printf("    Others have write permission\n");
            }
            if (info.st_mode & S_IXOTH){ 
                printf("    Others have execute permission\n");
            }
            if (info.st_mode & S_ISUID){ 
                printf("    Set-UID bit is set\n");
            }
            if (info.st_mode & S_ISGID){
                printf("    Set-GID bit is set\n");
            }
            if (info.st_mode & S_ISVTX){
                printf("    Sticky bit is set\n");
            }
            printf("File owner uid: %d\n", info.st_uid);
            printf("File size: %ld bytes\n", info.st_size);
            // last modification
            char buffer[50];
            struct tm *time = localtime(&info.st_mtime);
            strftime(buffer, sizeof(buffer), "%c", time);
            printf("Last modification: %s\n", buffer);
        } else{
            fprintf(stderr, "error reading file\n");
        }
    } else{
        fprintf(stderr, "invalid arguments\n");
    }
    return 0;
}