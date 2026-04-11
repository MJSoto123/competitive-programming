#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
using namespace ::std;
using ll = long long;
typedef vector<int>  vi;
typedef vector<ll>   vl;
typedef pair<int,int> pii;
bool num(char i){
    for(char ii = '0' ; ii <= '9'; ii++)
        if(i == ii) return true;
    return false;
}

void solve(){
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string ans;
        string a; 
        getline(cin , a);
        stringstream ss(a);
        string w;
        while(ss >> w){
            if(num(w[0])) ans += w[0];
            else ans += toupper(w[0]);
        }
        cout << ans << '\n';
        
    }
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int tt; cin >> tt;
    // while(tt--)
        solve();
}

