#Python 3.6
from tkinter import *


master = Tk()
Label(master, text="Vector 1:").grid(row=0)
Label(master, text="Vector 2:").grid(row=1)


e1 = Entry(master)
e2 = Entry(master)

e1.insert(10,"1")
e2.insert(10,"4")

e1.grid(row=0, column=1)
e2.grid(row=1, column=1)

def summ():
    res = Label(master, text = "Summ: " + str(eval(e1.get()) + eval(e2.get()))).grid(row=5)
    res.pack()

Button(master, text='Summ', command=summ).grid(row=4, column=0, sticky=W, pady=4)
Button(master, text='Quit', command=master.quit).grid(row=3, column=0, sticky=W, pady=4)



mainloop( )