#ifndef IMPRESSORES_H_INCLUDED
#define IMPRESSORES_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

int Imprimir_Alunos_CAD(ALUNO [], int );
int Imprimir_Professores_CAD(PROFESSOR [], int );
int Imprimir_Disciplinas_CAD(DISCIPLINA [], int );

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/

int Imprimir_Alunos_CAD(ALUNO CAD_alunos[], int Num_alunos_Cadastrados)
{
    int i;
    system("cls");
    printf("\n _________________________________________\n");
    printf(" |       LISTA DE ALUNOS CADASTRADOS     |\n");
    printf(" |---------------------------------------|\n");
    printf(yellow" | NOME COMPLETO                  |  RA  |\n"white);
    printf(" |---------------------------------------|\n");
    for (i = 0; i < Num_alunos_Cadastrados; i++)
    {
        printf(yellow" | %-31s", CAD_alunos[i].nome);
        printf("|%6d|\n", CAD_alunos[i].ra);
    }
    printf(white" |_______________________________________|\n");

    return 0;
}
int Imprimir_Professores_CAD(PROFESSOR CAD_professores[], int Num_professores_Cadastrados)
{
    int i;
    system("cls");
    printf("\n _________________________________________\n");
    printf(" |    LISTA DE PROFESSORES CADASTRADOS   |\n");
    printf(" |---------------------------------------|\n");
    printf(yellow" | NOME COMPLETO                  |  RP  |\n"white);
    printf(" |---------------------------------------|\n");
    for (i = 0; i < Num_professores_Cadastrados; i++)
    {
        printf(yellow" | %-31s", CAD_professores[i].nome);
        printf(yellow"|%6d|\n", CAD_professores[i].rp);
    }
    printf(white" |_______________________________________|\n");

    return 0;
}
int Imprimir_Disciplinas_CAD(DISCIPLINA TAB_REGISTRO[], int Num_disciplinas_Cadastradas)
{
    int i;
    system("cls");
    printf("\n _________________________________________\n");
    printf(" |     LISTA DE DISCIPLINAS CADASTRADAS  |\n");
    printf(" |---------------------------------------|\n");
    printf(yellow" | NOME DA DISCIPLINA             |  COD |\n"white);
    printf(" |---------------------------------------|\n");
    for (i = 0; i < Num_disciplinas_Cadastradas; i++)
    {
        printf(yellow" | %-31s", TAB_REGISTRO[i].nome);
        printf("|%6d|\n", TAB_REGISTRO[i].cod);
    }
    printf(white" |_______________________________________|\n");

    return 0;
}
#endif // IMPRESSORES_H_INCLUDED
