#!/bin/bash
#
if pacman -V >> /dev/null; then
    sudo pacman -S rofi ttf-roboto ttf-roboto-mono-nerd ttf-jetbrains-mono-nerd picom dunst rofi-calc rofi-emoji xss-lock bat trash-cli z stow scrot alacritty cpupower ttf-font-awesome bspwm sxhkd polybar zsh networkmanager gnome-keyring ly polkit-gnome feh variety eog qt5ct kcolorchooser neovim npm python-pynvim dolphin gedit breeze ripgrep fd lxappearance cups system-config-printer xorg-xsetroot intel-media-driver vulkan-intel vulkan-validation-layers network-manager-applet geary 
    sudo systemctl enable ly
    if yay; then
     yay -S betterlockscreen rofi-greenclip
     else
      sudo pacman -S --needed git base-devel && git clone https://aur.archlinux.org/yay-bin.git && cd yay-bin && makepkg -si
     yay -S betterlockscreen rofi-greenclip
    fi
  fi
  # dotfile copying
  #
    stow -v -t $HOME/.config/ i3
    stow -v -t $HOME/.config/ dunst
    stow -v -t $HOME/.config/ alacritty
    stow -v -t $HOME/.config/ rofi
    stow -v -t $HOME/.config/ wm
    stow -v -t $HOME zsh
    sudo cp -r ./Nordic-darker /usr/share/themes/
    if ls -a ~ | grep .icons; then
      sudo cp -r ./Nordic-cursors ~/.icons/
    else
      mkdir ~/.icons/ 
      sudo cp -r ./Nordic-cursors ~/.icons/
    fi
    if ls -a ~/Pictures/ | grep favwallpaper
     cp ./bg-default.jpg ~/Pictures/favwallpaper
     else
      mkdir ~/Pictures/Screenshots
      mkdir ~/Pictures/favwallpaper
      cp ./bg-default.jpg ~/Pictures/favwallpaper
    fi
