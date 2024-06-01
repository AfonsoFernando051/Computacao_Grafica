#include <GL/glut.h>

float posX = 0.0f; // Posi��o inicial do ret�ngulo no eixo X
float zoomFactor = 1.0f; // Fator de zoom inicial

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    // Desenha uma linha fixa na parte inferior da janela
    glColor3f(1, 1, 1); // Define a cor como branco
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.8); // Define a posi��o do primeiro v�rtice da linha
    glVertex2f(1.0, -0.8);  // Define a posi��o do segundo v�rtice da linha
    glEnd(); // Termina a especifica��o dos v�rtices da linha

    // Empilha a matriz atual
    glPushMatrix();

    // Aplica a transla��o
    glTranslatef(posX, 0.0f, 0.0f);

    // Desenha um ret�ngulo branco que se move horizontalmente acima da linha
    glColor3f(1, 1, 1); // Define a cor como branco
    glBegin(GL_QUADS); // Inicia a especifica��o dos v�rtices de um quadrado
    glVertex2f(-0.2, 0.0);  // Define a posi��o do primeiro v�rtice
    glVertex2f(0.2, 0.0);   // Define a posi��o do segundo v�rtice
    glVertex2f(0.2, 0.4);   // Define a posi��o do terceiro v�rtice
    glVertex2f(-0.2, 0.4);  // Define a posi��o do quarto v�rtice
    glEnd(); // Termina a especifica��o dos v�rtices do quadrado

    // Desempilha a matriz, restaurando a matriz anterior
    glPopMatrix();

    glFlush(); // Garante que todos os comandos de desenho sejam executados
}

void Inicializa(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo da janela como preta
}

void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        posX -= 0.1f; // Move o ret�ngulo para a esquerda
    }
    if (key == GLUT_KEY_RIGHT) {
        posX += 0.1f; // Move o ret�ngulo para a direita
    }
    if (key == GLUT_KEY_UP) {
        zoomFactor *= 0.9; // Zoom in
    }
    if (key == GLUT_KEY_DOWN) {
        zoomFactor /= 0.9; // Zoom out
    }
    glMatrixMode(GL_PROJECTION); // Define a matriz de proje��o
    glLoadIdentity(); // Carrega a matriz identidade
    gluOrtho2D(-1.0 * zoomFactor, 1.0 * zoomFactor, -1.0 * zoomFactor, 1.0 * zoomFactor); // Define a proje��o ortogr�fica
    glMatrixMode(GL_MODELVIEW); // Define a matriz de modelagem/visualiza��o
    glutPostRedisplay(); // Solicita a atualiza��o da tela
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400); // Define o tamanho da janela
    glutInitWindowPosition(0, 0); // Define a posi��o da janela
    glutCreateWindow("Ret�ngulo M�vel e Linha Fixa"); // Cria a janela com o t�tulo "Ret�ngulo M�vel e Linha Fixa"
    Inicializa(); // Chama a fun��o de inicializa��o
    glutDisplayFunc(desenha); // Define a fun��o de callback de desenho
    glutSpecialFunc(teclado); // Define a fun��o de callback de intera��o com teclado
    glutMainLoop(); // Entra no loop principal do GLUT
    return 0;
}
