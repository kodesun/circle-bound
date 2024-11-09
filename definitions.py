# Well .. definitions of important constants

import colorsys

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)

# Following a 9:16 (vertical video) aspect ratio
WINDOW_WIDTH, WINDOW_HEIGHT = 480, 854 
WINDOW_TITLE = "Satisfying Ball"

START_PAUSED = False

FRAMES_PER_SECOND = 90 
GRAVITY = -9.81

BACKGROUND_COLOR = BLACK 

# ============================ 
#       BOUNDARY 
# ============================ 
BOUNDARY_LINE_THICKNESS = 3
BOUNDARY_MARGIN = 10
BOUNDARY_RADIUS = (WINDOW_WIDTH//2) - BOUNDARY_MARGIN
BOUNDARY_COLOR = WHITE 


# ============================ 
#       BALL 
# ============================ 
BALL_RADIUS = 10
BALL_HUE = 0
BALL_HUE_SPEED = 0.5
BALL_SOUND_FILEPATH = "assets/audio/golf_ball.wav"

# Ball behavior after bounce
BALL_APPLY_SPEED_FACTOR = False
BALL_SPEED_FACTOR = 1.015

def hsl_to_rgb(h, s, l):
    r, g, b = colorsys.hls_to_rgb(h, l, s)
    return int(r*255), int(g*255), int(b*255)
