# Uses python3
#import sys

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

def fibonacci_partial_sum_fast(from_, to):
    #sum of F(m) to F(n) is F(n+2)-F(m+1)
    mod10 = pisano(10)
    clen = len(mod10)
    last_digit = (mod10[(to+2) % clen] - mod10[(from_+1) % clen])

    if  last_digit >=0:
        return last_digit
    else:
        return 10 + last_digit

if __name__ == '__main__':
    #input = sys.stdin.read();
    from_, to = map(int, input().split())
    print(fibonacci_partial_sum_fast(from_, to))
