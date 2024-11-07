''' A place to define objects used along the project. '''

import pygame
import pygame.gfxdraw

from math import sqrt


from definitions import WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE
from definitions import BACKGROUND_COLOR
from definitions import FRAMES_PER_SECOND, GRAVITY
from definitions import BOUNDARY_RADIUS, BOUNDARY_COLOR
from definitions import BALL_RADIUS, BALL_COLOR, BALL_SOUND_FILEPATH

class Display():
    def __init__(self):
        pygame.init()
        pygame.mixer.init()
        pygame.display.set_caption(WINDOW_TITLE)

        self.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
        self.clock = pygame.time.Clock()

    def handle_input(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    quit()

    def show(self):
        pygame.display.update()
        self.clock.tick(FRAMES_PER_SECOND)

    def clear(self):
        self.screen.fill(BACKGROUND_COLOR)

    def draw(self, object):
        object.draw(self.screen)

class Ball():
    def __init__(self):
        self.name = "BALL" 
        self.posx = WINDOW_WIDTH//2 
        self.posy = WINDOW_HEIGHT//2 
        self.radius = BALL_RADIUS 
        self.color = BALL_COLOR 
        self.sound = BALL_SOUND_FILEPATH
        self.velx = 1 
        self.vely = 0
        self.accx = 0
        self.accy = GRAVITY/FRAMES_PER_SECOND
        self.track = list()

    def draw(self, screen):
        pygame.draw.circle(
            screen,
            self.color,
            (self.posx, self.posy),
            self.radius
        )

    def accelerate(self):
        self.velx += self.accx
        self.vely += self.accy

    def move(self):
        self.posx += self.velx
        self.posy -= self.vely

    def dist_from_center(self):
        return sqrt(((WINDOW_WIDTH//2)-self.posx)**2 + (self.posy - (WINDOW_HEIGHT//2))**2) 

    def reflect(self):
        vel = sqrt(self.velx**2 + self.vely**2)
        step = 0.2
        while sqrt((WINDOW_WIDTH//2-self.posx)**2 + (WINDOW_HEIGHT//2-self.posy)**2) > BOUNDARY_RADIUS - self.radius:
            self.posx += -self.velx*step/vel 
            self.posy -= -self.vely*step/vel

        normal_vec = self.posx-WINDOW_WIDTH//2, self.posy-WINDOW_HEIGHT//2
        normal_mag = self.dist_from_center() 
        n = normal_vec[0]/normal_mag, normal_vec[1]/normal_mag
        nx, ny = n[0], n[1]

        d = self.velx, -self.vely
        dx, dy = d[0], d[1]
        dot_product = nx*dx+ny*dy
        reflected = dx-2*dot_product*nx, dy-2*dot_product*ny

        self.velx = reflected[0]
        self.vely = -reflected[1]


    def update(self):
        if self.dist_from_center() + self.radius >= BOUNDARY_RADIUS:
            pygame.mixer.Sound.play(pygame.mixer.Sound(self.sound))
            self.velx *= 1.05
            self.vely *= 1.05
            self.reflect()

        self.accelerate()
        self.move()

class Boundary():
    def __init__(self):
        self.posx = WINDOW_WIDTH//2
        self.posy = WINDOW_HEIGHT//2
        self.radius = BOUNDARY_RADIUS 
        self.color = BOUNDARY_COLOR

    def draw(self, screen):
        pygame.gfxdraw.aacircle(
            screen,
            self.posx,
            self.posy,
            self.radius,
            self.color
        )