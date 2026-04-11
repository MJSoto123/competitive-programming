#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    int mark = -1;
    int clo = true;
    cerr << s << endl;
    rep(i, 0, n){
        if(s[i] == '1') continue;
        int nmark = -10;
        if(clo) nmark = i + 1;
        
        if(i - mark <= 1){ clo = true; mark = i; }
        else clo = false;
        if(nmark != -10) mark = nmark;
        cerr << clo << " " << mark << endl;
    }

    if(clo || mark >= n) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}