///INCLUDE BIBLIOTECAS PADRÃO DE IN/OUT
#include <stdio.h>
#include <stdlib.h>

///USADA PARA CARACTERÍSTICAS GRÁFICAS
#include "tela.h"

///DEFINES
#define MAX 15
#define MAXNAMES 30

///DEFINE CORES DOS PRINTS
#define white "\033[37m"
#define yellow "\033[33m"

//***********************************    HIERARQUIA    **********************************//
//                                                                                       //
/******************************************************************************************
*                                                                                         *
*                                            /==> NOME                                    *
*                                           /==>  RP                                      *
*                        PROFESSORES[2][MAX]                                              *
*                       /                   \==>  DISCIPLINAS MINISTRADAS[MAX]            *
*                      /                     \==> QUANTIDADE DISCIPLINAS MINISTRADAS      *
*                     /                                                                   *
*                    /==>   NOME                                                          *
*    DISCIPLINA[MAX]                                                                      *
*                    \==>   COD                                                           *
*                     \                                                                   *
*                      \                /==>  NOME                                        *
*                       \              /==>   RA                                          *
*                        ALUNOS[2][MAX]                                                   *
*                                      \==>   DISCIPLINAS CURSADAS[MAX]                   *
*                                       \==>  QUANTIDADE DISCIPLINAS CURSADAS             *
*                                                                                         *
******************************************************************************************/

typedef struct                                          ///ALUNO
{
	char nome[MAXNAMES];                                ///Define o nome do aluno no registro
	int ra;                                             ///Define o RA do aluno no registo
	int cod_disciplinas_cursadas[MAX];                  ///Define quais são as disciplinas que este aluno está matriculado
	int qtd_disciplinas_cursadas;                       ///Guarda a informação de qtd para poder recuperar mais tarde nos prints
} ALUNO;
typedef struct                                          ///PROFESSOR
{
	char nome[MAXNAMES];                                ///Define o nome do professor no registro
	int rp;                                            	///Define qual o codigo do respectivo professor
	int cod_disciplinas_ministradas[MAX];               ///Define quais são as disciplinas que este professor ministra
	int qtd_disciplinas_ministradas;                    ///Guarda a informação de qtd para poder recuperar mais tarde nos prints
} PROFESSOR;
typedef struct                                          ///DISCIPLINA
{
	char nome[MAXNAMES];                                ///Define o nome da disciplina no registro
	int cod;                                            ///Define o cod da disciplina no registro
	ALUNO alunos[2][MAX];                               ///Posição [t1][x] do vetor T1 === Posição [t2][x] do vetor T2
	PROFESSOR professores[2][1];                        ///Posição [t1][x] do vetor T1 === Posição [t2][x] do vetor T2
} DISCIPLINA;

///Utilizada para fazer diversos tipos de buscas, seja em vetores,
///em vetores de struct, matrizes e Etc...
#include "Buscas.h"

///Todos os cadastros de (Alunos, Professores, Disciplinas) constam neste arquivo...
#include "Cadastros.h"

///Usada para matricular e desmatricular alunos...
#include "GerenciamentoDeAlunos.h"

///Usada para vincular e desvincular professores de disciplinas...
#include "GerenciamentoDeProfessores.h"

///Usada para imprimir os cadastros de (Alunos, Professores, Disciplinas)...
#include "ImpressaoDeCadastros.h"

///Descreve o menu e solicitação de um codigo de escolha de opção...
#include "MENU.H"

///Impressoes solicitadas na ementa do trabalho
#include "ImpressaoDeVinculosAluno.h"
#include "ImpressaoDeVinculoDisciplina.h"
#include "ImpressaoDeVinculoProfessor.h"

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

