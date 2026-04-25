<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 🗑️ LeetCode 27 — Remove Element

[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)](https://leetcode.com/problems/remove-element/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Two%20Pointers-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> Given an integer array `nums` and an integer `val`, remove all occurrences of `val` **in-place**. The relative order of the remaining elements may change.  
> Return `k` — the number of elements that are **not equal** to `val`.

**Constraints:**
- Do **not** allocate extra space for another array
- Modify the input array in-place with O(1) extra memory
- The judge will accept your solution if the first `k` elements of `nums` don't contain `val`

---

## 🧠 Intuition & Approach

The classic **two-pointer** trick. We keep a slow pointer (`track`) that marks where the next valid element should land. The fast pointer (`i`) sweeps through the whole array. Every time we find an element that isn't `val`, we write it at position `track` and advance `track`.

No extra space. One pass. Clean.

```
nums = [3, 2, 2, 3],  val = 3
         ↑ fast
         ↑ slow (track)

i=0 → nums[0]==3 → skip
i=1 → nums[1]==2 → nums[track]=2, track=1
i=2 → nums[2]==2 → nums[track]=2, track=2
i=3 → nums[3]==3 → skip

Result: [2, 2, _, _], k=2  ✅
```

---

## 💻 Solution (C++)

```cpp
#include <iostream>
#include <vector>
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
```

---

## ⏱️ Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(n)** | Single linear scan over all elements |
| 💾 Space | **O(1)** | No extra array — only one integer pointer |

---

## 📊 Examples

| Input `nums` | `val` | Output `k` | Modified Array |
|---|---|---|---|
| `[3,2,2,3]` | `3` | `2` | `[2,2,_,_]` |
| `[0,1,2,2,3,0,4,2]` | `2` | `5` | `[0,1,3,0,4,_,_,_]` |
| `[]` | `1` | `0` | `[]` |

---

## 🔑 Key Takeaways

- 🎯 **Two-pointer** is the go-to pattern for in-place array filtering
- 🚫 Never need to actually "delete" — just overwrite and track the valid count
- ✨ The elements beyond index `k` don't matter to the judge — leave them as-is
- 🔄 Relative order of surviving elements is **preserved** here (unlike some swap-based variants)

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 283 | [Move Zeroes](../0283.%20Move%20Zeroes) | Same two-pointer overwrite pattern |
| 26 | Remove Duplicates from Sorted Array | Same in-place filter concept |
| 80 | Remove Duplicates II | Extended version |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: Array*

</div>
