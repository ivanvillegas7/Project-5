from typing import List
import matplotlib.pyplot as plt
import numpy as np

#The data get extracted from different .txt files, in this case, the values of the deviation of the total probability for the cases with and without a double-slit barrier

with  open("Consistency_check0.txt", "r") as  infile:

    lines = infile.readlines()

    p0: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        p0.append(float(vals[0]))
       

with  open("Consistency_check1.txt", "r") as  infile:

    lines = infile.readlines()

    p1: List[float] = []
    
    for  line in  lines:
        vals = line.split()        
        p1.append(float(vals[0]))



#The data gets ploted

t = np.linspace(0 , 0.008, len(p0))

plt.figure()

plt.plot(t,p0, 'b', label = "No slit")
plt.plot(t,p1,'r', label = "Double slit")
plt.title('Deviation of the total probability from 1 ')
plt.xlabel(r't (s)')
plt.ylabel(r'|$p-1$|')
plt.legend()
plt.grid(True)

plt.savefig('Consistency_check.pdf')



