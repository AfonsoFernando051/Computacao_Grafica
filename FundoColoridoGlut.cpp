//Este programa utiliza a bibioteca GLUT(OpenGL Utility Toolkit), que facilita a cria��o de aplicativos OpenGL.
#include <GL/glut.h>

void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

	glBegin(GL_QUADS); // Inicia a especifica��o dos v�rtices de um quadrado
	glColor3f(1.0, 1.0, 1.0); // Define a cor do v�rtice como branco
	glVertex2f(-0.8, 0.8);  // Define a posi��o do primeiro v�rtice

	glColor3f(1.0, 0.0, 0.0); // Define a cor do v�rtice como vermelho
	glVertex2f(0.8, 0.8); // Define a posi��o do segundo v�rtice

	glColor3f(0.0, 1.0, 0.0); // Define a cor do v�rtice como verde
	glVertex2f(0.8, -0.8); // Define a posi��o do terceiro v�rtice

	glColor3f(0.0, 0.0, 1.0); // Define a cor do v�rtice como azul
	glVertex2f(-0.8, -0.8); // Define a posi��o do quarto v�rtice
	glEnd(); // Termina a especifica��o dos v�rtices do quadrado

	glColor3f(0.0, 0.0, 1.0); // Define a cor da linha como azul
	glBegin(GL_LINES); // Inicia a especifica��o dos v�rtices de uma linha
	glVertex2f(-1.0, 1.0); // Define a posi��o do primeiro v�rtice da linha
	glVertex2f(1.0, -1.0); // Define a posi��o do segundo v�rtice da linhas
	glEnd(); // Define a posi��o do segundo v�rtice da linha

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
	glutDisplayFunc(Desenha); // Define a fun��o de callback de desenho
	glutMainLoop(); // Entra no loop principal do GLUT
	return 0;
}