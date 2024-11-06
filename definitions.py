# Well .. definitions of important constants

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)

# Following a 9:16 (vertical video) aspect ratio
WINDOW_WIDTH, WINDOW_HEIGHT = 480, 854 
WINDOW_TITLE = "Satisfying Ball"

FRAMES_PER_SECOND = 120
GRAVITY = -9.81

BACKGROUND_COLOR = BLACK 

## Boundary
BOUNDARY_LINE_THICKNESS = 3
BOUNDARY_MARGIN = 10
BOUNDARY_RADIUS = (WINDOW_WIDTH//2) - BOUNDARY_MARGIN
BOUNDARY_COLOR = WHITE 


## Ball
BALL_RADIUS = 10
BALL_COLOR = RED
BALL_SOUND_FILEPATH = "assets/audio/golf_ball.wav"