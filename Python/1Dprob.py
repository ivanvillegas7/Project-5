import numpy as np
import matplotlib.pyplot as plt
import pyarma as pa

# 1 slit

fig = plt.figure()

p1slit = pa.cube()

p1slit.load("Colourmap_p_1slit.txt")

p2 = p1slit[pa.single_slice , 80]

px2 = p2[:,160]

A = np.trapz(px2, axis=0, dx=(1/len(px2)))

px2 = px2/A

y = np.linspace(0,1,len(px2))

plt.plot(y, px2, color = "b")

fontsize = 12

plt.xlabel("y", fontsize=fontsize)
plt.ylabel(r'$p(y|x=0.8;t=0.002)$', fontsize=fontsize)
plt.title(r'$p(y|x=0.8;t=0.002)$ with a single slit')

plt.grid()

plt.savefig("1Dprob_1slit.pdf")

# 2 slits

fig = plt.figure()

p2slits = pa.cube()

p2slits.load("Colourmap_p_2slits.txt")

p2 = p2slits[pa.single_slice , 80]

px2 = p2[:,160]

A = np.trapz(px2, axis=0, dx=(1/len(px2)))

px2 = px2/A

y = np.linspace(0,1,len(px2))

plt.plot(y, px2, color = "b")

fontsize = 12

plt.xlabel("y", fontsize=fontsize)
plt.ylabel(r'$p(y|x=0.8;t=0.002)$', fontsize=fontsize)
plt.title(r'$p(y|x=0.8;t=0.002)$ with double slit')

plt.grid()

plt.savefig("1Dprob_2slits.pdf")

# 3 slits

fig = plt.figure()

p3slits = pa.cube()

p3slits.load("Colourmap_p_3slits.txt")

p2 = p3slits[pa.single_slice , 80]

px2 = p2[:,160]

A = np.trapz(px2, axis=0, dx=(1/len(px2)))

px2 = px2/A

y = np.linspace(0,1,len(px2))

plt.plot(y, px2, color = "b")

fontsize = 12

plt.xlabel("y", fontsize=fontsize)
plt.ylabel(r'$p(y|x=0.8;t=0.002)$', fontsize=fontsize)
plt.title(r'$p(y|x=0.8;t=0.002)$ with triple slit')

plt.grid()

plt.savefig("1Dprob_3slits.pdf")
