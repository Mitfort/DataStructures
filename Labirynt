#include<iostream>
#include<fstream>
#include<iomanip>
#include"Stos.h"

using namespace std;

#define DEBUG

#ifdef DEBUG
ostream& debug = cout;
#else
ostream debug = ostream(nullptr);
#endif

struct Punkt {
	int value = 0;
	bool odwiedzone = false;
	int x = 0;
	int y = 0;
};

Punkt** szukaj_wyjscia(Punkt** maze, int width, int height,int startX,int startY,int koniecX, int koniecY)
{
	Node<Punkt>* stos = nullptr;

	stos->add(stos,maze[1][0]);
	int row = startY;
	int col = startX;

	while (!stos->czy_pusty(stos))
	{
		bool czyMaPrzejscie = false;

		col = stos->object.x;
		row = stos->object.y;

		maze[row][col].value = 100;
		maze[row][col].odwiedzone = true;

		if (row == koniecY && col == koniecX)
		{
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					debug << setw(4) << maze[i][j].value << " ";
				}

				debug << '\n';
			}

			return maze;
		}

		if (row + 1 < height)
		{
			if (maze[row + 1][col].value == 255 && !maze[row + 1][col].odwiedzone)
			{
				stos->add(stos, maze[row + 1][col]);
				czyMaPrzejscie = true;
			}
		}

		if (row - 1 >= 0)
		{
			if (maze[row - 1][col].value == 255 && !maze[row - 1][col].odwiedzone)
			{
				stos->add(stos, maze[row - 1][col]);
				czyMaPrzejscie = true;
			}
		}

		if (col + 1 < width)
		{
			if (maze[row][col+1].value == 255 && !maze[row][col + 1].odwiedzone)
			{
				stos->add(stos, maze[row][col+1]);
				czyMaPrzejscie = true;
			}
		}

		if (col - 1 >= 0)
		{
			if (maze[row][col-1].value == 255 && !maze[row][col-1].odwiedzone)
			{
				stos->add(stos, maze[row][col - 1]);
				czyMaPrzejscie = true;
			}
		}

		if (!czyMaPrzejscie)
		{
			maze[row][col].value = 50;
			stos->remove(stos);
		}
	}
}

void zapisz_obrazek(Punkt**maze, const char* plik_wyjsciowy, int width, int height)
{
	fstream file;
	file.open(plik_wyjsciowy, ios::out | ios::binary);

	if (!file.good()) return;

	file << "P5" << '\n' << width << " " << height << '\n' << "255\n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file.put(maze[i][j].value);
		}
	}
	file.close();
}


int main(int argc,char*argv[])
{
	fstream file;

	file.open(argv[1], fstream::in);

	if (!file.good()) return 0;

	string format = "";
	int width = 0;
	int height = 0;
	int maxValue = 0;

	file >> format;
	file >> width >> height;
	file >> maxValue;

	Punkt** maze = new Punkt* [height];

	file.ignore();
	for (int i = 0; i < height; i++)
	{
		*(maze + i) = new Punkt[width];

		for (int j = 0; j < width; j++)
		{
			unsigned char pixel;
			file.read(reinterpret_cast<char*>(&pixel), sizeof(pixel));
			int value = static_cast<int>(pixel);
			*(*(maze + i) + j) = Punkt{ value,false,j,i };
		}
	}

	file.close();

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			debug << setw(4) << maze[i][j].value << " ";
		}
		debug << '\n';
	}

	debug << '\n';

	maze = szukaj_wyjscia(maze, width, height, 0, 1, width - 1, height - 2);

	zapisz_obrazek(maze, argv[2], width, height);

	for (int i = 0; i < height; i++)
	{
		delete[] maze[i];
	}

	delete[] maze;

	return 0;
}
