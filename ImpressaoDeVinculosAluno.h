#ifndef IMPRESSAODEVINCULOSALUNO_H_INCLUDED
#define IMPRESSAODEVINCULOSALUNO_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

void Imprimir_DisciplinasdeUmAluno(DISCIPLINA [], ALUNO [],int , int );

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/

void Imprimir_DisciplinasdeUmAluno(DISCIPLINA TAB_REGISTRO[], ALUNO CAD_alunos[],int Num_alunos_Cadastrados, int Num_disciplinas_Cadastradas)
{
	int auxCodAluno, positAluno, positDisciplina,i, lin = 2;
	int escolha = 1;
	int aux = lin;

	system("cls");
	if (Num_disciplinas_Cadastradas == 0 || Num_alunos_Cadastrados == 0)
	{
		if(Num_disciplinas_Cadastradas == 0 && Num_alunos_Cadastrados == 0)
		{
			LF(9);printf("          NENHUMA DISCIPLINA NEM ALUNO CADASTRADO(A) !");
			delay(2000);
		}
		else
		{
			if(Num_disciplinas_Cadastradas == 0)
			{
				LF(9);printf("          NENHUMA DISCIPLINA CADASTRADA !");
				delay(2000);
			}
			if(Num_alunos_Cadastrados == 0)
			{
				LF(9);printf("          NENHUM ALUNO CADASTRADO !");
				delay(2000);
			}
		}
	}
	else
	{
		do
		{
			Imprimir_Alunos_CAD(CAD_alunos,Num_alunos_Cadastrados);

			printf("\n DIGITE O COD DO ALUNO QUE DESEJA VISUALIZAR E PRESSIONE ENTER: ");
			scanf("%d", &auxCodAluno);
			fflush(stdin);

			positAluno = SearchPositionAlunoByCode(auxCodAluno,CAD_alunos);
			system("cls");

			if(CAD_alunos[positAluno].qtd_disciplinas_cursadas == 0)
			{
				LF(9);printf("          ALUNO NAO VINCULADO A NENHUMA DISCIPLINA");
				LF(2);printf("          DIGITE OUTRO");
				delay(1500);
			}
			if(CAD_alunos[positAluno].ra == 0)
            {
                LF(9);printf("          ALUNO NAO CADASTRADO");
				LF(2);printf("          DIGITE OUTRO");
				delay(1500);
            }
			else if(CAD_alunos[positAluno].qtd_disciplinas_cursadas != 0 && CAD_alunos[positAluno].ra != 0)
			{
				lin = aux;
				gotoxy(lin+=1,0);printf(" ____________________________________________________________");
				gotoxy(lin+=1,0);printf(yellow" |    LISTA DE DISCIPLINAS DE %-30s|"white,CAD_alunos[positAluno].nome);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(yellow" | NOME DA DISCIPLINA                               |  COD  |"white);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");

				for (i = 0; i < MAX; i++)
				{
					if(CAD_alunos[positAluno].cod_disciplinas_cursadas[i] != 0)
					{
						positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,CAD_alunos[positAluno].cod_disciplinas_cursadas[i]);
						gotoxy(lin+=1,0);printf(yellow" | %s",TAB_REGISTRO[positDisciplina].nome);
						gotoxy(lin,52);printf("| %4d  |", CAD_alunos[positAluno].cod_disciplinas_cursadas[i]);
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
                LF(9);printf("          DESEJA VISUALIZAR MAIS UM ALUNO ?");
                LF(2);printf("          1 - SIM");
                LF(1);printf("          2 - NAO");
                scanf("%d", &escolha);
                fflush(stdin);
            }
		}while(escolha != 2);
	}
}
#endif // IMPRESSAODEVINCULOSALUNO_H_INCLUDED
