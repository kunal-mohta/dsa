// Application of Rabin-karp algorithm (rolling hash) - LC 1044

#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

vector<int> power;

// function where rabin karp (rolling hash) is used
string check (string s, int n, int len) {
    int hash = 0, p = 10000007;
    for (int i = 0; i < len; i++) {
        hash = ((hash * 26) % p + s[i] - 'a') % p; // **IMP**
    }
    unordered_map<int, vector<int>> ump; // (hash -> index) mapping
    ump[hash].push_back(0);

    int req_pow = power[len-1];
    for (int i = len; i < n; i++) {
        hash = (hash - ((s[i-len]-'a')*req_pow)%p + p) % p; // **IMP**
        hash = ((hash * 26) % p + s[i]-'a') % p; // **IMP**
        if (ump.find(hash) != ump.end()) {
            string curr_str = s.substr(i-len+1, len);
            for (int j : ump[hash]) {
                if (curr_str == s.substr(j, len)) {
                    return curr_str;
                }
            }
        }
        ump[hash].push_back(i-len+1);
    }
    return "";
}

string longestDupSubstring(string s) {
    int n = s.size();
    power = vector<int>(n+1);
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i-1] * 26) % 10000007;
    }
    int lo = 1, hi = n;

    string ans = "";
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        // cout<<"here "<<mid<<endl;
        string curr = check(s, n, mid);
        if (curr != "") {
            ans = curr;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ans;
}

int main () {
}