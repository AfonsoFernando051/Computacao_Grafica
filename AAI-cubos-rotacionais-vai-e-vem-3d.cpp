#include "GL/glut.h"
#include <math.h> // Inclua a biblioteca math.h

// Variáveis globais para controle da animação e posição da câmera
int anguloDir = 0;
int anguloEsq = 0;
bool animacaoAtiva = true;
float posicaoCameraZ = 100.0; // Ajustado para distância maior para caber os cubos maiores
float anguloCameraY = 20.0; // Ângulo de rotação da câmera no eixo Y

// Variáveis para controle do movimento de vai e vem dos cubos
float posicaoVaiVem = 0.0;
bool direcaoVaiVem = true;

void Inicializa() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo como preta
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
        0.0, 1.0, 0.0); // Vetor para cima (direção do eixo Y)

    // Define como os polígonos serão desenhados, no caso front and back,
    // define as faces do polígono, e FILL, define que será totalmente preenchido
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Cubo Amarelo
    glPushMatrix();
    glTranslatef(-13.0, 0.0, 0.0); // Posiciona o cubo na esquerda
    glRotatef(anguloEsq, 0, 1, 0); // Rotação em torno do próprio eixo
    glColor3f(1, 1, 0); // Cor amarela para o cubo
    glutSolidCube(10.0);
    glColor3f(0, 0, 0);
    glutWireCube(10.0);
    glPopMatrix();

    // Cubo Verde
    glPushMatrix();
    glTranslatef(-13.0, -12.1, 0.0); // Posiciona o cubo na esquerda, mais abaixo
    glRotatef(anguloDir, 0, 1, 0); // Rotação em torno do próprio eixo
    glColor3f(0, 1, 0); // Cor verde para o cubo
    glutSolidCube(10.0);
    glColor3f(0, 0, 0);
    glutWireCube(10.0);
    glPopMatrix();

    // Cubo Vermelho
    glPushMatrix();
    glTranslatef(13.0 + posicaoVaiVem, 0.0, 0.0); // Movimento de vai e vem no eixo X
    glColor3f(1, 0, 0); // Cor Vermelho para o cubo
    glutSolidCube(10.0);
    glColor3f(0, 0, 0);
    glutWireCube(10.0);
    glPopMatrix();

    // Cubo Azul
    glPushMatrix();
    glTranslatef(13.0 - posicaoVaiVem, -12.1, 0.0); // Movimento de vai e vem no eixo X, invertido
    glColor3f(0, 0, 1); // Cor Azul para o cubo
    glutSolidCube(10.0);
    glColor3f(0, 0, 0);
    glutWireCube(10.0);
    glPopMatrix();

    glFlush(); // Forca a execucao das chamadas dos metodos
}

// Função chamada toda vez que a janela de visualização é redimensionada
void Reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0); // Aumentado o plano de visualização para acomodar a distância maior
    glMatrixMode(GL_MODELVIEW);
}

// Funcao de animacao
void Anima(int value) {
    if (animacaoAtiva) {
        anguloDir++;
        anguloEsq--;

        // Atualiza a posição de vai e vem dos cubos
        if (direcaoVaiVem) {
            posicaoVaiVem += 1.1;
            if (posicaoVaiVem >= 10.0) direcaoVaiVem = false; // Inverte a direção ao alcançar a posição máxima
        }
        else {
            posicaoVaiVem -= 1.1;
            if (posicaoVaiVem <= -10.0) direcaoVaiVem = true; // Inverte a direção ao alcançar a posição mínima
        }

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
        posicaoCameraZ -= 1.1; // Move a câmera para frente
    }
    else if (key == GLUT_KEY_DOWN) {
        posicaoCameraZ += 1.1; // Move a câmera para trás
    }
    else if (key == GLUT_KEY_LEFT) {
        anguloCameraY -= 0.05; // Gira a câmera para a esquerda
    }
    else if (key == GLUT_KEY_RIGHT) {
        anguloCameraY += 0.05; // Gira a câmera para a direita
    }
    else if (key == GLUT_KEY_HOME) {
        // Retorna a câmera e os cubos para a posição inicial e reinicia a animação
        posicaoCameraZ = 100.0; // Ajustado para a nova distância
        anguloCameraY = 20.0;
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
    glutInitWindowPosition(0, 0); // Define a posição da janela
    glutCreateWindow("Auto Instrucional O1"); // Título da janela
    Inicializa(); // Inicializa a janela limpando o buffer e definindo a cor de fundo
    glutDisplayFunc(Display); // Callback que renderiza o desenho na tela
    glutReshapeFunc(Reshape); // Callback chamada quando a tela será renderizada novamente
    glutTimerFunc(16, Anima, 1); // Inicia a animação
    glutSpecialFunc(TecladoEspecial); // Define a função para capturar teclas especiais
    glutMainLoop(); // Loop contínuo que permite visualização
    return 0;
}
