#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ofstream off("Rezultatas.txt");
    ifstream fin("Skaiciai.txt");
    
    int N;
    cout << "Iveskite elementu skaicu\n";
    cin >> N;
	//int N // aibes elementu skaicius
    /*int skaicius;

    cout << "Iveskite ieskoma skaiciu\n";
    cin >> skaicius;*/
	
	// sudarysime subalansuota dvejetaini paieskos medi is atsitiktinai sumaisyto masyvo
	vector<int> masyvas_atsitiktinis;
	// generuojame is pradziu surusiuota masyva
	for (int i = 1; i <= N; i++)
		masyvas_atsitiktinis.push_back(i);

    // inicializuojame atsitiktiniu skaiciu generatoriu:
	srand(1);
	// Atsitiktinai sumaisome masyva:
	random_shuffle(masyvas_atsitiktinis.begin(), masyvas_atsitiktinis.end());

	// subalansuotam dvejetainiam paieskos medziui naudosime C++ map duomenu struktura
	map< int, int > subalansuotas_medis;

	// sudarome subalansuota dvejetaini paieskos medi is gauto atsitiktinai sumaisyto masyvo
	for (int i = 0; i < N; i++) {
		int key = masyvas_atsitiktinis[i];
		int data = masyvas_atsitiktinis[i];
		subalansuotas_medis.insert(pair<int,int>(key,data));
	}

	// Atliekame skaiciaus paieska subalansuotame dvejetainiame paieskos medyje:
    clock_t startas;
    clock_t pabaiga;
    int num;
    map<int,int>::iterator iterator;
    while(!fin.eof())
    {
        fin >> num;
        cout << "Ieskome skaiciaus " << num << endl;
        iterator = subalansuotas_medis.find(num);

        if (iterator!=subalansuotas_medis.end())
        {
            cout << "Skaicius " << iterator->first << " rastas" << endl;
            off << "Skaicius " << iterator->first << " rastas" << endl;
        }   
        else
        {
            cout << "Skaicius " << num << " nerastas" << endl;
            off << "Skaicius " << num << " nerastas" << endl;
        }
        iterator = subalansuotas_medis.begin();
    }

    off.close();
    fin.close();

    return 0;
}