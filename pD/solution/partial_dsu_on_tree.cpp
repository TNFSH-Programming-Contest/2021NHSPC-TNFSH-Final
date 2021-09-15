#include <bits/stdc++.h>
using namespace std;

using pii = tuple<int, int>;
const auto& _ignore = std::ignore;

vector<int> AE[1000005];
vector<pii> nd_qry[1000005];

vector<int> ans;

int dep[1000005];
int trsz[1000005];
map<int, int> depge[1000005];

void dfs_qry(int p)
{
    map<int, int>& mp = depge[p];
    trsz[p] = 1;
    
    if (AE[p].size() > 0)
    {
        pii mxchd = {0, -1};
        for (int x: AE[p])
        {
            dep[x] = dep[p] + 1;
            dfs_qry(x);
            
            trsz[p] += trsz[x];
            mxchd = max(mxchd, pii{depge[x].size(), x});
        }
        
        int mchid; tie(_ignore, mchid) = mxchd;
        swap(mp, depge[mchid]);
        
        for (int x: AE[p])
        {
            if (x != mchid)
            {
                for (auto it: depge[x])
                {
                    mp[it.first] += it.second;
                }
            }
        }
    }
    
    mp[dep[p]] = (mp.count(dep[p]+1)? mp[dep[p]+1]: 0) + 1;
    
    for (pii qry : nd_qry[p])
    {
        int qi, k; tie(qi, k) = qry;
        
        int deplw = (dep[p] + k) + 1;
        ans[qi] = trsz[p] - (mp.count(deplw)? mp[deplw]: 0);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        
        AE[a].push_back(b);
//        AE[b].push_back(a);
    }
    
    int q;
    cin >> q;
    
    ans.resize(q);
    for (int qi=0; qi<q; qi++)
    {
        int i, k;
        cin >> i >> k, --i;
        nd_qry[i].push_back({qi, k});
    }
    
    dfs_qry(0);
    for (int qi=0; qi<q; qi++)
    {
        cout << ans[qi] << '\n';
    }
}
