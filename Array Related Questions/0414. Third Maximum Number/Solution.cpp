#include <iostream>
#include <vector>
using namespace std;

int thirdMax(vector<int>& nums) {
    long int max1 = -2147483649;
    long int max2 = -2147483649;
    long int max3 = -2147483649;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3) {
            continue;
        }

        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } 
        else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } 
        else if (nums[i] > max3) {
            max3 = nums[i];
        }
    }

    if (max2 == -2147483649 || max3 == -2147483649) {
        return max1;
    } else {
        return max3;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Result: " << thirdMax(nums) << endl;

    return 0;
}