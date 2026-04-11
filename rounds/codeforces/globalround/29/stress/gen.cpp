#include <bits/stdc++.h>
using namespace std;

string to_bin(int x) {
    if (x == 0) return "0";
    string s;
    while (x > 0) {
        s.push_back((x & 1) ? '1' : '0');
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <numero>\n";
        return 1;
    }
    int x = stoi(argv[1]);
    string s = to_bin(x);
    cout << (int)s.size() << "\n" << s << "\n";
    return 0;
}
