#!/bin/bash
output="$HOME/Pictures/Screenshots/%Y-%m-%d-%T.png"
case $1 in
	1) scrot "$output" --select --line mode=edge && notify-send "Screenshot taken." || exit ;;
	2) scrot "$output" && notify-send "Screenshot taken." || exit ;;
	*) exit ;;
esac
