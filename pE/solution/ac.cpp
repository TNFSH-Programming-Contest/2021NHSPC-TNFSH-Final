#include<bits/stdc++.h>
using namespace std;

#define int ll
#define endl '\n'
#define CLR(x, y) memset(x, y, sizeof(x))

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr)
using ll  = long long;

const int V = 10000;

// a_{n + 2} = a * a_{n + 1} * a_n + b * a_{n + 1} + c * a_n
// given a_0, a_1
// find a_n % p
// n ~ 1e18
// p ~ 1e4

bool vis[V][V];

void solve() {
    CLR(vis, 0);
    
    int a, b, c;
    int a0, a1;
    int n, p;

    cin >> a >> b >> c;
    cin >> a0 >> a1;
    cin >> n >> p;

    a = (a % p + p) % p;
    b = (b % p + p) % p;
    c = (c % p + p) % p;
    a0 = (a0 % p + p) % p;
    a1 = (a1 % p + p) % p;

    int k = 0, ak = a0, ak1 = a1;
    while (k < n && !vis[ak][ak1]) {
        vis[ak][ak1] = 1;
        swap(ak, ak1);
        ak1 = (a * ak1 % p * ak % p + b * ak % p + c * ak1 % p) % p;
        ++k;
    }

    if (k == n)
        return cout << ak << endl, void();
    
    int l = 0, al = a0, al1 = a1;
    while (al != ak || al1 != ak1) {
        swap(al, al1);
        al1 = (a * al1 % p * al % p + b * al % p + c * al1 % p) % p;
        ++l;
    }

    n = l + (n - l) % (k - l);
    l = 0, al = a0, al1 = a1;
    while (l < n) {
        swap(al, al1);
        al1 = (a * al1 % p * al % p + b * al % p + c * al1 % p) % p;
        ++l;
    }

    cout << al << endl;
}

signed main () {
    IOS;
    solve();
}