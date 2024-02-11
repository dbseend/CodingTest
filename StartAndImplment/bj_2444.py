n = int(input())

for i in range(1, n*2):
    blanks = abs(n-i)
    stars = (n-blanks) * 2 - 1
    print(" " * blanks + "*" * stars)

# dst = n*2
# for i in range(1, dst):
#     if (i < n):
#         print(" " * (n-i) + "*"*(i*2-1))
#     elif (i == n):
#         print("*"*(dst-1))
#     else:
#         print(" " * (i-n) + "*" * ((dst-i)*2-1))
