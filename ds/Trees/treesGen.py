# Based on my own understanding, no implmentation seen #

class TreeNode:
  def __init__ (self, parent, value):
    self.value = value
    self.childNodes = []
    self.parent = parent

class Tree:
  def addChildNode(self, newNode):
    if (newNode.parent is None):
      self.root = newNode
    else:
      newNode.parent.childNodes.append(newNode)

  def addSiblingNode(self, existingNode, newNode):
    if (existingNode.parent is None):
      print "Sibling cannot be made"
    else:
      newNode.parent = existingNode.parent
      existingNode.parent.childNodes.append(newNode)


tree = Tree()

x = TreeNode(None, 3)
tree.addChildNode(x)

y = TreeNode(x, 4)
tree.addChildNode(y)

z = TreeNode(None, 5)
tree.addSiblingNode(y, z)

print tree.root.childNodes[1].value