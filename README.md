# Koch curves

The Koch curves, or Koch algorithm, is defined as follows:

The simplest Koch curve uses a line segment as an initiator. 
Then, at each level of recursion, the segment is replaced with four segments that are one-third of the original segment's length. 
The first segment is in the direction of the original segment, the next is rotated −60 degrees, the third is rotated 120 degrees, and the final segment is in the original direction.

## Algorithmic implementation

The function `koch()` is recursive, since the number of iterations is strictly related to the times the function is called. For each line, 4 more are generated. 
This implementation has O(4^n) complexity and O(4n) memory usage.

## Quick start

1. **Compile the project**
```bash
make
```

2. **Run the program (replace N with the number of iterations for the Koch curve):**

```bash
make run ARG=N
```

Example: 

```bash
make run ARG=5
```

Or run the predefined test:

```bash
make test
```

3. **Visualize the graph:**
Once the data is generated, use the Python script to display it:

```bash
python python/graph_generator.py
```

4. **Clean the compiled files:**

```bash
make clear
```

## Project structure

```
.
├── src/                    # Source code for main.cpp
│ └── koch.hpp              # Koch fractal algorithm implementation
│
├── python/                 # Python script to generate the lines draw
│ ├── requirements.txt      # Python required dependencies
│ └── graph_generator.py    # Lines drawer
│
├── main.cpp                # Testing for Koch function
├── Makefile                # Compilation for the main program
├── .gitignore              # Gitignore file
└── README.md               # This file
```


