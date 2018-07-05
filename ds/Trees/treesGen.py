# Based on my own understanding, no implmentation seen #

class TreeNode:
  def __init__ (self, parent, value):
    self.value = value
    self.childNodes = []
    self.parent = parent

class Tree:
  def __init__ (self):
    self.root = None

  def addChildNode (self, newNode):
    if (newNode.parent is None):
      self.root = newNode
    else:
      newNode.parent.childNodes.append(newNode)

  def addSiblingNode (self, existingNode, newNode):
    if (existingNode.parent is None):
      print "Sibling cannot be made"
    else:
      newNode.parent = existingNode.parent
      existingNode.parent.childNodes.append(newNode)

  def preOrderTraversal (self, node):
    if node is None:
      if self.root is not None:
        node = self.root
      else:
        return False

    print node.value
    if len(node.childNodes) is 0:
      return False
    else:
      for i in range(0, len(node.childNodes)):
        self.preOrderTraversal(node.childNodes[i])

tree = Tree()

x = TreeNode(None, 3)
tree.addChildNode(x)

y = TreeNode(x, 4)
tree.addChildNode(y)

q = TreeNode(y, 7)
tree.addChildNode(q)

z = TreeNode(None, 5)
tree.addSiblingNode(y, z)

tree.preOrderTraversal(None)

# only pre order traversal possible for trees which are not binary
