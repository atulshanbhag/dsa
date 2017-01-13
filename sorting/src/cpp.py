#! /usr/bin/env python

import os
import sys
import optparse
import subprocess as sbp

parser = optparse.OptionParser()

parser.add_option('-f', '--filename', dest='filename', help='C++ filename')

(options, args) = parser.parse_args()

sbp.check_call('clear', shell=True)

if options.filename == None:
	options.filename = raw_input('Enter filename...:\t').strip('.cpp')
else:
	options.filename = options.filename.rstrip('.cpp')

filepath = os.path.join(os.getcwd(), options.filename) + '.cpp'

if not os.path.exists(filepath):
	print 'File {0} not found!'.format(filepath)
	sys.exit()

print '--------------------'
print ''
print 'Compiling.... {0}.cpp'.format(options.filename)
print '--------------------'

cmd = 'g++ -std=c++1z -o {0} {0}.cpp'.format(options.filename)

try:
	sbp.check_call(cmd, shell=True)
except sbp.CalledProcessError:
	print 'CompileError!'
	sys.exit()

print ''
print 'Compile successful!'
print '--------------------'

sbp.check_call('mv {0} {1}'.format(filepath[:-4], 
			os.path.join(os.getcwd()[:-3], 'bin')), 
			shell = True)

print ''
print 'Running... '
print '--------------------'
print ''

try:
	sbp.check_call('./../bin/{0}'.format(options.filename), shell=True)
except sbp.CalledProcessError:
	print 'RuntimeError!'
	sys.exit()

print ''
print 'Run successful!'
print '--------------------'