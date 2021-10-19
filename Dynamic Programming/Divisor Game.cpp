/*
1025. Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Constraints:

1 <= n <= 1000
*/

class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N + 1];
        memset(dp, false, N + 1);
        for(int i = 2; i <= N; i++) {
            for(int j = 1; j*j <= i; j++) {
                if(i % j == 0 && !dp[i - j])
                    dp[i] = true;
            }
        }
        return dp[N];
    }
};
