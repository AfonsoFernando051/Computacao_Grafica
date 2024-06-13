#include "GL/glut.h"
#include <math.h> // Inclua a biblioteca math.h

// Variáveis globais para controle da animação e posição da câmera
int anguloDir = 0;
int anguloEsq = 0;
bool animacaoAtiva = true;
float posicaoCameraZ = 6.0; // Posição inicial da câmera no eixo Z
float anguloCameraY = 0.0; // Ângulo de rotação da câmera no eixo Y

void Inicializa() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo
    glEnable(GL_DEPTH_TEST); // Habilita teste de profundidade
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa os buffers de cor e profundidade
    glLoadIdentity(); // Reseta a matriz de modelagem/visualização para a matriz identidade

    // Define a posição da câmera usando a rotação em torno do eixo Y
    float camX = posicaoCameraZ * sin(anguloCameraY);
    float camZ = posicaoCameraZ * cos(anguloCameraY);
    gluLookAt(camX, 0.0, camZ, // Posição da câmera rotacionada
        0.0, 0.0, 0.0, // Para onde a câmera está olhando (centro do cubo)
        0.0, 1.5, 1.5); // Vetor para cima (direção do eixo Y)

    // Define como os polígonos serão desenhados, no caso front and back,
    // define as faces do polígono, e FILL, define que será totalmente preenchido
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //Cubo Vermelho
    glPushMatrix();
    glRotatef(anguloEsq, 0, 1, 0);
    glColor3f(1, 0, 0);
    glutSolidCube(0.9);
    glColor3f(0, 0, 0);
    glutWireCube(0.9);
    glPopMatrix();

    //Cubo Azul
    glPushMatrix();
    glTranslatef(0.0, -1.1, 0.0);
    glRotatef(anguloDir, 0, 1, 0); // Rotaciona no eixo y
    glColor3f(0, 0, 1);
    glutSolidCube(0.9);
    glColor3f(0, 0, 0);
    glutWireCube(0.9);
    glPopMatrix();

    //Cubo Amarelo
    glPushMatrix();
    glRotatef(anguloEsq, 0, 1, 0); // Rotação em torno do eixo Y
    glTranslatef(1.3, 0.0, 0.0); // Translada para a direita para orbitar
    glColor3f(1, 1, 0); // Cor amarela para o cubo orbitando
    glutSolidCube(0.9);
    glColor3f(0, 0, 0);
    glutWireCube(0.9);
    glPopMatrix();

    //Cubo Verde
    glPushMatrix();
    glRotatef(anguloEsq, 0, 1, 0); // Rotação em torno do eixo Y
    glTranslatef(1.3, -1.1, 0.0); // Translada para a direita para orbitar
    glColor3f(0, 1, 0); // Cor verde para o cubo orbitando
    glutSolidCube(0.9);
    glColor3f(0, 0, 0);
    glutWireCube(0.9);
    glPopMatrix();

    glFlush(); // Forca a execucao das chamadas dos metodos
}

// Função chamada toda vez que a janela de visualização é redimensionada
void Reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

//Funcao de animacao
void Anima(int value) {
    if (animacaoAtiva) {
        anguloDir++;
        anguloEsq--;
        if (anguloDir > 360) anguloDir = 0; // Reseta o ângulo após uma volta completa
        if (anguloEsq < -360) anguloEsq = 0; // Reseta o ângulo após uma volta completa
        glutPostRedisplay();
    }
    glutTimerFunc(16, Anima, 1); // Aproximadamente 60 FPS
}

void TecladoEspecial(int key, int x, int y) {
    if (key == GLUT_KEY_END) {
        animacaoAtiva = !animacaoAtiva; // Alterna o estado de animação
    }
    else if (key == GLUT_KEY_UP) {
        posicaoCameraZ -= 0.1; // Move a câmera para frente
    }
    else if (key == GLUT_KEY_DOWN) {
        posicaoCameraZ += 0.1; // Move a câmera para trás
    }
    else if (key == GLUT_KEY_LEFT) {
        anguloCameraY -= 0.05; // Gira a câmera para a esquerda
    }
    else if (key == GLUT_KEY_RIGHT) {
        anguloCameraY += 0.05; // Gira a câmera para a direita
    }
    else if (key == GLUT_KEY_HOME) {
        // Retorna a câmera e os cubos para a posição inicial e reinicia a animação
        posicaoCameraZ = 6.0;
        anguloCameraY = 0.0;
        anguloDir = 0;
        anguloEsq = 0;
        animacaoAtiva = true;
    }
    glutPostRedisplay(); // Solicita a atualização da tela
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa a GLUT e processa os parâmetros da linha de comando
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600); // Define o tamanho da janela
    glutInitWindowPosition(0, 0); //Define a posicao da janela
    glutCreateWindow("Auto Instrucional O1"); // Titulo da janela
    Inicializa(); // Inicializa a janela limpando o buffer e definindo a cor de fundo
    glutDisplayFunc(Display); // Callback que renderiza o desenho na tela
    glutReshapeFunc(Reshape); // Callback chamada quando a tela sera renderizada novamente
    glutTimerFunc(16, Anima, 1); // Inicia a animação
    glutSpecialFunc(TecladoEspecial); // Define a função para capturar teclas especiais
    glutMainLoop(); // Loop continuo que permite visualizacao
    return 0;
}
