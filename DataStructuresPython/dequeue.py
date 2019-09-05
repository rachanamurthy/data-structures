# Implementation of Dequeue Data Structure
# Dequeue is an extension of a queue data structure.
# Insertion and Deletion from both the ends is possible.

def insertFront(dequeue,element):
  if len(dequeue) == 10:
    print('Overflow: Queue size full. Cannot push element.')
  else:
    dequeue.append(element)
    print('Element has been pushed.')
  return(dequeue)

def insertRear(dequeue,element):
  if len(dequeue) == 10:
    print('Overflow: Queue size full. Cannot push element.')
  else:
    dequeue.insert(0,element)
    print('Element has been pushed.')
  return(dequeue)

def removeFront(dequeue):
  if len(dequeue) == 0:
    print('Underflow : No element is present that can be popped.')
  else:
    print('The queue has been popped : ', dequeue.pop(len(dequeue) - 1))
  return(dequeue)

def removeRear(dequeue):
  if len(dequeue) == 0:
    print('Underflow : No element is present that can be popped.')
  else:
    print('The queue has been popped : ', dequeue.pop(0))
  return(dequeue)

def main():
  dequeue = []
  while(True):
    choice = int(input('Please enter the operation that you would like to perform on the dequeue : \n1.PushFrontEnd \n2.PushRearEnd \n3.PopFrontEnd \n4.PopBackEnd \n5.Show \n6.Quit : '))
    if choice == 1:
      element = int(input('Enter the element that you wish to push : '))
      print(insertFront(dequeue,element))
    elif choice == 2:
      element = int(input('Enter the element that you wish to push : '))
      print(insertRear(dequeue,element))
    elif choice == 3:
      print('The Dequeue is : ', removeFront(dequeue))
    elif choice == 4:
      print('The Dequeue is : ', removeRear(dequeue))
    elif choice == 5:
      print('The Dequeue is : ', dequeue)
    elif choice == 6:
      print('Thank you!')
      break
    else:
      print('Invalid Choice!')

if __name__ == '__main__':
  main()
