#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int n = inf.readInt(1, 100000);
	inf.readSpace();
	int m = inf.readInt(6, 1000);
	inf.readSpace();
	int k = inf.readInt(1, n);
	inf.readEoln();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			if(j) inf.readSpace();
			int tmp = inf.readInt(1, m);
		}
		inf.readEoln();
	}

	for(int i = 1; i <= m; i++){
		int siz = inf.readInt(0, n);
		for(int j = 0; j < siz; j++){
			inf.readSpace();
			inf.readInt(1, n);
		}
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
