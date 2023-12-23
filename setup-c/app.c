#include "lib/connected.h"
#include "lib/essentials.h"
#include "lib/instnvim.h"
#include "lib/instzsh.h"
#include "lib/os.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // checks if we are connected.If not it exits with 1
  connected();

  // declare selection as int
  int selection;

  // use the os function from os.h> If it returns 1 it is arch and if 2 it is debian-based
  puts(os() == 1 ? "os: arch-based" : "os: debian-based");

  // now the installer begins
  printf("Hi welcome again to the Installer\n");

  printf("What do you want to install and "
         "config\n1>Neovim\n2>Zsh\n3>Essential stuff\n4>all\nEnter 1/2/3/4 as "
         "options(anything else is taken as cancellation):");
  // read selection
  scanf("%d", &selection);
  // nvim
  if (selection == 1) {
    installnvim(os());
  }

  // zsh or not
  if (selection == 2) {
    instzsh(os());
  }
  // Essentials
  if (selection == 3) {
    instessen(os());
  }
  // all
  if (selection == 4) {
    installnvim(os());
    instzsh(os());
    instessen(os());
  }
  if (selection != (1 | 2 | 3 | 4)) {
    puts("cancelled");
    exit(1);
  }

  return 0;
}
