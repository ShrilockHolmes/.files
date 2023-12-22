#!/bin/bash
xinput set-prop "ELAN1200:00 04F3:3067 Touchpad" 'libinput Scrolling Pixel Distance' '32'
# use this or qt5ct
flatpak --user override --filesystem=/home/$USER/.icons/:ro
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

/usr/bin/xcalib -d :0 ~/Documents/X540NA_8086_AE0D15DB.icm
exit 
