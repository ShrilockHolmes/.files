#!/bin/bash

chosen=$(printf "  Power Off\n  Restart\n Suspend\n  Hibernate\n  Log Out\n  Lock" | rofi -dmenu -i -theme-str '@import "power.rasi"')

case "$chosen" in
	"  Power Off") poweroff ;;
	"  Restart") reboot ;;
	"  Suspend") systemctl suspend ;;
	"  Hibernate") systemctl hibernate ;;
	"  Log Out") i3-nagbar -t warning -m 'You pressed the exit shortcut. Do you really want to exit i3? This will end your X session.' -B 'Yes, exit i3' 'i3-msg exit';;
	"  Lock") betterlockscreen -l ;;
	*) exit 1 ;;
esac
