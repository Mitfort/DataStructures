#pragma once

#ifndef STOS_H
#define STOS_H

#include<iostream>

template<typename T>
struct Node {
	T object;
	Node* poprz = nullptr;
	void add(Node<T>*& stos, T value);
	void remove(Node<T>*& stos);
	void check_top(Node<T>* stos);
	int rozmiar(Node<T>* stos);
	bool czy_pusty(Node<T>* stos);
	void wypisz(Node<T>* stos);
};

template<typename T>
void Node<T>::add(Node<T>*& stos, T value)
{
	Node<T>* nowy = new Node<T>{ value,stos };
	stos = nowy;
}

template<typename T>
void Node<T>::remove(Node<T>*& stos)
{
	if (stos == nullptr)
	{
		std::cout << "Stos jest pusty";
		return;
	}

	Node<T>* kopia = stos;

	stos = stos->poprz;

	delete kopia;
}

template<typename T>
void Node<T>::check_top(Node<T>* stos)
{
	if (stos == nullptr)
	{
		std::cout << "Stos jest pusty" << '\n';
		return;
	}

	std::cout << "Na wierzchu stosu: " << stos->object << '\n';
}

template<typename T>
int Node<T>::rozmiar(Node<T>* stos)
{
	int rozm = 0;

	while (stos != nullptr)
	{
		rozm++;
		stos = stos->poprz;
	}

	std::cout << "Rozmiar stosu: " << rozm << '\n';
	return rozm;
}

template<typename T>
bool Node<T>::czy_pusty(Node<T>* stos)
{
	if (stos == nullptr)
	{
		//std::cout << "Stos jest pusty" << '\n';
		return true;
	}

	//std::cout << "Stos nie jest pusty" << '\n';
	return false;
}

template<typename T>
void Node<T>::wypisz(Node<T>* stos)
{
	if (stos == nullptr)
	{
		std::cout << "Stos jest pusty" << '\n';
		return;
	}

	int idx = 1;
	int idxCopy = idx;

	while (stos != nullptr)
	{
		std::cout << "[";
		int* tab = new int[3];
		for (int i = 0; i < 3; i++)
		{
			tab[i] = -1;
		}

		int i = 2;
		while (idx > 0)
		{
			tab[i] = idx % 10;
			idx /= 10;
			i--;
		}

		for (int i = 0; i < 3; i++)
		{
			if (tab[i] != -1)
			{
				std::cout << tab[i];
			}
			else
			{
				std::cout << " ";
			}
		}

		std::cout << "] " << stos->object << '\n';
		stos = stos->poprz;
		idx = idxCopy + 1;
		idxCopy++;
	}
}

#endif
