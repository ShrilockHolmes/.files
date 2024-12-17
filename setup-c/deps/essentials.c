#include "../lib/essentials.h"
#include <stdlib.h>

void instessen(int which) {
  if (which == 1) {
    if (system("yay") == 0) {
      system("yay -S brave-bin variety eog geary neofetch htop");
    } else {
      // install yay
      system("pacman -Sy --needed git base-devel && cd ~/.cache/ && "
             "git clone https://aur.archlinux.org/yay-bin.git && cd "
             "~/.cache/yay-bin && makepkg -si");
      system("yay -S brave-bin neofetch htop scrot");
    }
  }
  if (which == 2) {
system("sudo apt install curl");

system("sudo curl -fsSLo /usr/share/keyrings/brave-browser-beta-archive-keyring.gpg https://brave-browser-apt-beta.s3.brave.com/brave-browser-beta-archive-keyring.gpg");

system("echo 'deb [signed-by=/usr/share/keyrings/brave-browser-beta-archive-keyring.gpg] https://brave-browser-apt-beta.s3.brave.com/ stable main'|sudo tee /etc/apt/sources.list.d/brave-browser-beta.list");

system("sudo apt update");
system("sudo apt install brave-browser-beta variety htop");
  }
}
