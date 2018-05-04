import random, time
random.seed(int(time.time()))
count = 0
rounds = 100000
for i in range(rounds):
    x = random.random()
    y = random.random()
    if(x*x + y*y <= 1):
        count+=1
print(4 * count / rounds)
