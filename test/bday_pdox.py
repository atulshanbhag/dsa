from random import randint
from collections import Counter

def func(n = 5):
	c = Counter([randint(0, 367) for _ in xrange(n)])
	for k in c:
		if c[k] > 1:
			print 'Yes!'
			break
	else:
		print 'No!'

for n in xrange(5, 26, 5):
	print n, 
	func(n)