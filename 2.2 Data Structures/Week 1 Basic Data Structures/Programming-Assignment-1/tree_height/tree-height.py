# python3

import sys, threading
sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

class TreeHeight:
        def read(self):
                self.n = int(sys.stdin.readline())
                self.parents = list(map(int, sys.stdin.readline().split()))
                self.maxdepth = 0
                self.depths = [0] * self.n

        def compute_height(self):
                if self.maxdepth == 0:
                        for idx, pa in enumerate(self.parents):
                                depth = self.get_depth(idx)
                                if self.maxdepth < depth:
                                        self.maxdepth = depth
                return self.maxdepth

        def get_depth(self, idx):
                depth = self.depths[idx]
                if depth != 0:
                        return depth
                parent = self.parents[idx]
                if parent == -1:
                        depth = 1
                else:
                        depth = self.get_depth(parent) + 1
                self.depths[idx] = depth
                return depth

def main():
  tree = TreeHeight()
  tree.read()
  print(tree.compute_height())

threading.Thread(target=main).start()
