# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    points = []

    seg = sorted(segments, key=lambda Segment: Segment.end)
    p=seg[0].end
    points.append(p)
    
    for s in seg:
        if (p < s.start | p > s.end):
            p = s.end
            points.append(p)
    return points

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    ##print(segments)
    points = optimal_points(segments)
    print(len(points))
    for p in points:
        print(p, end=' ')
    
