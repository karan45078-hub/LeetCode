# 🔤 Close Strings Problem (LeetCode)

## 📌 Problem Statement
Given two strings `word1` and `word2`, determine if they are **close**.

Two strings are considered **close** if:
1. You can swap any two characters.
2. You can transform all occurrences of one character into another existing character.

---

## 🧠 Approach

### Step 1: Length Check
If lengths are different → return `false`

### Step 2: Frequency Count
Count frequency of characters using arrays of size 26

### Step 3: Character Presence Check
Both strings must have the same set of characters

### Step 4: Frequency Comparison
**4.1** Sort both frequency arrays
**4.2** If sorted frequencies match → return true ---> Else → return false

---

## 💻 LeetCode (C++): 

```cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        
        if (word1.length() != word2.length()) return false;

        for (int i = 0; i < word1.length(); i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) ||
                (freq2[i] == 0 && freq1[i] != 0)) {
                return false;
            }
        }

        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }

        return true;
    }
};
```

---

## ⏱️ Time Complexity
**O(n)**

## 📦 Space Complexity
**O(1)**

---

## 📊 Example

| word1 | word2 | Output |
|------|------|--------|
| abc  | bca  | true   |
| a    | aa   | false  |
| cabbba | abbccc | true |

---

## 🚀 Key Insight
Same characters + same frequency distribution ⇒ strings are **close**