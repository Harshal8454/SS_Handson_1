/*============================================================================
Name : 2.c
Author : Harshal Gujarathi
Description : Write a simple program to execute in an infinite loop at the background. 
              Go to /proc directory and identify all the process related information in
              the corresponding proc directory.
Date: 15th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

// A simple Program that runs infinite time in a background.
int main() {
    while (1) {
        // just looping  indefinitely
        sleep(1); // For reducing CPU usage allowed to sleep for 1 sec
    }
    return 0;
}


//OUTPUT
//[1] 26732 (Process id)
// All the process related information.
/*Name:	loop
Umask:	0002
State:	S (sleeping)
Tgid:	26732
Ngid:	0
Pid:	26732
PPid:	26698
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
*/