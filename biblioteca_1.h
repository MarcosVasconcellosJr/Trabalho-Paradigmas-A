///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

/*****************************************************************************/
/**		*	*	*	* DECLARAÇÕES DE VÁRIAVEIS E DEFINES *	*	*	*	*	**/
/*****************************************************************************/

//BIBLIOTECAS DE USO GRAFICO E OPERACIONAL
#include <stdio.h>
#include <conio.h>
#include <windows.h>
//ARQUIVOS DE FUNCOES E PROCEDIMENTOS
#include "tela.h"
//POSSIVEIS TECLAS
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
#define KEY_ENTER 13

/*****************************************************************************/
/**  	*	*	*	*				FERRAMENTAS			*	*	*	*	*	**/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE PULA QUANTAS LINHAS O USUARIO PEDIR
void pulaLinha(int quantasLinhas)
{
	for (int i = 0; i < quantasLinhas; ++i)
	{
		printf("\n");
	}
}
///////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE MOSTRA AO USUARIO UMA SEQUENCIA DE OPCOES DE DIFICULDADE
void menu(int X,int Y)
{
		system("cls");
		gotoxy(X+1,Y);printf(" ÚÄÄÄÄÄÄÄ ESCOLHA O JOGO ÄÄÄÄÄÄ¿\n");
		gotoxy(X+2,Y);printf(" ³                             ³\n");
		gotoxy(X+3,Y);printf(" ³1%c FACIL                    ³\n",248);
		gotoxy(X+4,Y);printf(" ³2%c DIFICIL                  ³\n",248);
		gotoxy(X+5,Y);printf(" ³3%c EXIT                     ³\n",248);
		gotoxy(X+6,Y);printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
}
///////////////////////////////////////////////////////////////////////////////
// LEITURA DE UM CARACTERE NAO BLOQUEANTE PARA AGUARDAR O INICIO DO PROGRAMA
char readNonBlock(){
	if (kbhit()){        // RETORNA VERDADEIRO QUANDO ALGUMA TECLA E PRESSIONONADA
		return getch();
    }return '\0';
}

