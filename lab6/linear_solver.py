import numpy as np

# Coefficients of the equations
# Example:
# 2x + y - z = 8
# -3x - y + 2z = -11
# -2x + y + 2z = -3

A = np.array([[1, 1, 1], [1, 2, 2], [1, 2, 3]])
B = np.array([0, 0, 1])

# Solving for the unknowns
X = np.linalg.solve(A, B)

print("The solutions are: x =", X[0], "y =", X[1], "z =", X[2])
