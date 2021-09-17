#include <bits/stdc++.h>

#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int n = inf.readInt(1, 1000);
	inf.readSpace();
	int m = inf.readInt(1, 1000);
	inf.readEoln();

	inf.readInt(1, n);
	inf.readSpace();
	inf.readInt(1, m);
	inf.readEoln();

	inf.readInt(1, n);
	inf.readSpace();
	inf.readInt(1, m);
	inf.readEoln();

	for (int i = 0; i < n; i++) {
		inf.readInt(-1000000000, 1000000000);
		for (int j = 1; j < m; j++) {
			inf.readSpace();
			inf.readInt(-1000000000, 1000000000);
		}
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
