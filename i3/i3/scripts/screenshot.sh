#!/bin/bash
output="$HOME/Pictures/Screenshots/%Y-%m-%d-%T.png"
chosen=$(printf "normal\nselection" | rofi -dmenu -i -theme-str '@import "power.rasi"')
case "$chosen" in
	"selection") scrot "$output" --select --line mode=edge && notify-send "Screenshot taken." || exit ;;
	 "normal") scrot "$output" && notify-send "Screenshot taken." || exit ;;
esac
