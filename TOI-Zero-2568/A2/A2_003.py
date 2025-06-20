N = int(input())
heights = list(map(int, input().split()))

count = 0

for i in range(N):
    left = heights[i - 1] if i - 1 >= 0 else float('-inf')
    right = heights[i + 1] if i + 1 < N else float('-inf')

    if heights[i] > left and heights[i] > right:
        count += 1

print(count)