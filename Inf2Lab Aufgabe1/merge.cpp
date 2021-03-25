
#include "vectorlib.h"
using namespace std;

bool isSort(int* v, int vLen) {
	if (vLen == 1) {
		return 1;
	}

	int* tmp;
	for (int* ptr = v; (ptr - v) < vLen - 1; ptr++) {
		tmp = ptr;
		if (*ptr > *(++ptr)) {
			return 0;
		}
		ptr = tmp;
	}
	return 1;
}

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) {
	if ((!isSort(v1, v1Len)) || (!isSort(v2, v2Len))) {
		return -1;
	}

	int v3Len = v1Len + v2Len;
	bool flag = 0;
	for (int* ptr = vDest; (ptr - vDest) < v3Len; ptr++) {
		if (((*v1 <= *v2) || (flag)) && (v1Len != 0)) {
			*ptr = *v1;
			v1++;
			v1Len--;
		}
		else if (v2Len != 0) {
			*ptr = *v2;
			v2++;
			v2Len--;
			if (v2Len == 0) {
				flag = 1;
			}
		}
	}
	return v3Len;
}