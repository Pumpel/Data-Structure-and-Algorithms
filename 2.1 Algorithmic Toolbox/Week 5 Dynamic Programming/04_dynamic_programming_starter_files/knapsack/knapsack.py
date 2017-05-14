# Uses python3
import sys

def optimal_weight(W, w):
    # write your code here
    n = len(w)
    rows = n + 1
    cols = W + 1
    value = [[0 for _ in range(cols)] for _ in range(rows)]
    #print(value)

    for i in range(1, rows):
        for j in range(1, cols):
            value[i][j] = value[i-1][j]
            if w[i-1] <= j:
                val = value[i-1][j-w[i-1]] + w[i-1]
                if value[i][j] < val:
                    value[i][j] = val
    return value[rows-1][cols-1]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    '''
    print(W)
    print(n)
    print(w)
    '''
    print(optimal_weight(W, w))
