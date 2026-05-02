*This project has been created as part of the 42 curriculum by magrass.*

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from a file descriptor. Repeated calls to the function allow you to read through an entire file line by line.

I would suggest never using a function which traps state within a static variable but if you would like to have horrible state management this function is perfect for you!

The function handles reading from any valid file descriptor — regular files, standard input, or other sources — and correctly includes the terminating `\n` character in the returned string, except when the end of the file is reached without one.

A core concept explored in this project is the **static variable**, while I already knew what static variables are, I guess I can be useful for someone who never used one before.

## Instructions

### Compilation

The project requires the `-D BUFFER_SIZE=n` flag to define the read buffer size. A default value is defined in the header if the flag is omitted.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Usage

An example would be to include the header in your project and call the function in a loop:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
```

### Files

| File | Description |
|------|-------------|
| `get_next_line.h` | Header — contains the function prototype and `BUFFER_SIZE` default |
| `get_next_line.c` | Core logic of the function |
| `get_next_line_utils.c` | Helper functions (string operations, etc.) |

## Resources

- [`read()` man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`open()` man page](https://man7.org/linux/man-pages/man2/open.2.html)

**AI usage:** AI was used for asking some questions and to understand to excercise better.
              Otherwise I wrote all the code myself.
