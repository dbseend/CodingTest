n = int(input())

# 1중 반복문
for i in range(1, n+1):
    print(" " * (n-i) + "*" * i)

# 2중 반복문
# for i in range(1, n+1):
#     for j in range(n-i):
#         print(" ", end="")
#     for j in range(i):
#         print("*", end="")
#     print()
