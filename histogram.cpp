#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cmath>

using namespace std;

#define DEBUG
#ifdef DEBUG
ostream& debug = cout;
#else
ostringstream nullStream;
ostream& debug = nullStream;
#endif

int main(int argc,char*argv[])
{
	string inputPath = argv[1];
	string outputPath = argv[2];

	fstream file1;
	file1.open(inputPath, fstream::in | fstream::binary);

	if (!file1.good()) return 0;

	string format = "";
	int width = 0;
	int height = 0;
	int maxValue = 0;

	file1 >> format >> width >> height >> maxValue;
	file1.ignore();
	debug << format << " " << width << " " << height << " " << maxValue;

	int* wystapienia = new int[maxValue];
	int* dystrybuanty = new int[maxValue];

	for (int i = 0; i < maxValue; i++)
	{
		*(wystapienia + i) = 0;
		*(dystrybuanty + i) = 0;
	}

	int** tab = new int* [height];

	debug << '\n' << "STARE WARTOSCI" << '\n';

	for (int i = 0; i < height; i++)
	{
		*(tab + i) = new int[width];

		for (int j = 0; j < width; j++)
		{
			int wartosc = (file1.get());
			debug << wartosc << " ";
			*(*(tab + i) + j) = wartosc;
			wystapienia[wartosc]++;
		}
		debug << '\n';
	}

	debug << "---------------------------------------" << '\n';

	file1.close();

	int suma = 0;
	
	debug << "DYSTRYBUANTY" << '\n';
	for (int i = 0; i < maxValue; i++)
	{
		suma += wystapienia[i];
		dystrybuanty[i] = suma;
		debug << dystrybuanty[i] << " ";
	}

	debug << "------------------------------" << '\n';

	int min_dystrybuanta = 0;

	for (int i=0; i < maxValue; i++)
	{
		if (dystrybuanty[i] > 0)
		{
			min_dystrybuanta = dystrybuanty[i];
			break;
		}
	}

	debug << "MIN DYST: " << min_dystrybuanta << '\n';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int nowaWartosc = (round(((dystrybuanty[tab[i][j]] - min_dystrybuanta) / ((width * height) - min_dystrybuanta)) * (maxValue - 1)));
			debug << nowaWartosc << " ";
			tab[i][j] = nowaWartosc;
		}
	}

	debug << "-------------------------------";

	fstream file2;
	file2.open(outputPath, fstream::out | fstream::binary);

	if (!file2.good()) return 0;

	file2 << format << '\n';
	file2 << width << " " << height << '\n';
	file2 << maxValue << '\n';

	debug << '\n';
	debug << "NOWE WARTOSCI" << '\n';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file2.put(tab[i][j]);
			debug << tab[i][j] << " ";
		}

		debug << '\n';
	}

	file2.close();

	for (int i = 0; i < height; i++)
	{
		delete[] tab[i];
	}

	delete[] tab;

	return 0;
}
