#include<bits/stdc++.h>
using namespace std;

#define int ll
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const int V = 8005;
const int INF = 1000000007;

signed main () {
    IOS;
    int a, b, c, r0, r1, n, p;
    cin >> a >> b >> c >> r0 >> r1 >> n >> p;
    int ans;
    for (int i = 2; i <= n; ++i)
        ans = (a * r1 % p * r0 % p + b * r1 % p + c * r0 % p) % p, r0 = r1, r1 = ans;
    cout << (ans % p + p) % p << endl;
}