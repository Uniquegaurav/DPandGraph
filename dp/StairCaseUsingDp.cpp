// Code : Staircase using Dp

// A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. 
// Implement a method to count and return all possible ways in which the child can run-up to the stairs.

// The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
// Print the total possible number of ways.

long staircase(int n)
{
	long * dp = new  long[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i =3 ;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}