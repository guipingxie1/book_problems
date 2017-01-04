#include <map>
#include <iostream>
using namespace std;

map<char, int> char_mapper;

void fill_map() {
    char_mapper['A'] = 2;
    char_mapper['B'] = 2;
    char_mapper['C'] = 2;
    char_mapper['D'] = 3;
    char_mapper['E'] = 3;
    char_mapper['F'] = 3;
    char_mapper['G'] = 4;
    char_mapper['H'] = 4;
    char_mapper['I'] = 4;
    char_mapper['J'] = 5;
    char_mapper['K'] = 5;
    char_mapper['L'] = 5;
    char_mapper['M'] = 6;
    char_mapper['N'] = 6;
    char_mapper['O'] = 6;
    char_mapper['P'] = 7;
    char_mapper['R'] = 7;
    char_mapper['S'] = 7;
    char_mapper['T'] = 8;
    char_mapper['U'] = 8;
    char_mapper['V'] = 8;
    char_mapper['W'] = 9;
    char_mapper['X'] = 9;
    char_mapper['Y'] = 9;
}

bool is_num(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int main() {
    fill_map();
    int t, p;
    cin >> p;
    while (p--) {
        cin >> t;
        map<string, int> counter;
        string s;
        while (t--) {
            cin >> s;
            int len = s.length();

            string res = "";
            for (int i = 0; i < len; ++i) {
                if (s[i] != '-') {
                    if (is_num(s[i]))
                        res += s[i];
                    else res += to_string(char_mapper[s[i]]);
                }
            }

            if (counter.find(res) != counter.end())
                counter[res] += 1;
            else counter[res] = 1;
        }

        int count = 0;
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            string res = it -> first;
            if (it -> second > 1) {
                ++count;
                for (int i = 0; i < 3; ++i)
                    cout << res[i];
                cout << "-";
                for (int i = 0; i < 4; ++i)
                    cout << res[3 + i];
                cout << " ";
                cout << it -> second << "\n";
            }
        }

        if (!count)
            cout << "No duplicates.\n";
        
        if (p)
            cout << "\n";
    }

    return 0;
}


