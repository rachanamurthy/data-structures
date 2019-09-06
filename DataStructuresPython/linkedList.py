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

def removeNode(linkedList,value):
  if linkedList.head == None:
    print('Linked List empty')
  else:
    node = linkedList.head
    while(node.next.data != value):
      node = node.next

    deleteNode = node.next
    node.next = deleteNode.next
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
    choice = int(input('Please enter the operation that you would like to perform on the stack : \n1.Insert Node \n2.Remove Node \n3.Show Linked List \n4.Quit : '))
    if (choice == 1):
      value = int(input('What is the value of the new node to be inserted? '))
      position = int(input('What is the position of the new node to be inserted? Enter 0 if you wish to just add the node to the end of the list '))
      insertNode(llist,value,position)
    elif (choice == 2):
      value = int(input('Enter the value of the node to be removed: '))
      removeNode(llist,value)
    elif (choice == 3):
      llist.printLinkedList();
    elif (choice == 4):
      print('Thank you')
      break
    else:
      print('Invalid Choice\n')
      continue

if __name__ == '__main__':
  main()