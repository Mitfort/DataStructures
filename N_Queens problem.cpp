#include<iostream>

using namespace std;

//struct Hetman {
//	int x;
//	int y;
//};

const int PUSTE = -1;

//int abs(int a, int b)
//{
//	return a - b < 0 ? -(a - b) : (a - b);
//}

bool isValid(int **board,int N, int row, int col)
{
	int j = col;
	int jLeft = j;
	int jRight = j;
	bool moveRight = true;
	bool moveLeft = true;

	while (row > 0)
	{	
		row--;
		if (jLeft - 1 >= 0)
		{
			jLeft--;
		}
		else
		{
			moveLeft = false;
		}

		if (jRight + 1 < N)
		{
			jRight++;
		}
		else
		{
			moveRight = false;
		}

		if (board[row][j] != PUSTE)
		{
			return false;
		}

		if (moveLeft && board[row][jLeft] != PUSTE)
		{
			return false;
		}

		if (moveRight && board[row][jRight] != PUSTE)
		{
			return false;
		}
	}

	return true;
}

void wyswietl_plansze(int** board, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1) //MA HETMANA
			{
				cout << "[]";
			}
			else
			{
				(i + j) % 2 == 0 ? cout << "  " : cout << "##";
			}
		}

		cout << '\n';
	}

	//cout << "--------------";
	cout << '\n';
}


int szukaj_rozwiazan(int **board,int N, int row)
{
	if (row == N)
	{
		wyswietl_plansze(board, N);
		return 1;
	}

	int counter = 0;

	for (int col = 0; col < N; col++)
	{
		if (isValid(board, N, row, col))
		{
			board[row][col] = 1;
			//wyswietl_plansze(board, N);
			counter += szukaj_rozwiazan(board, N, row + 1);
			board[row][col] = PUSTE;
		}
	}

	return counter;
}

int main()
{
	short N; 
	cout << "N: ";
	cin >> N;

	int** board = new int* [N];

	for (int i = 0; i < N; i++)
	{
		*(board + i) = new int[N];

		for (int j = 0; j < N; j++)
		{
			*(*(board + i) + j) = PUSTE;
		}
	}

	//cout << "ILE ROZW: " << szukaj_rozwiazan(board, N, 0);	

	szukaj_rozwiazan(board, N, 0);

	for (int i = 0; i < N; i++)
	{
		delete[] board[i];
	}

	delete[] board;

	return 0;
}
