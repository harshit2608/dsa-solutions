/**
This problem is a variation of the Fibonacci sequence, where the number of ways to reach step n is the sum of the ways to reach steps n-1 and n-2.
 */
var climbStairs = function (n) {
    if (n <= 2) return n;

    let prev1 = 2;
    let prev2 = 1;
    let curr;

    for (let i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
};