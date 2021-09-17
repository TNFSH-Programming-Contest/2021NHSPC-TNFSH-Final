#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    
    auto test = [&](int k) -> int
    {
        int mxslen = 0;
        for (int i=0, j=0; i<n; i = j)
        {
            int S = 0;
            for (j=i; j<n && S<k; j++)
            {
                S += v[j];
            }
            
            if (S != k)
            {
                return -1;
            }
            else
            {
                mxslen = max(mxslen, j - i);
            }
        }
        
//        cout << "##" << k << ' ' << mxslen << '\n';
        return mxslen;
    };
    
    int mnlen = n;
    for (int i=0, S=0; i<n; i++)
    {
        S += v[i];
        
        int len = test(S);
        if (len > 0)
        {
            mnlen = min(mnlen, len);
        }
    }
    
    cout << mnlen << '\n';
}
