#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    string s; cin >> s;
    int cnt = 0;
    int pos = -1;
    if(k == 0) {cout << s << "\n"; return 0;}

    for(int i = 0; i < n; i++){
        if(s[i] == '.') {cnt++; pos = i;}
        if(cnt == k) break;
    }

    
    if(pos == -1) {cout << s << "\n"; return 0;} 
    int one = 0;
    for(int i = 0; i < pos + 1; i++) if(s[i] == 'o') one++;
    
    for(int i = pos - one + 1; i < pos + 1; i++) s[i] = 'o';
    s[pos - one] = '#';
    for(int i = pos - one - 1; i >= 0; i--) s[i] = '.';
    cout << s << "\n";

}