
#include "vector.h"

int main()
{
	//--------LAIKO MATAVIMAS--------------
	// Pradėti v1 užpildymo laiko matavimą
	// vector<int> v1;
	// auto start = high_resolution_clock::now();
	// auto stop = high_resolution_clock::now();
	// duration<double> laikas = stop - start;
	// for (int sz = 10000; sz <= 10000000; sz *= 10)
	// {
	// 	start = high_resolution_clock::now();
	// 	for (int i = 1; i <= sz; ++i)
	// 			v1.push_back(i);
	// 	stop = high_resolution_clock::now();
	// 	laikas = stop - start;
	// 	cout << sz << " std::vector: " << laikas.count() << endl;
	// }
	
	// // Baigti v1 užpildymo laiko matavimą

	// // Pradėti v2 užpildymo laiko matavimą
	// MyVector<int> v2;
	// for (int sz = 10000; sz <= 10000000; sz *= 10)
	// {
	// 	start = high_resolution_clock::now();
	// 	for (int i = 1; i <= sz; ++i)
	// 		v1.push_back(i);
	// 	stop = high_resolution_clock::now();
	// 	laikas = stop - start;
	// 	cout << sz << " Mano vektorius: " << laikas.count() << endl;
	// }
	// Baigti v2 užpildymo laiko matavimą


	MyVector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	cout << "Pirmas elementas: " << test.begin() << endl << endl;
	
	//---------Shrink_To_Fit------
	MyVector<int> test2;
	test2.push_back(1);
	test2.push_back(2);
	test2.push_back(3);

	cout << "Capacity pries Shrink_To_Fit: " << test2.gettalpa() << endl;

	test2.shrink_to_fit();
	cout << "Capacity po Shrink_To_Fit: " << test2.gettalpa() << endl;

	//-----Operator= --------------
	MyVector<int> test3;
	MyVector<int> copy;
	test3.push_back(1);
	test3.push_back(2);
	copy = test3;
	cout << "Copy elementai: ";
	copy.print();

	//-----erase-----------------
	MyVector<int> test4;
	test4.push_back(1);
	test4.push_back(2);
	test4.push_back(3);
	cout << "Pradiniai elementai: ";
	test4.print();

	test4.erase(1);
	cout << "Elementai po trynimo: ";
	test4.print();

	//-----pop_back-----------------
	MyVector<int> test5;
	test5.push_back(1);
	test5.push_back(2);
	test5.push_back(3);
	cout << "Pradiniai elementai: ";
	test5.print();

	test5.pop_back();
	cout << "Elementai po pop_back: ";
	test5.print();


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

}