//Jakob Frank und Volodymyr Burdiian
//Erstellt 24.03.21
//Mergen von zwei aufsteigend sortierten Arrays  
//main

#include <iostream>
#include "vectorlib.h"

using namespace std;

int main() {
//----------------------------------------------------------------------//Dekleration und gegebenfalls Initialisierung
	int i = 1;															//i wird nur als Zählervariable für die Ausgabe verwendet 
	int v1Len;
	int v2Len;
	int v3Len;
//----------------------------------------------------------------------//Erstes Array Eingabe
	cout << "Geben Sie die Laenge des 1. Arrays ein(max. 10) -> ";		//Ausgabe zur Aufforderung der Eingabe der Länge des ersten Arrays mit max. 10 Elementen
	cin >> v1Len;														//Eingabe erste Arraylänge
	int* v1 = new int[v1Len];											//Dekleration und Initialisierung des ersten Arrays mit Größenabhängigkeit der Eingabe

	for (int* ptr = v1; (ptr - v1) < v1Len; ptr++) {
		cout << i << ". Arrayelement -> ";								//Ausgabe zur Aufforderung der Eingabe  des ersten Arrays der Elementen
		cin >> *ptr;													//Eingabe der ersten Arrayelementen
		i++;
	} 
	i = 1;
//----------------------------------------------------------------------//Zweites Array Eingabe
	cout << "Geben Sie die Laenge des 2. Arrays ein(max. 10) -> ";		//Ausgabe zur Aufforderung der Eingabe der Länge des zweiten Arrays mit max. 10 Elementen
	cin >> v2Len;														//Eingabe zweite Arraylänge
	int* v2 = new int[v2Len];											//Dekleration und Initialisierung des zweiten Arrays mit Größenabhängigkeit der Eingabe
	
	for (int* ptr = v2; (ptr - v2) < v2Len; ptr++) {
		cout << i << ". Arrayelement -> ";								//Ausgabe zur Aufforderung der Eingabe  des zweiten Arrays der Elementen
		cin >> *ptr;													//Eingabe der zweiten Arrayelementen
		i++;
	}
//----------------------------------------------------------------------//
	int* vDest = new int[v1Len + v2Len];								//Dekleration und gegebenfalls Initialisierung des Ergebnissarrays mit der Summe aus Länge 1 und 2
	v3Len = merge(v1, v1Len, v2, v2Len, vDest);							//Initialisierung der Länge 3 mit der merge() welche bei richtg sortierten Arrays die Länge zurück gibt 
																		//und bei falsch sortierten Arrays eine -1 zurück gibt

//----------------------------------------------------------------------//Überprüfung der Rückgabe von der merge() und Ausgabe des Ergebnisses
	cout << "Ergebnis: ";												
	if (v3Len == -1) {													//Wenn der Wert von v3Len -1 entspricht war ein Array nicht richtig und eine "Fehlermeldung" wird ausgegeben 	
		cout << "Ein oder beide Array(s) lag(en) nicht in aufsteigender Reihenfolge vor." << endl;
	}
	else {																//Ansonsten wird das gesamte Array ausgegeben			

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