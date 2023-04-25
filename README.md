Our Simple Shell Project
========================

![Simple Shell logo](docs/static_files/simpleshellLogo.png "Our Simple Shell Project")

---

Our Simple Shell is a command-line shell implemented in C for educational purposes. It supports basic command execution and has limited features compared to shells like bash.

---

<div align="center"><strong>This is a Holberton School project.</strong></div>

---

![Holberton School logo](docs/static_files/holbertonschoollogo.png "Holberton School")

---

## Functionalities

As previously mentioned this code lacks advanced functionalities so, here I will list a few of its most important capabilities.

- Displays a prompt and waits for the user to type a command. A command line always ends with a new line.
- If an executable cannot be found, prints an error message and displays the prompt again.
- Handles command lines with arguments.
- Handles the PATH.
- Input exit implemented.

## Pre-requisites

GCC (GNU89 Compiler)

## Installation

1. Clone the repository:
```sh
git clone https://github.com/RoPallas/holbertonschool-simple_shell.git
```
2. Navigate to the installation directory:
```sh
cd holbertonschool-simple_shell
```
3. Compile the source code:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

- Execute:
```sh
./hsh
```

You should be able to see the prompt:
```sh
$
```

## Audience

Our Simple Shell Project is primarily intended for the educators' review in Holberton School and also for our peers to compare the codes if needed.
