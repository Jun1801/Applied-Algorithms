def Input():
    [n, x, y] = list(map(int, input().split()))
    a = list(map(int, input().split()))
    m = int(input())
    pairs = []
    for _ in range(m):
        [i, j] = list(map(int, input().split()))
        pairs.append([i, j])
    return n, x, y, a, m, pairs

def create_prefix_sum(arr):
    prefix = {}
    n = len(arr)
    prefix[0] = arr[0]
    for i in range(1, n):
        prefix[i] = prefix[i-1] + arr[i]
    return prefix

def solve():
    n, x, y, a, m , pairs = Input()
    prefix = create_prefix_sum(a)
    for [i, j] in pairs:
        if i == 1 and i < j:
            s = prefix[j-1]
        elif i > 1 and i < j:
            s = prefix[j-1] - prefix[i-2]
        if s >= x and s <= y:
            print("1")
        else: print("0")
solve()

