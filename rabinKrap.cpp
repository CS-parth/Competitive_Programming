    #include <bits/stdc++.h>
    using namespace std;

    vector<int> rabin_karp(string const& s, string const& t) {
        const int p = 31; 
        const int m = 1e9 + 9;
        int S = s.size(), T = t.size();

        vector<long long> p_pow(max(S, T)); 
        p_pow[0] = 1; 
        for (int i = 1; i < (int)p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1] * p) % m;

        vector<long long> h(S + 1, 0); 
        for (int i = 0; i < S; i++)
            h[i+1] = (h[i] + (s[i]) * p_pow[i]) % m; 
        long long h_t = 0; 
        for (int i = 0; i < S; i++) 
            h_t = (h_t + (t[i]) * p_pow[i]) % m; 

        vector<int> occurrences;
        for (int i = 0; i + T - 1 < S; i++) {
            long long cur_h = (h[i+T] + m - h[i]) % m;
            if (cur_h == h_t * p_pow[i] % m)
                occurrences.push_back(i);
        }
        return occurrences;
    }

    int main(){
        
    }