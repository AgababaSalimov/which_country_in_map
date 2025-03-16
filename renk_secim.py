from PIL import Image
Image.open('c:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\dataset\\images\\train\\img2.jpg')
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from sklearn.cluster import KMeans

image = mpimg.imread('c:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\dataset\\images\\train\\img2.jpg')
w, h, d=image.shape
pixels = image.reshape(w * h, d)
n_colors = 10
kmeans = KMeans(n_clusters=n_colors, random_state=42).fit(pixels)
palette=np.uint8(kmeans.cluster_centers_)

plt.imshow([palette])
plt.axis('off')
plt.show()
