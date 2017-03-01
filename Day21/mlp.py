import input_data_mnist
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

mnist = input_data_mnist.read_data_sets("/tmp/data/", one_hot = True)

learningRate = 0.001
trainingEpochs = 50

batchSize = 100
displayStep = 1

nHiddenLayer1 = 256
nHiddenLayer2 = 256
nInput = 784 #pixels, 28*28 image dimensions
nClasses = 10

x = tf.placeholder("float", [None, nInput])
y = tf.placeholder("float", [None, nClasses])

h = tf.Variable(tf.random_normal([nInput, nHiddenLayer1]))
biasLayer1 = tf.Variable(tf.random_normal([nHiddenLayer1]))
layer1 = tf.nn.sigmoid(tf.add(tf.matmul(x, h), biasLayer1))

w = tf.Variable(tf.random_normal([nHiddenLayer1, nHiddenLayer2]))
biasLayer2 = tf.Variable(tf.random_normal([nHiddenLayer2]))
layer2 = tf.nn.sigmoid(tf.add(tf.matmul(layer1, w), biasLayer2))

output = tf.Variable(tf.random_normal([nHiddenLayer2, nClasses]))
biasOutput = tf.Variable(tf.random_normal([nClasses]))
outputLayer = tf.matmul(layer2, output) + biasOutput

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(outputLayer, y))
optimizer = tf.train.AdamOptimizer(learning_rate = learningRate).minimize(cost)

avg_set = []
epoch_set = []

init = tf.global_variables_initializer()
with tf.Session() as sess:
	sess.run(init)
	for epoch in range(trainingEpochs):
		avg_cost = 0.
		total_batch = int(mnist.train.num_examples/batchSize)
		for i in range(total_batch):
			batch_xs, batch_ys = mnist.train.next_batch(batchSize)
			sess.run(optimizer, feed_dict={x: batch_xs, y: batch_ys})
			avg_cost += sess.run(cost, feed_dict={x: batch_xs, y: batch_ys})/total_batch
		if epoch % displayStep == 0:
			print "Epoch: ", '%04d' % (epoch + 1), "cost = ", "{:.9f}".format(avg_cost)
		avg_set.append(avg_cost)
		epoch_set.append(epoch + 1)
	print "Training phase finished"

	#plt.plot(epoch_set, avg_set, 'o', label='MLP Training Phase')
	#plt.ylabel('cost')
	#plt.xlabel('epoch')
	#plt.legend()
	#plt.show()

	correct_prediction = tf.equal(tf.argmax(outputLayer, 1), tf.argmax(y, 1))
	accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))
	print "Model accuracy: ", accuracy.eval({x: mnist.test.images, y: mnist.test.labels})

	for i in range(100):
		_image, _class = mnist.test.next_batch(1)
		sess.run(optimizer, feed_dict={x: _image, y: _class})

		acc = 1.0 - sess.run(cost, feed_dict={x: _image, y: _class})
		print _class

		_class = []
		_class1 = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 0, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 1, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 2, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 1, 0, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 3, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 1, 0, 0, 0, 0, 0]
		_class.append(_class1)
		print 4, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0]
		_class.append(_class1)
		print 5, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 1, 0, 0, 0]
		_class.append(_class1)
		print 6, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]
		_class.append(_class1)
		print 7, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 0, 0, 1, 0]
		_class.append(_class1)
		print 8, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_class = []
		_class1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
		_class.append(_class1)
		print 9, 1 - sess.run(cost, feed_dict={x: _image, y: _class})

		_image = np.reshape(_image,[28,28])

		plt.imshow(_image)
		plt.show()

