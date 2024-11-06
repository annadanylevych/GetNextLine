# get_next_line

Welcome to get_next_line, my third project at 42 School! This project focuses on creating a function that reads lines from a file descriptor one at a time, making it a handy tool for handling input streams. Moving on from `ft_printf`, this project pushed me further into working with memory allocation, buffers, and file handling in C.

## Project Overview

The goal of get_next_line is to develop a function that reads from a file descriptor and returns each line one by one, regardless of line length. Since this was only my third project, there are definitely areas for improvement, but I kept the code as it was originally to track my progress and learning over time.

## Features

- **Line-by-Line Reading**: Reads from a file descriptor and returns each line individually.
- **Dynamic Buffer Management**: Manages buffers to handle varying line lengths and multi-line files.
- **Memory Allocation**: Makes extensive use of memory allocation and freeing, providing a great intro to dynamic memory handling in C.

## Usage

This project provides a custom `get_next_line` function that can be compiled and linked into other C programs. Run `make` to compile the function into an object file.

## Compilation

To compile, run:
```bash
make
```

This will generate `get_next_line.o`, which can be linked to other projects to add line-by-line reading functionality.

---

get_next_line was a great learning experience for understanding file handling and buffer management. Check it out to see how my skills were developing in handling dynamic memory and file I/O!
