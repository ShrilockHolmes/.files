#!/bin/bash

# Increment, decrement, or mute the volume and send a notification
# of the current volume level.

send_notification() {
  BRIGHTNESS=$(cat /sys/class/backlight/intel_backlight/brightness)
  BRIGHTNESS=$(($BRIGHTNESS*5/4800))
  volume=${BRIGHTNESS/.*} # truncating to int, just in case
	dunstify -a "changebrightness" -u low -r 9993 -h int:value:"$volume" -i "brightness" "brightness" "${volume}%" -t 2000

}

case $1 in
up)
	# Set the volume on (if it was muted)
  brightnessctl s 5%+
	send_notification "$1"
	;;
down)
  brightnessctl s 5%-
	send_notification "$1"
	;;
esac
