#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

int getmin(int a, int b){
    return (a + b - 1);
}

int getmax(int a, int b){
    return (a * b);
}

void solve(){
    int num, den; cin >> num >> den;
    int g = gcd(num, den);
    num /= g; den /= g;

    for(int i = 1; i <= 500; i++){
        for(int j = 1; j <= 500; j++){   
            int p = 2 * i + 2 * j;
            int a = p * den;
            if(a % num) continue;
            
            a /= num;
            int mn = getmin(i, j);
            int mx = getmax(i, j);
            if(a < mn || a > mx || a > 50000) continue;

            cout << a << "\n";
            for(int r = 0; r < i; r++){
                cout << r << " " << 0 << "\n";
                a--;
            }
            for(int c = 1; c < j; c++){
                cout << 0 << " " << c << "\n";
                a--;
            }

            for(int r = 1; r < i; r++){
                for(int c = 1; c < j; c++){
                    if(a){
                        cout << r << " " << c << "\n";
                        a--;
                    }
                }
            }
            return;
        }
    }

    cout << "-1\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}