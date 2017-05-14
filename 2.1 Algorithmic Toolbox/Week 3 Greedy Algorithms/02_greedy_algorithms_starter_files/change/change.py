# Uses python3
# import sys

def get_change(m):
    #write your code here
    coins = [10, 5, 1]
    num = [0, 0, 0]
    cn = len(coins)
    remainder = m
    for i in range(cn):
        num[i] = int(remainder / coins[i])
        remainder = int(remainder % coins[i])
    return sum(num)

if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
