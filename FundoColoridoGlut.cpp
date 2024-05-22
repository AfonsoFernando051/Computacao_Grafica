//Este programa utiliza a bibioteca GLUT(OpenGL Utility Toolkit), que facilita a criação de aplicativos OpenGL.
#include <GL/glut.h>

void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

	glBegin(GL_QUADS); // Inicia a especificação dos vértices de um quadrado
	glColor3f(1.0, 1.0, 1.0); // Define a cor do vértice como branco
	glVertex2f(-0.8, 0.8);  // Define a posição do primeiro vértice

	glColor3f(1.0, 0.0, 0.0); // Define a cor do vértice como vermelho
	glVertex2f(0.8, 0.8); // Define a posição do segundo vértice

	glColor3f(0.0, 1.0, 0.0); // Define a cor do vértice como verde
	glVertex2f(0.8, -0.8); // Define a posição do terceiro vértice

	glColor3f(0.0, 0.0, 1.0); // Define a cor do vértice como azul
	glVertex2f(-0.8, -0.8); // Define a posição do quarto vértice
	glEnd(); // Termina a especificação dos vértices do quadrado

	glColor3f(0.0, 0.0, 1.0); // Define a cor da linha como azul
	glBegin(GL_LINES); // Inicia a especificação dos vértices de uma linha
	glVertex2f(-1.0, 1.0); // Define a posição do primeiro vértice da linha
	glVertex2f(1.0, -1.0); // Define a posição do segundo vértice da linhas
	glEnd(); // Define a posição do segundo vértice da linha

	glFlush(); // Garante que todos os comandos de desenho sejam executados
}

void Inicializa(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo da janela como preta
}

int main() {
	glutInitWindowSize(400, 400); // Define o tamanho da janela
	glutInitWindowPosition(0, 0); // Define a posição da janela
	glutCreateWindow("Primeiro Desenho"); // Cria a janela com o título "Primeiro Desenho"
	Inicializa(); // Chama a função de inicialização
	glutDisplayFunc(Desenha); // Define a função de callback de desenho
	glutMainLoop(); // Entra no loop principal do GLUT
	return 0;
}