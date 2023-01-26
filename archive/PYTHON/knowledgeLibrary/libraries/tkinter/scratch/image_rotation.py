"""
Purpose:
    Show how to resize / crop images using the PIL Library

Known Issues:
    10-30-2021
        the for look opens up new windows instead of updating current view finder

        Helpful animation link: https://stackoverflow.com/questions/13215215/python-tkinter-animation
"""

# # Importing Image class from PIL module
# from PIL import Image
 
# # Opens a image in RGB mode
# im = Image.open("../images/earth.png")

# # Size of the image in pixels (size of original image)
# width, height = im.size 
# newsize = (50, 50)
# im1 = im.resize(newsize)

# # After resizing
# im1.show("testing")
# rotation = 0

# for x in range(10):
#     rotation += 10
#     print(rotation)
#     im1.rotate(rotation).show("testing")

import time
import tkinter
from PIL import Image, ImageTk

class SimpleApp(object):
    def __init__(self, master, filename, **kwargs):
        self.master = master
        self.filename = filename
        self.canvas = tkinter.Canvas(master, width=500, height=500)
        self.canvas.pack()

        self.process_next_frame = self.draw().__next__  # Using "next(self.draw())" doesn't work
        self.master.after(1, self.process_next_frame)
        

    def draw(self):
        image = Image.open(self.filename)
        newsize = (250, 250)
        image = image.resize(newsize)
        angle = 0
        print(self.process_next_frame)
        
        while True:
            tkimage = ImageTk.PhotoImage(image.rotate(angle))
            canvas_obj = self.canvas.create_image(250, 250, image=tkimage)
            self.master.after_idle(self.process_next_frame)
            yield
            self.canvas.delete(canvas_obj)
            angle += 1
            angle %= 360
            time.sleep(0.002)

root = tkinter.Tk()
app = SimpleApp(root, 'earth.png')

root.mainloop()