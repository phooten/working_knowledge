## Latest
Tkinter is more GUI/User interface stuff. I'm going to shift over to OpenGL

### Notes
building program with skeletonn code from: https://zetcode.com/tkinter/snake/

    self.pack():
    [ tkinter method ]
   
TKINTER 
-   Event Binding:
    -   Helpful link: https://anzeljg.github.io/rin2/book2/2405/docs/tkinter/events.html

-   Key Presses:
    -   Link: https://www.tcl.tk/man/tcl8.4/TkCmd/keysyms.html


## Todo
self.bind_all("<Key>", self.onKeyPressed)
self.after(Settings.DELAY, self.onTimer)



### Dependencies

tkinter ( graphics library )
    brew install python-tk@3.9
-   Python needs to have tkinter configurated in it's installation. They aren't supported by MacOS to be 
    installed seperatley. They provided this command instead.

PIL ( Pillow - python image library)
    python3 -m pip install --upgrade pip
    python3 -m pip install --upgrade Pillow
-   Used to import images into programs.
-   Link: https://pillow.readthedocs.io/en/stable/installation.html

pyautogui
    python3 -m pip install pyautogui