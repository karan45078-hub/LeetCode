<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 🔲 LeetCode 2022 — Convert 1D Array Into 2D Array

[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)](https://leetcode.com/problems/convert-1d-array-into-2d-array/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Matrix-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> You are given a **0-indexed** 1D integer array `original` and two integers `m` and `n`.  
> Construct a **2D array** with `m` rows and `n` columns using **all** elements from `original` in row-major order.  
> Return the 2D array. If it's impossible, return an **empty** 2D array.

**Impossible condition:** `original.size() != m * n`

---

## 🧠 Intuition & Approach

The elements should be placed left-to-right, top-to-bottom — exactly like reading a book (row-major order). There's a neat index formula:

```
1D index k  →  2D position (k / n, k % n)
```

Alternatively, use a flat counter `k` and fill row by row with nested loops.

**Visual trace:**
```
original = [1,2,3,4], m=2, n=2

k=0 → mat[0][0] = 1
k=1 → mat[0][1] = 2
k=2 → mat[1][0] = 3
k=3 → mat[1][1] = 4

Result: [[1,2],[3,4]]  ✅
```

---

## 💻 Solution (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> mat(m, vector<int>(n));
    if (m * n == (int)original.size()) {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = original[k];
                k++;
            }
        }
    } else {
        return {};
    }
    return mat;
}
```

---

## ⏱️ Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(m × n)** | Every element placed exactly once |
| 💾 Space | **O(1)** | Output excluded — no auxiliary data structures used |

---

## 📊 Examples

| `original` | `m` | `n` | Output |
|---|---|---|---|
| `[1,2,3,4]` | `2` | `2` | `[[1,2],[3,4]]` |
| `[1,2,3]` | `1` | `3` | `[[1,2,3]]` |
| `[1,2]` | `1` | `1` | `[]` (impossible: 2 ≠ 1×1) |

---

## 🔑 Key Takeaways

- 🎯 Always **validate** `m * n == original.size()` first — return `{}` otherwise
- 📐 Row-major order is the natural reading order: row 0 fully filled, then row 1, etc.
- 💡 The index formula `k = i*n + j` is the **mathematical definition** of row-major layout — useful in many problems
- 🔄 This is essentially the inverse of `.flatten()` in numpy

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 867 | [Transpose Matrix](../0867.%20Transpose%20Matrix) | 2D array construction |
| 54 | Spiral Matrix | 2D traversal |
| 59 | Spiral Matrix II | Fill 2D array in order |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: Array / Matrix*

</div>
