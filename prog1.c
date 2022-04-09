//yara adel hassan mohamed 19100683
//programming assignment q1
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
#define R 0
#define W 1

int buffer;
int x=8;
int fd_a[2], fd_b[2];// 2pipes
if ( (pipe(fd_a) < 0) || (pipe(fd_b) < 0) ){
perror("pipe error!\n");}
/* error opening pipes */
if (fork()==0){
/* child process */
close(fd_a[0]); close(fd_b[1]); // Close unused ends
read(fd_b[R], &buffer, sizeof (int));
printf("%d\n", buffer*buffer);
close(fd_b[R]);
/* write to parent via fd_a[1], read from fd_b[0] */
} else {
/* parent process */
write(fd_b[W], &x,  sizeof (int));
close(fd_b[W]);
wait(NULL); // Wait for child
write(fd_b[W],&x , sizeof(int) );
close(fd_a[1]); close(fd_b[0]); // Close unused ends
/* write to child via fd_b[1], read from fd_a[0] */
}}

