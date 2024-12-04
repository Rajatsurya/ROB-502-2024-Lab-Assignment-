import math

def sqrt(x):
    # Calculate the square root using math.sqrt
    x_2 = round(math.sqrt(x))
    return x_2

if __name__ == "__main__":
    input_1 = int(input("Enter a number: "))  # Convert input to an integer
    approx_root = sqrt(input_1)
    print(f"The approximate square root of {input_1} is {approx_root}")
