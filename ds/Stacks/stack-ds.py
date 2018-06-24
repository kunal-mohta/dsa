# Based on my understanding, no implementation seen #

class Stack ():
  def __init__ (self):
    self.stack = []

  def pushStack (self, element):
    self.stack.append(element)

  def popStack (self):
    if (len(self.stack) > 0):
      self.stack.pop()

    else:
      print 'Cannot popStack the stack is empty'

x = Stack()
x.pushStack(1)
x.pushStack(3)
print x.stack
x.popStack()
x.popStack()
x.popStack()
print x.stack

# this was useless because python already has functions to do the same job