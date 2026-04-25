<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 🔀 LeetCode 867 — Transpose Matrix

[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=flat-square)](https://leetcode.com/problems/transpose-matrix/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Matrix-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> Given a 2D integer array `matrix`, return the **transpose** of `matrix`.  
> The transpose of a matrix is obtained by flipping it over its **main diagonal** — every element at position `(i, j)` moves to position `(j, i)`.

```
Original (2×3):          Transposed (3×2):
 1  2  3                  1  4
 4  5  6        →         2  5
                          3  6
```

---

## 🧠 Intuition & Approach

Create a new matrix of dimensions `cols × rows` (dimensions are swapped). Then iterate over every cell `(i, j)` in the original and write it into `(j, i)` in the new matrix.

```
Original[i][j]  →  Transposed[j][i]
```

That's it — no tricks needed. This is a **direct simulation** problem.

**Visual trace:**
```
matrix = [[1,2,3],[4,5,6]]
row=2, col=3  →  transmat size: 3×2

(0,0)→(0,0): 1    (0,1)→(1,0): 2    (0,2)→(2,0): 3
(1,0)→(0,1): 4    (1,1)→(1,1): 5    (1,2)→(2,1): 6

transmat = [[1,4],[2,5],[3,6]]  ✅
```

---

## 💻 Solution (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> transmat(col, vector<int>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transmat[j][i] = matrix[i][j];
        }
    }
    return transmat;
}
```

---

## ⏱️ Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| ⏰ Time | **O(m × n)** | Every element visited exactly once |
| 💾 Space | **O(m × n)** | New matrix of size `n × m` is allocated |

> 💡 Note: For **square matrices** you *could* transpose in-place by swapping `(i,j)` ↔ `(j,i)` for `i < j`, reducing space to O(1). For non-square matrices, an output matrix is unavoidable.

---

## 📊 Examples

| Input | Output |
|-------|--------|
| `[[1,2,3],[4,5,6]]` | `[[1,4],[2,5],[3,6]]` |
| `[[1,2],[3,4],[5,6]]` | `[[1,3,5],[2,4,6]]` |
| `[[1]]` | `[[1]]` |

---

## 🔑 Key Takeaways

- 🎯 Transposing = **swapping row and column indices**
- 📐 Result dimensions are always `cols × rows` — remember to swap them when creating the output!
- 🔄 For square matrices you can go in-place; for rectangular ones you need extra space
- 🧮 Foundation for many linear algebra and image-processing operations

---

## 🔗 Related Problems

| # | Problem | Similarity |
|---|---------|-----------|
| 2022 | [Convert 1D Array Into 2D Array](../2022.%20Convert%201D%20Array%20Into%202D%20Array) | 2D array construction |
| 48 | Rotate Image | In-place matrix transformation |
| 54 | Spiral Matrix | 2D traversal patterns |

---

<div align="center">

*Part of the [LeetCode Solutions](../../README.md) repository · Language: C++ · Category: Array / Matrix*

</div>
