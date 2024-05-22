//Este programa utiliza a bibioteca GLUT(OpenGL Utility Toolkit), que facilita a criação de aplicativos OpenGL.
#include <GL/glut.h>

float zoomFactor = 1.0; // Fator de zoom inicial

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    // Desenha um quadrado branco
    glColor3f(1, 1, 1); // Define a cor como branco
    glBegin(GL_QUADS); // Inicia a especificação dos vértices de um quadrado
    glVertex2f(-0.8, 0.8); // Define a posição do primeiro vértice
    glVertex2f(0.8, 0.8);  // Define a posição do segundo vértice
    glVertex2f(0.8, -0.8); // Define a posição do terceiro vértice
    glVertex2f(-0.8, -0.8); // Define a posição do quarto vértice
    glEnd(); // Termina a especificação dos vértices do quadrado

    // Desenha um triângulo vermelho
    glColor3f(1, 0, 0); // Define a cor como vermelho
    glBegin(GL_TRIANGLES); // Inicia a especificação dos vértices de um triângulo
    glVertex2f(-0.6, -0.6); // Define a posição do primeiro vértice
    glVertex2f(0.0, 0.6);   // Define a posição do segundo vértice
    glVertex2f(0.6, -0.6);  // Define a posição do terceiro vértice
    glEnd(); // Termina a especificação dos vértices do triângulo

    // Desenha um polígono verde
    glColor3f(0, 1, 0); // Define a cor como verde
    glBegin(GL_POLYGON); // Inicia a especificação dos vértices de um polígono
    glVertex2f(-0.6, -0.4); // Define a posição do primeiro vértice
    glVertex2f(0.0, -0.3);  // Define a posição do segundo vértice
    glVertex2f(0.6, -0.4);  // Define a posição do terceiro vértice
    glVertex2f(0.6, -0.6);  // Define a posição do quarto vértice
    glVertex2f(-0.6, -0.6); // Define a posição do quinto vértice
    glEnd(); // Termina a especificação dos vértices do polígono

    // Desenha uma linha diagonal verde
    glColor3f(0, 1, 0); // Define a cor como verde
    glBegin(GL_LINES); // Inicia a especificação dos vértices de uma linha
    glVertex2f(-1.0, 1.0); // Define a posição do primeiro vértice da linha
    glVertex2f(1.0, -1.0); // Define a posição do segundo vértice da linha
    glEnd(); // Termina a especificação dos vértices da linha

    glFlush(); // Garante que todos os comandos de desenho sejam executados
}


void Inicializa(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo da janela como preta
}

void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        zoomFactor *= 0.9; // Zoom in
    }
    if (key == GLUT_KEY_DOWN) {
        zoomFactor /= 0.9; // Zoom out
    }
    glMatrixMode(GL_PROJECTION); // Define a matriz de projeção
    glLoadIdentity(); // Carrega a matriz identidade
    gluOrtho2D(-1.0 * zoomFactor, 1.0 * zoomFactor, -1.0 * zoomFactor, 1.0 * zoomFactor); // Define a projeção ortográfica
    glMatrixMode(GL_MODELVIEW); // Define a matriz de modelagem/visualização
    glutPostRedisplay(); // Solicita a atualização da tela
}

int main() {
    glutInitWindowSize(400, 400); // Define o tamanho da janela
    glutInitWindowPosition(0, 0); // Define a posição da janela
    glutCreateWindow("Primeiro Desenho"); // Cria a janela com o título "Primeiro Desenho"
    Inicializa(); // Chama a função de inicialização
    glutDisplayFunc(desenha); // Define a função de callback de desenho
    glutSpecialFunc(teclado); // Define a função de callback de interacao com teclado
    glutMainLoop(); // Entra no loop principal do GLUT
    return 0;
}