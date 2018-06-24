# Based on my understanding only, no implementation seen #

class Queue ():
  def __init__ (self):
    self.queue = []

  def enqueue (self, element):
    self.queue.append(element)

  def dequeue (self):
    if (len(self.queue) > 0):
      self.queue.pop(0)

    else:
      print 'Cannot dequeue the queue is empty'

x = Queue()
x.enqueue(1)
x.enqueue(2)
print x.queue
x.dequeue()
x.dequeue()
print x.queue
x.dequeue()