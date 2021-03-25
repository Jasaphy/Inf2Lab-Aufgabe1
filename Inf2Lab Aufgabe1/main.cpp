//main 

#include <iostream>
#include "vectorlib.h"

using namespace std;

int main() {

	int i = 1;
	int v1Len;
	int v2Len;
	int v3Len;

	cout << "Geben Sie die Laenge des 1. Arrays ein(max. 10) -> ";
	cin >> v1Len;
	int* v1 = new int[v1Len];

	for (int* ptr = v1; (ptr - v1) < v1Len; ptr++) {
		cout << i << ". Arrayelement -> ";
		cin >> *ptr;
		i++;
	}
	i = 1;

	cout << "Geben Sie die Laenge des 2. Arrays ein(max. 10) -> ";
	cin >> v2Len;
	int* v2 = new int[v2Len];
	for (int* ptr = v2; (ptr - v2) < v2Len; ptr++) {
		cout << i << ". Arrayelement -> ";
		cin >> *ptr;
		i++;
	}

	int* vDest = new int[v1Len + v2Len];
	v3Len = merge(v1, v1Len, v2, v2Len, vDest);

	cout << "Ergebnis: ";
	if (v3Len == -1) {
		cout << "Ein oder beide Array(s) lag(en) nicht in aufsteigender Reihenfolge vor." << endl;
	}
	else {

		cout << "{";
		for (int* ptr = vDest; (ptr - vDest) < v3Len; ptr++) {
			cout << " " << *ptr;
			if (!((ptr - vDest) == v3Len - 1)) {
				cout << ",";
			}
		}
		cout << "}" << endl;

	}

	system("Pause");
	return 0;
}