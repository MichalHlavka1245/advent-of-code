#include <bits/stdc++.h>
using namespace std;

struct Block {
    int id, size, pos;
};

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int pos = 0;
    vector<Block> blocks;
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        if (i % 2 == 0) {
            blocks.push_back(Block{i/2, digit, pos});
        }
        pos += digit;
    }
    string out(pos, '.');
    long long answer = 0;
    while ( blocks.size() >= 2) {
        Block me = blocks.back();

        bool inserted = false;
        for (int i = 0; i <  blocks.size() - 1; i++) {
            int A = blocks[i].pos + blocks[i].size;
            int B = blocks[i+1].pos;
            if (B - A >= me.size) {
                inserted = true;
                me.pos = A;
                blocks.pop_back();
                blocks.insert(blocks.begin() + i + 1, me);
                break;
            }
        }
        if (!inserted) {
            blocks.pop_back();
            cout << me.pos << " " << me.id << endl;
            for (int j = 0; j < me.size; j++) {
                answer += (me.pos+j) * me.id;
                out[me.pos+j] = '0' + me.id;
            }
        }
    }
  
    //cout << out << "\n";

    cout << answer << "\n";
    return 0;
}
