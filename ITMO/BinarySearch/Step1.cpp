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

    int n, q; cin >> n;
    vi a(n); 
    rep(i, 0, n) cin >> a[i];
    sort(all(a));

    cin >> q;

    rep(qq, 0, q){
        int lval, rval; cin >> lval >> rval;
        int low = n + 1, high = -1;
        {
            int l = -1, r = n;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(a[mid] < lval) l = mid;
                else r = mid;
            }
            low = r;
        }

        {
            int l = -1, r = n;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(a[mid] <= rval) l = mid;
                else r = mid;
            }
            high = l;
        }

        cout << max(high - low + 1, 0) << " "; 
    }
    cout << "\n";
}