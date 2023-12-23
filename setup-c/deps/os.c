#include "../lib/os.h"
#include <stdio.h>
#include <stdlib.h>
int os(){
  int os;
  if (system("pacman -V >> /dev/null") == 0) {
    os = 1;
  } else if (system("apt -v >> /dev/null") == 0) {
    os = 2;
  }
  if (os == 0) {
    printf("you are on an operating system this script doesn't work with sorry "
           "exitting:\n");
    exit(1);
  }
return os;
}
