# Uses python3
#import sys

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def fib(n, memo = {0: 0, 1: 1}):
    if n not in memo:
        memo[n] = fib(n-1, memo)+fib(n-2, memo)
    return memo[n]

def pisano(n):
    cycle = []
    i = 0
    while True:
        cycle.append(fib(i) % n)
        m = len(cycle)
        if m % 2 == 0 and m != 0 and cycle[:int(m/2)] == cycle[int(m/2):]:
            break
        i += 1
    return cycle[:int(m/2)]

def fibonacci_sum_fast(n):
    # the sum of the nth fibonnaci is F(n+2)-1
    mod10 = pisano(10)
    clen = len(mod10)
    return mod10[(n+2) % clen] - 1

if __name__ == '__main__':
    #input = sys.stdin.read()
    n = int(input())
    print(fibonacci_sum_fast(n))
