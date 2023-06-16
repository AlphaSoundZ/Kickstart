import os
import math

import matplotlib.pyplot as plt
import numpy as np


def gerade(m, x, b):
    return m*x + b

f = open("anotherdata12.dat", "r")
g = open("anotherdata12.dat", "r")
result = 0
max_value = float("-inf")
min_value = float("inf")
sum = 0
for line in f:
    sum += float(line)
    min_value = min(float(line), min_value)
    max_value = max(float(line), max_value)

mittelwert = sum/100

print("Mittelwert:", mittelwert)

# convert file to list
data = []
for line in g:
    data.append(float(line))

# CONSTS
STEPS = 10 # Anzahl der Schritte pro m und b
M_RANGE = 10 # Bereich der m-Werte (von -M_RANGE bis M_RANGE): Steigung der Geraden

# Varianz
# Summe der quadrate der Abweichungen vom Mittelwert
result = float("inf") # Varianz soll möglichst klein sein
result_m, result_b = 0, 0 # m und b, die die Varianz minimieren
for m in range(-M_RANGE * STEPS, M_RANGE * STEPS, 1): # für alle möglichen m
    m = m/STEPS
    varianz = 0
    for b in range(math.floor(min_value) * STEPS, math.ceil(max_value) * STEPS, 1): # für alle möglichen b
        b = b/STEPS
        x = 0 # x-Wert des Punktes
        for value in data: # Varianz berechnen
            y = float(value)
            varianz += (y - gerade(m, x, b))**2/100
            x += 1 # x-Wert des nächsten Punktes
        if (varianz < result): # wenn die Varianz kleiner ist als die bisherige, dann speichern
            result = varianz
            result_m = m
            result_b = b


# X axis parameter:
xaxis = np.array([0, 99])
# Y axis parameter:
yaxis = np.array([min_value, max_value])

# Plot the data:
plt.plot(data, 'ro')

# Plot the line:
plt.plot(xaxis, gerade(result_m, xaxis, result_b), 'b') # 'b' means blue line

plt.show()


print("Minimum Varianz:", result, "m:", result_m, "b:", result_b)