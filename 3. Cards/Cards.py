#Author: Jacob Bonfanti
#Date: 2/15/2018
#Assignment 3: Card Shuffling
import random, time
random.seed(time.time())

def shuffle(n):
    arr = []
    #Get list of numbers from 0 - (n - 1)
    for i in range(n):
        arr.append(i)
    #Knuth Fisher Yates Shuffle
    for i in range(n):
        x = i + int(random.random()*(n - i))
        arr[i], arr[x] = arr[x], arr[i]
    return arr

rounds = 100000
success = 0
for i in range(rounds):
    arr = shuffle(52)
    for j in range(52):
        if(arr[j] == j):
            success += 1
            break
print(success / rounds)
