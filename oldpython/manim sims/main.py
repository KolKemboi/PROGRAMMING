from manim import *

class BasicExample(Scene):
    def construct(self):
        # Create a text object
        text = Text("Welcome to Manim")
        text.set_color(BLUE)
        text.scale(1.5)
        
        # Create a circle object
        circle = Circle()
        circle.set_fill(YELLOW, opacity=0.5)
        circle.set_stroke(color=WHITE, width=4)
        circle.shift(2 * DOWN)

        # Show the text on the screen
        self.play(Write(text))
        self.wait(1)

        # Transform the text into the circle
        self.play(Transform(text, circle))
        self.wait(1)

        # Make the circle grow
        self.play(circle.animate.scale(2))
        self.wait(2)

        # Fade out the circle
        self.play(FadeOut(circle))

