# fork-
// use this code on an ubnto linux device terminal
Use fork() to create a child process and pipe() which the parent uses to send a number to the child, then the child returns the number squared to the parent.
SAMPLE OUTPUT:
Child read <x = 8> from Parent
Parent read <x ^ 2 = 64> from Child
Hint: use two pipes to achieve two-way communication between the parent and the child
as follows:
int fd_a[2], fd_b[2];
if ( (pipe(fd_a) < 0) || (pipe(fd_b) < 0) )
/* error opening pipes */
if (fork()==0){
/* child process */
close(fd_a[0]); close(fd_b[1]); // Close unused ends
/* write to parent via fd_a[1], read from fd_b[0] */
} else {
/* parent process */
close(fd_a[1]); close(fd_b[0]); // Close unused ends
/* write to child via fd_b[1], read from fd_a[0] */
}
