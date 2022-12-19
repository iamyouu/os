/* ********************************
   ****     System calls       ****
   ******************************** */
  
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[18] = "This is a mess";
    char buf1[18];

    // Creates file0 if not exists, and opens in Read/Write mode   
    int fd = open("file", O_CREAT | O_RDWR);
    chmod("file", S_IRWXU);
    printf("Set Read+Write+Execute permission to file owner uschmod() \n");
    printf("Written %ld bytes into file\n", write(fd, buf, 18));  
  // seeks to the start of the file
  // SEEK_SET for absolute file positioning
  // SEEK_CUR for file positioning relative to current positon    
    lseek(fd , 0, SEEK_SET);

  // reads content of file fd into buf1
    printf("Read %ld bytes into the buffer\n", read(fd, buf1, 18));
    printf("%s \n", buf1);
    close(fd);  
    unlink("file"); 
    printf("Deleted the file using unlink() \n");
}
