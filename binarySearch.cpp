#include <bits/stdc++.h>
using namespace std;
bool issmaller(int ok,int key){
    return ok <= key;
}
int binary_search_(vector<int> &nums,int key,int left,int right){
    while(right - left > 1){    // stoping the loop when both iterators are closest
        int mid = left + (right-left)/2;    
        if(issmaller(nums[mid],key)){
            left = mid;     // as mid is also a contender (we will keep it) 
        }else{
            right = mid - 1;    // as mid is not a contender (we will remove it)
        }
    }
        // Finally checking the final two conditions manually
        if(issmaller(nums[right],key)){
            return nums[right];
        }if(issmaller(nums[left],key)){
            return nums[left];
        }
    return INT_MIN;
}
int binary_search__(vector<int> &nums,int key,int left,int right){
    int mid = left + (right - left)/2;
    if(right - left <= 1){
        // Finally checking the final two conditions manually
        if(issmaller(nums[right],key)){
            return nums[right];
        }if(issmaller(nums[left],key)){
            return nums[left];
        }
    return INT_MIN;
    }
    if(issmaller(nums[mid],key)){
        left = mid;     // as mid is also a contender (we will keep it)  
        return binary_search__(nums,key,left,right); // recursive call 
    }else{
        right = mid - 1;    // as mid is not a contender (we will remove it)
        return binary_search__(nums,key,left,right); // recursive call
    }
}
bool predicate(int mid){
    return true;
}
int BS(int index){
    int lo = -1;    // set lo to the first 0
    int hi = index + 1; // set hi to the last possible 1
    while(hi > lo + 1){
        int mid = (hi - lo)/2 + lo;
        if(predicate(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    if(1){ // If you want to return the fist 1 than return hi
        return hi;
    }else{ // if you want to return last zero return lo
        return lo;
    }
}
int main(){
    vector<int> nums = {5,10,10,98,66,40,33,29};    // 5,10,10,29,33,40,66,98 //0-7
    sort(nums.begin(),nums.end());
    cout << binary_search__(nums,10,0,nums.size()-1);
}

