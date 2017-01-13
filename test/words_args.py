from collections import Counter

def func(*words):
	for key, val in Counter(words).items():
		print  key, val

func('atul', 'rahul')