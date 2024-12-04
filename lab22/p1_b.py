import math

def sqrt(x):
    # Calculate the square root using math.sqrt and round it
    x_2 = round(math.sqrt(x))
    return x_2

if __name__ == "__main__":
    num_list = [4, 9, 11, 25, 32]
    approx_list = []
    actual_root_list = []
    for num in num_list:
        # Use the custom sqrt function for consistency
        approx_list.append(sqrt(num))
        actual_root_list.append(math.sqrt(num))
        print(f"The number {num} has an actual square root of {math.sqrt(num):.2f} "
              f"and the approximate value is {sqrt(num)}")


 
