import input_data_mnist
import numpy as np
import matplotlib.pyplot as plt

#Using input_data we load the data sets :

mnist_images = input_data_mnist.read_data_sets\
               ("MNIST_data/",\
                one_hot=False)

mnist_images.train.next_batch(10)
pixels,real_values = mnist_images.train.next_batch(10)

#it also returns two lists, the matrix of the pixels loaded, and the list that contains the real values loaded:

print "list of values loaded ",real_values
example_to_visualize = 5
print "element No " + str(example_to_visualize + 1)\
+ " of the list plotted"

image = pixels[example_to_visualize,:]
image = np.reshape(image,[28,28])
plt.imshow(image)
plt.show()
