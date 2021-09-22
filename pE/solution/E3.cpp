#include<bits/stdc++.h>
using namespace std;

#define int ll
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const int INF = 1000000007;

int qp(int a, int b, int c) {
    int ans = 1;
    for (; b; b >>= 1, a = a * a % c) if (b & 1) ans = ans * a % c;
    return ans;
}

signed main () {
    IOS;
    int a, b, c, r0, r1, n, p;
    cin >> a >> b >> c >> r0 >> r1 >> n >> p;

    r0 = (r0 % p + p) % p;
    r1 = (r1 % p + p) % p;
    c = (c % p + p) % p;
    if (n & 1)
        cout << qp(c, (n ^ 1) >> 1, p) * r1 % p << endl;
    else 
        cout << qp(c, n >> 1, p) * r0 % p << endl;
}