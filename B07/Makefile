.PHONY: all plot

all: 18-roman 17-cubic-splines

interpolated.dat: 17-cubic-splines
	./17-cubic-splines

../B06/interpolated.dat:
	make -C "../B06" interpolated.dat

plot: interpolated.dat ../B06/interpolated.dat
	./plot.py
