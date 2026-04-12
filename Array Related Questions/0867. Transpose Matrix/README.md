# 🔄 Transpose Matrix (LeetCode 867)

## 📌 Problem Statement
Given a 2D integer matrix `matrix`, return the **transpose** of the matrix.

👉 The **transpose** of a matrix is obtained by converting all rows into columns.

---

## 🧠 Intuition
- Rows become columns  
- Columns become rows  
- Element at position `(i, j)` moves to `(j, i)`

---

## ⚙️ Approach

### Step-by-step:
1. Get number of rows and columns  
2. Create a new matrix of size `col × row`  
3. Traverse the original matrix  
4. Assign:
   `transposed[j][i] = matrix[i][j]`  
5. Return the new matrix  

---

## 💻 Code (C++)

```cpp
class Solution {
public:
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
};
```

---

## 📊 Example

### Input:
```
matrix = [
  [1, 2, 3],
  [4, 5, 6]
]
```

### Output:
```
[
  [1, 4],
  [2, 5],
  [3, 6]
]
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity |
|-------|----------|
| Time  | O(m × n) |
| Space | O(m × n) |

---

## 🚀 Key Takeaways
- Simple matrix manipulation problem  
- Great for understanding 2D traversal  
- Common in image processing & data transformation  

---

## ⭐ If you found this helpful
Give this repo a ⭐ and keep grinding LeetCode 💪
** If you find any mistakes or improvements, please open an issue or submit a pull request. **
