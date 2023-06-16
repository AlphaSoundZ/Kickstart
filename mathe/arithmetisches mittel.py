import os

sum = 0
result = 0

f = open("anotherdata12.dat", "r")

for line in f:
    sum += float(line)

result = sum/100

# g = open("anotherdata12.dat", "r")
# for line in g:
#     result += abs(float(line) - sum)


print(result)

#result: 240.49840320685743