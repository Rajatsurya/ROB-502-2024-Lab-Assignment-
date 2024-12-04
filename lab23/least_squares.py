import numpy as np
import matplotlib.pyplot as plt

def main():
    points = np.array([
        [0, 0, -2],
        [0, 1, -1.2],
        [0, 2, -0.6],
        [1, 0, 0.2],
        [1, 1, 0.1],
        [1, 2, 0.4],
        [2, 0, 1],
        [2, 1, 1.2],
        [2, 2, 1.5],
        [3, 0, 1.2],
        [3, 1, 1.4],
        [3, 2, 1.7]
    ])
    
    # Create the A matrix and b vector
    A = points[:, :2]  # Take the first two columns (x and y)
    A = np.hstack((A, np.ones((A.shape[0], 1))))  # Add a column of 1s for homogeneity
    print(A)
    b = points[:, 2]  # Take the z values
    print(b)

    # Solve for the coefficients using least squares
    x, _, _, _ = np.linalg.lstsq(A, b, rcond=None)

    # Plane coefficients: ax + by - z + d = 0
    print(f"a: {x[0]} b: {x[1]} c: -1 d: {x[2]}")
    print(f"Product of coefficients: {np.prod(x)}")

    # Uncomment to visualize
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')

    # Create a grid to plot the plane
    xx, yy = np.meshgrid(range(4), range(3))
    z = x[0] * xx + x[1] * yy + x[2]  # Compute z = a*x + b*y + d
    ax.plot_surface(xx, yy, z, alpha=0.2, color='blue')

    # Plot the original points
    ax.scatter(points[:, 0], points[:, 1], points[:, 2], color='green')

    # Labels for better visualization
    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("Z")
    plt.show()

if __name__ == "__main__":
    main()
