import sys
input = sys.stdin.readline

def run():
    n = int(input())
    print("Yes" if n % 6 == 0 else "No")

t = int(input())
while t > 0:
    run()
    t -= 1

