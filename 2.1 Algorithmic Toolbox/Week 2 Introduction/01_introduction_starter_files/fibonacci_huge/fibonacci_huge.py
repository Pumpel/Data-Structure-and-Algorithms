# Uses python3
#import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m


def get_fibonacci_huge_fast(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    cycle = []
    cycle.append(0)
    cycle.append(1)

    while True:
        previous, current = current, (previous + current) % m
        cycle.append(current)
        clen = len(cycle)
        if clen%2 == 0 and clen != 0 and cycle[:int(clen/2)] == cycle[int(clen/2):]:
            break

    pasino = cycle[: int(clen/2)]
    clen = len(pasino)
    
    return pasino[n%clen]

if __name__ == '__main__':
    #input = sys.stdin.read();
    n, m = map(int, input().split())
    print(get_fibonacci_huge_fast(n, m))
