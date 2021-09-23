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
    
    map<long long, int> prfidx;
    for (int i=0; i<n; i++)
    {
        long long S = accumulate(v.begin(), next(v.begin() + i), 0LL);
        prfidx[S] = i;
    }
    
    auto test = [&](long long k) -> int
    {
        int mxslen = 0;
        long long S = accumulate(v.begin(), v.end(), 0LL);
        if (S % k != 0)
        {
            return -1;
        }
        
        bool ok = true;
        {
            int lidx = -1;
            for (long long ps=k; ps<=S; ps+=k)
            {
                ok &= prfidx.count(ps);
                
                mxslen = max(mxslen, prfidx[ps] - lidx);
                lidx = prfidx[ps];
            }
        }
        
        if (!ok)
        {
            return false;
        }
        
//        for (long long lidx=-1, ps=k; ps<=S; ps+=k)
//        {
//            cout << "##" << lidx+2 << " " << prfidx[ps]+1 << '\n';
//            lidx = prfidx[ps];
//        }
//        cout << "###\n";
        
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
