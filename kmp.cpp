#include <bits/stdc++.h>

using namespace std;

vector<int> prefix(string s){
    vector<int> pi(s.size(),0);
    for(int i = 1;i < s.size();i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> kmpsearch(string s,string t){
        if(s.size() < t.size()) return {};
        vector<int> pi = prefix(t);
        vector<int> indices;
        int i = 0;
        int j = 0;
        while(i < s.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            if(j == t.size()){
                indices.push_back(i-j);
                j = pi[j-1];
            }else if(s[i] != t[j]){
                if(j != 0) j = pi[j-1];
                else i++;
            }
        }
        return indices;
}
int main(){
    // This is not everyone that should
    
}