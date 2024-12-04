import math
import numpy as np

def main():
    # Constructors
    a = np.array([0, 1])  # vector of 2 integers
    b = np.array([0.1, -0.5, 3.0])  # vector of 3 doubles
    c = np.array([0.2, -0.3, 0.1, 1.0])  # vector of 4 doubles
    d = np.array([[0, 1], [2, 5]])  # 2x2 matrix of integers

    # Compute t and matrix 'e'
    t = math.pi / 2 + 0.2
    e = np.array([
        [math.cos(t), -math.sin(t), 0],
        [math.sin(t), math.cos(t), 0],
        [0, 0, 1]
    ])  # 3x3 matrix of doubles

    # Matrix 'f'
    f = np.array([
        [0.1, 0.3],
        [0.4, 0.1],
        [0.3, -0.2],
        [0.4, 0.1],
        [0.5, -0.1]
    ])  # 5x2 matrix of doubles

    # Assertions to verify initialization
    assert abs(e.sum() - 0.6) < 0.01
    assert abs(f.sum() - 1.9) < 0.01

    # Create identity matrix 'g'
    g = np.eye(3, dtype=float)

    # Perform operations
    h = g + e  # h = g + e
    i = d.T  # Transpose of d
    j = np.abs(b)  # Element-wise absolute value of b
    k = h + j[:, np.newaxis]  # Broadcasting over columns

    # Mean of each column in 'f'
    l = f.mean(axis=0)

    # Matrix multiplication: m = e * e^T
    m = np.matmul(e, e.T)
    print(f"trace of m: {m.trace()}")

    # Add 5 to vector 'a'
    n = a + 5

    # Add matrices k and m
    o = k + m
    print(f"o[0,0]: {o[0,0]}")

    # Get first row of 'o'
    o_first_row = o[0, :]

    # Slice first 3 elements of the first column in 'f'
    f_head = f[:3, 0]

    # Compute dot product of f_head and o_first_row
    p = np.dot(f_head, o_first_row)
    print(f"p: {p}")

    return 0

if __name__ == "__main__":
    main()
