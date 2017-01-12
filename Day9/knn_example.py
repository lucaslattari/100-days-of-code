import numpy as np
import tensorflow as tf
import input_data_mnist
import matplotlib.pyplot as plt

mnist_images = input_data_mnist.read_data_sets("/tmp/data/",one_hot=True)

train_pixels, train_list_values = mnist_images.train.next_batch(500)
test_pixels, test_list_of_values = mnist_images.test.next_batch(100)

train_pixel_tensor = tf.placeholder("float", [None, 784])
test_pixel_tensor = tf.placeholder("float", [784])

distance = tf.reduce_sum(tf.abs(tf.add(train_pixel_tensor,tf.neg(test_pixel_tensor))),reduction_indices = 1)

pred = tf.arg_min(distance, 0)

acc = 0

init = tf.global_variables_initializer()
with tf.Session() as session:
	session.run(init)
	for i in range(len(test_list_of_values)):
		nn_index = session.run(pred,feed_dict={train_pixel_tensor:train_pixels, test_pixel_tensor:test_pixels[i,:]})
		print "Test No ", i, "Predicted Class: ", np.argmax(train_list_values[nn_index]), "True Class: ", np.argmax(test_list_of_values[i])

		if np.argmax(train_list_values[nn_index]) == np.argmax(test_list_of_values[i]):
			acc += 1./len(test_pixels)
		else:
			image = test_pixels[i,:]
			image = np.reshape(image,[28,28])

			plt.imshow(image)
			plt.show()

	print "Result = ", acc
