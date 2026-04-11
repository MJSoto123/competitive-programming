#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<int> a, b;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') a.insert(i + 1);
        else b.insert(i + 1);
    }
    if(a.count(1)){
        if(a.count(n)) { cout << "Alice\n"; return; }
        
        // B tiene n
        if(b.size() == 1){ cout << "Alice\n"; return; }

        // B > 1
        cout << "Bob\n";
    }else{
        if(b.count(n)) { cout << "Bob\n"; return; }

        // A tiene n
        if(a.size() == 1) { cout << "Bob\n"; return; }

        // A tiene otras mas
        if(a.count(n - 1)) { cout << "Alice\n"; return; }

        cout << "Bob\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}