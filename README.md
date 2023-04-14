#SIMPLE SHELL PROGRAM.
---

## Synopsis
---

* This is a simple implementation of a UNIX command line interpreter .

* The shell is written in C programming language and is compiled using gcc with the following flags:-Wall -Werror -Wextra -pedantic -std=gnu89.
-----
## Compilation
---

* To compile the shell,navigate to the repository and use the following command:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh. `

-----

# Usage
---

* This shell can be used in interactive mode or non-interactive mode.

* In interactive mode, run the executable `hsh` and enter commands when prompted:

`$ ./hsh
 $ /bin/ls
 hsh main.c shell.c
 $ exit`

* In non-interactive mode,input commands through a pipeline or redirect from a file:

`$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$ cat test_ls_2
/bin/ls
/bin/ls
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
`
-----

# Allowed functions and system calls.
---

