# 🔁 Mirror Frequency Counter

This is a simple C++ solution to calculate the **mirror frequency** of characters in a string.

## 📌 Problem Idea

Given a string containing **lowercase alphabets (`a-z`)** and **digits (`0-9`)**, we define:

- Mirror of `'a'` → `'z'`
- Mirror of `'b'` → `'y'`
- ...
- Mirror of `'0'` → `'9'`
- Mirror of `'1'` → `'8'`
- ...

The goal is to count how many **extra occurrences exist compared to their mirror characters**.

---

## ⚙️ Approach

1. Maintain two frequency arrays:
   - `freqc[26]` → for alphabets
   - `freqd[10]` → for digits

2. Traverse the string:
   - For each alphabet:
     - Increment its frequency
     - Decrement its mirror character frequency **It automatecaly remove dublicate mirror pair**
   - For each digit:
     - Same logic using `'9' - digit`

3. Count only **positive values** in frequency arrays:
   - These represent unmatched characters (more than their mirror)

---

## 💻 LeetCode (C++): 

```cpp
class Solution {
public:
    int mirrorFrequency(string s) {
        int freqc[26] = {0};
        int freqd[10] = {0};
        int ans = 0;
        for (int i=0; i<s.length(); i++){
            if (isalpha(s[i])){
                freqc[s[i] - 'a']++;
                freqc['z' - s[i]]--;
            }
            if(isdigit(s[i])){
                freqd[s[i]-'0']++;
                freqd['9'-s[i]]--;
            }
        }

        for (int val:freqc){
            if (val>0){
                ans += val;
            }
        }
        for (int val:freqd){
            if (val>0){
                ans += val;
            }
        }
        return ans;
    }
};