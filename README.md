# Vector klasės implementacija

# Užpildymo greičio palyginimas

10000 std::vector: 0
100000 std::vector: 0.002001
1000000 std::vector: 0.015012
10000000 std::vector: 0.165038
---------------------------------
10000 Mano vektorius: 0
100000 Mano vektorius: 0.001001
1000000 Mano vektorius: 0.013003
10000000 Mano vektorius: 0.176933

# begin() funkcija
### Funkcija gražinanti pirmą reikšmę

Funkcija:
T& begin()
{
  return arr[0];
}

Testas:

MyVector<int> test;
test.push_back(1);
test.push_back(2);
test.push_back(3);
cout << "Pirmas elementas: " << test.begin() << endl << endl;

Output:

Pirmas elementas: 1

# shrink_to_fit() funkcija

Funkcija:

void shrink_to_fit()
{
  capacity = current;
  T* newarr = new T[capacity];
  for (int i = 0; i < capacity; i++)
  {
    newarr[i] = arr[i];
  }
  delete[] arr;
  arr = newarr;
}

Testas:

MyVector<int> test2;
test2.push_back(1);
test2.push_back(2);
test2.push_back(3);

cout << "Capacity pries Shrink_To_Fit: " << test2.getcapacity() << endl;

test2.shrink_to_fit();
cout << "Capacity po Shrink_To_Fit: " << test2.getcapacity() << endl;

Output: 

Capacity pries Shrink_To_Fit: 4
Capacity po Shrink_To_Fit: 3

# operator=

Funkcija

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

Testas:

MyVector<int> test3;
MyVector<int> copy;
test3.push_back(1);
test3.push_back(2);
copy = test3;
cout << "Copy elementai: ";
copy.print();

Output:

Copy elementai: 1 2

# erase() funkcija

Funkcija:

void erase(int index)
{
  for (int i = index; i < current - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  current--;
}

Testas:

MyVector<int> test4;
test4.push_back(1);
test4.push_back(2);
test4.push_back(3);
cout << "Pradiniai elementai: ";
test4.print();

test4.erase(1);
cout << "Elementai po trynimo: ";
test4.print();

Output:

Pradiniai elementai: 1 2 3
Elementai po trynimo: 1 3

# pop_back() funkcija

Funkcija:

void pop_back()
{ 
  current--;
} 

Testas:

MyVector<int> test5;
test5.push_back(1);
test5.push_back(2);
test5.push_back(3);
cout << "Pradiniai elementai: ";
test5.print();

test5.pop_back();
cout << "Elementai po pop_back: ";
test5.print();

Output:

Pradiniai elementai: 1 2 3
Elementai po pop_back: 1 2

# Atminties perskirstymas

Testas:

unsigned int sz = 100000000;
int p1 = 0, p2 = 0;

vector<int> v1;
for (int i = 1; i <= sz; ++i) {
  v1.push_back(i);
  if (v1.size() == v1.capacity())
    p1++;
}

MyVector<int> v2;
for (int i = 1; i <= sz; ++i) {
  v2.push_back(i);
  if (v2.size() == v2.gettalpa())
    p2++;
}
cout << "std::vector: " << p1 << endl;
cout << "MyVector: " << p2 << endl;

output:

std::vector: 27
MyVector: 27



