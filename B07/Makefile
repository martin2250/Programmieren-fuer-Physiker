.PHONY: all

all: 18-roman 17-cubic-splines interpolated.dat

interpolated.dat: 17-cubic-splines
	./17-cubic-splines

plot: interpolated.dat
	./plot.py
