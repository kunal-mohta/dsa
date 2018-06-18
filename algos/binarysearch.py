# Based on my understanding, no implementation seen #

def binarySearch (arr, key, minIndex, maxIndex):
  midIndex = int(round((minIndex + maxIndex) / 2))
  if (minIndex <= maxIndex):
    if (arr[midIndex] > key):
      return binarySearch(arr, key, 0, midIndex - 1)

    elif (arr[midIndex] < key):
      return binarySearch(arr, key, midIndex + 1, maxIndex)

    else:
      return midIndex

  else:
    return False

def lowerBoundBinarySearch (arr, key, minIndex, maxIndex):
  midIndex = int(round((minIndex + maxIndex)/2))
  if (minIndex <= maxIndex):
    if (arr[midIndex] < key):
      return lowerBoundBinarySearch(arr, key, midIndex + 1, maxIndex)
    
    elif (arr[midIndex] >= key and ( midIndex == 0 or arr[midIndex-1] < key )):
      return midIndex

    else:
      return lowerBoundBinarySearch(arr, key, 0, midIndex - 1)

  else:
    return False

def upperBoundBinarySearch (arr, key, minIndex, maxIndex):
  midIndex = int(round((minIndex + maxIndex) / 2))
  if (minIndex <= maxIndex):
    if (arr[midIndex] <= key):
      return upperBoundBinarySearch(arr, key, midIndex + 1, maxIndex)

    elif (arr[midIndex] > key and ( midIndex == 0 or arr[midIndex - 1] <= key )):
      return midIndex

    else:
      return upperBoundBinarySearch(arr, key, 0, midIndex - 1)

  else:
    return False


list =  [1,2,3,5,5,6,7,8]
print binarySearch(list, 3, 0, len(list)-1)
print lowerBoundBinarySearch(list, 1, 0, len(list) - 1)
print upperBoundBinarySearch(list, 7, 0, len(list) - 1)
