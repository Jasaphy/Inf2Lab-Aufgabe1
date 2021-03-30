//Jakob Frank und Volodymyr Burdiian
//Erstellt 24.03.21
//merge

#include "vectorlib.h"
using namespace std;
//----------------------------------------------------------------------//isSort() zur überprüfung auf Richtigkeit der Arrays mit Rückgabe 0/1
bool isSort(int* v, int vLen) {
	if (vLen == 1) {													//Wenn die Länge des Arrays 1 ist wird 1 zurück gegeben
		return 1;
	}
//----------------------------------------------------------------------//Durchlauf des Arrays mit return
	int* tmp;															//Dekleration für tmp um den Pointer zu speichern da dieser in der Schleife verändert wird
	for (int* ptr = v; (ptr - v) < vLen - 1; ptr++) {
		tmp = ptr;
		if (*ptr > *(++ptr)) {											//Wenn eine Folgestelle größer als die aktuelle Stelle ist, gibt die Funktion 0 zurück und wird beendet
			return 0;
		}
		ptr = tmp;
	}
	return 1;															//Wenn das Array korrekt ist wird eine 1 zurück gegeben
}
//----------------------------------------------------------------------//merge() zum zusammenfügen der  2 Arrays
int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) {
	if ((!isSort(v1, v1Len)) || (!isSort(v2, v2Len))) {					//Überprüfung der zwei Arrays mit der isSort() 
		return -1;														//Sollte ein oder beide Arrays inkorrekt sein wird -1 zurück gegeben und die Funktion beendet
	}

	int v3Len = v1Len + v2Len;											//Dekleration und Initialisierung einer lokalen Länge 3 
	bool flag = 0;														//Dekleration und Initialisierung einer Prüfflag
	for (int* ptr = vDest; (ptr - vDest) < v3Len; ptr++) {
		if (((*v1 <= *v2) || (flag)) && (v1Len != 0)) {					//Wenn Inhalt Array 1 <= Inhalt Array 2 ist oder flag und die Lange des ersten Array !0 ist wird 
			*ptr = *v1;													//an der aktuellen Position der Inhalt des ersten Arrays ind das Ergebnis Array gespeichert
			v1++;														//Erhöhung der Pointers für Array 1 
			v1Len--;													//Verringerung der Länge des Array 1
		}
		else if (v2Len != 0) {											//Ansonsten wird der aktuelle Inhalt der zweiten Arrays in das Ergebnis Array
			*ptr = *v2;
			v2++;														//Erhöhung der Pointers für Array 2
			v2Len--;													//Verringerung der Länge des Array 2
			if (v2Len == 0) {											//Wenn die Länge von Array 2 0 ist wird flag auf 1 gesetzt. Dies verhindert das Problem, wenn der Pointer 
				flag = 1;												//über das Arrayende läuft wird der Wert ein negativer und so gilt oben v1 <= v2 nicht mehr
			}
		}
	}
	return v3Len;														//Rückgabe der Länge 3
}

