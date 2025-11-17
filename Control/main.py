import control as ct
import matplotlib.pyplot as plt
import numpy as np
# %%

m, c, k = 1, 0.1, 2

A = np.array([
    [0, 0, 1 ,0],
    [0, 0, 0 ,1],
    [-2*k/m, k/m, -c/m ,0],
    [k/m, -2*k/m, 0 ,-c/m],
])

B = np.array([[0], [0], [0], [k/m]])
C = np.array([[1, 0, 0, 0], [0, 1, 0, 0]])
D = 0

# %%
sys = ct.ss(A,B,C,D, outputs = ['q1', 'q2'], name = "coupled spring mass")
print(sys)

# %%
res = ct.initial_response(sys, x0=[1, 0, 0, 0])
cplt = res.plot()

# %%
t = res.time
x = res.states
plt.plot(t, x[0], 'b', t, x[1], 'r')
plt.savefig("coupled spring mass.png")
plt.show()

# %%

for X0 in [[1, 0, 0, 0], [0, 2, 0, 0], [1, 2, 0, 0], [0, 0, 1, 0], [0, 0, 2, 0]]:
    res = ct.initial_response(sys, T = 20, X0=X0)

