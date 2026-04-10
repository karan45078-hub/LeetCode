# 🚀 LeetCode 11: Container With Most Water

## 🧠 Problem Summary

You are given an array `height` where each element represents the height of a vertical line on the x-axis.

Your task is to find **two lines** that together with the x-axis form a container that can hold the **maximum amount of water**.

👉 The amount of water a container can store is calculated as:

```
Area = min(height[i], height[j]) * (j - i)
```

---

## 💡 Approach Used (Two Pointer Technique)

Instead of checking all possible pairs (which would be slow), we use an optimized **two-pointer approach**.

### 🔑 Idea:

* Start with two pointers:

  * `start` → beginning of array
  * `end` → end of array
* Calculate area between them
* Move the pointer pointing to the **shorter line**

  * Because the shorter line can't give heigher value of height of water

---

## ⚙️ Algorithm Steps

1. Initialize:

   * `start = 0`
   * `end = n - 1`
   * `water = 0`

2. While `start < end`:

   * Calculate current water:

     ```
     currWater = min(height[start], height[end]) * (end - start)
     ```
   * Update max water
   * Move pointer:

     * If `height[start] <= height[end]` → move `start++`
     * Else → move `end--`

3. Return `water`

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int start = 0;
        int end = n-1;
        
        while (start < end){
            int currWater = 0;
            if (height[start] <= height[end]){
                currWater = height[start] * (end - start);
                water = max(currWater, water);
                start++;
            } else {
                currWater = height[end] * (end - start);
                water = max(currWater, water);
                end--;
            }
        }

        return water;
    }
};
```

---

## ⏱️ Complexity Analysis

| Type             | Complexity |
| ---------------- | ---------- |
| Time Complexity  | **O(n)**   |
| Space Complexity | **O(1)**   |

👉 Only one pass through the array, no extra space used.

---

## 🎯 Why This Works

* The width decreases every step.
* To maximize area, we must try to increase height.
* Moving the taller line is useless because:

  * The shorter one still limits the water.

---

## 🧪 Example

```
Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

👉 Best container is between index `1` and `8`:

* Height = min(8,7) = 7
* Width = 8 - 1 = 7
* Area = 7 × 7 = 49

---

## ⚠️ Common Mistakes

* Using brute force → O(n²) (too slow)
* Moving the taller pointer instead of shorter one
* Forgetting to update max water

---

## 📌 Final Thoughts

This is a classic **two-pointer optimization problem**.
Once you understand *why moving the shorter line works*, the solution becomes very intuitive.

---

⭐ If this helped you, consider starring your repo!
