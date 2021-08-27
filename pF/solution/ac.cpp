#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define int ll
#define fi first
#define se second
#define vi vector<ll>
#define pb emplace_back
#define all(n) (n).begin(),(n).end()
#define mem(n,x) memset(n,x,sizeof(n))
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define dbg(...) cerr<<#__VA_ARGS__<<" = ";_do(__VA_ARGS__);
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T,typename ...U> void _do(T x,U ...y){cerr<<x<<", ";_do(y...);}
const ll mod = 1000000007;

ll n;
#define mat array<array<ll, 10>, 10>
mat trans[62];
vi ans(10, 0);

vi dp(vi v){
    vi aa(10, 0);
    aa[0] = v[0];
    for(int i = 1; i < 10; i++) aa[i] = (aa[i-1] + v[i]) % mod;
    return aa;
}

vi vec_mul(vi v, mat m){
    vi aa(10, 0);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            aa[i] += v[j] * m[j][i];
            aa[i] %= mod;
        }
    }
    return aa;
}

mat operator*(mat x, mat y){
    mat aa;
    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) aa[i][j] = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                aa[i][j] += x[i][k] * y[k][j];
                aa[i][j] %= mod;
            }
        }
    }
    return aa;
}

mat mat_mul(mat x, ll p){
    mat m = x, aa;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            aa[i][j] = 0;
        }
    }
    for(int i = 0; i < 10; i++) aa[i][i] = 1;
    while(p){
        if(p & 1) aa = aa * m;
        m = m * m;
        p >>= 1;
    }
    return aa;
}

signed main(){
    IOS;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            trans[0][i][j] = 10 - max(i, j);
        }
    }
    for(int i = 1; i < 60; i++) trans[i] = trans[i-1] * trans[i-1];
    cin >> n;
    fill(all(ans), 0);
    for(int i = 0; i < 10; i++) ans[i] = 1;
    for(ll i = 0, d = (n - 1) / 2; i < 60; i++){
        if(d >> i & 1) ans = vec_mul(ans, trans[i]);
    }
    if(~n & 1) ans = dp(ans);
    ll cnt = 0;
    for(int i = 0; i < 10; i++) cnt += ans[i], cnt %= mod;
    cout << cnt << '\n';
}

/*
1
5 2
2 6
4 5
*/