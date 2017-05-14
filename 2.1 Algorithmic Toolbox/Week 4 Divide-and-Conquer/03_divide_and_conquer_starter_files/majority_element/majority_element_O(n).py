# Uses python3
import sys

def get_majority_element(a, left, right):
    if left == right:
        return -1
    if left + 1 == right:
        return a[left]
    #write your code here
    '''
    Boyer-Moore Majority Vote Algorithms: O(n)
    https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    '''
    major, counter = 0, 0
    for i in range(len(a)):
        if (counter == 0):
            major = a[i]
            counter = 1
        elif (a[i] ==  major):
            counter += 1
        else:
            counter -= 1
    major_counter = 0
    for i in range(len(a)):
        if (a[i] == major):
            major_counter += 1
    if (major_counter > len(a)/2):
        return 1
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
