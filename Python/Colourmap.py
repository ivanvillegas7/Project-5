import matplotlib.pyplot as plt
import matplotlib
import numpy as np
import pyarma as pa

M = 1/h + 1

P = 0.002/0.000025 + 1

# We create a cube, and fill it with a txt that contains the data of the real part
Re = pa.cube()
Re.load("Colourmap_re.txt")

# Set up a 2D xy grid
h = 0.005
x_points = np.arange(0, 1, h)
y_points = np.arange(0, 1, h)
x, y = np.meshgrid(x_points, y_points, sparse = True)

# Array of time points
dt = 2.5e-5
t_points = np.arange(0, 1, dt)

# Some settings
fontsize = 12
t_min = t_points[0]
x_min, x_max = x_points[0], x_points[-1]
y_min, y_max = y_points[0], y_points[-1]

# Create figure
fig = plt.figure()
ax = plt.gca()

#We take the 0 slice of the cube
Re0 = Re[ pa.single_slice , 0 ]

# Create a colour scale normalization according to the max Re0 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Re0.max() )

# Plot the first frame
img = ax.imshow( Re0, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("Re", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.000", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_Re_t0.pdf")

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 40 slice of the cube
Re1 = Re[ pa.single_slice , 40 ]

# Create a colour scale normalization according to the max Re1 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Re1.max() )

# Plot the first frame
img = ax.imshow( Re1, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("Re", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.001", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_Re_t1.pdf")

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 80 slice of the cube
Re2 = Re[ pa.single_slice , 80 ]

# Create a colour scale normalization according to the max Re2 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Re2.max() )

# Plot the first frame
img = ax.imshow( Re2, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("Re", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.002", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_Re_t2.pdf")


# We create a cube, and fill it with a txt that contains the data of the imaginary part
Im = pa.cube()
Im.load("Colourmap_im.txt" )

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 0 slice of the cube
Im0 = Im[ pa.single_slice , 0 ]

# Create a colour scale normalization according to the max Im0 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Im0.max() )

# Plot the first frame
img = ax.imshow( Im0, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("Im", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.000", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_Im_t0.pdf")

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 40 slice of the cube
Im1 = Im[ pa.single_slice , 40 ]

# Create a colour scale normalization according to the max Im1 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Im1.max() )

# Plot the first frame
img = ax.imshow( Im1, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("Im", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.001", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_Im_t1.pdf")

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 80 slice of the cube
Im2 = Im[ pa.single_slice , 80 ]

# Create a colour scale normalization according to the max Im2 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Im2.max() )

# Plot the first frame
img = ax.imshow( Im2, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("Im", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.002", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_Im_t2.pdf")



# We create a cube, and fill it with a txt that contains the data of the 2D probability function
p = pa.cube()
p.load("Colourmap_p.txt" )

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 0 slice of the cube
p0 = p[ pa.single_slice , 0 ]

p0.brief_print()

p0.max()

# Create a colour scale normalization according to the max z value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=p0.max() )

# Plot the first frame
img = ax.imshow( p0, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("p", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.000", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_p_t0.pdf")

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 40 slice of the cube
p1 = p[ pa.single_slice , 40 ]

p1.brief_print()

p1.max()

# Create a colour scale normalization according to the max p1 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=p1.max() )

# Plot the first frame
img = ax.imshow( p1, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("p", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.001", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

plt.savefig("Colourmap_p_t1.pdf")

# Create figure
fig = plt.figure()
ax = plt.gca()


#We take the 80 slice of the cube
p2 = p[ pa.single_slice , 80 ]

# Create a colour scale normalization according to the max p2 value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=p2.max() )

# Plot the first frame
img = ax.imshow( p2, extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("p", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0.002", color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

#We save the figure in a PDF
plt.savefig("Colourmap_p_t2.pdf")


