#include <GL/glut.h>

float cameraX = 2.0;
float cameraY = 2.0;
float cameraZ = 5.0;
float angle = 0.0;
int angulo = 0;

void display() {
    //Limpa os buffers de cor e profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reseta a matriz de modelagem/visualiza��o para a matriz identidade
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Define a posi��o da c�mera

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Define como os poligonos serao desenhados, no caso front and back,
    // define as faces do poligono, e FILL, define que sera totalmente preenchido
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glRotatef(angulo, 0, 1, 0); // Aplica a rota��o em torno do eixo Y

    // Desenha o primeiro cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glRotatef(angle, 1.0, 0.0, 0.0); // Aplica rota��o em torno do eixo X
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva


    // Desenha o segundo cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(0.0, 1.1, 0.0); // Transla��o para cima
    glRotatef(angle, 0.0, 1.0, 0.0); // Aplica rota��o em torno do eixo Y
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva

    // Desenha o terceiro cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glRotatef(angle, 1.0, 0.0, 0.0); // Aplica rota��o em torno do eixo X
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva


    // Desenha o quarto cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(0.0, -1.1, 0.0); // Transla��o para cima
    glRotatef(angle, 0.0, 1.0, 0.0); // Aplica rota��o em torno do eixo Y
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva

    // Desenha o quinto cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(-1.1,0.0, 0.0); // Transla��o para cima
    glRotatef(angle, 0.0, 1.0, 0.0); // Aplica rota��o em torno do eixo Y
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva

    // Desenha o sexto cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(1.1, 0.0, 0.0); // Transla��o para cima
    glRotatef(angle, 0.0, 1.0, 0.0); // Aplica rota��o em torno do eixo Y
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva

    // Desenha o setimo cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(0.0, 0.0, 1.1); // Transla��o para cima
    glRotatef(angle, 0.0, 1.0, 0.0); // Aplica rota��o em torno do eixo Y
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva

    // Desenha o oitavo cubo preenchido
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(0.0, 0.0, -1.1); // Transla��o para cima
    glRotatef(angle, 0.0, 1.0, 0.0); // Aplica rota��o em torno do eixo Y
    glColor3f(0.0, 0.0, 1.0); // Colore bordas do cubo em azul
    glutSolidCube(0.9); // Cria cubo solido
    glColor3f(0.0, 0.0, 0.0); // Preto
    glutWireCube(0.9); // Cria formato de cubo
    glPopMatrix(); // Restaura a matriz de transforma��o salva

    glRotatef(angulo, 0, 1, 0); // Aplica a rota��o em torno do eixo Y

    glFlush();
}

// Funcao chamada toda vez que a janela de visualizacao eh redimensionada
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init() {
    // Cor De Fundo
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Teste de profundidade, essencial para imagens 3d
    glEnable(GL_DEPTH_TEST);
}

// Funcao que cria animacao
void Anima(int value) {
    angulo++;
    glutPostRedisplay();
    glutTimerFunc(10, Anima, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Movimenta��o de Teclado");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    Anima(1);
    glutMainLoop(); // Estrutura de repeti��o que deixa a imagem num loop infinito
    return 0;
}
