#Author: Jacob Bonfanti
#Assignment 5: Birthday Paradox - But with a twist!
#Date: 3/1/2018
import random, time
random.seed(time.time())

def distinct_birthdays_sim(n):
    rounds = 20000
    count = 0
    for i in range(rounds):
        birthdays = [False]*365
        for j in range(n):
            rnd = int(random.random()*365)
            birthdays[rnd] = True
        for j in range(365):#Increments count for each distinct birthday
            count += 1 if birthdays[j] else 0 #Fancy python code,
                                              #Compresses if/else
                                              #statements into one line
    return count / rounds

print("Simulated probability for n = 365: " + str(distinct_birthdays_sim(365)))
