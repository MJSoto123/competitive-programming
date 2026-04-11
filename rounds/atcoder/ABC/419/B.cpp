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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    priority_queue<int, vi, greater<int>> q;
    for(int i = 0; i < n; i++){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            q.push(x);
        }else{
            cout << q.top() << "\n";
            q.pop();
        }
    }

}