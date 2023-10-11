#!/usr/bin/python3
import os
import signal
import sys
import tempfile
import subprocess
import glob
import shutil
import re
import time
import csv
import threading
import random
import datetime as dt

duedate = dt.datetime(2023, 9, 30, 23, 59, 59)

'''
This class takes the place of sys.stdout. It intercepts whatever is
being written to the console and writes it the console, a file, and
a local data structure.
In other words, whatever you print here or in your program also
prints to the file and to a list. The list can then be searched for 
proper output. 
'''
class Tee(object):
	def open(self, name, mode):
		sys.stdout.flush()
		self.file = open(name, mode)
		self.stdout = sys.stdout
		sys.stdout = self
	def close(self):
		sys.stdout = self.stdout
		self.file.close()
	def write(self, data):
		self.file.write(data)
		self.stdout.write(data)
	def flush(self):
		self.file.flush()
		self.stdout.flush()

def kill_proc(proc, timeout):
	# you must have done something wrong
	# to end up here
    timeout["value"] = True
    proc.kill()

# a run with timeout function 
def run_with_timeout(cmd, timeout_sec, stdinput):
    proc = subprocess.Popen(cmd,stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    timeout = {"value": False}
    timer = threading.Timer(timeout_sec, kill_proc, [proc, timeout])
    timer.start()
    (out, err) = proc.communicate(input = stdinput.encode("utf-8"))
    if len(out) < 1000:
        print(out.decode("utf-8"))
    else:
    	#wow you printed a lot of stuff
        print(out[:1000].decode("utf-8") + "...")
    timer.cancel()
    return proc.returncode, timeout["value"]

	
def run(cmd, time, stdinput=""):
	print("Running: {}\n".format(cmd))
	try:
		
		# just in case we will kill your process 
		# after <time> seconds
		res, timeout = run_with_timeout(cmd, time, stdinput)
	except:
		print("An exception occurred")
		print("{} test failed!".format(cmd))
		return 0
	if timeout:
		print("Taking too long, abort")
		print("Infinite loop?")
		return 0
	if res == 0:
		return 2
	else: 
		print("Program exited with non-zero status, test failed")
	return 0

def test(dirname, outof):

	
	#switch to directory dirname
	os.chdir(dirname)
	sys.stdout.flush()
	print("\n{stars}\n* Compilation\n{stars}".format(stars="*"*75))
	
	# run the 'make clean' and 'make all' commands
	cmds = ["clean","all"]
	for c in cmds:
		cmd = ["make",c]
		print("Executing: {}".format(" ".join(cmd)))
		res = subprocess.call(cmd)
		sys.stdout.flush()
		if res:
			# make command produced an error
			# return with 0 marks
			print("make: non-zero exit status {}".format(res))
			print("\n\n{stars}\n* Mark: {mark}/{outof}\n".format(stars="*"*75, mark=0, outof=outof))
			return
		
	score = 0
	
	args = ["0","1","2"]

	#total marks: 4
	
	
	for i in args:
		score += run("./test", 5, i)


	now = dt.datetime.now()
	if now > duedate:
		print("Tutorial is late, 10% penalty")
		score *= 0.9	

	print("\n\n{stars}\n* Mark: {mark}/{outof}\n{stars}\n".format(stars="*"*75, mark=score, outof=outof))



	

def process_all():
	 
			
	t = Tee()
	
	t.open('results.txt', 'w')
	dirname = 'tutorial3'
	#dirname = '.'
	test(dirname, 6)
		
	t.close()



if __name__ == "__main__":
	
	sys.stdout.flush()
	process_all()
	sys.stdout.flush()
	
