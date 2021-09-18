#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    clock_t start_time = clock();
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    
    int h_minseg = -1;
    
    auto test = [&](int k) -> int
    {
        int mnslen = n;
        
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
                
                mnslen = min(mnslen, j - i);
            }
        }
        
        h_minseg = mnslen;
//        cout << "##" << k << ' ' << mxslen << '\n';
        return mxslen;
    };
    
    int way_cnt = 0;
    
    int mnlen = n;
    for (int i=0, S=0; i<n; i++)
    {
        S += v[i];
        
        int len = test(S);
        if (len > 0)
        {
            mnlen = min(mnlen, len);
            
            way_cnt++;
        }
    }
    
    int ans_mnS = 1e15, ans_mxS = 0, ans_minseg = n;
    {
        for (int i=0, S=0; i<n; i++)
        {
            S += v[i];
            
            int len = test(S);
            if (len == mnlen)
            {
                ans_mnS = min(ans_mnS, S);
                ans_mxS = max(ans_mxS, S);
                ans_minseg = min(ans_minseg, h_minseg);
            }
        }
    }
    
    cout << mnlen << '\n';
    
    int totsum = accumulate(v.begin(), v.end(), 0LL);
    int mnsegcnt = totsum / ans_mxS;
    
    cerr << "n=" << n << ", ans=" << mnlen << ", minS=" << ans_mnS << ", ";
    cerr << "min_segcnt=" << mnsegcnt << ", minseglen=" << ans_minseg << ", ways=" << way_cnt << ", ";
    cerr << "time=" << fixed << setprecision(2) << 1.0 * (clock() - start_time) / CLOCKS_PER_SEC;
    cerr << "\n";
}
