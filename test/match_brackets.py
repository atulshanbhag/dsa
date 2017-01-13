class StackEmptyException(Exception):
	pass

class Stack(object):
	def __init__(self):
		self._list = []

	def __len__(self):
		return len(self._list)

	def is_empty(self):
		return len(self) == 0

	def top(self):
		if self.is_empty():
			raise StackEmptyException('Stack in empty!')
		return self._list[-1]

	def push(self, item):
		self._list.append(item)

	def pop(self):
		if self.is_empty():
			raise StackEmptyException('Stack is empty!')
		return self._list.pop()

	def __str__(self):
		return self._list.__str__()

	def __del__(self):
		del self._list

def is_matched(expr):
	left = '([{'
	right = ')]}'

	s = Stack()

	for c in expr:
		if c in left:
			s.push(c)
		elif c in right:
			if s.is_empty():
				return False
			if right.index(c) != left.index(s.pop()):
				return False

	return s.is_empty()

