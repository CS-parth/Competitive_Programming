#include <iostream>
using namespace std;
// O(sqrtN)


void primefact(int num){
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0){
            int cnt = 0;
            while(num%i == 0){
                cnt++;
                num = num/i;
            }
            cout << i << "^" << cnt << " * ";
        }
    }
}