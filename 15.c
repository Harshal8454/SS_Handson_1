/*============================================================================
Name : 15.c
Author : Harshal Gujarathi
Description : Write a program to display the environmental variable of the user (use environ).
Date: 26th Aug, 2024.
============================================================================
*/

#include <stdio.h>

extern char **environ;  // Declare the external environ variable which holds the environmental variables.

int main() {
    char **env = environ;  // Pointer to the array of environment variables

    while (*env) {
        printf("%s\n", *env);  // Print each environment variable
        env++;  // Move to the next environment variable
    }

    return 0;
}

//OUTPUT 
/*VTE_VERSION=7200
WAYLAND_DISPLAY=wayland-0
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/107b8cd8_771a_466a_80ae_ee346662da66
GNOME_SETUP_DISPLAY=:1
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=harshal
GNOME_TERMINAL_SERVICE=:1.159
DISPLAY=:0
SHLVL=1
QT_IM_MODULE=ibus
XDG_RUNTIME_DIR=/run/user/1000
DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
GDMSESSION=ubuntu
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
_=./env
OLDPWD=/home/harshal/temp */

/*Environmental variables provide a way for the operating system and applications to share configuration and information*/

