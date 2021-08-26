#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

vector<array<int, 6>> v;
vector<int> rk, tmp;
vector<int> chose[1005];

bool cmp(int a, int b){
	return rk[a - 1] < rk[b - 1];
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int n, m, k;

	if(subtask == 1){
		n = rnd.next(1, 100000);
		k = rnd.next(1, min(n, 100));
		m = rnd.next(6, 1000);

		for(int i = 0; i < n; i++){
			array<int, 6> arr;
			tmp = rnd.perm(m, 1);
			for(int j = 0; j < 6; j++) arr[j] = tmp[j], chose[arr[j]].push_back(i + 1);
			v.push_back(arr);
		}

		for(int i = 1; i <= m; i++){
			if(i == 1) rk = rnd.perm(n, 1);
			sort(chose[i].begin(), chose[i].end(), cmp);
		}
	
	}
	else if(subtask == 2){
		n = rnd.next(1, 8);
		k = rnd.next(1, n);
		m = rnd.next(6, 2 * n);
		for(int i = 0; i < n; i++){
			array<int, 6> arr;
			tmp = rnd.perm(m, 1);
			for(int j = 0; j < 6; j++) arr[j] = tmp[j], chose[arr[j]].push_back(i + 1);
			v.push_back(arr);
		}

		for(int i = 1; i <= m; i++){
			rk = rnd.perm(n, 1);
			sort(chose[i].begin(), chose[i].end(), cmp);
		}
	}
	else if(subtask == 3){
		n = rnd.next(1, 1000);
		k = rnd.next(1, min(n, 100));
		m = rnd.next(6, 1000);
		for(int i = 0; i < n; i++){
			array<int, 6> arr;
			tmp = rnd.perm(m, 1);
			for(int j = 0; j < 6; j++) arr[j] = tmp[j], chose[arr[j]].push_back(i+1);
			v.push_back(arr);
		}

		for(int i = 1; i <= m; i++){
			rk = rnd.perm(n, 1);
			sort(chose[i].begin(), chose[i].end(), cmp);
		}
	}
	else{
		n = rnd.next(1, 100000);
		k = rnd.next(1, min(n, 1000));
		m = rnd.next(6, 1000);
		for(int i = 0; i < n; i++){
			array<int, 6> arr;
			tmp = rnd.perm(m, 1);
			for(int j = 0; j < 6; j++) arr[j] = tmp[j], chose[arr[j]].push_back(i + 1);
			v.push_back(arr);
		}

		for(int i = 1; i <= m; i++){
			rk = rnd.perm(n, 1);
			sort(chose[i].begin(), chose[i].end(), cmp);
		}
	}
	cout << n << " " << m << " " << k << '\n';
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			cout << v[i][j] << " \n"[j == 5];
		}
	}

	for(int i = 1; i <= m; i++){
		cout << chose[i].size();
		for(auto &x : chose[i]) cout << " " << x;
		cout << '\n';
	}
}
