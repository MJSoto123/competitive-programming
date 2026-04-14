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

    cout << fixed << setprecision(3);
    double len, n, c;

    while(true){
        cin >> len >> n >> c;
        if(len < 0) break;
        if(n == 0 || c == 0){ cout << 0.0 << "\n"; continue; }

        double len2 = (1.0 + n * c);
        double l = 0, r = acos(-1);

        // anotao
        rep(i, 0, 69){
            double mid = (l + r) / 2.0;
            double cur = mid / sin(mid);

            if(cur > len2) r = mid;
            else l = mid;
        } 
        
        double angle = l / 2.0;
        double ans = (len / 2.0) * (sin(angle) / cos(angle));
        cout << ans << "\n";
    }   
}