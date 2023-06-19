import math
import matplotlib.pyplot as plt
import numpy as np

def average(data):
    ans = sum(data)/len(data)
    return ans

def getData(filename):
    f = open(filename, "r")
    data = []
    for line in f:
        data.append(float(line))
    return data

def line(m, x, b=0):
    return m*x + b

def variance(data, m, b=0):
    ans = 0
    i = 0
    for x in data:
        ans += (x - line(m, i, b))**2
        i += 1
    ans /= len(data)
    return ans

def find_m(data, current_value, min_value, max_value, accuracy): # binary search
    right = current_value + math.ceil((max_value-current_value)/2)
    left = current_value + math.floor((min_value-current_value)/2)

    var_right = variance(data, (current_value + 1)/accuracy)
    var_left = variance(data, (current_value - 1)/accuracy)
    var_current = variance(data, current_value/accuracy)

    if (left <= min_value and right >= max_value):
        if (var_current < var_right and var_current < var_left):
            return current_value/accuracy
        elif (var_right < var_left):
            return (current_value + 1)/accuracy
        else:
            return (current_value - 1)/accuracy

    if (var_right < var_left):
        return find_m(data, right, current_value, max_value, accuracy)
    elif (var_right > var_left):
        return find_m(data, left, min_value, current_value, accuracy)
    else:
        return current_value/accuracy

def find_b(data, current_value, min_value, max_value, m, accuracy): # binary search
    right = current_value + math.ceil((max_value-current_value)/2)
    left = current_value + math.floor((min_value-current_value)/2)

    var_right = variance(data, m, (current_value + 1)/accuracy)
    var_left = variance(data, m, (current_value - 1)/accuracy)
    var_current = variance(data, m, current_value/accuracy)

    if (left <= min_value and right >= max_value):
        if (var_current < var_right and var_current < var_left):
            return current_value/accuracy
        elif (var_right < var_left):
            return (current_value + 1)/accuracy
        else:
            return (current_value - 1)/accuracy

    if (var_right < var_left):
        return find_b(data, right, current_value, max_value, m, accuracy)
    elif (var_right > var_left):
        return find_b(data, left, min_value, current_value, m, accuracy)
    else:
        return current_value/accuracy

min_value = math.inf
max_value = -math.inf

data = getData("anotherdata1.dat")
if len(data) == 0:
    exit()
av = average(data)
for x in data:
    min_value = min(x, min_value)
    max_value = max(x, max_value)
max_slope = (max_value - min_value) / len(data)

# increase accuracy to get better results
accuracy = 100000

best_m = find_m(data, 0, -1*math.ceil(max_slope*accuracy), math.ceil(max_slope*accuracy), accuracy)
best_b = find_b(data, 0, math.floor(min_value*accuracy), math.ceil(max_value*accuracy), best_m, accuracy)
best_var = variance(data, best_m, best_b)

# print results
print("All data:")
print("Average:", av)
print("maxslope:", max_slope)
print("Variance:", best_var)
print ("f(x) =", best_m, "x +", best_b)

# Plotting:

# X axis parameter:
xaxis = np.array([0, len(data)])
# Y axis parameter:
yaxis = np.array([min_value, max_value])

# draw lines between points and main line in gray dashed line style
for i in range(len(data)):
    plt.plot(np.array([i, i]), np.array([data[i], line(best_m, i, best_b)]), 'k--')

# Plot the data
plt.plot(data, 'ro')
plt.plot(data[:10], 'go')


# Plot the line with dashed line style:
plt.plot(xaxis, line(best_m, xaxis, best_b), 'r') # 'b' means blue line

#text at the top
plt.text(0, max_value + max_value/10, "Gerade: f(x) = " + str(best_m) + "x + " + str(best_b) + "\nVarianz der Gerade: " + str(round(best_var, 3)) + " (bzw. " + str(round(math.sqrt(best_var), 3)) + ")\nMittelwert: " + str(round(av, 3)) + "\nVarianz vom Mittelwert: " + str(round(variance(data, 0, av), 3)))



# Predicted line by the first 10 values
av = average(data[:10])
for x in data[:10]:
    min_value = min(x, min_value)
    max_value = max(x, max_value)
max_slope = (max_value - min_value) / len(data)

best_m = find_m(data[:10], 0, -1*math.ceil(max_slope*accuracy), math.ceil(max_slope*accuracy), accuracy)
best_b = find_b(data[:10], 0, math.floor(min_value*accuracy), math.ceil(max_value*accuracy), best_m, accuracy)
best_var = variance(data, best_m, best_b)

# print results
print()
print("With first 10 values:")
print("Average:", av)
print("maxslope:", max_slope)
print("Variance:", best_var)
print ("f(x) =", best_m, "x +", best_b)

# Plotting:

# draw line
plt.plot(xaxis, line(best_m, xaxis, best_b), 'g')





plt.show()