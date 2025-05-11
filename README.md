# MyGrep

A lightweight, user-friendly command-line text search utility written in C that mimics the basic functionality of the Unix `grep` command.

## Features

- Search for text patterns within files
- Case-sensitive or case-insensitive search options
- Displays line numbers for matched content
- Counts occurrences of search terms per line and in total
- Simple and clean interface

## Installation

### Prerequisites

- GCC compiler or equivalent
- Standard C libraries

### Compiling

```bash
gcc -o mygrep mygrep.c
```

## Usage

Run the compiled program:

```bash
./mygrep
```

The program will prompt you for:
1. The filename to search
2. The search term
3. Whether the search should be case-sensitive (yes/no)

### Example

```
Enter filename to search: example.txt
Enter search term: function
Case-sensitive search? (yes/no): no
```

### Output Format

For each line containing a match:
- The line number and content
- Number of occurrences in that line

At the end:
- Total number of occurrences across the file
- Or a "No matches found" message

## How It Works

MyGrep reads the specified file line by line and checks each line for the search term. It implements:

- Custom case-insensitive search functionality
- Occurrence counting for search terms
- Clear output formatting with relevant information

## Limitations

- Maximum line length is defined as 1024 characters
- Searches only one file at a time
- No support for regular expressions

## Contributing

Feel free to fork this repository and submit pull requests. Some ideas for improvements:

- Add support for searching multiple files
- Implement basic regular expression support
- Add color highlighting for matched terms
- Support for command-line arguments instead of interactive prompts

## License

This project is open source and available under the [MIT License](LICENSE).
