#include <glad/glad.h>
#include <GLFW/glfw3.h> // traz tudo do glfw3 como janela, teclado, mouse e opengl context
#include <iostream>

int main() {

    // inicia o glfw.

    // verifica se deu certo ou não
    //evita que o programa crashe

    if (!glfwInit()) {
        std::cerr << "Falha ao iniciar GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(
        800, 600, // largura e altura em px
        "Hello OpenGL", // título
        nullptr, // monitor, janela normal não fullscreen
        nullptr // compartilhamento de texto(???)

        // retorna um ponteiro para GLFWwindow
        // se falhar retorna nullptr
    );

    // verifica se a janela foi criada com sucesso
    if (!window) {
        std::cerr << "Falha ao criar janela\n";
        glfwTerminate();
        return -1;
    }

    // ativa o contexto openg
    glfwMakeContextCurrent(window);

    // Contexto openGl.
    // Contexto openGl não funciona sozinho. Precisa de um Contexto Gráfico.
    // O contexto está associado à janela.
    // Sem isso glClear, shaders e buffers não funcionam.


    // verifica se o processo deu certo

    // carrega os ponteiros das funções modernas do openGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Falha ao iniciar o GLAD\n";
        return -1;
    }


    // loop principal (game loop)

    // esse loop funciona até o usuário fechar a janela.

    // isso é chamado de render loop, game loop, main loop. tudo gráfico acontece aqui. 
    while (!glfwWindowShouldClose(window)) {

        // apaga a tela, preenche com a cor atual, que é por padrã preto.
        // se não limpar a imagem anterior fica "suja".
        // aparecem erros estranhos.

        glClear(GL_COLOR_BUFFER_BIT);


        // troca de buffers.
        // openGL usa double buffering.
        // back buffer => onde você desenha.
        // front buffer => o que aparece na tela.

        // esse comando troca os dois tipos de buffers e mostra o frame pronto.
        // sem isso a tela não atualiza.

        glfwSwapBuffers(window);


        // processamento de eventos.
        // lê inputs como teclado, mouse, clique no "❌" da janela e por fim atualiza os estados internos da GLFW
        
        // sem isso a janela congela e o OS marca como "não respondendo"

        glfwPollEvents();

        /*
            Ordem correta dentro do loop
            Sempre:
                Desehar(glClear, render)
                Mostrar(glfwSwapBuffers)
                Processar eventos(glfwPollEvents)
        */
    }

    // encerramento limpo.
    // libera memória.
    // fecha conexão com o sistema gráfico.
    // evita leaks.
    // Boa prática, mesmo que o OS limpe depois.

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
