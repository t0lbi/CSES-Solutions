# Submission Timestamp: 2026-04-04 19:16:43

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)
def lcm(a, b):
	return a * b // gcd(a, b)
n = int(input())
r = list(map(int, input().split()))
p = 0
q = 1
for i in range(n):
	for j in range(n):
		q = int(lcm(q, r[i] * r[j]))
for i in range(n):
	for j in range(i):
		for a in range(2, r[j]+1):
			c = int(min(r[i], a-1) * q // (r[i] * r[j]))
			p = p + c
 
ans = int(round(1000000*p/q))
 
if (ans * 10 + 5) * q == p * 10000000:
	if (ans % 2 == 1):
		ans = ans + 1
elif (ans * 10 - 5) * q == p * 10000000:
	if (ans % 2 == 1):
		ans = ans - 1
elif (ans * 10 + 5) * q < p * 10000000:
	ans = ans + 1
elif (ans * 10 - 5) * q > p * 10000000:
	ans = ans - 1
 
 
print(f"{ans/1000000:.6f}")