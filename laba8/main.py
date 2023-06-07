from matplotlib import pyplot as plt

f = open('C:\projects\hw_sem_2\laba8\laba8.txt')
file = f.readlines()
f.close()
x = []
y = []
kol = []
for i in range(0,len(file), 2):
    x.append(float(file[i]))
for j in range(1,len(file),2):
    y.append(float(file[j]))
for l in range(len(y)):
    kol.append(int(l*10))
plt.plot(kol, x, label='V_apogee')
plt.plot(kol, y, label='V_omega')
plt.xlabel('Kilometres')  
plt.ylabel('V')
plt.legend()
plt.show()
