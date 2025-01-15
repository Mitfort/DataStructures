#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc,char * argv[])
{
	string sciezka = argv[1];
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	int n_points = atoi(argv[4]);

	float x = rand() % width;
	float y = rand() % height;

	int** tab = new int*[height];

	for (int i = 0; i < height; i++)
	{
		*(tab + i) = new int[width];

		for (int j = 0; j < width; j++)
		{
			*(*(tab + i) + j) = 0;
		}
	}

	float przesuniecie_k = width / 2.0f;
	float przesuniecie_w = 50;
	float skalowanie_k = przesuniecie_k / 3;
	float skalowanie_w = (height - 100) / 10.f;


	for (int i = 0; i < n_points; i++)
	{
		int los = (rand() % 101) + 1;
		float newX = 0;
		float newY = 0;

		if (los <= 85)
		{
			newX = 0.85 * x + 0.04 * y;
			newY = -0.04 * x + -0.85 * y + 1.6;
		}
		else if (los >= 86 && los <= 92)
		{
			newX = -0.15 * x + 0.28 * y;
			newY = 0.26 * x + 0.24 * y + 0.44;
		}
		else if (los >= 93 && los <= 99)
		{
			newX = 0.20 * x - 0.26 * y;
			newY = -0.23 * x + 0.22 * y + 1.6;
		}
		else {
			newX = 0;
			newY = 0.16 * y;
		}

		int IndexX = static_cast<int>(skalowanie_k * newX + przesuniecie_k);
		int IndexY = static_cast<int>(skalowanie_w * newY + przesuniecie_w);

		if (IndexX >= 0 && IndexX < width && IndexY >= 0 && IndexY < height)
		{
			int value = tab[height - IndexY][IndexX] + 20;
			tab[height - IndexY][IndexX] = value > 255 ? 255 : value; 
		}

		x = newX;
		y = newY;

	}

	fstream file;

	file.open(sciezka, fstream::out);

	if (!file.good()) return 0;

	file << "P5" << '\n';
	file << width << " " << height << '\n';
	file << 255 << '\n';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file.put(tab[i][j]);
		}
	}

	file.close();

	for (int i = 0; i < height; i++)
	{
		delete[] tab[i];
	}

	delete[] tab;

	return 0;
}
