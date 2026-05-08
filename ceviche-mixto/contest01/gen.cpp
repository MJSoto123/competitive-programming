#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;



// Generate a random number between 0 and 100
ll ran_ll(ll L, ll R) {
    int randomNum = rand() % (R-L+1);
    return randomNum + L;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    
    ll n, m, k;
    n = ran_ll(1, 10);
    m = ran_ll(0, 10);
    k = ran_ll(1, n);

    string st;
    for (ll i = 0; i < n; ++i) {
        if(ran_ll(0, 1)) {
            st.push_back('R');
        } else {
            st.push_back('B');
        }
    }

    cout << n << " " << m << " " << k << endl;
    cout << st << endl;
}