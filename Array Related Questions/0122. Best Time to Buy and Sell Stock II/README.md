<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode Logo" width="80"/>

# 📈 LeetCode 122 — Best Time to Buy and Sell Stock II

[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow?style=flat-square)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square\&logo=cplusplus)](./Solution.cpp)
[![Status](https://img.shields.io/badge/Status-Solved%20✅-success?style=flat-square)]()
[![Topic](https://img.shields.io/badge/Topic-Array%20%7C%20Greedy-orange?style=flat-square)]()

</div>

---

## 📌 Problem Statement

> You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `i-th` day.
> On each day, you may decide to buy and/or sell the stock.

👉 You can:

* Buy and sell multiple times
* Hold at most **one share at a time**

Return the **maximum profit** you can achieve.

---

## 🧠 Intuition & Approach

This problem follows a **greedy strategy**.

Instead of trying to find global peaks and valleys explicitly, we:

* Buy whenever we see a low price
* Sell whenever we see a higher price next

👉 Key idea:

> Capture **every upward price difference**

If price increases from one day to next, we take that profit.

```
prices = [7, 1, 5, 3, 6, 4]

1 → 5  = +4 profit  
3 → 6  = +3 profit  

Total = 7 ✅
```

Your approach simulates this by:

* Tracking a `buy` value (minimum so far)
* Selling whenever a profit opportunity appears
* Immediately resetting buy to current price

---

## 💻 Solution (C++)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int buy = INT_MAX;
    int sell = INT_MAX;

    for (int pr : prices) {
        if (pr < buy) {
            buy = pr;
        }
        if (pr > buy) {
            sell = pr;
            ans += sell - buy;
            buy = pr;
        }
    }
    return ans;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices);

    return 0;
}
```

---

## ⏱️ Complexity Analysis

| Metric   | Value    | Reason                               |
| -------- | -------- | ------------------------------------ |
| ⏰ Time   | **O(n)** | Single pass through the array        |
| 💾 Space | **O(1)** | Only variables used, no extra memory |

---

## 📊 Examples

| Input           | Output |
| --------------- | ------ |
| `[7,1,5,3,6,4]` | `7`    |
| `[1,2,3,4,5]`   | `4`    |
| `[7,6,4,3,1]`   | `0`    |

---

## 🔑 Key Takeaways

* 💡 Greedy works because **every local profit contributes to global profit**
* 📉 No need to track full transactions explicitly
* ⚡ Add profit whenever `price[i] > price[i-1]`
* 🔄 This problem allows **multiple transactions**, unlike LeetCode 121

---

## 🔗 Related Problems

| #   | Problem                             | Similarity               |
| --- | ----------------------------------- | ------------------------ |
| 121 | Best Time to Buy and Sell Stock     | Single transaction only  |
| 123 | Best Time to Buy and Sell Stock III | At most two transactions |
| 188 | Best Time to Buy and Sell Stock IV  | At most k transactions   |

---

<div align="center">

*Part of the LeetCode Solutions repository · Language: C++ · Category: Array / Greedy*

</div>
