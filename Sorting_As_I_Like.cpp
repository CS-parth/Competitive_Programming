#include <bits/stdc++.h>
using namespace std;
bool sortAsILike(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return (a.first < b.first);     // FirstPreference
    else
        return (a.second > b.second);   // SecondPreference
}
int main()
{

    vector<pair<int, int>> v;
    int First_In[] = {80,29,58,92,62,64,78,41,62,32};
    int Second_In[] = {55,46,5,80,68,20,56,66,44,80};

    int Size = 10;

    for (int i = 0; i < Size; i++)
        v.push_back({First_In[i],Second_In[i]});

    cout << "Vector befor sorting:\n";
    for (int i = 0; i < Size; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    sort(v.begin(), v.end(), sortAsILike);

    cout << "Modified sorted vector:\n";
    for (int i = 0; i < Size; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}

bool sortAsILike1(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first != b.first)
        return (a.first > b.first);     // FirstPreference
    else
        return (a.second > b.second);   // SecondPreference
}
bool sortAsILike2(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first != b.first)
        return (a.first > b.first);     // FirstPreference
    else
        return (a.second < b.second);   // SecondPreference
}
bool sortAsILike3(const pair<int, int> &a, const pair<int, int> &b){ // TimeComplexity will be greater than normal sort function
    if (a.first != b.first)
        return (a.first < b.first);     // FirstPreference
    else
        return (a.second < b.second);   // SecondPreference
}
