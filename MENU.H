#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//void menuzinho(int ,int , int *);

void menuzinho(int X,int Y, int *menu_op)
{
    system("mode con:cols=90 lines=39");///SETA O TAMANHO DO DOS

    gotoxy(X+1,Y);printf(" ___________________               ESCOLHA UMA OPCAO               ___________________");
    gotoxy(X+2,Y);printf(yellow" | -- CADASTROS                                                                      |"white);
    gotoxy(X+3,Y);printf(" |                                                                                   |");
    gotoxy(X+4,Y);printf(" |      1 =>>  CADASTRAR ALUNOS                                                      |");
    gotoxy(X+5,Y);printf(" |      2 =>>  CADASTRAR PROFESSORES                                                 |");
    gotoxy(X+6,Y);printf(" |      3 =>>  CADASTRAR DISCIPLINAS                                                 |");
    gotoxy(X+7,Y);printf(" |                                                                                   |");
    gotoxy(X+8,Y);printf(yellow" | -- IMPRESSAO DE CADASTROS                                                         |"white);
    gotoxy(X+9,Y);printf(" |                                                                                   |");
    gotoxy(X+10,Y);printf(" |      4 =>>  IMPRIMIR ALUNOS CADASTRADOS                                           |");
    gotoxy(X+11,Y);printf(" |      5 =>>  IMPRIMIR PROFESSORES CADASTRADOS                                      |");
    gotoxy(X+12,Y);printf(" |      6 =>>  IMPRIMIR DISCIPLINAS CADASTRADAS                                      |");
    gotoxy(X+13,Y);printf(" |                                                                                   |");
    gotoxy(X+14,Y);printf(yellow" | -- IMPRESSAO VINCULO DE ALUNOS                                                    |"white);
    gotoxy(X+15,Y);printf(" |                                                                                   |");
    gotoxy(X+16,Y);printf(" |      7 =>>  IMPRIMIR A LISTA DE DISCIPLINAS DE UM ALUNO                           |");
    gotoxy(X+17,Y);printf(" |      8 =>>  IMPRIMIR A LISTA DE ALUNOS NUMA DISCIPLINA                            |");
    gotoxy(X+18,Y);printf(" |      9 =>>  IMPRIMIR A LISTA DE ALUNOS NUMA DISCIPLINA POR TURMA                  |");
    gotoxy(X+19,Y);printf(" |                                                                                   |");
    gotoxy(X+20,Y);printf(yellow" | -- IMPRESSAO VINCULO DE PROFESSORES                                               |"white);
    gotoxy(X+21,Y);printf(" |                                                                                   |");
    gotoxy(X+22,Y);printf(" |      10 =>> IMPRIMIR A LISTA DE DISCIPLINAS MINISTRADAS POR UM PROFESSOR          |");
    gotoxy(X+23,Y);printf(" |      11 =>> IMPRIMIR A LISTA DE PROFESSORES VINCULADOS A UMA DISCIPLINA           |");
    gotoxy(X+24,Y);printf(" |                                                                                   |");
    gotoxy(X+25,Y);printf(yellow" | -- GERENCIAMENTO DE MATRICULA DE ALUNOS                                           |"white);
    gotoxy(X+26,Y);printf(" |                                                                                   |");
    gotoxy(X+27,Y);printf(" |      12 =>> MATRICULAR ALUNOS EM DISCIPLINAS                                      |");
    gotoxy(X+28,Y);printf(" |      13 =>> CANCELAR MATRICULA DE ALUNOS EM DISCIPLINAS                           |");
    gotoxy(X+29,Y);printf(" |                                                                                   |");
    gotoxy(X+30,Y);printf(yellow" | -- GERENCIAMENTO DE VINCULO DE PROFESSORES                                        |"white);
    gotoxy(X+31,Y);printf(" |                                                                                   |");
    gotoxy(X+32,Y);printf(" |      14 =>> VINCULAR PROFESSORES A DISCIPLINAS                                    |");
    gotoxy(X+33,Y);printf(" |      15 =>> DESVINCULAR PROFESSORES DE DISCIPLINAS                                |");
    gotoxy(X+34,Y);printf(" | _________________________________________________________________________________ |");
    gotoxy(X+35,Y);printf(" |                                                                                   |");
    gotoxy(X+36,Y);printf(yellow" | ESCOLHA:                                               16 =>> SAIR DA APLICACAO   |"white);
    gotoxy(X+37,Y);printf(" |___________________________________________________________________________________|");

    gotoxy(X+36,Y+12);scanf("%d", menu_op);fflush(stdin);

}

#endif // MENU_H_INCLUDED
