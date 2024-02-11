n = list(input())

for i in range(len(n)):
    n[i] = chr(ord(n[i])-3)

result = ''.join(n)
print(result)