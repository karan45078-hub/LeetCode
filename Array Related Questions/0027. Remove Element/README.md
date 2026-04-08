# 🧩 Remove Element (LeetCode 27)

## 📌 Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` **in-place** and return the new length.

The order of elements may be changed. It doesn't matter what you leave beyond the returned length.

---

## 💡 Approach

* Use a **two-pointer technique**:

  * One pointer (`i`) traverses the array
  * Another pointer (`track`) keeps track of valid elements
* If the current element is not equal to `val`, place it at `track` index
* Increment `track` to build the updated array

---

## ⚙️ Code

```cpp
#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int track = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[track] = nums[i];
            track++;
        }
    }
    return track;
}

int main() {
    return 0;
}
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n)
  → We traverse the array once

* **Space Complexity:** O(1)
  → No extra space used (in-place modification)

---

## 📚 Key Concepts

* Two pointer technique
* In-place array modification
* Efficient traversal

---

## 🎯 Key Takeaway

This problem teaches how to modify an array **without using extra space**, which is a common interview pattern.

---

## 🔗 Problem Link

https://leetcode.com/problems/remove-element/
