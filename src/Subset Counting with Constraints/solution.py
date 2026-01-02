import heapq
from bisect import bisect_left, bisect_right
def Input():
    n = int(input())
    a = list(map(int, input().split()))
    [LB, UB] = [int(x) for x in input().split()]
    return n, a, LB, UB
def get_subset_sums(arr):
    sums = [0]
    for num in arr:
        new_sums = [num + x for x in sums]
        sums.extend(new_sums)
    return sums
def solve():
    n, a, LB, UB = Input()
    mid = n // 2
    a_left = a[:mid]
    a_right = a[mid:]
    
    sum_left = get_subset_sums(a_left) # Liệt kê tất cả các tổng con có thể ở a_left
    sum_right = get_subset_sums(a_right) # Liệt kê tất cả các tổng con có thể ở a_right

    sum_right.sort()
    count = 0
    
    for x in sum_left:
        # Tìm y trong sum_right sao cho LB<= x+y<=UB hay tìm các giá trị y sao cho LB-x <= y<=UB-x
        target_min = LB - x
        target_max = UB - x
        idx_min = bisect_left(sum_right, target_min) # Chỉ số đầu tiên mà sum_right >= target_min
        idx_max = bisect_right(sum_right, target_max)
        count += idx_max - idx_min
    print(count)

solve()