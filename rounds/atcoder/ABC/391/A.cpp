#include<bits/stdc++.h>
using namespace std;


map<string, string> mp = {
    {"S", "N"},
    {"N", "S"},
    {"E", "W"},
    {"W", "E"},
    {"NE", "SW"},
    {"NW", "SE"},
    {"SE", "NW"},
    {"SW", "NE"},
};
int main(){
    string s; cin >> s;
    cout << mp[s] << "\n";
}