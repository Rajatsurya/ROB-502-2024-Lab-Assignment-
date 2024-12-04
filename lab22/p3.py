def two_sum(numbers, target):
    # Iterate over each number in the list
    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):  # Start from the next number
            if numbers[i] + numbers[j] == target:
                return [i, j]  # Return the indices as a list
    return None  # Return None if no such pair is found

if __name__ == '__main__':
    indices = two_sum([3, 3], 6)
    print(indices)  # Output: [0, 1]
    
    indices = two_sum([10, 2, 4, 10], 20)
    print(indices)  # Output: [1, 2]
