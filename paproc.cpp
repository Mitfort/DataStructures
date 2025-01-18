#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string sciezka = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int n_points = atoi(argv[4]);

    float x = 0.0f, y = 0.0f;

    int** tab = new int* [height];
    
    for (int i = 0; i < height; i++) 
    {
        *(tab + i) = new int[width]();
    }

    float przesuniecie_k = width / 2.0f;
    float przesuniecie_w = height * 0.1f;
    float skalowanie_k = width / 5.0f;
    float skalowanie_w = height / 10.0f;

    for (int i = 0; i < n_points; i++) 
    {
        int los = rand() % 100 + 1;
        float newX, newY;

        if (los <= 85) 
        {
            newX = 0.85 * x + 0.04 * y;
            newY = -0.04 * x + 0.85 * y + 1.6;
        }
        else if (los <= 92)
        {
            newX = -0.15 * x + 0.28 * y;
            newY = 0.26 * x + 0.24 * y + 0.44;
        }
        else if (los <= 99)
        {
            newX = 0.2 * x - 0.26 * y;
            newY = 0.23 * x + 0.22 * y + 1.6;
        }
        else
        {
            newX = 0.0;
            newY = 0.16 * y;
        }

        int IndexX = static_cast<int>(skalowanie_k * newX + przesuniecie_k);
        int IndexY = static_cast<int>(skalowanie_w * newY + przesuniecie_w);

        if (IndexX >= 0 && IndexX < width && IndexY >= 0 && IndexY < height) 
        {
            tab[height - 1 - IndexY][IndexX] = (tab[height - 1 - IndexY][IndexX] + 20, 255);
        }

        x = newX;
        y = newY;
    }

    ofstream file(sciezka, ios::binary);
    
    if (!file.good()) return 0;

    file << "P5\n" << width << " " << height << "\n255\n";
    
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            file.put(static_cast<unsigned char>(tab[i][j]));
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
