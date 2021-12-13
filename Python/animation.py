import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import pyarma as pa

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
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Re0.max())

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
time_txt = plt.text(0.95, 0.95, "t = {:.3e}".format(t_min), color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

# Function that takes care of updating the Re data and other things for each frame
def animation(i):
    # Normalize the colour scale to the current frame
    norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Re[pa.single_slice, i].max())
    img.set_norm(norm)

    # Update Re data
    img.set_data(Re[pa.single_slice, i])

    # Update the time label
    current_time = t_min + i * dt
    time_txt.set_text("t = {:.3e}".format(current_time))

    return img

# Use matplotlib.animation.FuncAnimation to put it all together
anim = FuncAnimation(fig, animation, interval=1, frames=np.arange(0, 81, 2), repeat=False, blit=0)

# Save the animation
anim.save('Re_animation.mp4', writer="ffmpeg", bitrate=-1, fps=30)

# We create a cube, and fill it with a txt that contains the data of the imaginary part
Im = pa.cube()

Im.load("Colourmap_im.txt" )

# Create figure
fig = plt.figure()
ax = plt.gca()

#We take the 0 slice of the cube
Im0 = Im[ pa.single_slice , 0 ]

# Create a colour scale normalization according to the max Im value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Im0.max())

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
time_txt = plt.text(0.95, 0.95, "t = {:.3e}".format(t_min), color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

# Function that takes care of updating the Im data and other things for each frame
def animation(i):
    # Normalize the colour scale to the current frame
    norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=Im[pa.single_slice, i].max())
    img.set_norm(norm)

    # Update z data
    img.set_data(Im[pa.single_slice, i])

    # Update the time label
    current_time = t_min + i * dt
    time_txt.set_text("t = {:.3e}".format(current_time))

    return img

# Use matplotlib.animation.FuncAnimation to put it all together
anim = FuncAnimation(fig, animation, interval=1, frames=np.arange(0, 81, 2), repeat=False, blit=0)

# Save the animation
anim.save('Im_animation.mp4', writer="ffmpeg", bitrate=-1, fps=30)


# We create a cube, and fill it with a txt that contains the data of the 2D probability function
p = pa.cube()
p.load("Colourmap_p.txt" )

# Create figure
fig = plt.figure()
ax = plt.gca()

#We take the 0 slice of the cube
p0 = p[ pa.single_slice , 0 ]

# Create a colour scale normalization according to the max p0 value in the first frame
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
time_txt = plt.text(0.95, 0.95, "t = {:.3e}".format(t_min), color="white", 
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

# Function that takes care of updating the p data and other things for each frame
def animation(i):
    # Normalize the colour scale to the current frame?
    norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=p[pa.single_slice, i].max())
    img.set_norm(norm)

    # Update p data
    img.set_data(p[pa.single_slice, i])

    # Update the time label
    current_time = t_min + i * dt
    time_txt.set_text("t = {:.3e}".format(current_time))

    return img

# Use matplotlib.animation.FuncAnimation to put it all together
anim = FuncAnimation(fig, animation, interval=1, frames=np.arange(0, 81, 2), repeat=False, blit=0)

# Save the animation
anim.save('p_animation.mp4', writer="ffmpeg", bitrate=-1, fps=30)
