import numpy as np
import struct
from matplotlib import pyplot as plt

pixels = 64;

img = []
f = open("data/U.bin","rb")
while True:
    byte=f.read(1)
    if not byte:
        break;
    value = struct.unpack('B', byte)[0]
    img.append(value)

f.close()

fig, axes = plt.subplots(nrows=1, ncols=4, figsize=(12, 6),
                         sharex=True, sharey=True)
ax = axes.ravel()

img = np.array(img)
img = (img.astype(np.float32) / max(img))*255
img = np.uint8(img)
img = np.reshape(img,(pixels,pixels))

cpu_reconstruction = []
f = open("data/cpu_Ux.bin","rb")
while True:
    byte=f.read(4)
    if not byte:
        break;
    value = struct.unpack('f', byte)[0]
    cpu_reconstruction.append(value)

f.close()
cpu_reconstruction = np.array(cpu_reconstruction)
cpu_reconstruction = (cpu_reconstruction.astype(np.float32) / max(cpu_reconstruction))*255
cpu_reconstruction = np.uint8(cpu_reconstruction)
cpu_reconstruction = np.reshape(cpu_reconstruction,(pixels,pixels))


rtl_reconstruction = []
f = open("data/rtl_Ux.bin","rb")
while True:
    byte=f.read(4)
    if not byte:
        break;
    value = struct.unpack('f', byte)[0]
    rtl_reconstruction.append(value)

f.close()
rtl_reconstruction = np.array(rtl_reconstruction)
rtl_reconstruction = (rtl_reconstruction.astype(np.float32) / max(rtl_reconstruction))*255
rtl_reconstruction = np.uint8(rtl_reconstruction)
rtl_reconstruction = np.reshape(rtl_reconstruction,(pixels,pixels))


rtl_divergence = []
f = open("data/divU.bin","rb")
while True:
    byte=f.read(4)
    if not byte:
        break;
    value = struct.unpack('f', byte)[0]
    rtl_divergence.append(value)

f.close()
rtl_divergence = np.array(rtl_divergence)
rtl_divergence = (rtl_divergence.astype(np.float32) / max(rtl_divergence))*255
rtl_divergence = np.uint8(rtl_divergence)
rtl_divergence = np.reshape(rtl_divergence,(pixels,pixels))


ax[0].imshow(img, cmap=plt.cm.gray)
ax[0].set_title('Original image')

ax[1].imshow(cpu_reconstruction, cmap=plt.cm.gray)
ax[1].set_title('CPU X-Derivate')

ax[2].imshow(rtl_reconstruction, cmap=plt.cm.gray)
ax[2].set_title('RTL X-Derivate')

ax[3].imshow(rtl_divergence, cmap=plt.cm.gray)
ax[3].set_title('RTL Divergence')
plt.show()
