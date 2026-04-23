# 🔍 Next Greater Element I – LeetCode 496

Solution to **Next Greater Element I** from LeetCode using an optimized **Monotonic Stack** approach.

---

## 📌 Problem Summary

Given two arrays:

* `nums1` ⟶ subset of `nums2`
* `nums2` ⟶ reference array

For each element in `nums1`, find the **next greater element in nums2**.

👉 The next greater element is the first element to the right that is greater than the current number.
👉 If none exists, return `-1`.

---

## 🧠 Intuition

Brute force would check each element → **O(n²)** ❌

Instead, we:

* Process `nums2` once
* Use a **Monotonic Decreasing Stack**
* Store results in a lookup array (`max_freq`)

💡 Idea:

* Keep stack elements in decreasing order
* When a larger element appears:

  * It becomes the "next greater" for all smaller elements in stack

---

## ⚙️ Approach (Step-by-Step)

1. Traverse `nums2`
2. Maintain a stack:

   * While current element > stack top:

     * Pop from stack
     * Store mapping
3. Push current element to stack
4. Use stored results to build answer for `nums1`

---

## 🔄 Dry Run

### Input:

```
nums1 = [4,1,2]
nums2 = [1,3,4,2]
```

### Process:

| Step | Stack | Mapping Updates |
| ---- | ----- | --------------- |
| 1    | [1]   | —               |
| 2    | [3]   | 1 → 3           |
| 3    | [4]   | 3 → 4           |
| 4    | [4,2] | —               |

### Final Mapping:

```
1 → 3
3 → 4
4 → -1
2 → -1
```

### Output:

```
[-1, 3, -1]
```

---

## ⚡ Complexity Analysis

* **Time Complexity:** `O(n1 + n2)`
* **Space Complexity:** `O(n2)`

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> max_freq(10001, -1);
        vector<int> st; //stack like

        for (int i = 0; i < nums2.size(); i++) {
            while (st.size() > 0 && st[stack.size() - 1] < nums2[i]) {
                max_freq[st[st.size() - 1]] = nums2[i];
                st.pop_back();
            }
            st.push_back(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(max_freq[nums1[i]]);
        }

        return ans;
    }
};
```

---

## 🧩 Key Concepts

* Monotonic Stack (Decreasing)
* Greedy Processing
* Precomputation for fast lookup

---

## 🚀 Why This Solution is Efficient

* Each element is pushed & popped **at most once**
* No nested loops
* Fast lookup using array instead of map

---

## ✨ Improvement Idea

Instead of:

```cpp
vector<int> max_freq(10001, -1);
```

You can use:

```cpp
unordered_map<int, int>
```

👉 More flexible if constraints change

---

## 📚 Author

* 👨‍💻 Karan Kumar
