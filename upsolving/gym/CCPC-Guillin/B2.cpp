#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
using namespace ::std;
using ll = long long;
#define int long long
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;

void solve(){
    int n; cin >> n;
    int m; cin >> m;
    multiset<int> a, b;
    vi aa(n), bb(m);
    for(int i = 0; i < n; i++) {
        cin >> aa[i];
        a.insert(aa[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> bb[i];
        b.insert(bb[i]);
    }
    
    int cnts = n - m;
    sort(all(aa));
    sort(all(bb));
    
    bool ok = 1;
    int mx1 = *max_element(all(aa));
    int mx2 = *max_element(all(bb));
    if(mx1 > mx2) ok = 0;
    vi ans;

    auto get_ops = [&](){
        int C = cnts;
        int i = n - 1;
        int j = m - 1;
        int ini = 0;
        multiset<int> res = a;
        vi auxA = aa;
        while(C && j >= 0){
            if(auxA[i] != bb[j]){
                if(ini <= i){
                    assert (res.find(auxA[i]) != res.end());
                    res.erase(res.find(auxA[i]));
                    // ans.emplace_back(auxA[i]);
                    auxA[i]++;
                    ini++;
                    res.insert(auxA[i]);
                    res.erase(res.begin());
                    C--;
                }   
                else break;
            }
            if(auxA[i] == bb[j]){
                i --;
                j --;
            }
        }
        return max(C, 0LL);
    };
    int sob = get_ops();
    // cerr << "Sob: " << sob << '\n';
    if(sob){
        for(int i =0 ; i < sob; i++){
            auto it = a.begin();
            int aux = *it + 1;
            ans.emplace_back(*it);
            a.erase(it);
            a.insert(aux);
            a.erase(a.begin());
        }
    }
    aa.clear();
    for(int i : a) aa.emplace_back(i);
    // for(int i : a) cout << i << ' '; cout << '\n';
    cnts -= sob;
    int lstA = sz(aa) - 1;
    int lstB = m - 1;
    int iniA = 0;

    while(cnts && lstB >= 0){
        if(aa[lstA] != bb[lstB]){
            if(iniA <= lstA){
                assert (a.find(aa[lstA]) != a.end());
                a.erase(a.find(aa[lstA]));
                ans.emplace_back(aa[lstA]);
                aa[lstA]++;
                iniA++;
                a.insert(aa[lstA]);
                a.erase(a.begin());
                cnts--;
            }
            else break;
        }
        if(aa[lstA] == bb[lstB]){
            lstA --;
            lstB --;
        }
    }
    if(cnts){
        for(int i =0 ; i < cnts; i++){
            auto it = a.begin();
            int aux = *it + 1;
            ans.emplace_back(*it);
            a.erase(it);
            a.insert(aux);
            a.erase(a.begin());
        }
    }
    // cout << "A after: \n";
    // for(int i : a) cout << i << ' ';
    // cout << '\n';
    ok &= (a == b);
    if(!ok) cout << -1 << '\n';
    else{
        cout << sz(ans) << '\n';
        for(int i : ans) cout << i << ' '; cout << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();
}
