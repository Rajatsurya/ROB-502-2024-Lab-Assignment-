import numpy as np
x = np.random.rand(4, 4)
last_row = np.array([0,0,0,1])
x[-1] = last_row.reshape(1,-1)
print(x)