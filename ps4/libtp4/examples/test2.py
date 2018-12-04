import sys
sys.path.append('../lib')

import tp4
import sys
import math


def f():
	v1 = tp4.Vector_create(1, 2, 3)
	v2 = tp4.Vector_create(4, 5, 6)
	v = tp4.Vector_add(v1, v2)
	tp4.stats()
	val_v = tp4.Vector_str(v)
	print("Vector v: " + val_v)
	del(val_v)
	tp4.Vector_destroy(v2)
	del(v2)
	tp4.Vector_destroy(v1)
	del(v1)
	tp4.Vector_destroy(v)
	return v

tp4.stats()
vector = f()
tp4.stats()
val_v = tp4.Vector_str(vector)
#Error at previous line v was destroyed
del(val_v)
	