#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	long long n;

	if(subtask == 1){
		n = 4;
	}
	else if(subtask == 2){
		n = rnd.next(2, 1000);
	}
	else if(subtask == 3){
		n = rnd.next(1, 1000000);
	}
	else if(subtask == 4){
		n = rnd.next(1LL, 1000000000LL);
	}
	else{
		n = rnd.next(1LL, (long long)1e18);
	}
	cout << n << '\n';
}
