#include <stdio.h>
#include <stdlib.h>
#include "../lib/instzsh.h"
void instzsh(int which) {

    if (which == 1) {
      system("sudo pacman -S zsh zsh-completions && cd ~/.cache/ && git clone https://github.com/ShrilockHolmes/.files && cd .files && cp .zshrc ~/");

      system("cd ~ && curl -L git.io/antigen > antigen.zsh");

        printf("zsh installed\n");
    }
    if (which == 2) {
        system("sudo apt install zsh zsh-completions && cd ~/.cache/ && git clone https://github.com/ShrilockHolmes/.files && cd .files && cp .zshrc ~/");

      system("cd ~ && curl -L git.io/antigen > antigen.zsh");

        printf("zsh installed\n");
    }
}
