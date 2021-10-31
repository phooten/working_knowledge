#! python3

# libraries
import pyautogui
import sys


print('Press Ctrl-C to quit.')
try:
    while True:
        x, y = pyautogui.position()
        positionStr = 'X: ' + str(x).rjust(4) + ' Y: ' + str(y).rjust(4)
        print(positionStr, end='')
        print('\b' * len(positionStr), end='', flush=True)
except KeyboardInterrupt: 
    print('\n')

# from tkinter import *
# from tkinter import ttk

# root = Tk()
# frm = ttk.Frame(root, padding=10)
# frm.grid()

# ttk.Label(frm, text="Orbit").grid(column=0, row=0)
# ttk.Button(frm, text="Quit", command=root.destroy).grid(column=0, row=1)

# root.mainloop()
