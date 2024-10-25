def main():
    mod = 10**9 + 7
    n = int(input())
    to = list(map(lambda x: int(x)-1, input().split()))
    f = [0] * (n+1)

    for i in range(n):
        f[i+1] = 2*f[i] - f[to[i]] + 2
        f[i+1] %= mod

    print(f[n])


if __name__ == '__main__':
    _ = 1
    while _:
        _ -= 1
        main()
