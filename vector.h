#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;


template <typename T> class MyVector
{

	// arr is the integer pointer
	// which stores the address of our vector
	T* arr;

	int talpa; //talpa

	int elKiekis; //elementu kiekis

public:
		//member functions
	MyVector() //default konstruktorius
	{
		arr = new T[1];
		talpa = 1;
		elKiekis = 0;
	}
	~MyVector()//destruktorius
	{
		delete[] arr;
	};

	MyVector& operator =(const MyVector& temp)//= operatorius
	{
		if (temp.elKiekis > elKiekis)
		{
			delete[] arr;
			talpa = temp.elKiekis;
			arr = new int[talpa];
		}
		for (int i = 0; i < temp.elKiekis; i++)
		{
			arr[i] = temp.arr[i];
		}

		elKiekis = temp.elKiekis;

		return *this;
	}

	
		//index element access
	T& operator[](int a)
	{
		return arr[a];
	}
	T& at(int index)
	{
		return arr[index];
	}
	T& front()
	{
		return arr[0];
	}
	T& back()
	{
		return arr[elKiekis - 1];
	}
	T& data()
	{
		return arr;
	}
		//iterators
	
	T& begin()
	{
		return arr[0];
	}
	T& end()
	{
		return arr[elKiekis - 1];
	}
	T& rbegin()
	{
		return arr[elKiekis - 1];
	}
	T& rend()
	{
		return arr[0];
	}

		//talpa
	int size() { return elKiekis; }// function to get size of the vector
	int gettalpa() { return talpa; }// function to get talpa of the vector
	bool empty()
	{
		return elKiekis == 0;
	}
	void reserve(int n)
	{
		if (n < talpa)
		{
			talpa = n;
		}
		
	}
	void shrink_to_fit()
	{
		talpa = elKiekis;
		T* newarr = new T[talpa];
		for (int i = 0; i < talpa; i++)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}

		//modifiers
	void clear()
	{
		elKiekis = 0;
	}
	void insert(int index, int value)
	{
		if (talpa != elKiekis)
		{
			for (int i = elKiekis - 1; i >= index; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[index] = value;
			elKiekis++;
		}
		else
		{
			talpa *= 2;
			T* newarray = new T[talpa];
			for (int i = 0; i < elKiekis; i++)
			{
				newarray[i] = arr[i];
			}
			delete[] arr;
			arr = newarray;
			insert(index, value);
		}
	}
	void erase(int index)
	{
		for (int i = index; i < elKiekis - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		elKiekis--;
	}
	void resize(int n)
	{
		talpa = n;
		T* newarr = new T[talpa];
		for (int i = 0; i < elKiekis; i++)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}
	
	
	void push_back(T data) //std::vector push
	{
		if (elKiekis == talpa) { //jeigu sutampa talpa su elementu skaiciumi, padidiname talpa
			T* temp = new T[2 * talpa];

			for (int i = 0; i < talpa; i++) { //kopijuojam visus elementus
				temp[i] = arr[i];
			}

			delete[] arr; //istriname pradini masyva
			talpa *= 2;
			arr = temp;
		}

		arr[elKiekis] = data; //irasome naujus duomenis
		elKiekis++;
	}

	T get(int index) //funkcija gauti norima elementa zinant jo numeri
	{
		if (index < elKiekis) 
			return arr[index];
	}

	void pop_back() //funkcija istrinanti paskutini elementa
	{ 
		elKiekis--;
	} 
	
		//operatoriai
	bool operator==(const MyVector& temp) const
	{
		if (size() != temp.size())
		{
			return false;
		}
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] != temp.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const MyVector& temp) const
	{
		return !(*this == temp);
	}
	bool operator<(const MyVector& temp) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] > temp.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator<=(const MyVector& temp) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] >= temp.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator>(const MyVector& temp) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] < temp.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator>=(const MyVector& temp) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] <= temp.arr[i])
			{
				return false;
			}
		}
		return true;
	}



	void print()
	{
		for (int i = 0; i < elKiekis; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};