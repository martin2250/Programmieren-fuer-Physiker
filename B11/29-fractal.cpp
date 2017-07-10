#include <iostream>
#include <CImg.h>
using namespace cimg_library;

const unsigned char black[3] = { 0, 0, 0} , white[3] = { 255, 255, 255}, red[3] = { 255, 0,0 }, green[3] = { 0, 255, 0 }, blue[3] = { 0, 0, 255 }, yellow[3] = { 255, 255, 0 };

const float adiff = 3.141592653589 * 60. / 180.;

void draw(CImg<unsigned char>& canvas, float x, float y, float angle, int order, int direction, float length)
{
	if(length <= 0.5)
	{
		canvas.draw_point(std::round(x), std::round(y), 0, white);
	}
	else if(order == 0)
	{
		canvas.draw_line(std::round(x), std::round(y), std::round(x + length * cos(angle)), std::round(y + length * sin(angle)), white);
	}
	else
	{
		length /= 2;

		draw(canvas, x, y,
			angle + direction * adiff,
			order - 1,
			-direction,
			length
		);

		draw(canvas,
			x + length * cos(angle + direction * adiff),
			y + length * sin(angle + direction * adiff),
			angle,
			order - 1,
			direction,
			length
		);

		draw(canvas,
			x + length * cos(angle + direction * adiff) + length * cos(angle),
			y + length * sin(angle + direction * adiff) + length * sin(angle),
			angle - direction * adiff,
			order - 1,
			-direction,
			length
		);
	}
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "usage: ./" << argv[0] << " [order]" << std::endl;
		return 1;
	}

	int startorder = atoi(argv[1]);

	if(startorder < 0)
	{
		std::cout << "start order must be >= zero" << std::endl;
		return 1;
	}

    CImg<unsigned char> canvas( 1000, 1000, 1, 3, 0);
    CImgDisplay window( canvas, "Fractal");

    while (!window.is_closed())
    {
		canvas.fill(0) ;
		draw(canvas, 50, 50, 0, startorder++, 1, 900);

	    window.display(canvas) ;

		while(!window.button() && !window.key() && !window.is_closed())
			window.wait();
		while((window.button() || window.key()) && !window.is_closed())
			window.wait();
	}
}
