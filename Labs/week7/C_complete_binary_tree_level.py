n = int(input())
a = [0] + list(map(int, input().split()))
post = []
idx = 0

def postorder(x):
    global idx
    if x > n:
        return
    postorder(x * 2)
    postorder(x * 2 + 1)
    post.append(x)

postorder(1)
mp = [0] * (n + 1)
for i in range(1, n + 1):
    mp[post[i - 1]] = a[i]

print(' '.join(str(mp[i]) for i in range(1, n + 1)))
