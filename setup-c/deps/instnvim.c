#include <stdio.h>
#include <stdlib.h>
#include "../lib/instnvim.h"
// declaration of install nvim func which is 1 for arch and 2 for apt based
void installnvim(int which) {
  int existsnvim = system("ls -a ~/.config/ | grep nvim");
  if (which == 1) {
    system("sudo pacman -S neovim nodejs npm");
    if (existsnvim == 0) {
      system("sudo rm -rf ~/.config/nvim && cd ~/.config/ && pwd && git "
             "clone https://github.com/ShrilockHolmes/nvim");
    } else {
      system("cd ~/.config/ && pwd && git clone "
             "https://github.com/ShrilockHolmes/nvim");
    }
  }
  if (which == 2) {
    printf("you are on ubuntu/debian derivative\n");
    printf("building from source\n");
    system(
        "cd ~/.cache/ && git clone https://github.com/neovim/neovim");
    system("sudo apt install ninja-build cmake make ccache -y");
    system(
        "cd ~/.cache/neovim && make CMAKE_BUILD_TYPE=RelWithDebInfo");
    system("cd ~/.cache/neovim && sudo make install");
    if (existsnvim == 0) {
      system("sudo rm -rf ~/.config/nvim && cd ~/.config/ && pwd && git "
             "clone https://github.com/ShrilockHolmes/nvim");
    } else {
      system("cd ~/.config/ && pwd && git clone "
             "https://github.com/ShrilockHolmes/nvim");
    }
  }
}
