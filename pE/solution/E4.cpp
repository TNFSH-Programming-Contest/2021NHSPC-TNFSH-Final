#include<bits/stdc++.h>
using namespace std;

#define int ll
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const int INF = 1000000007;

const int V = 2;

void mul(int A[V][V], int B[V][V], int &p) {
    int C[V][V] = {0};
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            for (int k = 0; k < V; ++k)
                C[i][j] += A[i][k] * B[k][j] % p;
    
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            A[i][j] = C[i][j] % p;
}

signed main () {
    IOS;
    int a, b, c, r0, r1, n, p;
    cin >> a >> b >> c >> r0 >> r1 >> n >> p;

    r0 = (r0 % p + p) % p;
    r1 = (r1 % p + p) % p;
    b = (b % p + p) % p;
    c = (c % p + p) % p;
    --n;
    int A[2][2] = {
        0, 1,
        c, b
    };
    int I[2][2] = {
        1, 0,
        0, 1
    };
    for (; n; n >>= 1, mul(A, A, p)) if (n & 1) mul(I, A, p);
    cout << (r0 * I[1][0] % p + r1 * I[1][1] % p) % p << endl;

}