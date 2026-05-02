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