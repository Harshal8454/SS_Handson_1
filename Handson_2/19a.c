/*============================================================================
Name : 19a.c
Author : Harshal Gujarathi
Description : Create a FIFO file by 
              a.mknod command
Date: 19th Sept, 2024.
============================================================================
*/

// mknod my_fifo p (created the my_fifo)
// ls -l my_fifo (checking)

/*
OUTPUT
prw-rw-r-- 1 harshal harshal 0 Sep 19 09:39 my_fifo
*/

//Now this Fifo is used for IPC, lets check!
/*
echo "Hello, World!" > my_fifo (in one terminal)
Hello, World! (in other terminal)
*/

