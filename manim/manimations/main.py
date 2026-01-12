from manim import *

class Sin_and_Cos(Scene):
    def construct(self):
        # Criar axes apenas para referência, mas não mostrar
        axes = Axes(
            x_range=[-5, 5, 1],
            y_range=[-2, 2, 0.5],
            x_length=12,   # largura da tela
            y_length=6     # altura da tela
        )
        axes.set_opacity(0)  # deixa invisível

        # Curvas
        seno = axes.plot(lambda x: np.sin(x), color=BLUE, stroke_width=8)
        cosseno = axes.plot(lambda x: np.cos(x), color=RED, stroke_width=8)

        # Mostrar curvas
        self.play(Create(seno), Create(cosseno))
        self.wait()
