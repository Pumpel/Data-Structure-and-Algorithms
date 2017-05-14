# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n

    return calc_fib(n - 1) + calc_fib(n - 2)

def calc_fib_fast(n):
    fib = [0] * (n+1)
    fib[0] = 0
    fib[1] = 1
    
    if (n > 1):
        for i in range(2,n+1):
            fib[i] = fib[i-1] + fib[i-2]

    return fib[n]


n = int(input())
#print(calc_fib(n))
print(calc_fib_fast(n))
