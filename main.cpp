// Final iteration comment
// Solution for Falling Balls problem
// Updated for final check

#include <bits/stdc++.h> // include all
// Falling Balls solution
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long D, n;
    if(!(cin >> D >> n)) return 0;
    long long original_n = n;
    // Compute leaf index of last ball
    long long idx = 1;
    long long k = n;
    for(int i = 0; i < D - 1; ++i) {
        if(k % 2 == 1) {
            idx = idx * 2;
            k = (k + 1) / 2;
        } else {
            idx = idx * 2 + 1;
            k = k / 2;
        }
    }
    cout << idx << "\n";
    // Compute leaf states using recursive distribution of passes
    long long leafCount = 1LL << (D - 1);
    vector<int> leafState(leafCount, 0);
    struct Node { long long id; int depth; long long passes; };
    vector<Node> stack;
    stack.push_back({1, 0, original_n});
    while(!stack.empty()) {
        Node cur = stack.back();
        stack.pop_back();
        if(cur.depth == D - 1) {
            long long leafIdx = cur.id - (1LL << (D - 1)); // 0-based
            leafState[leafIdx] = cur.passes % 2;
        } else {
            long long leftPass = (cur.passes + 1) / 2;
            long long rightPass = cur.passes / 2;
            stack.push_back({cur.id * 2 + 1, cur.depth + 1, rightPass});
            stack.push_back({cur.id * 2, cur.depth + 1, leftPass});
        }
    }
    for(size_t i = 0; i < leafState.size(); ++i) {
        if(i) cout << ' ';
        cout << leafState[i];
    }
    cout << "\n";
    return 0;
}
// End of solution
// Final comment for completeness
