_This activity has been created as part of the 42 curriculum by resonnet._

#   Decription
get_next_line is a project where each line delimited by `\n` or the `EOF` is returned one by one

_usefull for creating a minishell, i guess..._

##  Attributes
- Input: fd, the file descriptor where to read
- Output: A string with a string or NULL if there is an error or `EOF`

##  Known error
the version asked in the curriculum can handle only one fd by program, giving an undefined behavior if more than one is used.
however, the subject state the we can fix this problem. only the first 1024 fd can work, to make the entire range of fd work, A HashMap can be used (which is not in the scope of the exercice).

#   Instruction
To compile the project use this command:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

This command will compile with default buffer size.

To change the buffer size use:

```bash
cc -Wall -Wextra -Werror -DBUFFER_SIZE=<custom_buffer_size> get_next_line.c get_next_line_utils.c
```

#   Resources

- [Man page of read()](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variable in c](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [ulimit man page](https://ss64.com/bash/ulimit.html)

to go further:
- [Hashtable](https://benhoyt.com/writings/hash-table-in-c/)

_no generative AI has been used in this project_

#   Explanation of Algorithm
The functionment of the algorithm is as follow:

1. read `BUFFER_SIZE` bytes of the file pointed by the fd and put them in a buffer.
2. concatenate at the end of stack the buffer.
3. verify if the stack contain a `\n` character.
    1. if a `\n` is present stop the loop.
    2. continue the loop if `\n` is not present.
    3. stop the loop if number of bytes read is 0.
4. copy the n first charaters including the `\n` and stock it in a variable.
5. troncate the n first character including the `\n` and replace the stack by the troncature.
6. return the variable containing the line.

I choose this approch for its memory efficiency due to copying nearly what it needs, and the easness of implementing the use of multiple fd cocurently and its integration in libft afterwards.
