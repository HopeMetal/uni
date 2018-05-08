// Lab02.cpp : Defines the entry point for the console application.
// Paieskos masyve laiko ir veiksmu skaiciaus skaiciavimas
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int array_find(vector<int> &array, int num)
{
	for(unsigned int i = 0; i < array.size(); i++)
		if (array[i] == num) return i + 1;
	return -1;
}

int array_find_veiksmai(vector<int> &array, int num)
{
	int vsk = 0; //veiksmu skaicius
	for (unsigned int i = 0; i < array.size(); i++)
	{
		vsk++;
		if (array[i] == num) break;
	}
	return vsk;
}

int main()
{
	int N = 100; //masyvo dydis
	int K = 100000; //kartojim� skai�ius

	int s = 4; //ieskomas skaicius

	srand(time(NULL));

	vector<int> masyvas_s; //masyvas surusiuotas
	vector<int> masyvas_ats; //masyvas atsitiktinis

	for (int i = 1; i <= N; i++)
	{
		int num = rand() % N + 1;
		cout << num << endl;
		masyvas_ats.push_back(num);
		masyvas_s.push_back(i);
	}

	clock_t startas = clock();

	//paieska surusiuotame masyve
	int result;
	for (int i = 0; i < K; i++)
		result = array_find(masyvas_s, s);

	clock_t pabaiga = clock();

	double laikas = double(pabaiga - startas) / CLOCKS_PER_SEC / N / K * 1000;

	cout << "Laikas (surusiuotas masyvas): " << laikas << " ms\n";
	cout << "Skaicius " << s << " yra " << result << "-as masyvo elementas\n";

	int veiksmu_sk = array_find_veiksmai(masyvas_s, s);
	cout << "Atliktu veiksmu skaicius: " << veiksmu_sk << endl;
	//
	startas = clock();

	//paieska atsitiktiniame masyve
	for (int i = 0; i < K; i++)
		result = array_find(masyvas_ats, s);

	pabaiga = clock();

	laikas = double(pabaiga - startas) / CLOCKS_PER_SEC * 1000;

	cout << "Laikas (atsitiktinis masyvas): " << laikas << " ms\n";
	cout << "Skaicius " << s << " yra " << result << "-as masyvo elementas\n";

	veiksmu_sk = array_find_veiksmai(masyvas_ats, s);
	cout << "Atliktu veiksmu skaicius: " << veiksmu_sk << endl;

    return 0;
}

