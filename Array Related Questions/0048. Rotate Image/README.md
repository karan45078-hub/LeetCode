# 🌀 LeetCode 48 - Rotate Image

## 📌 Problem Statement

Given an `n x n` 2D matrix representing an image, rotate the image by **90 degrees clockwise**.

You must rotate the image **in-place**, which means you have to modify the input matrix directly without using another matrix.

---

## 🧾 Example

### Input:

```
matrix = [
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

### Output:

```
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]
```

---

## ⚙️ Approach

### 🔹 Key Idea:

We rotate the matrix **layer by layer** (like peeling an onion).

Each layer consists of 4 sides:

* Top
* Right
* Bottom
* Left

We rotate elements in groups of 4:

```
top → right  
right → bottom  
bottom → left  
left → top  
```

---

## 🔄 Step-by-Step Explanation

1. Traverse through each layer (`i = 0 to n/2`)
2. For each layer:

   * Identify 4 boundaries:

     * Top row
     * Bottom row
     * Left column
     * Right column
3. Move elements in cyclic order (4-way swap)
4. Continue until the entire layer is rotated

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i=0; i<n/2; i++){
            int row1 = i, row2 = i, row3 = n-1-i, row4 = n-1-i;
            int col1 = i, col2 = n-1-i, col3 = n-1-i, col4 = i;

            while (col1<col2){
                int ptr1 = matrix[row1][col1];
                int ptr2 = matrix[row2][col2];
                int ptr3 = matrix[row3][col3];
                int ptr4 = matrix[row4][col4];

                int temp1 = ptr2;
                matrix[row2][col2] = ptr1;
                row2++;

                int temp2 = ptr3;
                matrix[row3][col3] = temp1;
                col3--;

                int temp3 = ptr4;
                matrix[row4][col4] = temp2;
                row4--;

                matrix[row1][col1] = temp3;
                col1++;
            }
        }
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n²)`
  Every element is visited once.

* **Space Complexity:** `O(1)`
  In-place rotation, no extra space used.

---

## 🧠 Key Points

* Rotation is done **in-place**, no extra matrix allowed.
* Work **layer by layer** from outer to inner.
* Each iteration performs a **4-way swap**.
* Works only for **square matrices (n x n)**.

---

## 🚀 Alternative Approach (Simpler)

You can also solve this using:

1. **Transpose the matrix**
2. **Reverse each row**

---

## ✅ Summary

* Efficient in-place solution
* No extra memory used
* Clean layer-based rotation logic

---

Happy Coding! 🎯
