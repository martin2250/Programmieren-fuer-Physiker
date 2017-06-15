/*
 * Programmieren fuer Physiker, SS 2017, Blatt 8, Aufgabe 20
 *
 * Struct fuer Rechteck
 */

#include <iostream>
using namespace std;

typedef struct
{
	double width, height;
}rechteck_t;

rechteck_t rotation(rechteck_t rect)
{
	return (rechteck_t){rect.height, rect.width};
}

int bedeckt(rechteck_t a, rechteck_t b)
{
	return (a.width >= b.width) && (a.height >= b.height);
}

int main()
{
    cout << "Rechteckstuct" << endl;
    rechteck_t r1 = {3.3, 2.0};
    rechteck_t r2 = {1.8, 2.7};

    cout << "Vor Rotation: ";
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2.";
    else cout << "r1 bedeckt r2 nicht.";
    cout << endl;

    r2 = rotation(r2);

    cout << "Nach Rotation: ";
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2.";
    else cout << "r1 bedeckt r2 nicht.";
    cout << endl;
}
