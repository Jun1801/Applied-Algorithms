import random as rd
def Input():
    [n, K] = list(map(int, input().split()))
    arr = [int(x) for x in input().split()]
    return n, K, arr

def can_split(arr, s, K):
    count = 1
    current_sum = 0
    for x in arr:
        if current_sum + x > s:
            count += 1
            current_sum = x # khoảng tiếp theo
            if count > K:
                return False
        else:
            current_sum += x
    return True

def solve():
    n = rd.randint(1, 1000)
    K = rd.randint(1, 20)
    arr = [rd.randint(1, 1000) for x in range(n)]
    low = max(arr)
    high = sum(arr)
    upper_bound = high
    while low <= high:
        mid = (low + high) // 2 
        if can_split(arr, mid, K):
            upper_bound = mid
            high = mid - 1
        else:
            low = mid + 1
    # Tìm ra đc giá trị cận trên là mid để tổng các khoảng <= mid

    partitions = []
    sum_partitions = []
    subset = []
    current_sum = 0
    for x in arr:
        if current_sum + x > upper_bound:
            partitions.append(subset) # sum của khoảng cũ
            sum_partitions.append(sum(subset))
            subset = [x] # Khoảng tiếp theo
            current_sum = x
        else:
            current_sum += x
            subset.append(x)
    partitions.append(subset)
    sum_partitions.append(sum(subset))

    max_val = max(sum_partitions)
    min_val = min(sum_partitions)
    
    if len(partitions) > K:
        print("FAIL")
        return
    else:
        print(f"N = {n}, K = {K}")
        print(f"OPTIMAL VALUE: {max_val - min_val}")
        print("SOLUTION: ")
        for idx, subset in enumerate(partitions):
            print(f"Subset {idx + 1}: {subset}")
solve()
        

    