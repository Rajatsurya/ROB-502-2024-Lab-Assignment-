def read_file(fname):
    """Reads a file and returns a list of strings without trailing newlines."""
    with open(fname, 'r') as file:
        lines = [line.strip() for line in file]  # Remove trailing newlines
    return lines

def write_file(fname, data):
    """Writes a list of strings to a file, each on a new line."""
    with open(fname, 'w') as file:
        for line in data:
            file.write(line + '\n')  # Add newline after each string

if __name__ == '__main__':
    # Step 1: Read from the input file
    data = read_file('inputs.txt')
    print("Original data:")
    print(data)

    # Step 2: Modify the strings
    modified_data = [f"This is the {i+1} line: {line}" for i, line in enumerate(data)]
    print("\nModified data:")
    print(modified_data)

    # Step 3: Write modified strings to the output file
    write_file('outputs.txt', modified_data)
    print("\nModified data has been written to 'outputs.txt'.")
