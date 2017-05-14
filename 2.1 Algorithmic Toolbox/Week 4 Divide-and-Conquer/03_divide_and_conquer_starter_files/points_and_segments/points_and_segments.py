# Uses python3
import sys

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    #write your code here
    '''
    [0, 5], [-3, 2], [7, 10] and points of 1, 6 sorted into [-3, LEFT], [0, LEFT]
    , [1, POINT], [2, RIGHT], [5, RIGHT], [6, POINT] and count # of "LEFT" before
    POINT
    '''
    LEFT = 1
    POINT = 2
    RIGHT = 3

    sletter = [LEFT] * len(starts)
    eletter = [RIGHT] * len(ends)
    pletter = [POINT] * len(points)

    numlist = starts + ends + points
    letterlist = sletter + eletter + pletter

    sortednum, sortedletter = zip(*sorted(zip(numlist, letterlist)))

    count = 0
    point_counts = {}
    for p in points:
        point_counts[p] = 0
    
    for i in range(len(sortedletter)):
        if sortedletter[i] == LEFT:
            count += 1
        elif sortedletter[i] == RIGHT:
            count -= 1
        elif sortedletter[i] == POINT:
            if point_counts[sortednum[i]] == 0:
                point_counts[sortednum[i]] += count

    for i in range(len(points)):
        cnt[i] = point_counts[points[i]]
    
    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
