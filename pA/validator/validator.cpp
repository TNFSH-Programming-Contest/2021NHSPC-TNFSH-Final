#include <bits/stdc++.h>

#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int n = inf.readInt(1, 8000);
	cout << n << endl;
	inf.readEoln();

	inf.readInt(1, 1000000000);
	for (int i = 1; i < n; i++) {
		inf.readSpace();
		inf.readInt(1, 1000000000);
	}
	inf.readEoln();

	inf.readEof();

	return 0;
}
