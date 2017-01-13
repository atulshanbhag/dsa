s = 'catdog'
n = len(s)

for i in xrange(2 ** n):
	for j in xrange(n):
		if (i & (1 << j)):
			print s[j], 
	print