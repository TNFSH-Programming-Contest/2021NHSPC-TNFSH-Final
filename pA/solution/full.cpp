#include <bits/stdc++.h>
using namespace std;

int main()
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
    
    auto test = [&](long long k) -> int
    {
        int mxslen = 0;
        for (int i=0, j=0; i<n; i = j)
        {
            long long S = 0;
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
        
        return mxslen;
    };
    
    int mnlen = n;
    for (int i=0; i<n; i++)
    {
        long long S = accumulate(v.begin(), next(v.begin() + i), 0LL);
        
        int len = test(S);
        if (len > 0)
        {
            mnlen = min(mnlen, len);
        }
    }
    
    cout << mnlen << '\n';
}
