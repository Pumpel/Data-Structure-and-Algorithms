# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    # write your code here
    vpw = [x/y for x, y in zip(values, weights)]
    vpw, weights, values = zip(*sorted(zip(vpw, weights, values), reverse=True))
    print(vpw)
    print(values)
    print(weights)
    
    rem = capacity
    for i in range(len(vpw)):
        item = rem
        if item >= weights[i]:
            item = weights[i]
            value += item * vpw[i]
            rem -= item
        else:
            value += item * vpw[i]
            rem -= item

    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
