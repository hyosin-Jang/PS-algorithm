import sys

from collections import deque

dx = [-1,0,1,0]
dy = [0,1,0,-1]
m, n = map(int, sys.stdin.readline().split())
a=[]
q = deque()

for i in range(n):
    a.append(list(map(int, sys.stdin.readline().split() )))
    for j in range(m):
        if a[i][j] == 1 :
            q.append((i,j))

def bfs():
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if a[nx][ny]:
                continue
            a[nx][ny] = a[x][y] + 1
            q.append((nx,ny))

def solve():
    bfs()
    ans=0
    for i in range(n):
        if 0 in a[i]:
            return -1
        ans = max(ans, max(a[i]))
    return ans -1
print(solve())
