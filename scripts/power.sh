#!/bin/bash
#
chosen=$(printf "  Shutdown\n  Restart\n  Log Out\n💤 Sleep\n  Lock" | rofi -dmenu -i -theme-str '@import "power.rasi"')
# dmenu if rofi decides to quit
#chosen=$(printf "  Shutdown\n  Restart\n  Log Out\n💤 Sleep\n  Lock" | dmenu -fn 'JetBrainsMono Nerd Font')
notify-send $chosen
case "$chosen" in
	"  Shutdown") systemctl poweroff ;;
	"  Restart")systemctl  reboot ;;
  "💤 Sleep") systemctl suspend-then-hibernate ;;
	"  Log Out") i3-nagbar -t warning -m 'You pressed the exit shortcut. Do you really want to exit i3? This will end your X session.' -B 'Yes, exit i3' 'i3-msg exit' | bspc quit | pkill dwm;;
	"  Lock") betterlockscreen -l ;;
	*) exit 1 ;;
esac
