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

int valid(int val){
    while(val){
        if(val % 10 == 0) return false;
        val /= 10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pos; cin >> pos;
    int cnt = 0;
    int val = 1;
    while(cnt < pos){
        if(valid(val)) {
            cout << val << "\n";
            cnt++;
        }
        val++;
    }
}