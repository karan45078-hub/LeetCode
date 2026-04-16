# 🧩 36. Valid Sudoku

![LeetCode](https://img.shields.io/badge/LeetCode-Medium-orange)
![Language](https://img.shields.io/badge/Language-C++-blue)
![Topic](https://img.shields.io/badge/Topics-Array%2C%20Hashing%2C%20Matrix-green)
![Status](https://img.shields.io/badge/Status-Solved-success)

---

## 📌 Problem Overview

Given a **9 × 9 Sudoku board**, determine if it is valid.

A board is valid if:

- ✅ Each **row** contains unique digits (1–9)
- ✅ Each **column** contains unique digits (1–9)
- ✅ Each **3 × 3 sub-box** contains unique digits (1–9)

> ⚠️ Only filled cells need validation  
> ⚠️ Board does NOT need to be solvable

---

## 🧠 Intuition

Instead of solving Sudoku, we just **check for duplicates**.

We scan:
- All rows
- All columns
- All 3×3 boxes

If any duplicate is found → ❌ Invalid

---

## 🛠️ Approach

### 🔹 Step 1: Validate Rows
- Use a frequency array of size 9
- Track occurrences of digits
- Reset after each row

### 🔹 Step 2: Validate Columns
- Same logic as rows
- Traverse column-wise

### 🔹 Step 3: Validate 3×3 Boxes
- Iterate in blocks of size 3
- Check each box independently

---

## 🧮 Complexity Analysis

| Type | Complexity |
|------|------------|
| ⏱️ Time | `O(1)` |
| 🧠 Space | `O(1)` |

> Because the board size is fixed (9×9)

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>freqRow = {0,0,0,0,0,0,0,0,0};
        vector<int>freqCol = {0,0,0,0,0,0,0,0,0};

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                int currRow = board[i][j];
                if (currRow=='.'){
                    continue;
                }
                if(freqRow[currRow-'1']==0){
                    freqRow[currRow-'1']++;
                }else{
                    return false;
                }
            }
            freqRow = {0,0,0,0,0,0,0,0,0};
        }

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                int currCol = board[j][i];
                if (currCol=='.'){
                    continue;
                }
                if(freqCol[currCol-'1']==0){
                    freqCol[currCol-'1']++;
                }else{
                    return false;
                }
            }
            freqCol = {0,0,0,0,0,0,0,0,0};
        }

        vector<int>box = {0,0,0,0,0,0,0,0,0};

        for (int k=0; k<9; k+=3){
            for (int l=0; l<9; l+=3){
                for (int i=k; i<k+3; i++){
                    for (int j=l; j<l+3; j++){
                        int curr = board[i][j];
                        if (curr=='.'){
                            continue;
                        }
                        if(box[curr-'1']==0){
                            box[curr-'1']++;
                        }else{
                            return false;
                        }
                    }
                }
                box = {0,0,0,0,0,0,0,0,0};
            }
        }

        return true;
    }
};