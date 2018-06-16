# Based on my understanding only, no implementation seen #

# Heap Formulae #
'''
left = i * 2
right = i * 2 + 1
parent = i / 2  
'''
# Min Heap Functions #

class MinHeap():
  def __init__(self):
    self.heapList = [None]

  # Functions to be used outside 
  def addNode (self, nodeValue):
    heapList = self.heapList

    nodeIndex = len(heapList)
    heapList.append(nodeValue)

    self.heapifyNode(nodeIndex)

  def remove (self):
    heapList = self.heapList
    
    heapList[1] = heapList[len(heapList) - 1]
    heapList.pop()
    self.heapifyReverse(1)

  # Utility functions
  def heapifyNode (self, nodeIndex):
    heapList = self.heapList

    parentIndex = int(round(nodeIndex / 2))
    if heapList[nodeIndex] is None:
      return

    elif (heapList[nodeIndex] < heapList[parentIndex]):
      self.moveNodeUp(nodeIndex, parentIndex)
      self.heapifyNode(parentIndex)

    else:
      return

  def heapifyReverse (self, nodeIndex):
    heapList = self.heapList
    rightChildIndex = ( nodeIndex * 2 ) + 1
    leftChildIndex = ( nodeIndex * 2 )
    
    if (rightChildIndex < len(heapList)):
      minChild = min(heapList[leftChildIndex], heapList[rightChildIndex])

      if (heapList[nodeIndex] > minChild):
        minChildIndex = leftChildIndex if (heapList[leftChildIndex] < heapList[rightChildIndex]) else rightChildIndex
        self.moveNodeDown(nodeIndex, minChildIndex)
        self.heapifyReverse(minChildIndex)

      else:
        return

    elif (leftChildIndex < len(heapList)):
      if (heapList[nodeIndex] > heapList[leftChildIndex]):
        self.moveNodeDown(nodeIndex, leftChildIndex)
        self.heapifyReverse(leftChildIndex)
    
    else: 
      return

  def moveNodeUp (self, nodeIndex, parentIndex):
    heapList = self.heapList

    temp = heapList[nodeIndex]
    heapList[nodeIndex] = heapList[parentIndex]
    heapList[parentIndex] = temp

  def moveNodeDown (self, nodeIndex, childIndex):
    heapList = self.heapList
    temp = heapList[nodeIndex]
    heapList[nodeIndex] = heapList[childIndex]
    heapList[childIndex] = temp

x = MinHeap()
print x.heapList
x.addNode(6)
x.addNode(5)
x.addNode(4)
x.addNode(3)
x.addNode(2)
print x.heapList
x.remove()
print x.heapList
