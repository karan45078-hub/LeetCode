# 🧩 LeetCode 2022: Convert 1D Array Into 2D Array

![LeetCode](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)

## 📝 Problem Description

You are given a **0-indexed** 1-dimensional (1D) integer array `original`, and two integers, `m` and `n`. You are tasked with creating a 2-dimensional (2D) array with `m` rows and `n` columns using **all** the elements from `original`.

The elements from indices `0` to `n - 1` (inclusive) of `original` should form the first row of the constructed 2D array, the elements from indices `n` to `2 * n - 1` (inclusive) should form the second row, and so on.

**Return:** * An `m x n` 2D array constructed according to the above procedure.
* An empty 2D array if it is impossible to fit all elements.

---

## 💡 My Approach

The core logic revolves around checking if the total capacity of the requested 2D grid ($m \times n$) matches the actual size of the input array.

1.  **Validation:** I first check if $m \times n == original.size()$. If not, return an empty vector `{}` immediately.
2.  **Initialization:** Pre-allocate a 2D vector `mat` with $m$ rows and $n$ columns.
3.  **Mapping:** Use a nested loop to iterate through rows (`i`) and columns (`j`), while maintaining a pointer `k` to traverse the 1D `original` array linearly.
4.  **Efficiency:** This approach ensures we only touch each element once.

---

## 🚀 Code Implementation

```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Pre-allocate the matrix
        vector<vector<int>> mat(m, vector<int>(n));
        
        // Check if a 2D array can be formed
        if (m * n == original.size()) {
            int k = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = original[k];
                    k++;
                }
            }
        } else {
            return {}; // Return empty if dimensions don't match
        }

        return mat;
    }
};
