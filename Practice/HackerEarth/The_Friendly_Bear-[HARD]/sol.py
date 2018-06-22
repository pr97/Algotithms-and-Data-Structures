"""Runs on Python 2.x"""

n = int(raw_input())
l = []
for i in range(n):
	point = [int(x) for x in raw_input().split()]
	l.append(point)
sum = 0
for i in range(n - 1):
	for j in range(i + 1, n):
		sum += (abs(l[i][0] - l[j][0]) + abs(l[i][1] - l[j][1]))
print(sum)