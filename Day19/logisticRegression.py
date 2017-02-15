import input_data_mnist
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

mnist = input_data_mnist.read_data_sets("/tmp/data/", one_hot=True)

training_epochs = 25
learning_rate = 0.01
batch_size = 100

x = tf.placeholder("float", [None, 784])
y = tf.placeholder("float", [None, 10])

W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

activation = tf.nn.softmax(tf.matmul(x, W) + b)
crossEntropy = y * tf.log(activation)
cost = tf.reduce_mean(-tf.reduce_sum(crossEntropy, reduction_indices = 1))

optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

avg_set = []
epoch_set = []

init = tf.global_variables_initializer()

with tf.Session() as sess:
	sess.run(init)

	for epoch in range(training_epochs):
		avg_cost = 0.
		total_batch = int(mnist.train.num_examples / batch_size)

		for i in range(total_batch):
			batch_xs, batch_ys = mnist.train.next_batch(batch_size)
			sess.run(optimizer, feed_dict={x: batch_xs, y: batch_ys})

			avg_cost += sess.run(cost, feed_dict={x: batch_xs, y: batch_ys}) / total_batch

		print "Epoch:",'%04d' % (epoch + 1), "cost=", "{:.9f}".format(avg_cost)
		avg_set.append(avg_cost)
		epoch_set.append(epoch + 1)
	
	print "Training phase finished"
	
	#plt.plot(epoch_set, avg_set, 'o', label='Logistic Regression Training Phase')
	#plt.ylabel('cost')
	#plt.xlabel('epoch')
	#plt.legend()
	#plt.show()

	correct_prediction = tf.equal(tf.argmax(activation, 1), tf.argmax(y, 1))
	accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))
	print(accuracy.eval({x: mnist.test.images, y: mnist.test.labels}))

	for i in range(1000):
		_image, _class = mnist.test.next_batch(1)
		sess.run(optimizer, feed_dict={x: _image, y: _class})

		acc = 1 - sess.run(cost, feed_dict={x: _image, y: _class})
		print _class

		_class = []
		_class1 = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 0, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 1, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 2, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 1, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 3, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 1, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 4, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0]
		_class.append(_class1)
		print 5, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 1, 0, 0, 0]
		_class.append(_class1)
		print 6, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]
		_class.append(_class1)
		print 7, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 0, 0, 1, 0]
		_class.append(_class1)
		print 8, sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
		_class.append(_class1)
		print 9, sess.run(cost, feed_dict={x: _image, y: _class})

		_image = np.reshape(_image,[28,28])

		if acc < 0.5:
			plt.imshow(_image)
			plt.show()

