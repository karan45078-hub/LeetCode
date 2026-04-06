# 🧩 LeetCode 242 - Valid Anagram

## 📌 Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **anagram** is a word or phrase formed by rearranging the letters of another, using all original letters exactly once.

---

## 🧠 Approach

* First, check if the lengths of both strings are equal.

  * If not, they cannot be anagrams.
* Use a frequency array of size `26` (for lowercase English letters).
* Traverse string `s` and count occurrences of each character.
* Traverse string `t`:

  * Decrease the frequency of each character.
  * If any frequency becomes `0` before decrement → not an anagram.
* If all checks pass, return `true`.

---

## 💻 LeetCode (C++): 

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }
        int freq[26] = {0};
        for (int i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
        }
        for (int j=0; j<t.length(); j++){
            if (freq[t[j]-'a']==0){
                return false;
            }
            freq[t[j] - 'a']--;
        }
        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
  (Single pass over both strings)

* **Space Complexity:** `O(1)`
  (Fixed-size array of 26 characters)

---

## ✅ Example

| Input                        | Output |
| ---------------------------- | ------ |
| s = "anagram", t = "nagaram" | true   |
| s = "rat", t = "car"         | false  |

---

## 🚀 Key Takeaways

* Efficient use of frequency counting avoids sorting (`O(n log n)`).
* Works best when input is limited to lowercase English letters.
* Simple and optimal approach for anagram checking.

---
