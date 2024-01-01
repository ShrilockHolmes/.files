#!/bin/bash
#
# Full and short texts
#echo "Battery: $BAT"
#echo 
#!/bin/sh

# Send a notification if the laptop battery is either low 
# or is fully charged.

export DISPLAY=:0
export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/1000/bus"

# Battery percentage at which to notify
WARNING_LEVEL=15
BATTERY_DISCHARGING=$(acpi -b | grep "Battery 0" | grep -c "Discharging")
BATTERY_LEVEL=$(acpi -b | grep "Battery 0" | grep -P -o '[0-9]+(?=%)')

# Use two files to store whether we've shown a notification or not (to prevent multiple notifications)
EMPTY_FILE=/tmp/batteryempty
#FULL_FILE=/tmp/batteryfull

# Reset notifications if the computer is charging/discharging
if [ "$BATTERY_DISCHARGING" -eq 0 ] && [ -f $EMPTY_FILE ]; then
    rm $EMPTY_FILE
fi

# If the battery is charging and is full (and has not shown notification yet)
# If the battery is low and is not charging (and has not shown notification yet)
if [ "$BATTERY_LEVEL" -le $WARNING_LEVEL ] && [ "$BATTERY_DISCHARGING" -eq 1 ] && [ ! -f $EMPTY_FILE ]; then
    notify-send "Low Battery" "${BATTERY_LEVEL}% of battery remaining." -u critical -i "battery-alert" -r 9991
    touch $EMPTY_FILE
fi
#bat=$(cat /sys/class/power_supply/BAT0/capacity)
echo "$BATTERY_LEVEL%"
exit 0