///////////////////////////////////////////////////////////////////////////////
//PEDE UMA CONFIRMAÇÃO SE O USER DESEJA CONTINUAR
int continua(){

    int continuar;
	scanf("%[SN]", &continuar);
	continuar=toupper(continuar);
	return continuar;
}
/*****************************************************************************/
/**                                                                         **/
/**	*	*	*	*	*			PARTE GRÁFICA			*	*	*	*	*	**/
/**                                                                         **/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//FUNÇÃO PARA DAR EFEITO DE ANIMAÇÃO DE CORES AO PROGRAMA
void piscar_desenho()
{
    textbackground(CIANO_ESCURO);   textcolor(BRANCO);  printf(" ");clrscr();
		printa_tudo(1,1);
    textcolor(BRANCO);
		desenha_grade_qc8(15,20);
		desenha_grade_qc8(15,64);
	delay(400);
	system("cls");
	textcolor(PRETO);
		printa_tudo(1,1);
	textcolor(BRANCO);
		desenha_grade_qc8(15,20);
		desenha_grade_qc8(15,64);
	delay(400);
	system("cls");
}
///////////////////////////////////////////////////////////////////////////////
//TODOS OS PRINTS NUMA SÓ FUNÇÃO
void printa_tudo(int Avisos, int titulo)
{
	if(titulo == 1){
		printf("\n\t    /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$         /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$ ");
		printf("\n\t   | $$__  $$ /$$__  $$ /$$__  $$| $$  | $$ /$$__  $$       /$$__  $$| $$  | $$ /$$__  $$ /$$__  $$");
		printf("\n\t   | $$  \\ $$| $$  \\ $$| $$  \\__/| $$  | $$| $$  \\ $$      | $$  \\__/| $$  | $$| $$  \\__/| $$  \\ $$");
		printf("\n\t   | $$$$$$$/| $$$$$$$$| $$      | $$$$$$$$| $$$$$$$$      | $$      | $$  | $$| $$      | $$$$$$$$");
		printf("\n\t   | $$__  $$| $$__  $$| $$      | $$__  $$| $$__  $$      | $$      | $$  | $$| $$      | $$__  $$");
		printf("\n\t   | $$  \\ $$| $$  | $$| $$    $$| $$  | $$| $$  | $$      | $$    $$| $$  | $$| $$    $$| $$  | $$");
		printf("\n\t   | $$  | $$| $$  | $$|  $$$$$$/| $$  | $$| $$  | $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/| $$  | $$");
		printf("\n\t   |__/  |__/|__/  |__/ \\______/ |__/  |__/|__/  |__/       \\______/  \\______/  \\______/ |__/  |__/");}
	if(Avisos==1){gotoxy(12,43);printf("PARA COMECAR APERTE ENTER");}
	if(Avisos==2){//VITORIA
		delay(400);printf("\n\t\t##    ##  ## ######## ######## ######## ##   ####");
		delay(400);printf("\n\t\t##    ##  ##    ##    ##    ## ##    ## ##  ##  ##");
		delay(400);printf("\n\t\t##    ##  ##    ##    ##    ## ##   ##  ## ##    ##");
		delay(400);printf("\n\t\t ##  ##   ##    ##    ##    ## #####    ## ########");
		delay(400);printf("\n\t\t  ####    ##    ##    ######## ##   ##  ## ##    ##");
		delay(2000);}
	if (Avisos==3){//DERROTA
		delay(400);printf("\n\t\t######    ######## ########  ######## ######## ########   ####");
		delay(400);printf("\n\t\t##    ##  ##       ##    ##  ##    ## ##    ##    ##     ##  ## ");
		delay(400);printf("\n\t\t##    ##  ######   ##   ##   ##   ##  ##    ##    ##    ##    ##");
		delay(400);printf("\n\t\t##    ##  ##       #####     #####    ##    ##    ##    ########");
		delay(400);printf("\n\t\t######    #######  ##   ##   ##   ##  ########    ##    ##    ##");
		delay(2000);}
	if (Avisos == 4){
    	gotoxy(10,40);printf(" ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    	gotoxy(11,40);printf(" ³       DESEJA JOGAR NOVAMENTE ?        ³");
    	gotoxy(12,40);printf(" ³---------------------------------------³");
   	 	gotoxy(13,40);printf(" ³      |  S  |     OU     |  N  |       ³");
   	 	gotoxy(14,40);printf(" ³                                       ³");
    	gotoxy(15,40);printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    	fflush(stdin);  gotoxy(16,55);}
}
///////////////////////////////////////////////////////////////////////////////
//FUNÇÃO QUE SIMULA UM PSEUDO-CARREGAMENTO
void waiting_carregamento(int time)
{
	int i;
	textbackground(CIANO_ESCURO);textcolor(BRANCO);
	char Charging[120]="";

	for(i=0; i<=100; i++)
	{
		if(i%2){strcat(Charging,"Û");}
		system("cls");
		gotoxy(13,20);printf("               ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
		gotoxy(14,20);printf(" CARREGANDO    ³");printf("  %s",Charging);printf("³ %d%% ",i);
		gotoxy(15,20);printf("               ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		delay(time);//Aguarda um tempo
    }
	Sleep(300);/*Aguarda um tempo*/		system("cls");		gotoxy(0,0);/*Volta ao DOS posição inicial*/
}
///////////////////////////////////////////////////////////////////////////////
//FUNÇÃO PARA PRINTAR A GRADE E OS TÍTULOS NA TELA
void desenha_grade(int Linha, int Coluna)
{
	
	//DESENHA O QUADRO
	gotoxy(Linha,Coluna);   printf("\332\304\304\304\304\304\304\304\302\304\304\304\304\304\304\304\302\304\304\304\304\304\304\304\277");
	gotoxy(Linha+1,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+2,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+3,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+4,Coluna); printf("\303\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\264");
	gotoxy(Linha+5,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+6,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+7,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+8,Coluna); printf("\303\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\264");
	gotoxy(Linha+9,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+10,Coluna);printf("\263       \263       \263       \263");
	gotoxy(Linha+11,Coluna);printf("\263       \263       \263       \263");
	gotoxy(Linha+12,Coluna);printf("\300\304\304\304\304\304\304\304\301\304\304\304\304\304\304\304\301\304\304\304\304\304\304\304\331");
}
#endif // BIBLIOTECA_H_INCLUDED
