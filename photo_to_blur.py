from tkinter import *
from PIL import Image, ImageTk, ImageFilter

img = Image.open("C:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\a.jpeg")

def update(val):
    blur = int(val)
    out = img.filter(ImageFilter.GaussianBlur(blur))
    tkimg = ImageTk.PhotoImage(out)
    panel.config(image=tkimg)
    panel.image = tkimg

root = Tk()
panel = Label(root)
panel.pack()

Scale(root, from_=20, to=50, orient=HORIZONTAL,
      command=update).pack()

root.mainloop()
