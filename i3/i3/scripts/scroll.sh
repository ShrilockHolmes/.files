#!/bin/bash
# colormanages my display
/usr/bin/xcalib -d :0 ~/Documents/X540NA_8086_AE0D15DB.icm

# makes Scrolling speed like i like it
xinput set-prop "ELAN1200:00 04F3:3067 Touchpad" 'libinput Scrolling Pixel Distance' '32'

# flatpak should use my system cursor
#flatpak --user override --filesystem=/home/$USER/.icons/:ro
#flatpak --user override --filesystem=/home/$USER/.themes/:ro

id=`xinput list | grep -i "Touchpad" | cut -d'=' -f2 | cut -d'[' -f1`
natural_scrolling_id=`xinput list-props $id | \
  grep -i "Natural Scrolling Enabled (" \
  | cut -d'(' -f2 | cut -d')' -f1`

# Set the property to true
xinput --set-prop $id $natural_scrolling_id 1
id=`xinput list | grep -i "Touchpad" | cut -d'=' -f2 | cut -d'[' -f1`
tap_to_click_id=`xinput list-props $id | \
                      grep -i "Tapping Enabled (" \
                      | cut -d'(' -f2 | cut -d')' -f1`

# Set the property to true
xinput --set-prop $id $tap_to_click_id 1

xset s on
xset s 600

# my input delay and others
gsettings set org.gnome.desktop.peripherals.keyboard repeat-interval 5
gsettings set org.gnome.desktop.peripherals.keyboard delay 150

exit 
