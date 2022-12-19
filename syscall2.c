/* ********************************
   ****   Stat System calls    ****
   ******************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./a.out filePath");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file!");
        return 1;
    }
    struct stat statData;
    fstat(fd, &statData);
    printf("User ID: %d \t Group ID: %d \n", statData.st_uid, statData.st_gid);
    printf("Hard Links: %d \t Inode: %d \n", statData.st_nlink, statData.st_ino);
    printf("Size: %d Bytes \t Last Accessed: %d \n", statData.st_size, statData.st_atime);
    printf("File Type: ");
    if (S_ISREG(statData.st_mode))
        printf("Regular");
    else if (S_ISDIR(statData.st_mode))
        printf("Directory");
    else if (S_ISCHR(statData.st_mode))
        printf("Character");
    else if (S_ISBLK(statData.st_mode))
        printf("Block");
    putchar('\n');
    return 0;
}