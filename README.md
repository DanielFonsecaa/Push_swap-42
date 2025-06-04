<div align="center">

  <!-- Optionally add a relevant banner image here -->
  <!-- ![push_swap_banner](URL_TO_IMAGE) -->

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
| <!-- Example badge: <img src="https://img.shields.io/badge/100%20%2F%20100%20%E2%98%85-success"/> --> | `3 peers` `30 mins` |

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

## Further Reading

For more on how Radix Sort works in Push_swap, check out this tutorial:  
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
