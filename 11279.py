import sys
input = sys.stdin.readline

def parent(idx): return (idx-1) // 2
def leftChild(idx): return idx * 2 + 1
def rightChild(idx): return idx * 2 + 2

class Heap:
    def __init__(self):
        self._data = []

    def swap(self, i1, i2):
        self._data[i1], self._data[i2] = self._data[i2], self._data[i1]

    def push(self, value: int):
        self._data.append(value)

        idx = len(self._data) - 1
        while parent(idx) >= 0 and self._data[parent(idx)] < self._data[idx]:
            self.swap(idx, parent(idx))
            idx = parent(idx)

    def pop(self):
        if len(self._data) == 0: return 0
        self._data[0], self._data[-1] = self._data[-1], self._data[0]
        rst = self._data.pop()

        idx = 0
        while True:
            if leftChild(idx) >= len(self._data):
                break
            elif rightChild(idx) >= len(self._data):
                if self._data[idx] < self._data[leftChild(idx)]:
                    self.swap(idx, leftChild(idx))
                    idx = leftChild(idx)
                else:
                    break
            else:
                if self._data[idx] < max(self._data[leftChild(idx)], self._data[rightChild(idx)]):
                    if self._data[leftChild(idx)] < self._data[rightChild(idx)]:
                        self.swap(idx, rightChild(idx))
                        idx = rightChild(idx)
                    else:
                        self.swap(idx, leftChild(idx))
                        idx = leftChild(idx)
                else:
                    break
        return rst

heap = Heap()
for _ in range(int(input())):
    d = int(input())
    if d == 0: print(heap.pop())
    else: heap.push(d)
