# Implementation of Linked List Data Structure in Python

def insertNode(linkedList,value,index = 0):
  newNode = Node(value)
  if linkedList.head == None:
    linkedList.head = newNode
    print('Inserted the first node')
  else:
    node = linkedList.head
    if node.next == None:
      node.next = newNode
    else:
      count = 1
      while(count < index - 1):
        node = node.next
        count = count + 1
      if node.next == None:
        node.next = newNode 
      else:
        nextNode = node.next
        node.next = newNode
        newNode.next = nextNode

  linkedList.printLinkedList()

class Node:
  def __init__(self,data):
    self.data = data
    self.next = None

  def printNode(self):
    print('Data: ',self.data)
    print('Next : ',self.next.data)

  def printNodeValue(self):
    print('Data: ',self.data)


class linkedList:
  def __init__(self):
    self.head = None

  def printLinkedList(self):
    if self.head == None:
      print('No head')
    else:
      node = self.head
      while(node.next != None):
        node.printNode()
        node = node.next
      node.printNodeValue()
      print('Next: none')


def main():
  llist = linkedList()
  while(True):
    value = int(input('What is the value of the new node to be inserted? '))
    position = int(input('What is the position of the new node to be inserted? '))
    insertNode(llist,value,position)
    choice = input('Do you wish to continue? Hit y if yes ')
    if(choice == 'y'):
      continue
    else:
      print('Thank you')
      break

if __name__ == '__main__':
  main()