#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define int long long

using namespace std;

void print_vector(vector<int> v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void solve() {
    int blocks = 15;
    vector<int> ne(blocks*2+1), nw(blocks*2+1), sw(blocks*2+1), se(blocks*2+1);
    ne[2] = nw[2] = sw[2] = se[2] = 1; // drop first block
    int i;
    for (i = 2; i <= blocks; i++) { // dropping blocks
        vector<int> _ne(blocks*2+1), _nw(blocks*2+1), _sw(blocks*2+1), _se(blocks*2+1);
        for (int height = 0; height <= blocks*2; height++) {
            // NE combines with SW
            _ne[height+2] += ne[height]; // add NE block
            _nw[height+2] += ne[height]; // add NW block
            _sw[height+1] += ne[height]; // add SW block, COMBINES
            _se[height+2] += ne[height]; // add SE block
            
            // NW combines with SE
            _ne[height+2] += nw[height]; // add NE block
            _nw[height+2] += nw[height]; // add NW block
            _sw[height+2] += nw[height]; // add SW block
            _se[height+1] += nw[height]; // add SE block, COMBINES

            // SW combines with nothing
            _ne[height+2] += sw[height]; // add NE block
            _nw[height+2] += sw[height]; // add NW block
            _sw[height+2] += sw[height]; // add SW block
            _se[height+2] += sw[height]; // add SE block

            // SE combines with nothing
            _ne[height+2] += se[height]; // add NE block
            _nw[height+2] += se[height]; // add NW block
            _sw[height+2] += se[height]; // add SW block
            _se[height+2] += se[height]; // add SE block
        }
        ne = _ne; nw = _nw; sw = _sw; se = _se;
    }
    cout << "AFTER " << i-1 << "TH BLOCK DROP:" << endl;
    print_vector(ne);
    print_vector(nw);
    print_vector(sw);
    print_vector(se);
    
    int total_count = 0;
    double running_avg = 0;
    for (int height = 0; height <= blocks*2; height++) {
        int count = 0;
        count += ne[height];
        count += nw[height];
        count += sw[height];
        count += se[height];
        cout << "HEIGHT: " << height << ", CASES: " << count << endl;
        total_count += count;
        running_avg += count*height;
    }
    cout << "TOTAL CASES COMPUTED: " << total_count << endl;
    cout << "TOTAL CASES: " << pow(4, 15) << endl;
    cout << "ANSWER: " << running_avg / pow(4, 15) << endl;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
