// Q2 .Problem Understanding

// We are given coin denominations: {1, 2, 5, 10, 20, 50}(given)

// We must compute for each number 1 to 99 the minimum number of units used to reach that value.

// Logic:

// Try every combination of coins (backtracking/recursion) and pick the one with the least number of units that adds up to value ≤ 99.


//  Time & Space:

// Time: O(2⁶ × 100) → Exponential (~slow for larger n)

// Space: O(depth) recursion stack (at most 100)


// Code:


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50};

int minUnitsBrute(int target, int idx = 0) {

         if (target == 0) return 0;

          if (target < 0 || idx == coins.size()) return INT_MAX;


    int take = minUnitsBrute(target - coins[idx], idx);

    if (take != INT_MAX) take += 1;

    int skip = minUnitsBrute(target, idx + 1);

    return min(take, skip);
}

void bruteCoinUsage() {

    int totalUnits = 0;

    for (int i = 1; i < 100; i++) {

        totalUnits += minUnitsBrute(i);
    }
    cout << "Avg units used: " << totalUnits / 99.0 << endl;
}



// Optimal Approach (Dynamic Programming)

// We’ll use the classic Knapsack DP ;

// Time & Space:
// Time: O(n × m) = O(100 × 6) → very efficient

// Space: O(n) = O(100)

// Code:
int minUnitsDP(int target, const vector<int>& coins) {

    vector<int> dp(target + 1, 1e9);

    dp[0] = 0;

    for (int c : coins) {

        for (int i = c; i <= target; ++i) {

            dp[i] = min(dp[i], 1 + dp[i - c]);

        }
    }
    return dp[target];
}

void optimalCoinUsage() {

    vector<int> coins = {1, 2, 5, 10, 20, 50};

    int total = 0;

    for (int i = 1; i < 100; i++) {

        total += minUnitsDP(i, coins);

    }
    cout << "Avg units used: " << total / 99.0 << endl;
}


// Custome Test Case

// "Test Case 1 - Value: 50, Units: " << minUnitsDP(50, coins) << " (Expected: 1)" << endl;




//---------------------- backend services class logic and implementation ve logic abo----------------------



export class CoinUsageService {

  private readonly coins = [1, 2, 5, 10, 20, 50];


  minUnitsDP(target: number): number {


    const dp = Array(target + 1).fill(Infinity);

          dp[0] = 0;

     for (const coin of this.coins) {

        for (let i = coin; i <= target; i++) {

        dp[i] = Math.min(dp[i], 1 + dp[i - coin]);

      }
    }

    return dp[target];
  }

  getMinUnitsForRange(): { value: number; units: number }[] {

      const result = [];

    for (let i = 1; i < 100; i++) {

      result.push({ value: i, units: this.minUnitsDP(i) });

    }

    return result;
  }

  getAverageUnitsUsed(): number {

    let total = 0;

    for (let i = 1; i < 100; i++) {

      total += this.minUnitsDP(i);
    }
    return total / 99;
  }

  getUnitsForSingleValue(value: number): number {

    return this.minUnitsDP(value);

  }
}
