#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonZero = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]!=0){
            swap(nums[nonZero],nums[i]);
            nonZero++;
        }
    }
}

int main(){
    //Example
    vector<int>arr = {2,0,4,6,0,9,0,3,3};
    moveZeroes(arr);
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}