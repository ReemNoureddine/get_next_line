*This project has been created as part of the 42 curriculum by rnouredd.*

# get_next_line

## Description

**get_next_line** is a project from the 42 curriculum that consists of implementing a function capable of reading a file descriptor **line by line**, returning **exactly one line per function call**.

### Project Goal
This project focuses on deepening the understanding of:
- File descriptors
- Static variables
- Dynamic memory allocation
- Buffer-based reading
- Handling incomplete reads
- Writing safe and reusable string utilities

The function must work independently of the buffer size and must properly handle end-of-file and error cases.

### Bonus Goal
The bonus part of the project requires: 
- Supporting multiple file descriptors simultaneously
- Ensuring that each file descriptor keeps its own independent reading state
- Preventing data mixing between file descriptors

This is achieved by using a separate static stash for each file descriptor.

## Instructions

### Installation
No installation is required.

### Compilation
BUFFER_SIZE should be defined at compilation time, as required by the subject.

For the mandatory part: 
cc get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42

For the bonus part: 
cc get_next_line_bonus.c get_next_line_utils_bonus.c main.c -D BUFFER_SIZE=42

You may change the value of BUFFER_SIZE to test different behaviors.

### Memory Testing 
valgrind --leak-check=full --show-leak-kinds=all ./a.out 
this is actually used to check the leaks and making sure the heap memory is freed. 

## Resources

### Documentation & References
- `man read` – Understanding how the `read()` system call works
- `man open` / `man close` – File descriptor management
- 42 get_next_line subject subject PDF

### Programming Concepts
- different websites encluding w3schools.com
