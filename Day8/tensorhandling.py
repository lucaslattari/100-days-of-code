import tensorflow as tf
import numpy as np

matrix1 = np.array([(2, 2, 2), (2, 2, 2), (2, 2, 2)], dtype = 'int32')
matrix2 = np.array([(1, 1, 1), (1, 1, 1), (1, 1, 1)], dtype = 'int32')

print "matrix1 ="
print matrix1

print "matrix2 ="
print matrix2

#transform into a tensor data structure
matrix1 = tf.constant(matrix1)
matrix2 = tf.constant(matrix2)

matrix_prod = tf.matmul(matrix1, matrix2)
matrix_sum = tf.add(matrix1, matrix2)

matrix3 = np.array([(2, 7, 2), (1, 4, 2), (9, 0, 2)], dtype = 'float32')
print 'matrix3 =' 
print matrix3

#determinant
matrix_det = tf.matrix_determinant(matrix3)

with tf.Session() as session:
	result_prod = session.run(matrix_prod)
	result_sum = session.run(matrix_sum)
	result_det = session.run(matrix_det)

	print "mat1 * mat2 ="
	print result_prod
	print "mat1 + mat2 ="
	print result_sum
	print "mat3 determinant ="
	print result_det
