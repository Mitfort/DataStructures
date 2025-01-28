#include<iostream>

using namespace std;

struct Wezel{
	int data = 0;
	Wezel* next = nullptr;
};

struct HashTable {
	static const int size = 20;
	Wezel* table[size];

	HashTable()
	{
		for (int i = 0; i < size; i++)
		{
			*(table + i) = nullptr;
		}
	}

	int hashfuntion(int key) const {
		return key % size;
	}

	void insert(int value)
	{
		int hashKey = hashfuntion(value);

		Wezel* w = table[hashKey];
		Wezel* nowy = new Wezel{ value };

		if (w == nullptr)
		{
			table[hashKey] = nowy;
			return;
		}

		while (w->next != nullptr)
		{
			w = w->next;
		}

		w->next = nowy;
	}

	int chainLength(int value) const {
		int hashKey = hashfuntion(value);
		Wezel* w = table[hashKey];

		if (w == nullptr) return 0;

		int size = 1;
		while (w->next != nullptr)
		{
			size++;
			w = w->next;
		}

		return size;
	}

	void longestChain()
	{
		int longestChainSize = 0;
		for (int i = 0; i < size; i++)
		{
			int length = chainLength(i);
			cout << "LENGTH: " << length << '[' << i << ']' << '\n';
			if (length > longestChainSize)
			{
				longestChainSize = length;
			}
		}

		cout << "LONGEST CHAIN SIZE: " << longestChainSize << '\n';
	}

};

int main()
{
	HashTable HT;
	const int n = 10;
	int value = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> value;
		HT.insert(value);
	}

	HT.longestChain();


	return 0;
}
