# Uses python3
import sys

def get_majority_element(a, left, right):
    if left == right:
        return -1
    if left + 1 == right:
        return a[left]
    #write your code here
    '''
    Divide and Conquer: O(nlog(n))
    '''
    k = int(right/2)
    major_left = get_majority_element(a,left,left+k-1)
    major_right = get_majority_element(a,left+k,right)
    count_left = 0
    count_right = 0
    for i in range(len(a)):
        if (a[i] == major_left):
            count_left += 1
        if (a[i] == major_right):
            count_right += 1

    if (count_left > right/2):
        return major_left
    if (count_right > right/2):
        return major_right
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
