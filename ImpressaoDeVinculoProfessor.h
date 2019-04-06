#ifndef IMPRESSAODEVINCULOPROFESSOR_H_INCLUDED
#define IMPRESSAODEVINCULOPROFESSOR_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

void Imprimir_DisciplinasdeUmProfessor(DISCIPLINA [], PROFESSOR [],int , int );

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/
void Imprimir_DisciplinasdeUmProfessor(DISCIPLINA TAB_REGISTRO[], PROFESSOR CAD_professores[],int Num_professores_Cadastrados, int Num_disciplinas_Cadastradas)
{
	int auxCodProf, positProfessor, positDisciplina,i, lin = 2;
	int escolha = 1;
	int aux = lin;
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
			Imprimir_Professores_CAD(CAD_professores,Num_professores_Cadastrados);

			printf("\n DIGITE O COD DO PROFESSOR QUE DESEJA VISUALIZAR E PRESSIONE ENTER: ");
			scanf("%d", &auxCodProf);
			fflush(stdin);

			positProfessor = SearchPositionProfessorByCode(auxCodProf,CAD_professores);
			system("cls");

			if(CAD_professores[positProfessor].qtd_disciplinas_ministradas == 0)
			{
				LF(9);printf("          PROFESSOR NAO VINCULADO A NENHUMA DISCIPLINA");
				LF(2);printf("          DIGITE OUTRO");
				delay(1500);
			}
			if(CAD_professores[positProfessor].rp == 0)
            {
                LF(9);printf("          PROFESSOR NAO CADASTRADO");
				LF(2);printf("          DIGITE OUTRO");
				delay(1500);
            }
			else if(CAD_professores[positProfessor].qtd_disciplinas_ministradas != 0 && CAD_professores[positProfessor].rp != 0)
			{
				lin = aux;
				gotoxy(lin+=1,0);printf(" ____________________________________________________________");
				gotoxy(lin+=1,0);printf(yellow" |    LISTA DE DISCIPLINAS DE %-30s|"white,CAD_professores[positProfessor].nome);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(yellow" | NOME DA DISCIPLINA                               |  COD  |"white);
				gotoxy(lin+=1,0);printf(" |----------------------------------------------------------|");

				for (i = 0; i < MAX; i++)
				{
					if(CAD_professores[positProfessor].cod_disciplinas_ministradas[i] != 0)
					{
						positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,CAD_professores[positProfessor].cod_disciplinas_ministradas[i]);
						gotoxy(lin+=1,0);printf(yellow" | %s",TAB_REGISTRO[positDisciplina].nome);
						gotoxy(lin,52);printf("| %4d  |", CAD_professores[positProfessor].cod_disciplinas_ministradas[i]);
					}
				}
				gotoxy(lin+=1,0);printf(white" |__________________________________________________________|\n");
				system("pause");
            if(Num_professores_Cadastrados == 1)
            {
                escolha = 2;
            }
			}
            if(Num_professores_Cadastrados > 1)
            {
                system("cls");
                LF(9);printf("          DESEJA VISUALIZAR MAIS UM PROFESSOR ?");
                LF(2);printf("          1 - SIM");
                LF(1);printf("          2 - NAO");
                scanf("%d", &escolha);
                fflush(stdin);
            }
		}while(escolha != 2);
	}
}
#endif // IMPRESSAODEVINCULOPROFESSOR_H_INCLUDED
