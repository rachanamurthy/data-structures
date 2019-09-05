# Implementation of queue data structure - First In First Out
# In a queue, the top element or the first element is removed
# while new elements are added to the end of the list.

def insert(queue,n):
  if len(queue) == 10:
    print('Overflow: Queue size full. Cannot push element.')
  else:
    queue.append(n)
    print('Element has been pushed.')
  return(queue)

def remove(queue):
  if len(queue) == 0:
    print('Underflow : No element is present that can be popped.')
  else:
    print('The queue has been popped : ', queue.pop(0))
  return(queue)

def showQueue(queue):
  print(queue)


def main():
  queue = []
  while(True):
    choice = int(input('Please enter the operation that you would like to perform on the queue : \n1.Push \n2.Pop \n3.Show \n4.Quit : '))
    if choice == 1:
      element = int(input('Enter the element that you wish to push : '))
      print(insert(queue,element))
    elif choice == 2:
      remove(queue)
    elif choice == 3:
      showQueue(queue)
    elif choice == 4:
      print('Thank you!')
      break
    else:
      print('Invalid Choice!')


if __name__ == '__main__':
  main()