def Input():
    [n, x, y] = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    return n, x, y, a
def solve():
    n, x, y, a = Input()
    dp = {} # dp[i]: number of days from day a1 to day ai, where the revenue is betwwen x and y
    dp[0] = 0
    if a[0] >= x and a[0] <= y:
        dp[0] = 1
    for i in range(1, n):
        if a[i] >= x and a[i] <= y:
            dp[i] = dp[i-1] + 1
        else:
            dp[i] = dp[i-1]
    print(dp[n-1])
solve()