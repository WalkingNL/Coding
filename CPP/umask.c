/* CELEBU01

   This example will work only from C/MVS, not C++/MVS.

 */
// #define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
// #undef _POSIX_SOURCE
#include <stdio.h>

main() {
  int fd;
  mode_t oldmask;

  printf("Your old umask is %i\n",oldmask=umask(S_IRWXG));
  if ((fd = creat("umask.file", S_IRWXU|S_IRWXG|S_IRWXO)) < 0) {
        perror("creat() error");
    }
  else {
    printf("%d\n", S_IRWXU|S_IRWXG);
    system("ls -l umask.file");
    close(fd);
    unlink("umask.file");
  }
  umask(oldmask);
}
