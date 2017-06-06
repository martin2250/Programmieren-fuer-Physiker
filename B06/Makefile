.PHONY: all plot

all: 15-ascii-art 16-interpol

plot: plot.py interpolated.dat
	./plot.py

interpolated.dat: 16-interpol
	./16-interpol
