1) write a program that use fork() and assign some different task to child process and make sure that paretn exits after child fineshes it's task.
2) write a program that creates child process and find out/print values of process id and parent process for both child and parent process. (HINT : child, parent - getpid(), child's parent, parent's parent - getpptid()) Consider two casees as per bellow,
     1) child exits before parent (put wait(NULL) in parent process)
     3) parent exits before child (can either do nothing or can put wait(NULL) in child process)
  
        op of 2: parent it , child's parent id --- same,
                 parent's parent, child process id will be different.
