#include <bits/stdc++.h>
using namespace std;

int n, m, k;
pair<int, int> pick[100005][8];
int cur[100005];
vector<vector<int>> rk;
priority_queue<pair<int, int>> pq[1005];
queue<tuple<int, int, int>> q;
vector<vector<int>> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	rk.resize(m + 1);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= 6; j++) cin >> pick[i][j].first;
	for(int i = 1, siz; i <= m; i++){
		cin >> siz;
		rk[i].resize(siz);
		for(int j = 0; j < siz; j++){
			cin >> rk[i][j];
			for(int k = 1; k <= 6; k++){
				if(pick[rk[i][j]][k].first == i){
					pick[rk[i][j]][k].second = j;
					break;
				}
			}
		}
	}

	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++){
			cout << i << " " << j << " " << pick[i][j].first << " " << pick[i][j].second << '\n';
		}
	}
	*/

	for(int i = 1; i <= n; i++) q.push({i, pick[i][1].second, pick[i][1].first}), cur[i] = 1;

	while(!q.empty()){
		auto &[id, rank, school] = q.front();
		q.pop();
		pq[school].push({rank, id});
		if((int)pq[school].size() > k){
			int id = pq[school].top().second;
			pq[school].pop();
			cur[id]++;
			if(cur[id] <= 6) q.push({id, pick[id][cur[id]].second, pick[id][cur[id]].first}); 
		}
	}

	ans.resize(m + 1);
	for(int i = 1; i <= m; i++){
                ans[i].clear();
		while(!pq[i].empty()){
			ans[i].push_back(pq[i].top().second);
			pq[i].pop();
		}
		sort(ans[i].begin(), ans[i].end());
	}

	for(int i = 1; i <= m; i++){
		cout << ans[i].size();
		for(auto &x : ans[i]) cout << " " << x;
		cout << '\n';
	}


	
}
