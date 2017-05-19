#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

C = np.loadtxt('out.txt')
N = np.arange(0, len(C))
plt.plot(N, C)
plt.show()
