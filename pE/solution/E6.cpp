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

const int V = 3;

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

    int ep = p, tp = p;
    for (int i = 2; i * i <= tp; ++i)
        if (tp % i == 0) {
            ep = ep / i * (i - 1);
            while (tp % i == 0)
                tp /= i;
        }
    if (tp != 1)
        ep = ep / tp * (tp - 1);

    int AA = a, i;

    a = 0, b = 0, c, i = 2;
    for (; 1; ++i) {
        c = a + b + 1;
        if (c >= ep) break;
        a = b, b = c;
    }
    int al = i;

    a = 1, b = 0, c, i = 2;
    for (; 1; ++i) {
        c = a + b;
        if (c >= ep) break;
        a = b, b = c;
    }
    int a0l = i, a1l = i - 1;

    int A[3][3] = {
        0, 1, 0,
        1, 1, 1,
        0, 0, 1
    };
    int I[3][3] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };

    int tn = n;
    --n;
    for (; n; n >>= 1, mul(A, A, ep)) if (n & 1) mul(I, A, ep);
    
    int ap = I[1][2];
    if (tn >= al) ap += ep;
    // ap += ep;

    int uA[3][3] = {
        0, 1, 0,
        1, 1, 0,
        0, 0, 0
    };
    int uI[3][3] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 0
    };

    n = tn - 1;

    for (; n; n >>= 1, mul(uA, uA, ep)) if (n & 1) mul(uI, uA, ep);

    int p0 = uI[0][1], p1 = uI[1][1];
    if (tn >= a0l) p0 += ep;
    if (tn >= a1l) p1 += ep;
    // p0 += ep;
    // p1 += ep;

    AA = (AA % p + p) % p;
    r0 = (r0 % p + p) % p;
    r1 = (r1 % p + p) % p;

    cout << qp(AA, ap, p) * qp(r0, p0, p) % p * qp(r1, p1, p) % p << endl;

}