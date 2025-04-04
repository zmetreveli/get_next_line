get_next_line
get_next_line is a function designed to read and return a line from a file descriptor, one line at a time. It is part of the 42 School curriculum and is focused on practicing file I/O, memory management, and buffer handling in C.

📚 Project Overview
The goal of this project is to implement a function that returns a single line from a file each time it is called, handling buffer management internally and maintaining state between calls. It must work with any file descriptor, including stdin.

✅ Function Prototype
char *get_next_line(int fd);

Description
Returns the next line (including the newline \n character, if present) from a file descriptor.

Returns NULL if there's nothing more to read or if an error occurs.

Bonus
You must also support multiple file descriptors without their data getting mixed up (i.e., reading from one file shouldn't affect another).

🛠️ Mandatory Files
get_next_line.c

get_next_line_utils.c

get_next_line.h

You may use the following functions:

read()

malloc()

free()

⚙️ How It Works
Internally, the function uses a static variable to store the remainder of the buffer between function calls, and reads in chunks defined by the BUFFER_SIZE macro.

Each call to get_next_line(fd) reads from the file descriptor fd until it encounters a newline or reaches the end of the file.

📁 Usage
Clone and Compile
git clone git@github.com:zmetreveli/get_next_line.git
cd get_next_line
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
👉 Replace 42 with your desired buffer size and provide a test1.txt file for testing.

📄 License
This project is part of the 42 School curriculum and is intended for educational purposes only.

🧑‍💻 Author
Zurab Metreveli J.
42 Barcelona – get_next_line Project
