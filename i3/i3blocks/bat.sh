percentage=$(cat /sys/class/power_supply/BAT0/capacity)
charging=$(cat /sys/class/power_supply/AC0/online)
if [[ $charging -eq 1 ]]; then
 echo 🔌 
else
  echo "$percentage%"
fi

