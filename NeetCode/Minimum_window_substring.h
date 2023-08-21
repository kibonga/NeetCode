#pragma once
#include <stdio.h>
#include <map>
using namespace std;

string minimum_window_substring(string str, string t){
    map<char, int> window, T;
    char c;
    int i, j, need, have, n, min_len, start, end, temp_min;
    i = 0, j = 0, n = str.size(), have = 0, min_len = INT_MAX, start = 0, end = 0, temp_min = INT_MAX;

    for (char c : t) {
        T[c] += 1;
    }

    need = T.size();

    for (; i < n; i++) {
        c = str[i];

        if (T.find(c) == T.end()) {
            continue;
        }
        
        window[c] += 1;

        if (window[c] == T[c]) {
            have++;
        }

        if (have != need) {
            continue;
        }

        while (have == need) {
            c = str[j];
            if (T.find(c) == T.end()) {
                j++;
                continue;
            }
            
            window[c] -= 1;
            
            if (window[c] < T[c]) {
                have--;
                continue;
            }
            j++;
        }
        
        temp_min = i - j + 1;
        if (temp_min < min_len) {
            min_len = temp_min;
            start = j;
            end = i;
        }
        j++;
    }

    string result = "";
    if (min_len > 0 && min_len <= str.size()) {
        result = str.substr(start, min_len);
    }
    return result;
}
