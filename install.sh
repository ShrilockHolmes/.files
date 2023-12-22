#!/bin/bash
#
read -p "do you want to install i3wm:" i3

if [[ $i3 -eq 'y'||'yes' ]]; then
  if pacman -V >> /dev/null; then
    sudo pacman -S rofi i3 i3blocks ttf-roboto ttf-roboto-mono-nerd ttf-jetbrains-mono-nerd picom dunst rofi-calc rofi-emoji xss-lock
    if yay; then
     yay -S betterlockscreen 
     else
      sudo pacman -S --needed git base-devel && git clone https://aur.archlinux.org/yay-bin.git && cd yay-bin && makepkg -si
     yay -S betterlockscreen 
    fi

  fi
fi
