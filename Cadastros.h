#ifndef CADASTROS_H_INCLUDED
#define CADASTROS_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

void Cadastrar_Alunos(ALUNO [], int *);
void Cadastrar_Disciplinas(DISCIPLINA [], int *);
void Cadastrar_Professores(PROFESSOR [], int *);

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/

void Cadastrar_Alunos(ALUNO CAD_alunos[], int *Num_alunos_Cadastrados)
{
    int escolha = 1;

    if ((*Num_alunos_Cadastrados) == 15)
    {
        system("mode con:cols=50 lines=20");            //SETA O TAMANHO DO DOS
        MessageBox(0, "Numero máximo de alunos cadastrados atingido!", "Impossível cadastrar", MB_OK | MB_ICONINFORMATION);
    }

    fflush(stdin);

    while ((*Num_alunos_Cadastrados) < MAX && escolha != 2)
    {
        CAD_alunos[(*Num_alunos_Cadastrados)].ra = (*Num_alunos_Cadastrados) + 1;
        system("cls");
        gotoxy(1, 0);printf(" _______________________________________________________");
        gotoxy(2, 0);printf(" |                CADASTRO DE ALUNOS                  |");
        gotoxy(3, 0);printf(" |----------------------------------------------------|");
        gotoxy(4, 0);printf(" | DIGITE O NOME DO ALUNO %d: ", (*Num_alunos_Cadastrados) + 1);
        gotoxy(4, 54);printf("|");
        gotoxy(5, 0);printf(" |                                                    |");
        gotoxy(6, 0);printf(" |____________________________________________________|");
        gotoxy(4, 29);scanf("%30[^\n]s", CAD_alunos[(*Num_alunos_Cadastrados)].nome);
        fflush(stdin);system("cls");

        (*Num_alunos_Cadastrados)++;

        if((*Num_alunos_Cadastrados) < MAX)
        {
            gotoxy(1, 0);printf(" _______________________________________________________");
            gotoxy(2, 0);printf(" |                CADASTRO DE ALUNOS                  |");
            gotoxy(3, 0);printf(" |----------------------------------------------------|");
            gotoxy(4, 0);printf(" | DESEJA CADASTRAR MAIS UM ALUNO ?                   |");
            gotoxy(5, 0);printf(" | 1 - SIM                                            |");
            gotoxy(6, 0);printf(" | 2 - NAO                                            |");
            gotoxy(7, 0);printf(" |____________________________________________________|");
            gotoxy(6, 10);scanf("%d", &escolha);
            fflush(stdin);
        }
    }
}
void Cadastrar_Professores(PROFESSOR CAD_professores[], int *Num_professores_Cadastrados)
{
    int escolha = 1;

    if ((*Num_professores_Cadastrados) == 15)
    {
        system("mode con:cols=50 lines=20");            //SETA O TAMANHO DO DOS
        MessageBox(0, "Numero máximo de professores cadastrados atingido!", "Impossível cadastrar", MB_OK | MB_ICONINFORMATION);
    }

    while ((*Num_professores_Cadastrados) < MAX && escolha != 2)
    {
        fflush(stdin);
        CAD_professores[(*Num_professores_Cadastrados)].rp = (*Num_professores_Cadastrados) + 1;

        system("cls");

        gotoxy(1, 0);printf(" ___________________________________________________________");
        gotoxy(2, 0);printf(" |                CADASTRO DE PROFESSORES                 |");
        gotoxy(3, 0);printf(" |--------------------------------------------------------|");
        gotoxy(4, 0);printf(" | DIGITE O NOME DO PROFESSOR %d: ", CAD_professores[(*Num_professores_Cadastrados)].rp);
        gotoxy(4, 58);printf("|");
        gotoxy(5, 0);printf(" |                                                        |");
        gotoxy(6, 0);printf(" |________________________________________________________|");
        gotoxy(4, 33);scanf("%30[^\n]s", CAD_professores[(*Num_professores_Cadastrados)].nome);
        fflush(stdin);system("cls");

        (*Num_professores_Cadastrados)++;
        if((*Num_professores_Cadastrados) < MAX)
        {
            gotoxy(1, 0);printf(" _______________________________________________________");
            gotoxy(2, 0);printf(" |              CADASTRO DE PROFESSORES               |");
            gotoxy(3, 0);printf(" |----------------------------------------------------|");
            gotoxy(4, 0);printf(" | DESEJA CADASTRAR MAIS UM PROFESSOR ?               |");
            gotoxy(5, 0);printf(" | 1 - SIM                                            |");
            gotoxy(6, 0);printf(" | 2 - NAO                                            |");
            gotoxy(7, 0);printf(" |____________________________________________________|");
            gotoxy(6, 10);scanf("%d", &escolha);
            fflush(stdin);
        }
    }
}
void Cadastrar_Disciplinas(DISCIPLINA TAB_REGISTRO[], int *Num_disciplinas_Cadastradas)
{
    int escolha = 1;

    if ((*Num_disciplinas_Cadastradas) == 15)
    {
        system("mode con:cols=50 lines=20");            //SETA O TAMANHO DO DOS
        MessageBox(0, "Numero máximo de disciplinas cadastradas atingido!", "Impossível cadastrar", MB_OK | MB_ICONINFORMATION);
    }

    fflush(stdin);

    while ((*Num_disciplinas_Cadastradas) < MAX && escolha != 2)
    {

        TAB_REGISTRO[(*Num_disciplinas_Cadastradas)].cod = (*Num_disciplinas_Cadastradas) + 1;
        system("cls");

        gotoxy(1, 0);printf(" ____________________________________________________________");
        gotoxy(2, 0);printf(" |                   CADASTRO DE DISCIPLINAS                |");
        gotoxy(3, 0);printf(" |----------------------------------------------------------|");
        gotoxy(4, 0);printf(" | DIGITE O NOME DA DISCIPLINA %d: ", TAB_REGISTRO[(*Num_disciplinas_Cadastradas)].cod);
        gotoxy(4, 60);printf("|");
        gotoxy(5, 0);printf(" |                                                          |");
        gotoxy(6, 0);printf(" |__________________________________________________________|");
        gotoxy(4, 34);scanf("%30[^\n]s", TAB_REGISTRO[(*Num_disciplinas_Cadastradas)].nome);
        fflush(stdin);system("cls");

        (*Num_disciplinas_Cadastradas)++;

        if((*Num_disciplinas_Cadastradas) < MAX)
        {
            gotoxy(1, 0);printf(" ____________________________________________________________");
            gotoxy(2, 0);printf(" |                   CADASTRO DE DISCIPLINAS                |");
            gotoxy(3, 0);printf(" |----------------------------------------------------------|");
            gotoxy(4, 0);printf(" | DESEJA CADASTRAR MAIS UMA DISCIPLINA ?                   |");
            gotoxy(5, 0);printf(" | 1 - SIM                                                  |");
            gotoxy(6, 0);printf(" | 2 - NAO                                                  |");
            gotoxy(7, 0);printf(" |__________________________________________________________|");
            gotoxy(6, 10);scanf("%d", &escolha);
            fflush(stdin);
        }
    }
}
#endif // CADASTROAS_H_INCLUDED
