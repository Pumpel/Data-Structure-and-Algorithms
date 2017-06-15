# python3

'''
A priority queue is used to keep work. The work is compared by its status and index.
The next job is the root of min priority queue. Based on this, we need to change priority
of the tree and repair tree
'''

class JobQueue:
    def read_data(self):
        self.num_workers, m = map(int, input().split())
        self.jobs = list(map(int, input().split()))
        assert m == len(self.jobs)

    def write_response(self):
        for i in range(len(self.jobs)):
          print(self.assigned_workers[i], self.start_times[i]) 

    def assign_jobs(self):
        # TODO: replace this code with a faster algorithm.
        self.assigned_workers = [None] * len(self.jobs)
        self.start_times = [None] * len(self.jobs)
        min_pq = MinPQueue(self.num_workers)
        for i in range(len(self.jobs)):
            self.assigned_workers[i] = min_pq._data[0][0]
            self.start_times[i] = min_pq._data[0][1]
            min_pq.ChangePriority(0, min_pq._data[0][1] + self.jobs[i])

    def solve(self):
        self.read_data()
        self.assign_jobs()
        self.write_response()
        
class MinPQueue:
    def __init__(self, num_workers):
        self._data = []
        self.n = num_workers
        for i in range(num_workers):
            self._data.append((i, 0))
            
    def ChangePriority(self, index, priority):
        old_p = self._data[index][1]
        self._data[index] = (self._data[index][0], priority)
        if priority < old_p:
            self.ShiftUp(index)
        else:
            self.ShiftDown(index)
            
    def RepairTree(self, i):
        for i in range(int(self.n/2), -1, -1):
            self.ShiftDown(i)
            
    def Parent(self, i):
        return self._data[int((i-1)/2)]
    
    def LeftChild(self, i):
        return 2 * i + 1
    
    def RightChild(self, i):
        return 2 * i + 2
    
    def CompareWorker(self, worker1, worker2):
        if worker1[1] != worker2[1]:
            return worker1[1] < worker2[1]
        else:
            return worker1[0] < worker2[2]
        
    def ShiftUp(self, i):
        while i > 0 and self.CompareWorker(self._data[i], self._data[self.Parent(i)]):
            self._data[i], self._data[self.Parent(i)] = self._data[self.Parent(i)], self._data[i]
            i = self.Parent(i)
            
    def ShiftDown(self, i):
        minIndex = i
        left = self.LeftChild(i)
        if left < self.n and self.CompareWorker(self._data[left], self._data[minIndex]):
            minIndex = left

        right = self.RightChild(i)
        if right < self.n and self.CompareWorker(self._data[right], self._data[minIndex]):
            minIndex = right
        if i != minIndex:
            self._data[i], self._data[minIndex] = self._data[minIndex], self._data[i]
            self.ShiftDown(minIndex)

if __name__ == '__main__':
    job_queue = JobQueue()
    job_queue.solve()

