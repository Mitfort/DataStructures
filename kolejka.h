#pragma once

#ifndef KOLEJKA_H
#define KOLEJKA_H

#include<iostream>
#include<string>

template <typename T>
struct Node{
	T data;
	Node* nast = nullptr;
};

template<typename T,typename... Args>
void add(Node<T>*&kolejka, Args... args)
{
	T object{std::forward<Args>(args)...};

	if (kolejka == nullptr)
	{
		Node<T>* nowy = new Node<T>{ object ,nullptr};
		kolejka = nowy;
		return;
	}

	Node<T>* w = kolejka;

	while (w->nast != nullptr)
	{
		w = w->nast;
	}

	Node<T>* nowy = new Node<T>{ object, nullptr };
	w->nast = nowy;
}

template<typename T>
void remove(Node<T>*& kolejka)
{
	if (kolejka == nullptr)
	{
		std::cout << "Kolejka jest pusta";
		return;
	}

	Node<T>* copy = kolejka;
	kolejka = kolejka->nast;
	delete copy;
}

template<typename T>
int size(Node<T>* kolejka)
{
	int rozm = 0;

	while (kolejka != nullptr)
	{
		kolejka = kolejka->nast;
		rozm++;
	}

	return rozm;
}

template<typename T>
void display(Node<T>* kolejka)
{
	if (kolejka == nullptr)
	{
		std::cout << "Kolejka jest pusta" << '\n';
		return;
	}

	while (kolejka != nullptr)
	{
		std::cout << kolejka->data.imie << '\n';
		kolejka = kolejka->nast;
	}
}

#endif 
