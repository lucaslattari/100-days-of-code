import numpy as np
import tensorflow as tf

tensor1d = np.array([1.3, 1, 4.0,23.99])

print tensor1d

tf_tensor = tf.convert_to_tensor(tensor1d, dtype = tf.float64)

with tf.Session() as session:
	print session.run(tf_tensor)
	print session.run(tf_tensor[0])
	print session.run(tf_tensor[2])
