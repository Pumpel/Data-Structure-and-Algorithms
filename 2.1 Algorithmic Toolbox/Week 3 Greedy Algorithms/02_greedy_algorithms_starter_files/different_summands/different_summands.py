# Uses python3
import sys

def optimal_summands(n):
    summands = [1]
    Test = 2
    Total = 3
    while (Total <= n):
        summands.append(Test)
        Test += 1
        Total += Test
    summands[-1] += n - (Total - Test)
    return summands

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
