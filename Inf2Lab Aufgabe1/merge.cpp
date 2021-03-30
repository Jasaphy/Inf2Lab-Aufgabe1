//Jakob Frank und Volodymyr Burdiian
//Erstellt 24.03.21
//merge

#include "vectorlib.h"
using namespace std;
//----------------------------------------------------------------------//isSort() zur �berpr�fung auf Richtigkeit der Arrays mit R�ckgabe 0/1
bool isSort(int* v, int vLen) {
	if (vLen == 1) {													//Wenn die L�nge des Arrays 1 ist wird 1 zur�ck gegeben
		return 1;
	}
//----------------------------------------------------------------------//Durchlauf des Arrays mit return
	int* tmp;															//Dekleration f�r tmp um den Pointer zu speichern da dieser in der Schleife ver�ndert wird
	for (int* ptr = v; (ptr - v) < vLen - 1; ptr++) {
		tmp = ptr;
		if (*ptr > *(++ptr)) {											//Wenn eine Folgestelle gr��er als die aktuelle Stelle ist, gibt die Funktion 0 zur�ck und wird beendet
			return 0;
		}
		ptr = tmp;
	}
	return 1;															//Wenn das Array korrekt ist wird eine 1 zur�ck gegeben
}
//----------------------------------------------------------------------//merge() zum zusammenf�gen der  2 Arrays
int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) {
	if ((!isSort(v1, v1Len)) || (!isSort(v2, v2Len))) {					//�berpr�fung der zwei Arrays mit der isSort() 
		return -1;														//Sollte ein oder beide Arrays inkorrekt sein wird -1 zur�ck gegeben und die Funktion beendet
	}

	int v3Len = v1Len + v2Len;											//Dekleration und Initialisierung einer lokalen L�nge 3 
	bool flag = 0;														//Dekleration und Initialisierung einer Pr�fflag
	for (int* ptr = vDest; (ptr - vDest) < v3Len; ptr++) {
		if (((*v1 <= *v2) || (flag)) && (v1Len != 0)) {					//Wenn Inhalt Array 1 <= Inhalt Array 2 ist oder flag und die Lange des ersten Array !0 ist wird 
			*ptr = *v1;													//an der aktuellen Position der Inhalt des ersten Arrays ind das Ergebnis Array gespeichert
			v1++;														//Erh�hung der Pointers f�r Array 1 
			v1Len--;													//Verringerung der L�nge des Array 1
		}
		else if (v2Len != 0) {											//Ansonsten wird der aktuelle Inhalt der zweiten Arrays in das Ergebnis Array
			*ptr = *v2;
			v2++;														//Erh�hung der Pointers f�r Array 2
			v2Len--;													//Verringerung der L�nge des Array 2
			if (v2Len == 0) {											//Wenn die L�nge von Array 2 0 ist wird flag auf 1 gesetzt. Dies verhindert das Problem, wenn der Pointer 
				flag = 1;												//�ber das Arrayende l�uft wird der Wert ein negativer und so gilt oben v1 <= v2 nicht mehr
			}
		}
	}
	return v3Len;														//R�ckgabe der L�nge 3
}

