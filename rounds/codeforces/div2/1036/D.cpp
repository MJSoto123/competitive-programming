#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

void solve(){
    int n, k; cin >> n >> k;
    k--;

    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k == 0){ cout << "YES\n"; return; }

    vvi pos(n + 1);
    for(int i = 0; i < n; i++) pos[a[i]].emplace_back(i);
    
    int last = -1;
    int sm = 0;
    int sobra = 0;
    for(int i = 0; i < n; i++){
        if(sm + pos[i].size() == k){
            last = i;
            sobra = 0;
            sm += pos[i].size();
            break;
        }
        else if(sm + pos[i].size() < k){
            last = i;
            sm += pos[i].size();
        }else{
            last = i;
            sobra = k - sm;
            break;
        }
    }

    if(sobra == k){ cout << "YES\n"; return;}
    if(sobra == 0){
        vi s;
        for(int i = 0; i < n; i++) if(a[i] <= last) s.emplace_back(i);
        int m = s.size();
        for(int i = 0; i < m / 2; i++){
            if(a[s[i]] != a[s[m - 1 - i]]){ cout << "NO\n"; return; }
        }
        cout << "YES\n";
        return;
    }

    vi s;
    for(int i = 0; i < n; i++) if(a[i] < last) s.emplace_back(i);
    int m = s.size();
    for(int i = 0; i < m / 2; i++){
        if(a[s[i]] != a[s[m - 1 - i]]){ cout << "NO\n"; return; }
    }
    
    int l, r;
    if(m % 2 == 1){
        if(k % 2 == 0){ cout << "NO\n"; return; }
        int mid = s[m / 2];
        for(auto x : pos[last]) s.emplace_back(x);
        sort(s.begin(), s.end());
        m = s.size();
        
        int beg = 0;
        for(int i = 0; i < m; i++) if(s[i] == mid){ beg = i; break; }
        l = beg - 1; r = beg + 1;
    }else{
        int mid1 = s[m / 2 - 1], mid2 = s[m / 2];
        int in = 0;
        for(auto x : pos[last]){
            if(x > mid1 && x < mid2) in++;
            else s.emplace_back(x);
        }

        if(sobra % 2 == 0){
            sobra -= in;
            if(in % 2) sobra++;
        }
        else{
            sobra -= in;
            if(in % 2 == 0) sobra++; 
        }
        sort(s.begin(), s.end());
        m = s.size();
        for(int i = 0; i < m; i++) if(s[i] == mid1) l = i - 1;
        for(int i = 0; i < m; i++) if(s[i] == mid2) r = i + 1;
    }

    m = s.size();
    while(l >= 0 && r < m && sobra > 0){
        if(a[s[l]] == a[s[r]]){
            if(a[s[l]] == last) sobra -= 2;
            l--;
            r--;
        }else{
            if(a[s[l]] == last) l--;
            else if(a[s[r]] == last) r--;
        }
    }

    if(sobra) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}