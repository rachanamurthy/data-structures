# Implementation of Stack Data Structure using Python3
# In a stack, the top element or the first element is removed
# while new elements are added to the end of the list.

def insert(stack,n):
  if len(stack) == 10:
    print('Overflow: Stack size full. Cannot push element.')
  else:
    stack.append(n)
    print('Element has been pushed.')
  return(stack)

def remove(stack):
  if len(stack) == 0:
    print('Underflow : No element is present that can be popped.')
  else:
    print('The stack has been popped : ', stack.pop(0))
  return(stack)

def showStack(stack):
  print(stack)


def main():
  stack = []
  while(True):
    choice = int(input('Please enter the operation that you would like to perform on the stack : \n1.Push \n2.Pop \n3.Show \n4.Quit : '))
    if choice == 1:
      element = int(input('Enter the element that you wish to push : '))
      print(insert(stack,element))
    elif choice == 2:
      remove(stack)
    elif choice == 3:
      showStack(stack)
    elif choice == 4:
      print('Thank you!')
      break
    else:
      print('Invalid Choice!')


if __name__ == '__main__':
  main()