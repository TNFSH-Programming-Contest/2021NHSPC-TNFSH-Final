#include<bits/stdc++.h>
using namespace std;

#define int ll
#define endl '\n'
#define pb emplace_back
#define pp pop_back
#define ins insert
#define X first
#define Y second
#define LB lower_bound
#define UB upper_bound
#define SZ(a) ((int)a.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define CLR(x, y) memset(x, y, sizeof(x))
#define LC(i) (i << 1)
#define RC(i) ((i << 1) | 1)
#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) for (__typeof(b) i = (1); i <= (b); ++i)
#define ROF(i, a, b) for (__typeof(b) i = (b - 1); i >= (a); --i)
#define R0F(i, b) ROF(i, 0, b)
#define R1F(i, b) for (__typeof(b) i = (b); i >= (1); --i)
#define TRAV(a, x) for (auto& a : x)

/* Define in C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++\x86_64-w64-mingw32\bits */
#ifdef QWE854896
    #define IOS ios::sync_with_stdio(false); cin.tie(nullptr)
    #define DBG(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
    void err(istream_iterator<string> it) {}
    template<typename T, typename... Args>
    void err(istream_iterator<string> it, T a, Args... args) {
        cerr << *it << " = " << a << endl;
        err(++it, args...);
    }
    template<typename T1, typename T2>
    std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& x) {
        os << "\n(" << x.X << ", " << x.Y << ")\n";
        return os;
    }
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& x) {
        os << endl << '[';
        for (auto& y : x)
            os << y << ", ";
        os << ']' << endl;
        return os;
    }
    template<typename T1, typename T2>
    std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& x) {
        os << endl << '\"';
        for (auto& y : x)
            os << y << ", ";
        os << '\"' << endl;
        return os;
    }
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::set<T>& x) {
        os << endl << '{';
        for (auto& y : x)
            os << y << ", ";
        os << '}' << endl;
        return os;
    }
#else
    #define IOS ios::sync_with_stdio(false); cin.tie(nullptr)
    #define DBG(...)
#endif

template<typename T>
using Prior=std::priority_queue<T>;
template<typename T>
using prior=std::priority_queue<T,std::vector<T>,std::greater<T> >;

using str = string;
using ll  = long long;
using ld  = long double;
using pii = pair <int, int>;
using pdd = pair <ld , ld >;
using vi  = vector <int>;
using vvi = vector <vi >;
using vii = vector <pii>;

const ll MOD = 1000000007; // 998244353;
const ll INF = 0x7f7f7f7f7f7f7f7f; // 922337203685477580;
const int V = 10000;
const ld PI = acos((ld)-1);
const int dt[8][2] = {
    1, 0, 
    -1, 0, 
    0, 1, 
    0, -1, 
    1, 1, 
    -1, 1, 
    -1, -1, 
    1, -1, 
};

/* Template */


/* Main Code */

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
    DBG(k, ak, ak1);

    if (k == n)
        return cout << ak << endl, void();
    
    int l = 0, al = a0, al1 = a1;
    while (al != ak || al1 != ak1) {
        swap(al, al1);
        al1 = (a * al1 % p * al % p + b * al % p + c * al1 % p) % p;
        ++l;
    }
    DBG(l, al, al1);

    n = l + (n - l) % (k - l);
    l = 0, al = a0, al1 = a1;
    while (l < n) {
        swap(al, al1);
        al1 = (a * al1 % p * al % p + b * al % p + c * al1 % p) % p;
        ++l;
    }

    DBG(n, l);
    cout << al << endl;
}

signed main () {
     IOS;
    //int t;
    //cin >> t;
    //while (t--)
    solve();
}
