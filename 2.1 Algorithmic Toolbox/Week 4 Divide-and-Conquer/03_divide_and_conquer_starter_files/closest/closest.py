#Uses python3
import sys
from math import *

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

def dist(p1, p2):
    return sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)

def Brute_Force(points):
    mindis = 100000000000
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            mindis = min(dist(points[i], points[j]), mindis)
    return mindis
    
def minimum_distance(points):
    #write your code here
    if (len(points) <= 3):
        return Brute_Force(points)

    n = len(points)
    mid = n // 2
    p_left = points[0:mid]
    p_right = points[mid:n-1]
    minleft = minimum_distance(p_left)
    minright = minimum_distance(p_right)
    dmin = min(minleft, minright)

    p_cross = []
    for item in points:
        if (abs(item.x - points[mid].x) < dmin):
            p_cross.append(item)
    
    for i in range(len(p_cross)):
        for j in range(i+1, len(p_cross)):
            if (dist(p_cross[i], p_cross[j]) < dmin):
                dmin = dist(p_cross[i], p_cross[j])
    return dmin

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    points = []
    for i in range(len(x)):
        points.append(Point(x[i], y[i]))
    psort = sorted(points, key=lambda p: p.x)
    print("{0:.9f}".format(minimum_distance(psort)))
