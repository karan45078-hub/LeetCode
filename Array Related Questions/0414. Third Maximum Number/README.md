# 414. Third Maximum Number

## 🧩 Problem Statement
Given an integer array `nums`, return the **third distinct maximum number** in this array.  
If the third distinct maximum does not exist, return the **maximum number**.

### 🔗 Example





---

## 💡 Approach

Track the top 3 distinct maximum values in a single pass without sorting.

- `max1` → largest  
- `max2` → second largest  
- `max3` → third largest  

Skip duplicates to ensure distinct values.

---

## ⚙️ Algorithm

1. Initialize `max1`, `max2`, `max3` with a value smaller than `INT_MIN` using long int
2. Traverse array:
   - Skip duplicates
   - Update values accordingly
3. If third max doesn't exist → return `max1`
4. Else → return `max3`

---

## 🧠 Code (C++)

```cpp
class Solution {
public:
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
};

**Time Complexity**
-- Time: O(n)
-- Space: O(1)