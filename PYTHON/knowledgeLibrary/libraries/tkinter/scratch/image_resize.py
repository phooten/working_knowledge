"""
Purpose:
    Show how to resize / crop images using the PIL Library
"""

# Importing Image class from PIL module
from PIL import Image
 
# Opens a image in RGB mode
im = Image.open("../images/earth.png")

# Before resizing
im.show() 

# Size of the image in pixels (size of original image)
width, height = im.size 
newsize = (50, 50)
im1 = im.resize(newsize)

# After resizing
im1.show()


"""
# Cropping:
# link: https://www.geeksforgeeks.org/python-pil-image-resize-method/
____________________________________________ 
# Setting the points for cropped image
left = 4
top = height / 5
right = 154
bottom = 3 * height / 5

# Cropped image of above dimension
(It will not change original image)
im1 = im.crop((left, top, right, bottom))
____________________________________________ 
"""

