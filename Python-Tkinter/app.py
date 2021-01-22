# grid = [1*8 for n in range(8)]

# w = 70


# def setup():
#     size(800,600)

# def draw():
#     x,y = 0,0
#     for row in grid:
#         for col in grid:
#             rect(x, y, w ,w)
#             x += w
#         y += w


# draw()

import tkinter

window = tkinter.Tk()
# to rename the title of the window
window.title("Find Shortest Path")
# pack is used to show the object in the window
label = tkinter.Label(window, text = "Click").pack()
window.mainloop()