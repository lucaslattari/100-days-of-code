import matplotlib.image as mp_image
import matplotlib.pyplot as plt
import tensorflow as tf

filename = "trump.jpg"
input_image = mp_image.imread(filename)

print 'input dim = {}'.format(input_image.ndim)
print 'input shape = {}'.format(input_image.shape)

my_image = tf.placeholder("uint8", [None, None, 3])
my_slice = tf.slice(my_image, [40, 0, 0], [90, 140, -1])

with tf.Session() as session:
	result = session.run(my_slice, feed_dict={my_image: input_image})
	print result.shape

plt.imshow(result)
plt.show()
