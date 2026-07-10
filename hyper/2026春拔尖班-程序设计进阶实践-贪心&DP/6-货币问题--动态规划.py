n = int(input())

# 转化为以10元为单位，缩小规模
n = n // 10
coins = [1, 2, 5]  # 10元=1单位, 20元=2单位, 50元=5单位

# dp[i] 表示凑出 i 个单位的方案数
dp = [0] * (n + 1)
dp[0] = 1  # 凑0元有一种方案（什么都不选）

for coin in coins:
    for i in range(coin, n + 1):
        dp[i] += dp[i - coin]

print(dp[n])