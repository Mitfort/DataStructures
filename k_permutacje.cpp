#include<iostream>
#include<string>
#include<sstream>

using namespace std;

//#define DEBUG
#ifdef DEBUG
ostream& debug = cout;
#else
ostringstream nullStream;
ostream& debug = nullStream;
#endif

void k_permutacji(const int n, const char* S[], const int k);
void permutuj(int left, int right, const char*S[],const int k,int counter);
const char** zamien(int left, int i,const char*S[]);

int silnia(int n)
{
	if (n <= 0) return 1;

	return n * silnia(n - 1);
}

int main()
{
	const int n = 5; //N-elementów
	const char* S[] = {"a","b","c","d","e"}; //ZBIOR
	const int k = 2; //K-permutacje

	const int ile_permutacji = silnia(n) / silnia(n-k);

	cout << "ILE PERMUTACJI: " << ile_permutacji << '\n';

	k_permutacji(n, S, k);

	return 0;
}

void k_permutacji(const int n, const char* S[], const int k)
{
	permutuj(0, n - 1,S,k,0);
}

void permutuj(int left, int right, const char* S[], const int k,int counter)
{
	if (counter == k)
	{
		debug << "COUNTER: " << counter << '\n';

		debug << "WYNIK: ";
		for (int i = 0; i < counter; i++)
		{
			cout << S[i];
		}

		cout << '\n';
	}
	else
	{
		for (int i = left; i <= right; i++)
		{
			debug << S[left] << " : " << S[i] << '\n';
			S = zamien(left, i,S);
			counter++;
			permutuj(left + 1, right, S,k,counter);
			counter--;
			debug << "COUNTER: " << counter << '\n';
			S = zamien(left, i,S);
		}
	}


}

const char** zamien(int left, int i,const char*S[])
{
	const char* help = S[left];
	S[left] = S[i];
	S[i] = help;

	return S;
}
