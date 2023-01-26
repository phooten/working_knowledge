#!/usr/bin/env python3
from PIL import Image, ImageTk
from tkinter import Tk, Frame, Canvas, ALL, NW


# Settings
WINDOW_HEIGHT = 700
WINDOW_WIDTH = 1200

# Initalize
root = Tk()
root.title('space debree collection')
root.geometry(f"{WINDOW_WIDTH}x{WINDOW_HEIGHT}")

canvas = Canvas(root, height=WINDOW_HEIGHT, width=WINDOW_WIDTH, bg="black")
canvas.pack(padx=20, pady=20)

x = WINDOW_WIDTH // 2
y = WINDOW_HEIGHT // 2


# Creates Rocket image object
open_img = Image.open("images/rocket.png")
img_size = open_img.size

scale = 50
ratio = img_size[0] / img_size[1]         # x / y = new x / new y
new_x = scale * ratio
new_y = scale
newsize = (int(new_x) , new_y)

open_img = open_img.resize(newsize)
img = ImageTk.PhotoImage(open_img)
item = canvas.create_image(x, y, image=img, )


def left(event):
    x = -10
    y = 0
    canvas.move(item, x, y)


def right(event):
    x = 10
    y = 0
    canvas.move(item, x, y)

def up(event):
    x = 0
    y = -10
    canvas.move(item, x, y)

def down(event):
    x = 0
    y = 10
    canvas.move(item, x, y)

root.bind("<Left>", left)
root.bind("<Right>", right)
root.bind("<Up>", up)
root.bind("<Down>", down)

root.mainloop()

