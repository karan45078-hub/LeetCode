<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 0️⃣ LeetCode 283 — Move Zeroes

[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)](https://leetcode.com/problems/move-zeroes/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Two%20Pointers-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> Given an integer array `nums`, move all `0`'s to the **end** while maintaining the **relative order** of the non-zero elements. Do this **in-place** without making a copy of the array.

**Example:**
```
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

---

## 🧠 Intuition & Approach

Think of it as **compacting** the array: we slide all non-zero values to the front (preserving their order), then fill the tail with zeros.

We use a `nonZero` pointer that tracks the next slot for a non-zero value. When `nums[i]` is non-zero, we **swap** it with `nums[nonZero]` and advance `nonZero`. This keeps zeros drifting toward the right naturally.

```
[0, 1, 0, 3, 12]
 ^nonZero ^i

i=0: nums[0]==0, skip
i=1: nums[1]==1 → swap(nums[0],nums[1]) → [1,0,0,3,12], nonZero=1
i=2: nums[2]==0, skip
i=3: nums[3]==3 → swap(nums[1],nums[3]) → [1,3,0,0,12], nonZero=2
i=4: nums[4]==12 → swap(nums[2],nums[4]) → [1,3,12,0,0], nonZero=3 ✅
```

---

## 💻 Solution (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonZero = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[nonZero], nums[i]);
            nonZero++;
        }
    }
}
```

---

## ⏱️ Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(n)** | One pass through the array |
| 💾 Space | **O(1)** | In-place swapping, no auxiliary array |

---

## 📊 Examples

| Input | Output |
|-------|--------|
| `[0,1,0,3,12]` | `[1,3,12,0,0]` |
| `[0]` | `[0]` |
| `[1,2,3]` | `[1,2,3]` (no zeros, no change) |
| `[0,0,1]` | `[1,0,0]` |

---

## 🔑 Key Takeaways

- 🎯 Swap-based two-pointer keeps the **relative order** of non-zero elements intact
- 🚫 Avoid the temptation to use a second array — the whole point is O(1) space
- 💡 An alternative is to overwrite (like problem 27) then fill zeros — both are valid but swap minimises write operations when zeros are sparse
- 🧩 This pattern appears in partition problems (Dutch National Flag, quicksort pivot)

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 27 | [Remove Element](../0027.%20Remove%20Element) | Same two-pointer overwrite |
| 75 | Sort Colors | Extended 3-way partition |
| 26 | Remove Duplicates from Sorted Array | In-place filter |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: Array*

</div>
