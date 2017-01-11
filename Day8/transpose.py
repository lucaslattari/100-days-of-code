import tensorflow as tf
import matplotlib.image as mp_image
import matplotlib.pyplot as plt

filename = "trump.jpg"
input_image = mp_image.imread(filename)

x = tf.Variable(input_image, name='x')

model = tf.global_variables_initializer()

with tf.Session() as session:
	x = tf.transpose(x, perm=[1,0,2])
	session.run(model)
	result = session.run(x)

plt.imshow(result)
plt.show()
