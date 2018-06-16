# Based on my understanding only, no implementation seen #

def quicksort (list, pivotIndex):
  if pivotIndex is None: pivotIndex = int(round(len(list) / 2))

  leftList = []
  rightList = []
  
  if len(list) <= 1:
    return list

  elif len(list) == 2:
    if list[0] > list[1]:
      tmp = list[0]
      list[0] = list[1]
      list[1] = tmp

    return list

  else:
    for i in range(0, len(list)):
      if list[i] <= list[pivotIndex]:
        leftList.append(list[i])
      
      else:
        rightList.append(list[i])
    # return leftList

  if len(rightList) == 0:
    return quicksort(list, 0)
  else:
    return ( quicksort(leftList, None) + quicksort(rightList, None) )


list = [1,3,6,4,2,8,5,6,7]
print quicksort(list, None)
