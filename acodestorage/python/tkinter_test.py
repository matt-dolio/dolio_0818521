from tkinter import *
 
window = Tk()
 
window.title("Tkinter test")
 
window.geometry('350x200')
 
lbl = Label(window, text="Hello")
 
lbl.grid(column=0, row=0)
 
btn = Button(window, text="Click Me")
 
btn.grid(column=1, row=0)
 
window.mainloop()
