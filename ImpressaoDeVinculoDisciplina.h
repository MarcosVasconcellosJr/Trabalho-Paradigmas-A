#ifndef IMPRESSAODEVINCULODISCIPLINA_H_INCLUDED
#define IMPRESSAODEVINCULODISCIPLINA_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

int Imprimir_listaProf_numaDisciplina(DISCIPLINA [], PROFESSOR [], int , int );
void Imprimir_alunosEmDisciplina(DISCIPLINA [], ALUNO [],int , int , int );

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/

int Imprimir_listaProf_numaDisciplina(DISCIPLINA TAB_REGISTRO[], PROFESSOR CAD_professores[], int Num_professores_Cadastrados, int Num_disciplinas_Cadastradas)
{
	int auxCodDisciplina = 0;									///USADA PARA GUARDAR A DISCIPLINA DESEJADA

	int lin = 2;
	int escolha = 1;											///USADO PARA PARAR O FLUXO NO DO WHILE
	int aux = lin;
	int positDisciplina;										///USADA PARA GUARDAR A POSIÇÃO DA DISCIPLINA NO REGISTRO
	int positProfessorT1;										///USADA PARA GUARDAR A POSIÇÃO DO PROFESSOR 1 NO CADASTRO
	int positProfessorT2;										///USADA PARA GUARDAR A POSIÇÃO DO PROFESSOR 2 NO CADASTRO

	if (Num_disciplinas_Cadastradas == 0 || Num_professores_Cadastrados == 0)
	{
		if(Num_disciplinas_Cadastradas == 0 && Num_professores_Cadastrados == 0)
		{
			LF(9);printf("          NENHUMA DISCIPLINA NEM PROFESSOR CADASTRADO(A) !");
			delay(2000);
		}
		else
		{
			if(Num_disciplinas_Cadastradas == 0)
			{
				LF(9);printf("          NENHUMA DISCIPLINA CADASTRADA !");
				delay(2000);
			}
			if(Num_professores_Cadastrados == 0)
			{
				LF(9);printf("          NENHUM PROFESSOR CADASTRADO !");
				delay(2000);
			}
		}
	}
	else
	{
		do
		{
			///IMPRIME AS DISCIPLINAS CADASTRADAS PARA O USUARIO ESCOLHER UMA
			Imprimir_Disciplinas_CAD(TAB_REGISTRO, Num_disciplinas_Cadastradas);

			///PEDE AO USUARIO QUE ESCOLHA UMA DISCIPLINA PELO COD
			printf("\n DIGITE O CODIGO DA DISCIPLINA: ");
			scanf("%d", &auxCodDisciplina);
			fflush(stdin);

			///PROCURA A POSIÇÃO DA DISCIPLINA NO REGISTRO
			positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO, auxCodDisciplina);
			///PROCURA A POSIÇÃO DO PROFESSOR 1 DA TURMA 1 SE EXISTIR, SE NÃO RETORNA (-1)
			positProfessorT1 = SearchPositionProfessorByCode(TAB_REGISTRO[positDisciplina].professores[0][0].rp,CAD_professores);
			///PROCURA A POSIÇÃO DO PROFESSOR 2 DA TURMA 2 SE EXISTIR, SE NÃO RETORNA (-1)
			positProfessorT2 = SearchPositionProfessorByCode(TAB_REGISTRO[positDisciplina].professores[1][0].rp,CAD_professores);
			system("cls");

            if(TAB_REGISTRO[positDisciplina].cod == 0)
            {
                LF(9);printf("          DISCIPLINA NAO CADASTRADA");
				LF(2);printf("          DIGITE OUTRA");
				delay(1500);
            }
			else if(positProfessorT1 != -1 || positProfessorT2 != -1)
			{
				///LISTA OS PROFESSORES VINCULADOS NA DISCIPLINA SOLICITADA
				lin = aux;
				gotoxy(lin+=1,0);printf(" ____________________________________________________________");
		  		gotoxy(lin+=1,0);printf(yellow" |    LISTA DE PROFESSORES EM %-30s|"white,TAB_REGISTRO[positDisciplina].nome);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");
                gotoxy(lin+=1,0);printf(yellow" | NOME DO PROFESSOR                                |  COD  |"white);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");

				if(positProfessorT1 != -1 && CAD_professores[positProfessorT1].rp != 0)
				{
					gotoxy(lin+=1,0);printf(white" | TURMA 1                                                  |");
					gotoxy(lin+=1,0);printf(yellow" | %s",CAD_professores[positProfessorT1].nome);
					gotoxy(lin,52);printf("| %4d  |", CAD_professores[positProfessorT1].rp);
				}

				if(positProfessorT2 != -1 && CAD_professores[positProfessorT2].rp != 0)
				{
					gotoxy(lin+=1,0);printf(white" | TURMA 2                                                  |");
					gotoxy(lin+=1,0);printf(yellow" | %s",CAD_professores[positProfessorT2].nome);
					gotoxy(lin,52);printf("| %4d  |", CAD_professores[positProfessorT2].rp);
				}

				gotoxy(lin+=1,0);printf(white" |__________________________________________________________|\n");
				system("pause");

				system("cls");
                LF(9);printf("          DESEJA VISUALIZAR MAIS UMA DISCIPLINA ?");
                LF(2);printf("          1 - SIM");
                LF(1);printf("          2 - NAO");
                scanf("%d", &escolha);
                fflush(stdin);
			}
			else
			{
				LF(9);printf("          NENHUM PROFESSOR VINCULADO A ESTA DISCIPLINA");
				LF(2);printf("          DIGITE OUTRA DISCIPLINA");
				delay(2000);
			}
		}while(escolha != 2);
	}
	return 0;
}
void Imprimir_alunosEmDisciplina(DISCIPLINA TAB_REGISTRO[], ALUNO CAD_alunos[],int Num_alunos_Cadastrados, int Num_disciplinas_Cadastradas, int turma)
{
	int i;
	int escolheTurma;
	int auxCodDisciplina, positAluno, positDisciplina, lin = 2;
	int escolha = 1;
	int aux = lin;
    int positionCursada = 0;
    int flgSemAluno = 0;

    system("cls");

	if (Num_disciplinas_Cadastradas == 0 || Num_alunos_Cadastrados == 0)
	{
		if(Num_disciplinas_Cadastradas == 0 && Num_alunos_Cadastrados == 0)
		{
		    system("cls");
			LF(9);printf("          NENHUMA DISCIPLINA NEM ALUNO CADASTRADO(A) !");
			delay(2000);
		}
		else
		{
			if(Num_disciplinas_Cadastradas == 0)
			{
			    system("cls");
				LF(9);printf("          NENHUMA DISCIPLINA CADASTRADA !");
				delay(2000);
			}
			if(Num_alunos_Cadastrados == 0)
			{
			    system("cls");
				LF(9);printf("          NENHUM ALUNO CADASTRADO !");
				delay(2000);
			}
		}
	}
	else
	{
		do
		{
			Imprimir_Disciplinas_CAD(TAB_REGISTRO,Num_disciplinas_Cadastradas);

			printf("\n DIGITE O COD DA DISCIPLINA QUE DESEJA VER: ");
			scanf("%d", &auxCodDisciplina);
			fflush(stdin);

			positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO, auxCodDisciplina);
			system("cls");

			if(TAB_REGISTRO[positDisciplina].cod == 0)
            {
                LF(9);printf("          DISCIPLINA NAO CADASTRADA");
				LF(2);printf("          DIGITE OUTRA");
				delay(1500);
            }
            if(turma != 3)
            {
                ///ESCOLHE EM QUAL TURMA VAI VINCULAR O PROFESSOR
                system("cls");LF(9);printf("          EM QUAL TURMA?");LF(2);printf("          1 - TURMA 1");LF(1);printf("          2 - TURMA 2");
                scanf("%d", &turma);fflush(stdin);
            }

			if(TAB_REGISTRO[positDisciplina].cod != 0 && flgSemAluno !=1)
			{
			    system("cls");
				lin = aux;
				gotoxy(lin+=1,0);printf(" ____________________________________________________________");
				gotoxy(lin+=1,0);printf(yellow" |    LISTA DE ALUNOS DE %-30s    |"white, TAB_REGISTRO[positDisciplina].nome);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(yellow" | NOME DO ALUNO                                    |  COD  |"white);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");

				if(turma == 1 || turma == 3)
				{
					gotoxy(lin+=1,0);printf(" | ==> TURMA 1                                              |");
					for (i = 0; i < MAX; i++)
					{
						if(TAB_REGISTRO[positDisciplina].alunos[0][i].ra != 0)
						{
							positAluno = SearchPositionAlunoByCode(TAB_REGISTRO[positDisciplina].alunos[0][i].ra,CAD_alunos);
	                        positionCursada = SearchPositionDisciplinaDeAlunoByCode_Disciplina(TAB_REGISTRO,positAluno,TAB_REGISTRO[positDisciplina].cod);
							gotoxy(lin+=1,0);printf(yellow" | %s",CAD_alunos[positAluno].nome);
							gotoxy(lin,52);printf("| %4d  |", CAD_alunos[positAluno].ra);
						}
					}
				}
				if(turma == 2 || turma == 3)
				{
					gotoxy(lin+=1,0);printf(white" | ==> TURMA 2                                              |");
					for (i = 0; i < MAX; i++)
					{
						if(TAB_REGISTRO[positDisciplina].alunos[1][i].ra != 0)
						{
							positAluno = SearchPositionAlunoByCode(TAB_REGISTRO[positDisciplina].alunos[1][i].ra,CAD_alunos);
	                        positionCursada = SearchPositionDisciplinaDeAlunoByCode_Disciplina(TAB_REGISTRO,positAluno,TAB_REGISTRO[positDisciplina].cod);
							gotoxy(lin+=1,0);printf(yellow" | %s",CAD_alunos[positAluno].nome);
							gotoxy(lin,52);printf("| %4d  |", CAD_alunos[positAluno].ra);
						}
					}
				}

				gotoxy(lin+=1,0);printf(white" |__________________________________________________________|\n");
				system("pause");
                if(Num_alunos_Cadastrados == 1)
                {
                    escolha = 2;
                }
			}
            if(Num_alunos_Cadastrados > 1)
            {
                system("cls");
                LF(9);printf("          DESEJA VISUALIZAR MAIS UMA DISCIPLINA ?");
                LF(2);printf("          1 - SIM");
                LF(1);printf("          2 - NAO");
                scanf("%d", &escolha);
                fflush(stdin);system("cls");
            }
		}while(escolha != 2);
	}
}
#endif // IMPRESSAODEVINCULODISCIPLINA_H_INCLUDED
