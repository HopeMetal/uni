// Lab02medis.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

// dvejetainio medzio virsune-mazgas
struct node {
	int data; // medyje saugomu duomenu tipas, bendruoju atveju: T data;
	node *left; // nuoroda i kairiji pomedi
	node *right;// nuoroda i desiniji pomedi
};

// dvejetainio paieskos medzio klase - C++ realizacija
class Tree
{
private:
	node* root; // medzio saknis

				// Medzio virsunes-mazgo rekursinis iterpimo algoritmas 
	void addRecursive(int data, node* &mazgas) {

		if (mazgas != NULL) // dar ne tuscia virsune-mazgas
			if (data < mazgas->data)
				addRecursive(data, mazgas->left); // iterpsime i kairiji pomedi 
			else
				addRecursive(data, mazgas->right);// iterpsime i desiniji pomedi
		else { // pasiekeme sakos gala
			mazgas = new node; // sukuriame nauja virsune-mazga
			mazgas->data = data;
			mazgas->left = NULL;
			mazgas->right = NULL;
		}
	}

	// rekursinis paieskos algoritmas
	node* findRecursive(int skaicius, node* mazgas) {

		if (mazgas != NULL) {
			if (skaicius == mazgas->data) // palyginimo veiksmas
				return mazgas;
			else { // jei dar neradome
				if (skaicius < mazgas->data)
					return findRecursive(skaicius, mazgas->left); // tikrinsime kairiji pomedi 
				else
					return findRecursive(skaicius, mazgas->right);// tikrinsime desiniji pomedi
			}
		}
		return NULL;
	}
	//paieskos veiksmu skaiciaus skaiciavimas
	int findRecursive_vskaicius(int skaicius, node* mazgas, int &vsk)
	{
		if (mazgas != NULL) {
			if (skaicius == mazgas->data)
			{
				// palyginimo veiksmas
				vsk += 1;
				return vsk;
			}
			else { // jei dar neradome
				if (skaicius < mazgas->data)
				{
					vsk++;
					int bla = vsk;
					findRecursive_vskaicius(skaicius, mazgas->left, vsk); // tikrinsime kairiji pomedi
					return bla;
				}
				else
				{
					vsk++;
					int bla = vsk;
					findRecursive_vskaicius(skaicius, mazgas->right, vsk);// tikrinsime desiniji pomedi
					return bla;
				}
			}
		}
		return -1;
	}

	// rekursine funkcija medzio isvedimui
	void printInfix(node* mazgas, int level) {
		if (mazgas != NULL) {
			++level;
			printInfix(mazgas->left, level);
			--level;
			cout << mazgas->data << "(" << level << "), ";
			++level;
			printInfix(mazgas->right, level);
			--level;
		}
	}

	// metodas medzio sunaikinimui (rekursinis)
	void treeDelete(node* mazgas) {

		if (mazgas == NULL)
			return;

		if (mazgas->left != NULL)
			treeDelete(mazgas->left); // sunaikinti kairiji pomedi 
		if (mazgas->right != NULL)
			treeDelete(mazgas->right);// sunaikinti desiniji pomedi

		delete mazgas; // sunaikinti pati mazga - medzio virsune
	}

public:
	Tree() { // C++ konstruktorius
		root = NULL; // tuscias medis
	}

	~Tree() { // C++ destructorius
		treeDelete(root);// medzio naikinimui naudojame rekursini metoda 
		root = NULL;
	}

	// metodas duomenu (skaiciaus) iterpimui i dvejetaini paieskos medi
	void insert(int data) {
		addRecursive(data, root); // naudojame rekursine funkcija
	}

	// metodas skaiciaus paieskai dvejetainiame paieskos medyje
	node* find(int skaicius) {
		return findRecursive(skaicius, root); // naudojame rekursine funkcija
	}

	int find_vsk(int skaicius)
	{
		int vsk = 0;
		findRecursive_vskaicius(skaicius, root, vsk);
		return vsk;
	}

	// metodas medzio isvedimui
	void printInfix() {
		int level = 0;
		printInfix(root, level); // naudojame rekursine funkcija
		cout << endl;
	}
};

int main()
{
	cout << fixed << setprecision(3);
	srand(time(NULL));

	int N = 10; //elementu skaicius
	int K = 100000; //kartojimu skaicius

	int s;
	cout << "Iveskite ieskoma skaiciu" << endl;
	cin >> s;

	Tree medis;

	for (int i = 0; i < N; i++)
	{
		int num = rand() % N + 1;
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

	double laikas = double(pabaiga - startas) / CLOCKS_PER_SEC / N / K * 1000;

	if (e) cout << "Elementas " << s << " rastas\n";
	else cout << "Elementas " << s << " nerastas\n";
	cout << "Paieskos laikas: " << laikas << " ms\n";

	if (e)
	{
		int vskaicius = medis.find_vsk(s);
		cout << "Atliktu veiksmu skaicius: " << vskaicius << endl;
	}

    return 0;
}

