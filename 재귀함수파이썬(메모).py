def f(n, memo={}):
    if n<=1:
        return n
    if n not in memo:
        memo[n]=f(n-1,memo)+f(n-2,memo)
    return memo[n]

print(f(6))
