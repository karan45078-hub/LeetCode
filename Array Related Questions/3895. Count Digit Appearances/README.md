# 🔢 Count Digit Appearances (LeetCode 3895)

## 📌 Problem Statement

Given an array of integers `nums` and an integer `digit`, return the **total number of times** the given digit appears across all numbers in the array.

---

## 📜 Constraints

- `1 ≤ nums.length ≤ 1000`
- `1 ≤ nums[i] ≤ 10^6`
- `0 ≤ digit ≤ 9`

👉 This means:
- No number is `0`
- Digit can be `0`

So we **don’t need to handle zero-related edge cases**.

---

## 💡 Approach

The idea is straightforward:

- Traverse each number in the array
- Extract digits using `% 10`
- Compare each digit with the target digit
- Count occurrences and accumulate the result

---

## 🧠 Key Insight

We avoid string conversion and directly work with numbers using:
- Modulus (`%`) → to get last digit  
- Division (`/`) → to remove last digit  

This keeps the solution **simple and efficient**.

---

## ⏱️ Time Complexity
- O(N × D)

## 📦 Space Complexity
- O(1)

## 🚀 Code Implementation (C++)

```cpp
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for (int num: nums) {
            int count = 0;
            int n = num;
            while (n > 0) {
                int rem = n % 10;
                if (rem == digit) {
                    count++;
                }
                n /= 10;
            }
            ans += count;
        }
        return ans;
    }
};

