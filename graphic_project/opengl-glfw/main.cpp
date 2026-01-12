#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // 1. inicializa glfw
    if (!glfwInit()) {
        std::cerr << "Falha ao iniciar GLFW\n";
        return -1;
    }

    // 2. cria e configura a janela
    GLFWwindow* window = glfwCreateWindow(
        800, 600,
        "Hello OpenGL",
        nullptr,
        nullptr
    );

    // verifica se criou com sucesso
    if (!window) {
        std::cerr << "Falha ao criar janela\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 3. inicializa o glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Falha ao iniciar o GLAD\n";
        return -1;
    }

    // 4. shaders como strings

    //vertex shaders
    const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0)
    })";

    //fragment shaders
    const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 0.4, 0.2, 1.0);
    })";

    // 5. compila e linka os shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // dados do triângulo

    /*
                 X        Y        Z
    vertex 1  [-1 - 1]  [-1 - 1]  [-1 - 1]
    vertex 2  [-1 - 1]  [-1 - 1]  [-1 - 1]
    vertex 3  [-1 - 1]  [-1 - 1]  [-1 - 1]
    
    triângulos são 2D então todos os eixos z devem ficar no 0
    */
    float triangle_vertex[] = {
        0.0f, 0.5f, 0.0f,      // v1: topo do triângulo, meio do eixo X
        0.5f, -0.5f, -1.0f,     // v2: canto inferior direito
        -0.5f, -0.5f, -1.0f     // v3: canto inferior esquerdo
    };

    // aqui vai o VBO e VAO (vertex buffer object e vertex array object)
    unsigned int VBO, VAO;

    // 1️ Cria VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 2️ Cria VBO e envia os dados
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertex), triangle_vertex, GL_STATIC_DRAW);

    // 3️ Configura o layout do vértice (location = 0 no shader)
    glVertexAttribPointer(
        0,              // location no shader
        3,              // 3 floats por vértice (x, y, z)
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float), // stride (espaço entre vértices)
        (void*)0           // offset
    );
    glEnableVertexAttribArray(0);

    // 4️ Desbind por segurança
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // game loop 
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);        // usa o shader
        glBindVertexArray(VAO);             // liga o triângulo
        glDrawArrays(GL_TRIANGLES, 0, 3);   // desenha os 3 vértices

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // destroi a janela e termina
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
