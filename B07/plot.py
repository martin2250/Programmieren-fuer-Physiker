#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

(X, Y) = np.loadtxt('interpolated.dat', unpack=True)
(X_old, Y_old) = np.loadtxt('../B06/interpolated.dat', unpack=True)
(Xo, Yo) = np.loadtxt('../B06/a16-interpol.dat', unpack=True)

plt.plot(X_old, Y_old, 'g', label='polynomial')
plt.plot(X, Y, 'b', label='cubic splines')
plt.plot(Xo, Yo, 'or')
plt.legend()
plt.show()
