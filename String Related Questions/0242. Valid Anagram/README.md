<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 🧩 LeetCode 242 — Valid Anagram

[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)](https://leetcode.com/problems/valid-anagram/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-String%20%7C%20Hash%20Table-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **anagram** is a word or phrase formed by rearranging the letters of another word, using all the original letters exactly once.

```
"anagram"  →  rearrange  →  "nagaram"  ✅
"rat"      →  rearrange  →  "car"      ❌  (different letters)
```

---

## 🧠 Intuition & Approach

The naive approach sorts both strings and compares them — that works but costs **O(n log n)**. We can do better.

Since the strings only contain lowercase English letters (`a`–`z`), we can use a **fixed-size frequency array of 26 integers**:

1. If lengths differ → immediately `false`
2. Scan `s` and **increment** the frequency of each character
3. Scan `t` and **decrement** — if we'd go below `0`, some character in `t` appears more than in `s` → `false`
4. All decrements succeeded → every character matched → `true`

No sorting. No hash maps. Just arithmetic on a 26-element array — effectively **O(1) space**.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        for (int j = 0; j < t.length(); j++) {
            if (freq[t[j] - 'a'] == 0) {
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

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(n)** | Two linear passes over strings of length `n` |
| 💾 Space | **O(1)** | Fixed array of exactly 26 integers — constant regardless of input size |

> 🆚 Sorting approach: O(n log n) time, O(1) space — our solution is strictly better.

---

## 📊 Examples

| `s` | `t` | Output | Why |
|-----|-----|--------|-----|
| `"anagram"` | `"nagaram"` | `true` | Same letters, different order |
| `"rat"` | `"car"` | `false` | Different letters |
| `"a"` | `"ab"` | `false` | Different lengths |
| `"ab"` | `"ba"` | `true` | Simple swap |

---

## 🔍 Step-by-step Trace

```
s = "rat",  t = "car"

After scanning s:
freq['r'-'a'] = freq[17] = 1
freq['a'-'a'] = freq[0]  = 1
freq['t'-'a'] = freq[19] = 1

Scanning t:
t[0]='c' → freq[2]==0 → return false  ❌
```

---

## 🔑 Key Takeaways

- 🎯 **Frequency counting beats sorting** for character-level problems
- 📏 Always check lengths first — it's a free O(1) early exit
- 🔤 The `char - 'a'` trick maps any lowercase letter to `[0, 25]`
- 🌍 For **Unicode inputs** (follow-up), swap the array for an `unordered_map<char,int>`

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 49 | Group Anagrams | Anagram grouping with hash map |
| 438 | Find All Anagrams in a String | Sliding window anagram detection |
| 1657 | [Determine if Two Strings Are Close](../1657.%20Determine%20if%20Two%20Strings%20Are%20Close) | Extended frequency comparison |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: String*

</div>

