#include <GL/glut.h>

float posX = 0.0f; // Posição inicial do retângulo no eixo X
float zoomFactor = 1.0f; // Fator de zoom inicial

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    // Desenha uma linha fixa na parte inferior da janela
    glColor3f(1, 1, 1); // Define a cor como branco
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.8); // Define a posição do primeiro vértice da linha
    glVertex2f(1.0, -0.8);  // Define a posição do segundo vértice da linha
    glEnd(); // Termina a especificação dos vértices da linha

    // Empilha a matriz atual
    glPushMatrix();

    // Aplica a translação
    glTranslatef(posX, 0.0f, 0.0f);

    // Desenha um retângulo branco que se move horizontalmente acima da linha
    glColor3f(1, 1, 1); // Define a cor como branco
    glBegin(GL_QUADS); // Inicia a especificação dos vértices de um quadrado
    glVertex2f(-0.2, 0.0);  // Define a posição do primeiro vértice
    glVertex2f(0.2, 0.0);   // Define a posição do segundo vértice
    glVertex2f(0.2, 0.4);   // Define a posição do terceiro vértice
    glVertex2f(-0.2, 0.4);  // Define a posição do quarto vértice
    glEnd(); // Termina a especificação dos vértices do quadrado

    // Desempilha a matriz, restaurando a matriz anterior
    glPopMatrix();

    glFlush(); // Garante que todos os comandos de desenho sejam executados
}

void Inicializa(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo da janela como preta
}

void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        posX -= 0.1f; // Move o retângulo para a esquerda
    }
    if (key == GLUT_KEY_RIGHT) {
        posX += 0.1f; // Move o retângulo para a direita
    }
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400); // Define o tamanho da janela
    glutInitWindowPosition(0, 0); // Define a posição da janela
    glutCreateWindow("Retângulo Móvel e Linha Fixa"); // Cria a janela com o título "Retângulo Móvel e Linha Fixa"
    Inicializa(); // Chama a função de inicialização
    glutDisplayFunc(desenha); // Define a função de callback de desenho
    glutSpecialFunc(teclado); // Define a função de callback de interação com teclado
    glutMainLoop(); // Entra no loop principal do GLUT
    return 0;
}
