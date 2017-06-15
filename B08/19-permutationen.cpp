/*
 * Programmieren fuer Physiker, SS 2017, Blatt 8, Aufgabe 19
 *
 * Permutationen in lexikographischer Ordnung generieren
 * (Fragment, zu ergaenzen)
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(char* ptr, int a, int b)
{
	char tmp = ptr[a];
	ptr[a] = ptr[b];
	ptr[b] = tmp;
	//cout << "swapping " << a << "\t" << b << endl;
}

int next_permutation(char* ptr, int size)
{
	int k = -1;

	for(int i = 0; i < (size - 1); i++)
	{
		if(ptr[i] < ptr[i + 1])
			k = i;
	}

	if(k == -1)
		return 0;

	int l = -1;

	for(int i = 0; i < size; i++)
	{
		if(ptr[k] < ptr[i])
			l = i;
	}

	swap(ptr, k, l);

	int toswap = size - (k + 1);

	for(int i = 0; i < (toswap / 2); i++)
	{
		swap(ptr, k + 1 + i, size - (i + 1));
	}

	return 1;
}

int main()
{
    // Beispieldatensatz, muss sortiert vorliegen
    const int size=6;
    char wort[] = {'A','E','E','F','F','K'};

    cout << "Generierung aller Permutationen" << endl << endl;

    // Hauptschleife, erzeuge alle Permutationen
    int anzperm = 0;      // zaehle die Permutationen
    do
    {
		++anzperm;
		cout << "Nr: " << anzperm << "  ";
		for( int i=0; i<size; i++)
		    cout << wort[i] << " ";
		cout << endl;
    }
    while (next_permutation(wort, size));

    cout << "Anzahl der Permutationen: " << anzperm << endl;
}

//Zusatzfrage: https://de.wikipedia.org/wiki/Permutation#Permutation_mit_Wiederholung
