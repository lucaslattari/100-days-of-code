import tensorflow as tf

uniform_seed = tf.random_uniform([1], seed=1)
uniform_no_seed = tf.random_uniform([1])

print("first run")

with tf.Session() as first_session:
	print "uniform with (seed = 1) = {}"\
		.format(first_session.run(uniform_seed))
	print("uniform with (seed = 1) = {}"\
		.format(first_session.run(uniform_seed)))
	print("uniform without = {}"\
		.format(first_session.run(uniform_no_seed)))
	print("uniform without = {}"\
		.format(first_session.run(uniform_no_seed)))

print("second run")

with tf.Session() as second_session:
	print("uniform with (seed = 1) = {}"\
		.format(second_session.run(uniform_seed)))
	print("uniform with (seed = 1) = {}"\
		.format(second_session.run(uniform_seed)))
	print("uniform without = {}"\
		.format(second_session.run(uniform_no_seed)))
	print("uniform without = {}"\
		.format(second_session.run(uniform_no_seed)))
