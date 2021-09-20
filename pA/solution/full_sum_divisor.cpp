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
    
    long long totsum = accumulate(v.begin(), v.end(), 0LL); 
    
    int mnlen = n;
    for (long long div=1; div*div<=totsum; div++)
    {
        if (totsum % div != 0)
        {
            continue;
        }
        
        {
            long long S = div;
            
            int len = test(S);
            if (len > 0)
            {
                mnlen = min(mnlen, len);
            }
        }
        
        {
            long long S = totsum / div;
            
            int len = test(S);
            if (len > 0)
            {
                mnlen = min(mnlen, len);
            }
        }
    }
    
    cout << mnlen << '\n';
}
