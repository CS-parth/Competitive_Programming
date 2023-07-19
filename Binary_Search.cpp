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
int main(){
    vector<int> nums = {5,10,10,98,66,40,33,29};    // 5,10,10,29,33,40,66,98 //0-7
    sort(nums.begin(),nums.end());
    cout << binary_search__(nums,10,0,nums.size()-1);
}
