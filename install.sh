#!/bin/bash
#
whereisthisfile=$(pwd)
if pacman -V >> /dev/null; then
    sudo pacman -S rofi ttf-roboto ttf-jetbrains-mono-nerd picom dunst rofi-calc rofi-emoji trash-cli z stow scrot alacritty cpupower ttf-font-awesome bspwm sxhkd polybar zsh networkmanager lxqt-policykit feh qt5ct neovim python-pynvim gedit kvantum ripgrep fd lxappearance xorg-xsetroot intel-media-driver vulkan-intel vulkan-validation-layers network-manager-applet 
  sudo systemctl enable ly
    if yay; then
     yay -S betterlockscreen 
     else
      sudo pacman -S --needed git base-devel && git clone https://aur.archlinux.org/yay-bin.git && cd yay-bin && makepkg -si
     yay -S betterlockscreen 
     sudo systemctl enable betterlockscreen@$USER
    fi
  fi
  # dotfile copying
  #
  cd $whereisthisfile
    curl -L git.io/antigen > ~/antigen.zsh
    mkdir ~/.local/bin
    stow -v -t $HOME/.local/bin scripts
    stow -v -t $HOME/.config/ dunst
    stow -v -t $HOME/.config/ terminal
    stow -v -t $HOME/.config/ rofi
    stow -v -t $HOME/.config/ wm
    stow -v -t $HOME zsh
    sudo cp ./kdeglobals ~/.config/
    sudo cp ./power.rules /etc/udev/rules.d/
    sudo cp ./battery.service /etc/systemd/system/
    if ls -a ~/Pictures/ | grep favwallpaper; then
     cp ./bg-default.jpg ~/Pictures/favwallpaper
      betterlockscreen -u ~/Pictures/favwallpaper/bg-default.jpg
     else
       if ls -a ~ | grep Pictures;then
      mkdir ~/Pictures/favwallpaper
       mkdir ~/Pictures/Screenshots
      else
      mkdir ~/Pictures/
      mkdir ~/Pictures/favwallpaper
       mkdir ~/Pictures/Screenshots
       fi
      cp ./bg-default.jpg ~/Pictures/favwallpaper
      betterlockscreen -u ~/Pictures/favwallpaper/bg-default.jpg
    fi
