#include <bits/stdc++.h>

#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int n = inf.readInt(1, 1000000);
	inf.readEoln();

	for (int i = 0; i < n - 1; i++) {
		inf.readInt(1, n);
		inf.readSpace();
		inf.readInt(1, n);
		inf.readEoln();
	}

	int q = inf.readInt(1, 1000000);
	inf.readEoln();

	for (int i = 0; i < q; i++) {
		int p = inf.readInt(1, n);
		inf.readSpace();
		int k = inf.readInt(0, n);
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
