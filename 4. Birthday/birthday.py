#Author: Jacob Bonfanti
#Assignment 4: Birthday Paradox
#Date: 2/22/2018
import random, time
random.seed(time.time())

def chance_of_birthday_exact(n):
    p = 1
    for i in range(1, n+1): #Loop from 1 to n
        p *= ((366-i)/365)
    return 1 - p

def chance_of_birthday_sim(n):
    rounds = 20000
    count = 0
    for i in range(rounds):
        birthdays = [False]*365
        for j in range(n):
            rnd = int(random.random()*365)
            if(birthdays[rnd]):
                count+=1
                break
            birthdays[rnd] = True
    return count / rounds

for i in range(1, 51):
    print("Exact probability for n = " + str(i) + ":     " + str(chance_of_birthday_exact(i)))
    print("Simulated probability for n = " + str(i) + ": " + str(chance_of_birthday_sim(i)))
