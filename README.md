# work_14-light_up_the_bat_signal
Dylan Hu - Work 14: Light Up the Bat Signal

## Compilation and Execution
Run `make` to compile, and to use `make run` to execute.

## Behavior
When SIGINT is recieved, the program will write "recieved sigint" to the file "./exit_file.txt".

When SIGUSR1 is recieved, the program will print the parent process' ID.
