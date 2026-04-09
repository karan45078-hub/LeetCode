# 😅 Move Zeroes (C++)

> Not gonna lie… this problem looks easy, but it’s actually a nice test of how clean your thinking is.

---

## 🤔 What this does

Given an array, the goal is simple:

* Push all `0`s to the end
* Keep the order of other elements the same

Sounds basic… but the **way you solve it matters**.

---

## 💭 Honest Thoughts

At first, I thought:

> “Just swap zeros with elements from the back.”

But that quickly gets messy and inefficient.

Then comes the cleaner idea:

> “Why not just shift non-zero elements forward?”

And boom — problem becomes simple and elegant.

---

## 🧠 The Actual Idea (No Overhype)

* Keep a pointer (`insertPos`)
* Traverse the array once
* Place non-zero elements at the front
* Fill the rest with zeroes

No tricks. No fancy stuff. Just clean logic.

---

## ⚡ Complexity (Straight Talk)

* Time → `O(n)` (you have to look at everything anyway)
* Space → `O(1)` (no extra memory, which is nice)

---

## 🔍 Example

```
Input:  2 0 4 6 0 9 0 3 3
Output: 2 4 6 9 3 3 0 0 0
```

---

## 🛠️ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int insertPos = 0;

    for (int num : nums) {
        if (num != 0) {
            nums[insertPos++] = num;
        }
    }

    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
}

int main() {
    vector<int> arr = {2, 0, 4, 6, 0, 9, 0, 3, 3};

    moveZeroes(arr);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
```

---

## 🧪 Try It Yourself

Before running the code, pause for a second:

👉 What would be the output for this?

```
0 1 0 2 0 3
```

<details>
<summary>Click to reveal answer</summary>

```
1 2 3 0 0 0
```

</details>

---

## 📌 What I Learned

* Simple problems still test your thinking
* Clean code > clever code
* Two-pointer technique is everywhere

---

## 🧍 Final Thought

This isn’t a “wow” problem.

But solving it cleanly?
That’s what actually matters in interviews.

---

⭐ If you relate to this struggle, you’re on the right track.
