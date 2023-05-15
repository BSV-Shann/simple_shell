# C - Simple Shell.
---


<img src="shell.jpeg" alt="Shell image" width="500"/>


### Description.

* This is a simple implementation of a UNIX command line interpreter that executes the shell commands and scripts on a Unix-based operating system.

* This shell has a similar functionality to sh (the standard UNIX shell), such as the ability to execute commands,redirect input and output, and use pipes to connect commands.It works by reading a command from the user,parsing it into its constituent parts,and executing it by calling the appropriate system function.

----

### Compilation.

* To compile the shell,navigate to the repository and use the following command:

	`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh. `

---

### Usage

 * The shell can be run in interactive mode by executing the program without any arguments:
   `$ ./hsh`
   `($) /bin/ls`
   `hsh main.c shell.c`
   `($)`
   `($) exit`
   `$`

 * It can also be used in non-interactive mode:
   `$ echo "/bin/ls" | ./hsh`
   `hsh main.c shell.c test_ls_2`
   `$`
   `$ cat test_ls_2`
   `/bin/ls`
   `/bin/ls`
   `$`
   `$ cat test_ls_2 | ./hsh`
   `hsh main.c shell.c test_ls_2`
   `hsh main.c shell.c test_ls_2`
   `$`

---

### Allowed functions.

`Access (man 2 access)`
`chdir (man 2 chdir)`
`close (man 2 close)`
`closedir (man 3 closedir)`
`execve (man 2 execve)`
`exit (man 3 exit)`
`_exit (man 2 _exit)`
`fflush (man 3 fflush)`
`fork (man 2 fork)`
`free (man 3 free)`
`getcwd (man 3 getcwd)`
`getline (man 3 getline)`
`getpid (man 2 getpid)`
`isatty (man 3 isatty)`
`kill (man 2 kill)`
`malloc (man 3 malloc)`
`open (man 2 open)`
`opendir (man 3 opendir)`
`perror (man 3 perror)`
`read (man 2 read)`
`readdir (man 3 readdir)`
`signal (man 2 signal)`
`stat (__xstat) (man 2 stat)`
`lstat (__lxstat) (man 2 lstat)`
`fstat (__fxstat) (man 2 fstat)`
`strtok (man 3 strtok)`
`wait (man 2 wait)`
`waitpid (man 2 waitpid)`
`wait3 (man 2 wait3)`
`wait4 (man 2 wait4)`
`write (man 2 write)`

## Author :black_nib:

* **Kevin Kariuki** [vingentz](https://github.com/vingentz)
* **BenieShann** [Shann](https://github.com/BenieShann)

-----------
