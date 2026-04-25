<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 🔤 LeetCode 1657 — Determine if Two Strings Are Close

[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=flat-square)](https://leetcode.com/problems/determine-if-two-strings-are-close/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-String%20%7C%20Hash%20Table%20%7C%20Sorting-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> Given two strings `word1` and `word2`, return `true` if they are **close**, and `false` otherwise.

Two strings are **close** if you can attain one from the other using either of these operations **any number of times**:

- **Operation 1:** Swap any two **existing** characters  
  `"abc"` → `"bca"` (swap positions 0 and 1, then 1 and 2)
  
- **Operation 2:** Transform every occurrence of one character into another **existing** character, and vice versa  
  `"aacbb"` → `"bbcaa"` (swap all `a`s ↔ `b`s)

---

## 🧠 Intuition & Approach

Think about what these two operations actually change — and what they don't.

- **Operation 1** (swap positions) can produce **any permutation** of the string → only the **set of frequencies** matters, not their assignment to specific characters.
- **Operation 2** (swap characters globally) can reassign which frequency belongs to which character, but it can only reassign among characters that **already exist** in the string.

Two conditions must therefore both hold:

| Condition | What it checks | How |
|-----------|---------------|-----|
| Same character set | Both strings use exactly the same distinct characters | For each of the 26 letters, both frequency arrays must be either both zero or both non-zero |
| Same frequency multiset | The multiset of frequency values must match | Sort both frequency arrays and compare element by element |

### Step-by-step:
1. **Length check** — different lengths → impossible → `false`
2. **Frequency count** — build `freq1[26]` and `freq2[26]` in one pass
3. **Character presence check** — if `freq1[i]==0 XOR freq2[i]==0` → `false`
4. **Sort and compare** frequencies — if the sorted arrays differ → `false`
5. All checks passed → `true`

---

## 💻 Solution (C++)

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

## ⏱️ Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(n)** | One pass for frequency counting; sorting 26 elements is O(1) |
| 💾 Space | **O(1)** | Two fixed arrays of 26 integers each |

---

## 📊 Examples

| `word1` | `word2` | Output | Reason |
|---------|---------|--------|--------|
| `"abc"` | `"bca"` | `true` | Same chars, same frequencies — just rearranged |
| `"a"` | `"aa"` | `false` | Different lengths |
| `"cabbba"` | `"abbccc"` | `true` | Both use {a,b,c}; freq multisets are both {1,2,3} |
| `"cabbba"` | `"aabbss"` | `false` | `word2` has `s`, `word1` doesn't |

---

## 🔍 Why the two conditions are both necessary

```
word1 = "aab",  word2 = "bbc"
Freq1: a=2, b=1         sorted: [0,...,0, 1, 2]
Freq2: b=2, c=1         sorted: [0,...,0, 1, 2]

Sorted freqs MATCH ✅
But word1 has 'a', word2 doesn't → character sets differ ❌
→ return false
```

This shows that the sorted-frequency check alone is not enough — you need **both** checks.

---

## 🔑 Key Takeaways

- 🎯 Understand what each allowed operation **preserves** vs. what it can change
- 📊 Sorting a fixed-size array (26 elements) is O(1) — don't be scared to use it
- 🔄 "Same character set" is an XOR-zero check: `(f1==0) == (f2==0)` for every letter
- 🧩 This problem is a great example of reducing string equivalence to frequency analysis

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 242 | [Valid Anagram](../0242.%20Valid%20Anagram) | Frequency comparison |
| 49 | Group Anagrams | Sorting + grouping by frequency signature |
| 859 | Buddy Strings | Character swap conditions |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: String*

</div>
