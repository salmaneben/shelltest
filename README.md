# Simple Shell

This project is a simple UNIX command interpreter implemented as part of the ALX Software Engineering program.

## Description

Our Simple Shell can:
- Display a prompt and wait for the user to type a command.
- Handle command lines with arguments.
- Handle the `PATH`.
- Implement the `exit` and `env` built-ins.
- Handle commands without relying on the `PATH`.

## Installation

Clone this repository:
```
git clone https://github.com/salmaneben/simple_shell.git
```

Compile the C files:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the shell:
```
./hsh
```

## Usage

After compilation, the shell can be run with:
```
./hsh
```

### Interactive Mode

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
$
```

### Non-Interactive Mode

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$
```

## Built-ins

Our shell supports the following built-in commands:

- `exit`: Exits the shell.
- `env`: Prints the current environment.

## Authors

- Salmane Ben Yakhlaf
- El Mustapha Lakhloufi