void carregamentoInicialStructs(ALUNO[], PROFESSOR[], DISCIPLINA[]);
void waiting_carregamento(int , int , int , int );

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/
void carregamentoInicialStructs(ALUNO CAD_alunos[], PROFESSOR CAD_professores[], DISCIPLINA TAB_REGISTRO[])
{
	int i,j;

	for(i=0; i<MAX; i++)
	{
	    ///ZERA OS CADASTROS DE PROFESSORES (COD)
		CAD_professores[i].rp = 0;
		///ZERA OS CADASTROS DE ALUNOS (RA)
		CAD_alunos[i].ra = 0;
		///ZERA OS CADASTROS DE DISCIPLINAS (COD)
		TAB_REGISTRO[i].cod = 0;
		///ZERA O COD DE PROFESSORES VINCULADOS NAS DISCIPLINAS
		TAB_REGISTRO[i].professores[0][0].rp = 0;
		TAB_REGISTRO[i].professores[1][0].rp = 0;
		///ZERA A QUANTIDADE DE DISCIPLINAS CURSADAS NO CADASTRO (ALUNOS)
        CAD_alunos[i].qtd_disciplinas_cursadas = 0;
        ///ZERA A QUANIDADE DE DISCIPLINAS MINISTRADAS NO CADASTRO (PROF)
        CAD_professores[i].qtd_disciplinas_ministradas = 0;

		for (j = 0; j < MAX; j++)
		{
			///ZERA OS COD DISCIPLINAS CURSADAS NO CADASTRO
			CAD_alunos[i].cod_disciplinas_cursadas[j] = 0;
			///ZERA AS DISCIPLINAS MINISTRADAS NO CADASTRO
			CAD_professores[i].cod_disciplinas_ministradas[j] = 0;
			///ZERA OS COD CURSADOS NO REGISTRO
			TAB_REGISTRO[i].alunos[0][j].ra = 0; ///TURMA 1
			TAB_REGISTRO[i].alunos[1][j].ra = 0; ///TURMA 2
		}
	}
}
void waiting_carregamento(int time, int lin, int col, int helloORbye)
{
	int i;
	char Charging[120]="";
	int aux = lin;

	for(i=0; i<=100; i++)
	{
		lin = aux;
		if(i%2)
		{
			strcat(Charging,"=");
		}
		if(helloORbye == 1)
        {
            gotoxy(lin,col+5);	printf("  ____  ______ __  __  __      _______ _   _ _____   ____  ");
            gotoxy(lin+1,col+5);printf(" |  _ \\|  ____|  \\/  | \\ \\    / /_   _| \\ | |  __ \\ / __ \\ ");
            gotoxy(lin+2,col+5);printf(" | |_) | |__  | \\  / |  \\ \\  / /  | | |  \\| | |  | | |  | |");
            gotoxy(lin+3,col+5);printf(" |  _ <|  __| | |\\/| |   \\ \\/ /   | | | . ` | |  | | |  | |");
            gotoxy(lin+4,col+5);printf(" | |_) | |____| |  | |    \\  /   _| |_| |\\  | |__| | |__| |");
            gotoxy(lin+5,col+5);printf(" |____/|______|_|  |_|     \\/   |_____|_| \\_|_____/ \\____/ ");
        }
        if(helloORbye == 2)
        {
        	gotoxy(lin,col+5);	printf("                           __");
        	gotoxy(lin+1,col+5);printf("                          /_/");
        	gotoxy(lin+2,col+5);printf("           _______   ______     _         ____     _____    ____");
			gotoxy(lin+3,col+5);printf("     /\\   |__   __| |  ____|   | |       / __ \\   / ____|  / __ \\ ");
			gotoxy(lin+4,col+5);printf("    /  \\     | |    | |__      | |      | |  | | | |  __  | |  | | ");
			gotoxy(lin+5,col+5);printf("   / /\\ \\    | |    |  __|     | |      | |  | | | | |_ | | |  | | ");
			gotoxy(lin+6,col+5);printf("  / ____ \\   | |    | |____    | |____  | |__| | | |__| | | |__| | ");
			gotoxy(lin+7,col+5);printf(" /_/    \\_\\  |_|    |______|   |______|  \\____/   \\_____|  \\____/ ");


        }
		gotoxy(lin+13,col);printf("               \332\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
		if(helloORbye == 1){gotoxy(lin+14,col);printf(" CARREGANDO    ");printf(yellow"  %s",Charging);printf("%d %%",i);}
		if(helloORbye == 2){gotoxy(lin+14,col);printf("   SALVANDO    ");printf(yellow"  %s",Charging);printf("%d %%",i);}
		gotoxy(lin+15,col);printf(white"               \300\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331");
		delay(time);///Aguarda um tempo
	}
	Sleep(500);/**Aguarda um tempo**/     system("cls");
	gotoxy(0,0);/**Volta ao DOS posição inicial**/
}
void main()
{
    system("COLOR 0E");
    waiting_carregamento(50,4,5,1);


	///VETORES INTERMEDIÁRIOS PARA USO TEMPORÁRIO (AUX) NO VINCULO DE PROFESSORES E ALUNOS
	int Vet_Interm_Cad_Alunos[15], Vet_Interm_Cad_Professores[15], Vet_Interm_Cad_Disciplinas[15];

	///VARIÁVEIS QUE INDICAM A QUANTIDADE DE "XXXX" JÁ CADASTRADOS
	int Num_alunos_Cadastrados = 0, Num_disciplinas_Cadastradas = 0, Num_professores_Cadastrados = 0;

	///VARIAVEL PARA USO DO SWITCH CASE DO MENU INICIAL DE OPÇÕES
	int menu_op = 0;

	///VETORES DE STRUCTS USADOS PARA SALVAR O CADASTRO DE "XXX" PARA USO
	ALUNO CAD_alunos[MAX];
	PROFESSOR CAD_professores[MAX];
	DISCIPLINA TAB_REGISTRO[MAX];

	///INICIA AS STRUCTS COM VALOR ZERO (0)
	carregamentoInicialStructs(CAD_alunos,CAD_professores,TAB_REGISTRO);
	system("cls");

	do
	{
		menuzinho(0,0, &menu_op);
		system("cls");
		fflush(stdin);
		switch (menu_op)
		{
			case 1:Cadastrar_Alunos(CAD_alunos, &Num_alunos_Cadastrados);break;

			case 2:Cadastrar_Professores(CAD_professores, &Num_professores_Cadastrados);break;

			case 3:Cadastrar_Disciplinas(TAB_REGISTRO, &Num_disciplinas_Cadastradas);break;

			case 4:Imprimir_Alunos_CAD(CAD_alunos, Num_alunos_Cadastrados);system("pause");break;

			case 5:Imprimir_Professores_CAD(CAD_professores, Num_professores_Cadastrados);system("pause");break;

			case 6:Imprimir_Disciplinas_CAD(TAB_REGISTRO, Num_disciplinas_Cadastradas);system("pause");break;

			case 7:Imprimir_DisciplinasdeUmAluno(TAB_REGISTRO,CAD_alunos,Num_alunos_Cadastrados,Num_disciplinas_Cadastradas);break;

			case 8:Imprimir_alunosEmDisciplina(TAB_REGISTRO,CAD_alunos,Num_alunos_Cadastrados,Num_disciplinas_Cadastradas,3);break;

			case 9:Imprimir_alunosEmDisciplina(TAB_REGISTRO,CAD_alunos,Num_alunos_Cadastrados,Num_disciplinas_Cadastradas,1);break;

			case 10:Imprimir_DisciplinasdeUmProfessor(TAB_REGISTRO, CAD_professores, Num_professores_Cadastrados,Num_disciplinas_Cadastradas);break;

			case 11:Imprimir_listaProf_numaDisciplina(TAB_REGISTRO,CAD_professores,Num_professores_Cadastrados,Num_disciplinas_Cadastradas);break;

			case 12:Vincular_Alunos_a_Disciplinas(CAD_alunos,TAB_REGISTRO,Vet_Interm_Cad_Alunos,Vet_Interm_Cad_Disciplinas,Num_alunos_Cadastrados,Num_disciplinas_Cadastradas,1);break;

			case 13:Vincular_Alunos_a_Disciplinas(CAD_alunos,TAB_REGISTRO,Vet_Interm_Cad_Alunos,Vet_Interm_Cad_Disciplinas,Num_alunos_Cadastrados,Num_disciplinas_Cadastradas,2);break;

			case 14:Vincular_Professores_a_Disciplinas(CAD_professores,TAB_REGISTRO,Vet_Interm_Cad_Professores,Vet_Interm_Cad_Disciplinas,Num_professores_Cadastrados,Num_disciplinas_Cadastradas,1);break;

			case 15:Vincular_Professores_a_Disciplinas(CAD_professores,TAB_REGISTRO,Vet_Interm_Cad_Professores,Vet_Interm_Cad_Disciplinas,Num_professores_Cadastrados,Num_disciplinas_Cadastradas,2);break;
		}
	}while(menu_op != 16);
	system("cls");
	waiting_carregamento(50,4,5,2);
	system("cls");
}
