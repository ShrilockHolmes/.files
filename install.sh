#!/bin/bash
#
read -p "do you want to install i3wm:" i3

if [[ $i3 -eq 'y'||'yes' ]]; then
  if pacman -V >> /dev/null; then
    sudo pacman -S rofi i3 i3blocks ttf-roboto ttf-roboto-mono-nerd ttf-jetbrains-mono-nerd picom dunst rofi-calc rofi-emoji xss-lock bat trash-cli z stow scrot alacritty power-profiles-daemon
    if yay; then
     yay -S betterlockscreen rofi-greenclip
     else
      sudo pacman -S --needed git base-devel && git clone https://aur.archlinux.org/yay-bin.git && cd yay-bin && makepkg -si
     yay -S betterlockscreen rofi-greenclip
    fi
  fi
  # dotfile copying
  #
  if ls -a $(pwd) | grep i3;then
    stow -v -t $HOME/.config/ i3
    stow -v -t $HOME/.config/ dunst
    stow -v -t $HOME/.config/ alacritty
    stow -v -t $HOME/.config/ rofi
    stow -v -t $HOME/.config/ wm
    stow -v -t $HOME zsh
  fi
fi
