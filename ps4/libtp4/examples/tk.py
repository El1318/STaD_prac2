#Python 3.6
import sys
sys.path.append('../lib')

from tkinter import *
import tp4
import os


master = Tk()
Label(master, text="Vector 1:").grid(row=0, column=0)
Label(master, text="Vector 2:").grid(row=1, column=0)
Label(master, text="Scalar a:").grid(row=2, column=0)


e1 = Entry(master)
e2 = Entry(master)
e3 = Entry(master)

e1.insert(10,"0,0,0")
e2.insert(10,"0,0,0")
e3.insert(10,"0")

e1.grid(row=0, column=1)
e2.grid(row=1, column=1)
e3.grid(row=2, column=1)

summ_str = StringVar()
summ =  Label(master, textvariable = summ_str).grid(row=5,column=0)
summ_str.set("Summ: ")

pi_str = StringVar()
pi =  Label(master, textvariable = pi_str).grid(row=6,column=0)
pi_str.set("PI+a: ")

log_str = StringVar()
log =  Label(master, textvariable = log_str).grid(row=5,column=2)
log_str.set("Logging: OFF")
logging = 0

stats_str = StringVar()
stats =  Label(master, textvariable = stats_str).grid(row=6,column=2)
stats_str.set("Log stats")


def summ():
    try:
        v1 = [float(x) for x in e1.get().split(',')]
        v2 = [float(x) for x in e2.get().split(',')]
        v1 = tp4.Vector_create(v1[0],v1[1],v1[2])
        v2 = tp4.Vector_create(v2[0],v2[1],v2[2])
        v = tp4.Vector_add(v1,v2)
        summ_str.set("Summ: " + str(tp4.Vector_str(v)))
        tp4.Vector_destroy(v)
    except:
        summ_str.set("Summ: " + "Wrong input!")


def pi():
    try:
        a = float(e3.get())
        v = tp4.add_pi(a)
        pi_str.set("PI+a: " + str(v)[:5])
    except:
        pi_str.set("PI+a: " + "Wrong input!")


def enable_log():
    logging = 1
    tp4.set_log(1)
    log_str.set("Logging: ON") 

def disable_log():
    logging = 0
    tp4.set_log(0)  
    log_str.set("Logging: OFF")  
    
def stats():
    tp4.stats()
    

Button(master, text='Summ', command=summ).grid(row=4, column=0)
Button(master, text='Add PI to a', command=pi).grid(row=4, column=1)
Button(master, text='Enable logging', command=enable_log).grid(row=4, column=2)
Button(master, text='Disable logging', command=disable_log).grid(row=4, column=3)
Button(master, text='Show stats', command=stats).grid(row=4, column=4)
Button(master, text='Quit', command=master.quit).grid(row=10, column=0)

mainloop()







