// Lab02medis.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Tree.hpp"

using namespace std;

const char* fname = "Rezultatas.txt";

void print_result(const char* name)
{
	ifstream in;
	in.open(name);
	if (in.is_open())
	{
	/*while(!in.eof())
		cout << in;*/
		cout << in;
	in.close();
	}
	else
		cout << "print_result: Failed to open file for writing\n";
}

int main()
{
	ofstream off(fname);
	cout << fixed << setprecision(3);
	srand(time(NULL));

	int N = 100; //elementu skaicius
	int K = 1000000; //kartojimu skaicius

	int s;
	cout << "Iveskite ieskoma skaiciu" << endl;
	cin >> s;

	Tree medis;

	for (int i = 0; i < N; i++)
	{
		int num = rand() / N;
		medis.insert(num);
	}
	medis.printInfix();

	clock_t startas;
	clock_t pabaiga;
	node *e = NULL; //surastas elementas

	startas = clock();
	for (int i = 0; i < K; i++)
	{
		e = medis.find(s);
	}
	pabaiga = clock();

	double laikas = double(pabaiga - startas) / CLOCKS_PER_SEC;

	if (e) off << "Elementas " << s << " rastas\n";
	else off << "Elementas " << s << " nerastas\n";
	off << "Paieskos laikas: " << laikas << " s\n";

	if (e)
	{
		int vskaicius = medis.get_vsk();
		off << "Atliktu veiksmu skaicius: " << vskaicius << endl;
	}
	off.close();
	print_result(fname);

    return 0;
}

