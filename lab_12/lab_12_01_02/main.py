from tkinter import*
from tkinter import messagebox
from tkinter import ttk
from src.operations import *

def left_shift_arr():
    try:
        arr = list(map(int, nonoutput.get().split(',')))
        try:
            pos = int(n1.get())
            if pos <= 0 or pos >= len(arr):
                messagebox.showerror('Wrong input',
                                    'Postion must be an positive value or not bigger than Array size!')
            else:
                arr_2 = str(left_rotation(arr, pos)[1])[1:-1]
                output.delete(0, END)
                output.insert(END, arr_2)
        except:
            messagebox.showerror('Wrong input',
                                    'Postion must be an positive value or not bigger than Array size!')

    except:
        messagebox.showerror('wrong input',
                                'Only numbers, commas or spaces.')

def Filter_inputed():
    try:
        arr = list(map(int, nonoutput.get().split(',')))
        try:
            arr_2 = str(get_full_sq_nums(arr)[1])[1:-1]
            output.delete(0, END)
            output.insert(END, arr_2)
        except:
            output.delete(0, END)
            output.insert(END, 'Empty Array')

    except:
        output.delete(0, END)
        output.insert(END, 'Empty Array')
        messagebox.showerror('wrong input',
                                'Only numbers, commas or spaces.')

root = Tk()
root.geometry("625x250")
root.title("Lab 12")

info = ttk.Label(root, text = 'Array Elements')
info.place(x = 10, y = 25)

title = ttk.Label(root, text = 'Number of Left shift')
title.place(x = 10, y = 70)

nonoutput = ttk.Entry(root)
nonoutput.place(x = 160, y = 30, width = 300)

result = ttk.Label(root, text = 'Result')
result.place(x = 10, y = 130)

app_use = ttk.Label(root, text = 'This Program generates a new array by pushing button.\n'\
                                'Filter: Generated Array must contain full square numbers, otherwise (Empty Array).\n'\
                                'Left Shift: in this case you must enter the number of positions also, otherwise u can try ;)')
app_use.place(x = 10, y = 180)

output = ttk.Entry(root)
output.place(x = 160, y = 130, width = 300)

output_entry = ttk.Button(root, text = 'Left Shift', command = left_shift_arr)
output_entry.place(x = 500, y = 70, width = 100)

Filter_entery = ttk.Button(root, text = 'Filter', command = Filter_inputed)
Filter_entery.place(x = 500, y = 40, width = 100)

#input
n1 = StringVar()
N1 = ttk.Entry(root, textvariable = n1)
N1.place(x = 160, y = 70, width = 100)

root.mainloop()