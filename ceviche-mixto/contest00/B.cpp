#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve() { 
    int n, m; cin >> n >> m; 
    priority_queue<int> a, b; 
    rep(i,0,n) { 
        int x; cin >> x; 
        a.push(x); 
    }
    rep(i,0,m) { 
        int x; cin >> x; 
        b.push(x); 
    }

    bool alice = true; 
    while(true) { 
        if(alice) { 
            if(b.empty()) { 
                cout << "Alice\n"; return; 
            }
            int x = a.top(), y = b.top(); 
            b.pop(); 
            if(y - x > 0) b.push(y - x); 
        }else{ 
            if(a.empty()) { 
                cout << "Bob\n"; return; 
            }
            int x = b.top(), y = a.top(); 
            a.pop(); 
            if(y - x > 0) a.push(y - x); 
        }
        alice ^= 1; 
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve(); 

}