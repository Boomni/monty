# C - Stacks, Queues - LIFO, FIFO
## Program flowchart or overview
![Flowchart of Program](https://github.com/Boomni/monty/blob/main/images/monty.jpg?raw=true)

## Monty
`Monty 0.98` is a scripting language that is first compiled into monty byte codes (Just like python). It relies on a unique stack, with specific instructions to manipulate it. **`monty`** is an interpreter built specially for the said Monty Bytecodes files.

## More About the Monty language
This is a language that contains specific instructions to manipulate data information (stacks or queues), where each instruction (*called opcode*) is sended per line. Files which contains Monty byte codes usually have the `.m` extension.

Example (`file.m`):
```bash
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```

## Technologies
* Interpreter was written with C language
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C90 standard
* Tested on Ubuntu 20.04 LTS

## Usage
To compile all files:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
```

The **synopsis** of the interpreter is the following:

```bash
$ ./monty [filename]
$
```

To run the interpreter:

```bash
$ ./monty file.m
2
1
0
0
3
2
1
$
```

## Features
### Opcodes
`monty` executes the following opcodes:

| Opcode | Description |Function to handle opcode|
| -------- | ----------- |----------|
| `push` | Pushes an element to the stack |[push](./push.c)
| `pall` | Prints all the values on the stack |[pall](./pall.c)
| `pint` | Prints the value at the top of the stack |[pint](./pint.c)
| `pop` | Removes the top element of the stack |[pop](./pop.c)
| `swap` | Swaps the top two elements of the stack |[swap](./swap.c)
| `queue` | Sets the format of the data to a queue (FIFO) |[queue](./queue.c)
| `stack` | Sets the format of the data to a stack (LIFO) |[stack](./stack.c)
| `nop` | Doesn't do anything |[nop](./nop.c)
| `add` | Adds the top two elements of the stack |[add](./add.c)
| `sub` | Subtracts the top element of the stack from the second top element of the stack |[sub](./sub.c)
| `mul` | Multiplies the second top element of the stack with the top element of the stack |[mul](./mul.c)
| `div` | Divides the second top element of the stack by the top element of the stack |[div](./div.c)
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack |[mod](./mod.c)
| `pchar` | Prints the char at the top of the stack |[pchar](./pchar.c)
| `pstr` | Prints the string starting at the top of the stack |[pstr](./pstr.c)
| `rotl` | Rotates the stack to the top |[rotl](./rotl.c)
| `rotr` | Rotates the stack to the bottom |[rotr](./rotr.c)

Comments, indicated with `#`, are not executed by the interpreter.

When a **nonextistent opcode** is passed, the interpreter prints an error message and stops:

```bash
$ cat errorfile.m
push 1
pint
pcx
$ ./monty errorfile.m
1
L3: unknown instruction pcx
```

### Return value
When there is no errors, `monty` returns `0`. Otherwise, returns `1`

## Author
<details>
    <summary>Jonathan Boomni</summary>
    <ul>
    <li><a href="https://www.github.com/Boomni">Github</a></li>
    <li><a href="https://www.twitter.com/i_am_rejoicey">Twitter</a></li>
    <li><a href="mailto:rejoiceoye1@gmail.com">e-mail</a></li>
    </ul>
</details>
