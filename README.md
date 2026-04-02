*Este proyecto ha sido creado como parte del currículo de 42 por <tide-oli>.*

# 📄 get_next_line – 42 Project

## 📌 Description

`get_next_line` is a project from the 42 curriculum whose goal is to implement a function that reads a file descriptor and returns **one line at a time**, including the newline character (`\n`) when present.

The function must be capable of handling multiple calls, preserving the remaining data between each call using a static buffer.

---

## 🧠 Objective

Implement the following function:

```c
char *get_next_line(int fd);
```

### Behavior

- Reads from a file descriptor (`fd`)
- Returns **one line per call**
- Includes the newline (`\n`) if it exists
- Returns `NULL` when:
  - EOF is reached and no data remains
  - An error occurs

---

## ⚙️ Allowed Functions

- `read`
- `malloc`
- `free`

---

## 🧩 Core Concepts

This project focuses on:

- File descriptor management
- Dynamic memory allocation
- Static variables
- Buffer handling
- String manipulation
- Handling partial reads

---

## 🏗️ How It Works

The function follows this internal logic:

1. Read from the file descriptor using a buffer of size `BUFFER_SIZE`
2. Accumulate data into a static variable (`stash`)
3. Check for newline (`\n`)
4. If found:
   - Extract the line
   - Store the remaining data for the next call
5. If not:
   - Continue reading until a newline or EOF is reached

---

## 🔄 Execution Flow

```
read() → buffer → stash → extract line → return line
                          ↓
                     keep remainder
```

---

## 🗂️ Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── main.c (for testing)
```

---

## 🧪 Usage

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c
```

### Example

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## ⚠️ Important Notes

- `BUFFER_SIZE` can vary during compilation
- The function must work with:
  - Small buffers (`BUFFER_SIZE = 1`)
  - Large buffers
- Must handle:
  - Files without newline at the end
  - Empty files
  - Multiple consecutive calls
- Must not leak memory

---

## 🧪 Edge Cases

- Empty file
- File without `\n`
- Multiple `\n` in sequence
- Very large lines
- `BUFFER_SIZE = 1`

---

## 🧼 Memory Management

- All allocated memory must be freed properly
- No memory leaks
- No double free
- No invalid access

---

## 📚 Learning Outcomes

After completing this project, you should understand:

- How `read()` works with file descriptors
- How to manage persistent state using `static`
- Dynamic memory resizing strategies
- String handling at a low level
- Debugging memory issues (segfaults, leaks)

---

## 🚀 Author

- 42 Student – [tp4es](https://github.com/tp4es)

---

## 📜 License

This project is part of the 42 curriculum and follows its academic guidelines.