#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int track = 0;
        for (int i=0; i<n; i++){
            if (nums[i]!=val){
                nums[track] = nums[i];
                track++;
            }
        }
        return track;
}

int main(){
    return 0;
}