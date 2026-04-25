<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 🔁 LeetCode 3889 — Mirror Frequency Distance

[![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red?style=flat-square)](https://leetcode.com/problems/mirror-frequency-distance/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-String%20%7C%20Frequency%20Array-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> Given a string `s` containing **lowercase letters** (`a`–`z`) and **digits** (`0`–`9`), each character has a **mirror counterpart**:

| Characters | Mirror Rule |
|-----------|------------|
| `'a'` ↔ `'z'`, `'b'` ↔ `'y'`, ... | Alphabets mirror by alphabetical distance from both ends |
| `'0'` ↔ `'9'`, `'1'` ↔ `'8'`, ... | Digits mirror symmetrically |

Return the **total count of unmatched mirror characters** — characters that appear more than their mirror.

---

## 🧠 Intuition & Approach

This is where it gets clever. Instead of separately counting each character and then comparing with its mirror, we can use a **self-cancelling frequency array**.

For every character `c` we encounter:
- **Increment** `freq[index of c]`
- **Decrement** `freq[index of mirror(c)]`

Since `mirror(mirror(c)) == c`, every perfectly matched pair cancels itself out to `0`. Unmatched characters leave behind **positive residuals**.

At the end, sum up all positive values in the frequency arrays — that's our answer.

### Mirror formulas:
```
mirror of alphabet 'c'  :  index of mirror = 'z' - c  (in 0-based alphabet array)
mirror of digit 'd'     :  index of mirror = '9' - d  (in 0-based digit array)
```

### Visual trace:
```
s = "az"

Process 'a':
  freqc['a'-'a']++ → freqc[0]++ = 1
  freqc['z'-'a']-- → freqc[25]-- = -1

Process 'z':
  freqc['z'-'a']++ → freqc[25]++ = 0  (cancelled!)
  freqc['a'-'a']-- → freqc[0]--  = 0  (cancelled!)

All zeros → ans = 0  ✅ (perfectly mirrored pair)
```

```
s = "aaz"

Process 'a' (first):  freqc[0]=1,  freqc[25]=-1
Process 'a' (second): freqc[0]=2,  freqc[25]=-2
Process 'z':          freqc[25]++→-1, freqc[0]--→1

Positive values: freqc[0]=1 → ans = 1  ✅
```

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int mirrorFrequency(string s) {
        int freqc[26] = {0};
        int freqd[10] = {0};
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                freqc[s[i] - 'a']++;
                freqc['z' - s[i]]--;      // decrement mirror's slot
            }
            if (isdigit(s[i])) {
                freqd[s[i] - '0']++;
                freqd['9' - s[i]]--;      // decrement mirror's slot
            }
        }

        for (int val : freqc) {
            if (val > 0) ans += val;
        }
        for (int val : freqd) {
            if (val > 0) ans += val;
        }
        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(n)** | Single pass over the string; post-processing is O(36) = O(1) |
| 💾 Space | **O(1)** | Two fixed arrays: `freqc[26]` + `freqd[10]` |

---

## 📊 Examples

| Input `s` | Output | Explanation |
|-----------|--------|-------------|
| `"az"` | `0` | `a` and `z` are mirrors — fully cancel |
| `"aaz"` | `1` | Two `a`s vs one `z` → one `a` unmatched |
| `"abc"` | `3` | No mirrors present → all 3 unmatched |
| `"09"` | `0` | `0` and `9` are digit mirrors — fully cancel |

---

## 🔬 Why Not Just Count Then Compare?

The naive approach would be:
1. Count freq of every character
2. For each character, compare with its mirror
3. Sum the differences

That works, but requires a second pass. The trick here **folds step 2 into step 1** — every increment is paired with a mirror decrement, so mirrors automatically neutralise each other in one pass. Cleaner, and it makes the intent crystal clear.

---

## 🔑 Key Takeaways

- 🪞 **Self-cancelling counters** are a powerful technique for symmetric pair problems
- 🔢 The formula `'z' - c` gives the mirror index in a single arithmetic op — no lookup table needed
- ✨ Only **positive** residuals matter because negative values mean the mirror side was in excess (already counted from the other direction)
- 🧮 This pattern generalises to any bijective pairing of characters

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 242 | [Valid Anagram](../0242.%20Valid%20Anagram) | Frequency array manipulation |
| 1657 | [Determine if Two Strings Are Close](../1657.%20Determine%20if%20Two%20Strings%20Are%20Close) | Frequency multiset comparison |
| 383 | Ransom Note | Character availability via frequency counting |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: String*

</div>
