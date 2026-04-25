#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    vector<int> max_freq(10001, -1);
    vector<int> st;  // stack

    for (int i = 0; i < nums2.size(); i++) {
        while (!st.empty() && st.back() < nums2[i]) {
            max_freq[st.back()] = nums2[i];
            st.pop_back();
        }
        st.push_back(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++) {
        ans.push_back(max_freq[nums1[i]]);
    }

    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}