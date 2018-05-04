import random, time
random.seed(time.time())

left = 2
right = 4
epsilon = 0.0000001

while right - left > epsilon:
    count = 0
    rounds = 1000000
    mid = (left + right) / 2
    for i in range(rounds):
        x = (random.random() * (mid - 1)) + 1
        y = random.random()
        if(1 / x > y):
            count += 1
    rectArea = mid - 1
    if(rectArea * (count / rounds) < 1):
        left = mid
    else:
        right = mid
print("Left:  " + str(left))
print("Right: " + str(right))
