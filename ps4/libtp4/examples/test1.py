import tp4
import sys
import math

def print_part1()
	print("VERSION=", sys.version)
	print("PI=" + math.pi")
	print("pi()=" + tp4.pi())
	print("PI+5=" + tp4.add_pi(5))

tp4.stats()
print_part1()
tp4.set_log(1)
print_part1()
tp4.set_log(0)
tp4.stats()