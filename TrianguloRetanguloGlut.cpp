//Este programa utiliza a bibioteca GLUT(OpenGL Utility Toolkit), que facilita a cria��o de aplicativos OpenGL.
#include <GL/glut.h>

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    // Desenha um quadrado branco
    glColor3f(1, 1, 1); // Define a cor como branco
    glBegin(GL_QUADS); // Inicia a especifica��o dos v�rtices de um quadrado
    glVertex2f(-0.8, 0.8); // Define a posi��o do primeiro v�rtice
    glVertex2f(0.8, 0.8);  // Define a posi��o do segundo v�rtice
    glVertex2f(0.8, -0.8); // Define a posi��o do terceiro v�rtice
    glVertex2f(-0.8, -0.8); // Define a posi��o do quarto v�rtice
    glEnd(); // Termina a especifica��o dos v�rtices do quadrado

    // Desenha um tri�ngulo vermelho
    glColor3f(1, 0, 0); // Define a cor como vermelho
    glBegin(GL_TRIANGLES); // Inicia a especifica��o dos v�rtices de um tri�ngulo
    glVertex2f(-0.6, -0.6); // Define a posi��o do primeiro v�rtice
    glVertex2f(0.0, 0.6);   // Define a posi��o do segundo v�rtice
    glVertex2f(0.6, -0.6);  // Define a posi��o do terceiro v�rtice
    glEnd(); // Termina a especifica��o dos v�rtices do tri�ngulo

    // Desenha um pol�gono verde
    glColor3f(0, 1, 0); // Define a cor como verde
    glBegin(GL_POLYGON); // Inicia a especifica��o dos v�rtices de um pol�gono
    glVertex2f(-0.6, -0.4); // Define a posi��o do primeiro v�rtice
    glVertex2f(0.0, -0.3);  // Define a posi��o do segundo v�rtice
    glVertex2f(0.6, -0.4);  // Define a posi��o do terceiro v�rtice
    glVertex2f(0.6, -0.6);  // Define a posi��o do quarto v�rtice
    glVertex2f(-0.6, -0.6); // Define a posi��o do quinto v�rtice
    glEnd(); // Termina a especifica��o dos v�rtices do pol�gono

    // Desenha uma linha diagonal verde
    glColor3f(0, 1, 0); // Define a cor como verde
    glBegin(GL_LINES); // Inicia a especifica��o dos v�rtices de uma linha
    glVertex2f(-1.0, 1.0); // Define a posi��o do primeiro v�rtice da linha
    glVertex2f(1.0, -1.0); // Define a posi��o do segundo v�rtice da linha
    glEnd(); // Termina a especifica��o dos v�rtices da linha

    glFlush(); // Garante que todos os comandos de desenho sejam executados
}


void Inicializa(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo da janela como preta
}

int main() {
	glutInitWindowSize(400, 400); // Define o tamanho da janela
	glutInitWindowPosition(0, 0); // Define a posi��o da janela
	glutCreateWindow("Primeiro Desenho"); // Cria a janela com o t�tulo "Primeiro Desenho"
	Inicializa(); // Chama a fun��o de inicializa��o
	glutDisplayFunc(desenha); // Define a fun��o de callback de desenho
	glutMainLoop(); // Entra no loop principal do GLUT
	return 0;
}