def insertion_sort(a):
	n = len(a)
	for i in xrange(1, n):
		cur = a[i]
		j = i
		while j > 0 and a[j-1] > cur:
			a[j] = a[j-1]
			j -= 1
		a[j] = cur
	print a

insertion_sort([1, 4, 3, 2])
