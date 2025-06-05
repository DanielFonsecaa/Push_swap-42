<div align="center">

![push_swape](https://github.com/user-attachments/assets/545044e6-550c-4114-ae17-eb472b62aab4)

</div>

# Push_swap

Welcome to **Push_swap**, a project developed as part of the 42 curriculum. This project challenges you to sort a stack of numbers with a minimal set of stack operations, optimizing both the algorithm and your implementation.

---

## Overview

The **Push_swap** project tasks you with sorting a sequence of integers using only two stacks (A and B) and a limited set of allowed operations. Your goal is to sort the numbers with as few moves as possible, putting your algorithmic skills and knowledge of data structures to the test.

I implemented the solution using linked lists for stack management and the Radix Sort algorithm, assigning an index to each number and sorting them using bitwise operations for optimal efficiency.

<div align="center">

| Grade | Evaluation Information |
| :---- | :--------------------- |
| <img src="https://img.shields.io/badge/84%20%2F%20100%20%E2%98%85-success"/> | `3 peers` `30 mins` |

</div>

---

## Why I Chose Radix Sort

- **Real-World Applicability:**  
  Radix sort is widely used in industry for efficiently sorting large sets of integers — in databases, digital signal processing, and telecommunications.

- **Scalability:**  
  It handles large datasets efficiently, which is important for both this project and real-world scenarios.

- **Deterministic Performance:**  
  Predictable linear time complexity for integer sorting makes Radix sort suitable for performance-critical applications.

### Why Not Turkish (Turk) Sort?

While Turkish sort is academically interesting, it is rarely used in real-world systems due to its lack of practical optimizations and limited applicability.

### Conclusion

By choosing Radix sort, I optimized my Push_swap solution and focused on an algorithm with genuine software engineering and data processing value.

---

## Features

- Efficient sorting using Radix Sort and bitwise operations
- Linked list implementation for stack operations
- Index assignment without altering original order
- Handling of all required Push_swap operations (swap, push, rotate, reverse rotate)
- Comprehensive input parsing and error handling

---

## How it Works

1. Input a list of integers as program arguments.
2. The program assigns an index to each number for efficient bitwise radix sorting.
3. Using only stack operations, it sorts the numbers with the smallest number of moves possible.
4. The sequence of operations is output to standard output.

---
## Instruction Set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Installation

### Prerequisites

- GCC (or another C compiler)
- Make
- A Unix-like system (Linux, macOS)

### Clone the Repository

```sh
git clone https://github.com/DanielFonsecaa/Push_swap-42.git
cd Push_swap-42
```

### Build the Project

```sh
make
```

---

## Usage

To run the program, execute:

```sh
./push_swap [list of integers]
```

Example:

```sh
./push_swap 3 2 5 1 4
```

The program will output the optimal sequence of stack operations needed to sort the numbers.

---

## Visualizer
```sh
make visualizer
```
![Screenshot from 2025-06-05 13-39-53](https://github.com/user-attachments/assets/2eb7d1b0-3700-4e10-9af2-6ea23e57c432)

---


## Tester
```sh
make tester
```
![Screenshot from 2025-06-05 13-41-32](https://github.com/user-attachments/assets/47a8cee8-e8c3-42b5-8c56-73f3127645b3)

---
## Further Reading

For more on how Radix Sort works in Push_swap, check out this tutorial:  
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
