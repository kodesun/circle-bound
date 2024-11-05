''' A place to define objects used along the project. '''

import pygame
import pygame.gfxdraw

from definitions import WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE
from definitions import FRAMES_PER_SECOND, BACKGROUND_COLOR
from definitions import BOUNDARY_RADIUS, BOUNDARY_LINE_THICKNESS, BOUNDARY_COLOR

class Display():
    def __init__(self):
        pygame.init()
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
        pass


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