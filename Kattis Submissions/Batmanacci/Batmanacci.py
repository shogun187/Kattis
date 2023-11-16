s = [0, 1, 1]

list = input().split()
N = int(list[0])
K = int(list[1])

# if N <= 2:
#     if N == 1:
#         print("N")
#     elif N == 2:
#         print("A")

for _ in range(N - 2):
    s.append(s[-2] + s[-1])

while N > 2:

    if K <= s[N - 2]:
        N -= 2

    else:
        K -= s[N - 2]
        N -= 1


if N == 1:
    print("N")

if N == 2:
    print("A")
# N A AN