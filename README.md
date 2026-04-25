# 🚀 Welcome to My LeetCode Journey! 

<div align="center">

[![GitHub followers](https://img.shields.io/github/followers/karan45078-hub?style=social)](https://github.com/karan45078-hub)
[![GitHub stars](https://img.shields.io/github/stars/karan45078-hub/LeetCode?style=social)](https://github.com/karan45078-hub/LeetCode)
[![C++ Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat&logo=cplusplus)](https://github.com/karan45078-hub/LeetCode)

📝 **Documenting my problem-solving journey with clean, optimized C++ solutions**

</div>

---

## 👋 About This Repository

Hey there! Welcome to my LeetCode solutions repository. Here, I'm solving real-world coding problems, one at a time. Each solution comes with a detailed explanation, complexity analysis, and practical examples. The goal? To sharpen my coding skills and build a reference library I can revisit anytime.

I started this as a personal mission to master data structures and algorithms through hands-on practice. Every problem here represents a learning opportunity—from understanding the problem to implementing an efficient solution.

---

## 📚 Repository Structure

The solutions are organized by **problem categories** to make navigation easier:

```
📦 LeetCode
├── 🔢 Array Related Questions
│   ├── 0027. Remove Element
│   ├── 0283. Move Zeroes
│   ├── 0867. Transpose Matrix
│   └── 2022. Convert 1D Array Into 2D Array
└── 🔤 String Related Questions
    ├── 0242. Valid Anagram
    ├── 1657. Determine if Two Strings Are Close
    └── 3889. Mirror Frequency Distance
```

---

## 🔢 Array Related Questions

### [0027. Remove Element](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/0027.%20Remove%20Element)

**Difficulty:** 🟢 Easy | **Status:** ✅ Solved

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. The relative order of the elements may change. Return the number of elements in `nums` which are not equal to `val`.

- **Core Concept:** Two-pointer technique for in-place array modification
- **Time Complexity:** O(n) | **Space Complexity:** O(1)

[📖 View Solution](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/0027.%20Remove%20Element/Solution.cpp)

---

### [0283. Move Zeroes](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/0283.%20Move%20Zeroes)

**Difficulty:** 🟢 Easy | **Status:** ✅ Solved

Given an integer array `nums`, move all `0`'s to the end while maintaining the relative order of the non-zero elements.

- **Core Concept:** Two-pointer in-place manipulation
- **Time Complexity:** O(n) | **Space Complexity:** O(1)

[📖 View Solution](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/0283.%20Move%20Zeroes/Solution.cpp)

---

### [0867. Transpose Matrix](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/0867.%20Transpose%20Matrix)

**Difficulty:** 🟢 Easy | **Status:** ✅ Solved

Given a 2D integer array `matrix`, return the transpose of `matrix`. The transpose of a matrix is the matrix flipped over its main diagonal.

- **Core Concept:** 2D array manipulation and matrix operations
- **Time Complexity:** O(m × n) | **Space Complexity:** O(m × n)

[📖 View Solution](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/0867.%20Transpose%20Matrix/Solution.cpp)

---

### [2022. Convert 1D Array Into 2D Array](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/2022.%20Convert%201D%20Array%20Into%202D%20Array)

**Difficulty:** 🟢 Easy | **Status:** ✅ Solved

You are given a **0-indexed** 1-dimensional (1D) integer array `original`, and two integers, `m` and `n`. Your task is to construct a **2-dimensional (2D)** array with `m` rows and `n` columns using all the elements from `original`.

- **Core Concept:** Array reshaping and dimensional conversion
- **Time Complexity:** O(m × n) | **Space Complexity:** O(1)

[📖 View Solution](https://github.com/karan45078-hub/LeetCode/tree/main/Array%20Related%20Questions/2022.%20Convert%201D%20Array%20Into%202D%20Array/Solution.cpp)

---

## 🔤 String Related Questions

### [0242. Valid Anagram](https://github.com/karan45078-hub/LeetCode/tree/main/String%20Related%20Questions/0242.%20Valid%20Anagram)

**Difficulty:** 🟢 Easy | **Status:** ✅ Solved

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

**🎯 Key Insight:** Use frequency counting to compare character distributions without sorting!

- **Approach:** Frequency array (26 characters for lowercase English letters)
- **Time Complexity:** O(n) | **Space Complexity:** O(1)
- **Example:** `s = "anagram"`, `t = "nagaram"` → **true** ✨

[📖 View Detailed Explanation](https://github.com/karan45078-hub/LeetCode/tree/main/String%20Related%20Questions/0242.%20Valid%20Anagram)

---

### [1657. Determine if Two Strings Are Close](https://github.com/karan45078-hub/LeetCode/tree/main/String%20Related%20Questions/1657.%20Determine%20if%20Two%20Strings%20Are%20Close)

**Difficulty:** 🟡 Medium | **Status:** ✅ Solved

Two strings are considered **close** if you can swap any two characters or transform all occurrences of one character into another existing character.

**🎯 Key Insight:** Check for identical character sets and matching frequency distributions!

- **Approach:** Frequency counting + sorting + comparison
- **Time Complexity:** O(n) | **Space Complexity:** O(1)
- **Example:** `word1 = "abc"`, `word2 = "bca"` → **true** 🔄

[📖 View Detailed Explanation](https://github.com/karan45078-hub/LeetCode/tree/main/String%20Related%20Questions/1657.%20Determine%20if%20Two%20Strings%20Are%20Close)

---

### [3889. Mirror Frequency Distance](https://github.com/karan45078-hub/LeetCode/tree/main/String%20Related%20Questions/3889.%20Mirror%20Frequency%20Distance)

**Difficulty:** 🔴 Hard | **Status:** ✅ Solved

Calculate the **mirror frequency** of characters in a string. Mirror means:
- `'a'` ↔ `'z'`, `'b'` ↔ `'y'`, ... (for alphabets)
- `'0'` ↔ `'9'`, `'1'` ↔ `'8'`, ... (for digits)

Return the count of unmatched mirror characters.

**🎯 Key Insight:** Clever frequency array manipulation to automatically cancel out mirror pairs!

- **Approach:** Dual frequency arrays with mirror offset technique
- **Time Complexity:** O(n) | **Space Complexity:** O(1)

[📖 View Detailed Explanation](https://github.com/karan45078-hub/LeetCode/tree/main/String%20Related%20Questions/3889.%20Mirror%20Frequency%20Distance)

---

## 🛠️ Technology Stack

| Component | Details |
|-----------|---------|
| **Language** | C++ |
| **Standard** | C++11 or higher |
| **Focus Areas** | Data Structures, Algorithms, String Manipulation, Array Operations |
| **Problem Source** | [LeetCode](https://leetcode.com) |

---

## 📊 Problem Statistics

| Category | Count | Status |
|----------|-------|--------|
| 🔢 **Array Questions** | 4 | ✅ All Solved |
| 🔤 **String Questions** | 3 | ✅ All Solved |
| **Total Problems** | **7** | **✅ 100% Complete** |

---

## 🎓 What I've Learned

Through solving these problems, I've solidified my understanding of:

✅ **Two-Pointer Technique** - Efficient array manipulation without extra space
✅ **Frequency Counting** - A powerful approach for string/character problems  
✅ **In-Place Operations** - Optimizing space complexity  
✅ **Array Transformation** - Working with multi-dimensional arrays  
✅ **Problem Analysis** - Breaking down complex problems into simple steps

---

## 🚀 How to Use This Repository

1. **Browse Solutions** - Each problem folder contains:
   - 📝 Detailed problem explanation with examples and traces
   - 🧠 In-depth approach and intuition (not just the algorithm)
   - 💻 Clean, well-commented C++ code
   - ⏱️ Complexity analysis (time **and** space)
   - 🔗 Related problems to explore next

2. **Study the Code** - Solutions follow best practices:
   - Clear variable naming
   - Well-commented logic
   - Optimized approaches

3. **Learn the Concepts** - Read through explanations to understand:
   - Why certain approaches work
   - Trade-offs between solutions
   - Complexity considerations

---

## 🤝 Connect With Me

Let's talk about coding, algorithms, and problem-solving!

<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-%40karan45078--hub-black?style=for-the-badge&logo=github)](https://github.com/karan45078-hub)
[![LeetCode](https://img.shields.io/badge/LeetCode-%40karan45078--hub-FFA116?style=for-the-badge&logo=leetcode)](https://leetcode.com/u/karan45078/)
[![Email](https://img.shields.io/badge/Email-Contact%20Me-blue?style=for-the-badge&logo=gmail)](mailto:karan45078@gmail.com)

</div>

---

## 💡 Future Plans

I'm continuously solving new problems and expanding this repository. Upcoming categories:

- 🌳 **Tree & Graph Problems**
- 🔗 **Linked List Operations**
- 🎯 **Dynamic Programming**
- 📐 **Math & Bit Manipulation**
- 🔍 **Searching & Sorting**

---

## 📝 Notes

- All solutions are written and tested in **C++**
- Each solution aims for **optimal time and space complexity**
- Code is clean, readable, and follows best practices
- Detailed explanations help understand the **"why"** behind each solution

---

## ⭐ If You Found This Helpful

If my solutions helped you or you found them useful, don't forget to give this repository a **⭐ star!** It really helps and motivates me to keep solving and documenting more problems.

<div align="center">

**Happy Coding! 🎉**

*Last Updated: 2026-04-25*

</div>
