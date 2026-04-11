#include <iostream>
#include <string>
using namespace std;


int countDigitOccurrences(vector<int>& nums, int digit) {
    int ans = 0;
    for (int num:nums){
        int count = 0;
        int n=num;
        while(n>0){
            int rem = n%10;
            if (rem==digit){
                count++;
            }
            n /= 10;
        }
        ans += count;
    }
    return ans;
}

int main(){
    return 0;
}