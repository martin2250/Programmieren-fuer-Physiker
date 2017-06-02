#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

(X, Y) = np.loadtxt('interpolated.dat', unpack=True)
(Xo, Yo) = np.loadtxt('a16-interpol.dat', unpack=True)

plt.plot(X, Y)
plt.plot(Xo, Yo, 'o')
plt.show()
