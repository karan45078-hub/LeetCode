#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int water = 0;
    int n = height.size();
    int start = 0;
    int end = n-1;
    
    while (start<n){
        int currWater = 0;
        if (height[start]<=height[end]){
            currWater = height[start] * (end-start);
            water = max(currWater,water);
            start++;
        }else{
            currWater = height[end] * (end-start);
            water = max(currWater,water);
        end--;
        }
    }
    return water;
}

int main(){
    return 0;
}