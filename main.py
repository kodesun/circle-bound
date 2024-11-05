import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = 'hide'

from models import Display, Boundary

if __name__ == "__main__":
    display = Display() 
    boundary = Boundary()

    while True:
        display.handle_input()
        display.clear()
        display.draw(boundary)
        display.show()