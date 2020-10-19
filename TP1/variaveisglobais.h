#ifndef VARIAVEISGLOBAIS_H
#define VARIAVEISGLOBAIS_H


GLuint idTexturaFundo,idTexturaLulinha,idTexturaCaninha,idTexturaGado;
GLuint texturaAtual;
float xTextura,yTextura,xPosicaoSprite,xVerticeSprite=325,yCaninha=80,xCaninha=200, ladoCaninha=14;;
float xVerticeGado[8]={10,90,170,250,330,410,490,570},yVerticeGado=500;
int ladoDir=1,ladoEsq=1,direita=0,frames=0,costas=1,primeiraVez=1,tiro=0;
float sinal=0.1;
int ativo[8]={1,1,1,1,1,1,1,1};
int ativo2[7]={1,1,1,1,1,1,1};



#endif
