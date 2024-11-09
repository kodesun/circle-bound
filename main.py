import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = 'hide'

from models import Display, Boundary, Ball

if __name__ == "__main__":
    display = Display()

    ball = Ball()
    boundary = Boundary()

    while True:
        display.handle_input()
        if not display.paused:
            # display.clear()

            ball.update()

            display.draw(ball)
            display.draw(boundary)

        display.show()
