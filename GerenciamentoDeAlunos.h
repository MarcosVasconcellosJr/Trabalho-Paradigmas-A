#ifndef GERENCIAMENTODEALUNOS_H_INCLUDED
#define GERENCIAMENTODEALUNOS_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

int Vincular_Alunos_a_Disciplinas(ALUNO [], DISCIPLINA [], int [], int [], int , int , int );
void Desvincular_aluno(DISCIPLINA [], ALUNO [], int , int , int , int , int );

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/
int Vincular_Alunos_a_Disciplinas(ALUNO CAD_alunos[], DISCIPLINA TAB_REGISTRO[], int Vet_Interm_Cad_Alunos[], int Vet_Interm_Cad_Disciplinas[], int Num_alunos_Cadastrados, int Num_disciplinas_Cadastradas, int flgVinc_Desvinc)
{
	system("mode con:cols=80 lines=30");        ///SETA O TAMANHO DO DOS

	int escolha;                                ///USADA PARA SAIR DO (DO WHILE)
	int escolheTurma;                           ///USADA PARA SELECIONAR (T1 ou T2)

	int ChkCadastrado_Aluno;                    ///FLAG QUE INDICA SE DETERMINADO ALUNO      ESTA CADASTRADO
	int ChkCadastrada_disciplina;               ///FLAG QUE INDICA SE DETERMINADA DISCIPLINA ESTA CADASTRADA

	int ChkCadastrado_AlunoIntermediario;       ///FLAG DIZ SE O ALUNO      JÁ FOI LISTADO NO CONJUNTO
	int ChkCadastrada_disciplinaIntermediario;  ///FLAG DIZ SE A DISCIPLINA JÁ FOI LISTADA NO CONJUNTO

	int auxiliar_Cad_CodAluno;                  ///VARIAVEL GUARDA codAluno         ANTES DE LISTAR NO CONJUNTO
	int auxiliar_Cad_CodDisciplina;             ///VARIAVEL GUARDA codDisciplina    ANTES DE LISTAR NO CONJUNTO

	int flgAchouespacoVetor;                    ///QUANDO ACHA ESPAÇO VINCULA DISCIPLINA NO VETOR DE DISCIPLINAS DE ALUNO
	int flgQtdMax = 0;
	int i1;                                     ///
	int i2;                                     ///
	int lin = 2;                                ///
	int j;                                      ///
	int i;                                      ///ITERADOR COMUM AOS FOR DO SISTEMA (USO VÁRIAS VEZES QUANDO VOU ATIVAR FLAGS)
	int l;                                      ///PRECISO DE MAIS UM ITERADOR PARA DESCOBRIR ONDE ESTÁ OS NOMES NO REGISTRO
    int equal;
	int positDisciplina;                        ///CONSIGO A POSIÇÃO DO REGISTRO GERAL DO CADASTRO DAQUELA DISCIPLINA
	int positAluno;                             ///CONSIGO A POSIÇÃO NO CADASTRO CAD_alunos DAQUELE ALUNO
	int flgAchouAluno_REG;
	//int aluno_desvinculado;                      ///VAR AUXILIAR PARA GUARDAR A POSIÇÃO DO ALUNO A SER DESVINCULADO

	int vet_AlunosDesvinculados[15][15];        ///GUARDO PARA MOSTRAR AO USUARIO QUAIS ALUNOS
												///FORAM DESVINCULADOS E DE QUAIS DISCIPLINAS

	if (Num_disciplinas_Cadastradas == 0 || Num_alunos_Cadastrados == 0)
	{
		if(Num_disciplinas_Cadastradas == 0 && Num_alunos_Cadastrados == 0)
		{
			LF(9);printf("          NENHUMA DISCIPLINA NEM ALUNO CADASTRADO(A) !");delay(2000);
		}
		else{
			if(Num_disciplinas_Cadastradas == 0){LF(9);printf("          NENHUMA DISCIPLINA CADASTRADA !");delay(2000);}
			if(Num_alunos_Cadastrados == 0){LF(9);printf("          NENHUM ALUNO CADASTRADO !");delay(2000);}
		}
	}
	else
	{

		i1 = 0, i2 = 0;
		i = 0, j = 0;
		escolha = 1,escolheTurma = 0;
		ChkCadastrado_Aluno = 0, ChkCadastrada_disciplina = 0;
		ChkCadastrado_AlunoIntermediario = 0, ChkCadastrada_disciplinaIntermediario = 0;
		flgAchouespacoVetor = 0;

		//INICIA O VETOR INTERMEDIÁRIO COM ZERO
		for(i = 0 ; i < MAX ; i++)
        {
			Vet_Interm_Cad_Alunos[i] = 0;
			Vet_Interm_Cad_Disciplinas[i] = 0;
			for(j=0; j < MAX; j++){vet_AlunosDesvinculados[i][j] = 0;}
		}
		do
		{
			ChkCadastrado_AlunoIntermediario = 0;
			ChkCadastrado_Aluno = 0;

			system("cls");
			Imprimir_Alunos_CAD(CAD_alunos, Num_alunos_Cadastrados);

			printf("\nPARA SAIR DIGITE (-1)");
			if(flgVinc_Desvinc == 1){ printf("\nDIGITE O RA DO ALUNO QUE DESEJA VINCULAR: ");}
			if(flgVinc_Desvinc == 2){ printf("\nDIGITE O RA DO ALUNO QUE DESEJA DESVINCULAR: ");}
			scanf("%d", &auxiliar_Cad_CodAluno);
			fflush(stdin);

			if(auxiliar_Cad_CodAluno == -1){return 0;}
			else if(auxiliar_Cad_CodAluno != 0)
			{
				///VERIFICA SE O COD DO ALUNO EXISTE
				for(j = 0 ; j < Num_alunos_Cadastrados ; j++){
					if(CAD_alunos[j].ra == auxiliar_Cad_CodAluno){
						ChkCadastrado_Aluno = 1;///FLAG QUE DIZ SE O ALUNO EXISTE NO CADASTRO
					}
				}
				///VERIFICA SE O ALUNO JÁ NÃO FOI LISTADO PARA VINCULAR COM DISCIPLINA
				for(i = 0 ; i < i1 ; i++){
					if(Vet_Interm_Cad_Alunos[i] == auxiliar_Cad_CodAluno){
						ChkCadastrado_AlunoIntermediario = 1;///FLAG DE VERIFICAÇÃO SE JÁ FOI LISTADO NO CONJUNTO
					}
				}
				if(ChkCadastrado_Aluno != 1){
					system("cls");LF(9);printf("          ALUNO NAO CADASTRADO");LF(2);printf("          DIGITE OUTRO");LF(1);printf("          AGUARDE...");delay(1500);
				}
				else if(ChkCadastrado_AlunoIntermediario == 1){
					system("cls");LF(9);printf("          ALUNO JA LISTADO");LF(2);printf("          DIGITE OUTRO");LF(1);printf("          AGUARDE...");delay(1500);
				}
				else if(ChkCadastrado_Aluno == 1 && ChkCadastrado_AlunoIntermediario != 1){
					Vet_Interm_Cad_Alunos[i1] = auxiliar_Cad_CodAluno;
					i1++;
					system("cls");
					if(i1 < Num_alunos_Cadastrados){
						LF(9);printf("          DESEJA LISTAR MAIS UM ALUNO?");LF(2);printf("          1 - SIM");LF(1);printf("          2 - NAO");
						scanf("%d", &escolha);fflush(stdin);
					}
				}
			}
		}
		while( i1 < Num_alunos_Cadastrados && escolha == 1);

		escolha = 1;

		do
		{
			system("cls");
			Imprimir_Disciplinas_CAD(TAB_REGISTRO, Num_disciplinas_Cadastradas);
			printf("\nPARA SAIR DIGITE (-1)");
			printf("\nEM QUAIS DISCIPLINAS? DIGITE O COD: ");
			scanf("%d", &auxiliar_Cad_CodDisciplina);
			fflush(stdin);

			if(auxiliar_Cad_CodDisciplina == -1){return 0;}
			else if(auxiliar_Cad_CodDisciplina != 0)
			{
				///VERIFICA SE O COD DA DISCIPLINA EXISTE
				for(j = 0 ; j < MAX ; j++){
					if(TAB_REGISTRO[j].cod == auxiliar_Cad_CodDisciplina){
						ChkCadastrada_disciplina = 1;///FLAG QUE DIZ SE A DISCIPLINA EXISTE NO CADASTRO
					}
				}
				///VERIFICA SE A DISCIPLINA JÁ NÃO FOI LISTADA PARA VINCULAR COM ALUNO
				for(i = 0 ; i < MAX ; i++){
					if(Vet_Interm_Cad_Disciplinas[i] == auxiliar_Cad_CodDisciplina){
						ChkCadastrada_disciplinaIntermediario = 1;///FLAG DE VERIFICAÇÃO DE CADASTRO
					}
				}
				if(ChkCadastrada_disciplina != 1 ){
					system("cls");LF(9);printf("          DISCIPLINA NAO CADASTRADA");LF(2);printf("          DIGITE OUTRA");LF(1);printf("          AGUARDE...");delay(1500);
				}
				else if(ChkCadastrada_disciplinaIntermediario == 1){
					system("cls");LF(9);printf("          DISCIPLINA JA LISTADA");LF(2);printf("          DIGITE OUTRA");LF(1);printf("          AGUARDE...");delay(1500);
				}
				else if(ChkCadastrada_disciplina == 1 && ChkCadastrada_disciplinaIntermediario != 1){
					///JOGA NO VETOR INTERMEDIÁRIO SE EXISTIR NO CADASTRO
					Vet_Interm_Cad_Disciplinas[i2] = auxiliar_Cad_CodDisciplina;
					i2++;
					if(i2 < Num_disciplinas_Cadastradas){
						system("cls");LF(9);printf("          DESEJA LISTAR MAIS UMA DISCIPLINA?");LF(2);printf("          1 - SIM");LF(1);printf("          2 - NAO");
						scanf("%d", &escolha);fflush(stdin);
					}
				}
			}
			ChkCadastrada_disciplinaIntermediario = 0;
			ChkCadastrada_disciplina = 0;
		}
		while(i2 < Num_disciplinas_Cadastradas && escolha == 1);

		///ESCOLHE EM QUAL TURMA VAI VINCULAR O ALUNO
		system("cls");LF(9);printf("          EM QUAL TURMA?");LF(2);printf("          1 - TURMA 1");LF(1);printf("          2 - TURMA 2");
		scanf("%d", &escolheTurma);fflush(stdin);

		j=0;
		int k = 0;
		positDisciplina = 0;
		positAluno = 0;
		int positVetAlunos = 0;
		int flgDesvinculou = 0;
		int flgCadastrado_T_diferente = 0;

		if(escolheTurma == 1 && flgVinc_Desvinc == 1)
		{
			system("cls");
			///ITERADOR DE DISCIPLINA 1 A 15
			for (j = 0; j < i2; j++)
			{
				///PROCURA A DISCIPLINA NO REGISTRO GERAL
				positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[j]);

				for(k=0; k < i1; k++)
				{
					/*****************************************************************************/
					/**     *   *   *   *   VINCULA ALUNO EM DISCIPLINA  *  *   *   *   *       **/
					/*****************************************************************************/

					///VERIFICA SE O ALUNO NÃO ATINGIU O MÁXIMO DE DISCIPLINAS CURSADAS;
					positAluno = SearchPositionAlunoByCode(Vet_Interm_Cad_Alunos[k],CAD_alunos);

					if(CAD_alunos[positAluno].qtd_disciplinas_cursadas == 15)
					{
						system("cls");LF(9);printf("          ALUNO %s JA CURSA 15 DISCIPLINAS ! \nNAO VINCULADO",CAD_alunos[positAluno].nome);LF(1);printf("          AGUARDE...");delay(3000);
						flgQtdMax = 1;

					}
					for(l=0;l<MAX;l++)
					{
						if(Vet_Interm_Cad_Alunos[k] == TAB_REGISTRO[positDisciplina].alunos[1][l].ra)
						{
							system("cls");LF(9);printf("          O ALUNO %s JA ESTA CADASTRADO NA DISCIPLINA %s",CAD_alunos[positAluno].nome,TAB_REGISTRO[positDisciplina].nome);LF(1);printf("          TURMA 2");LF(1);printf("          NAO SERA VINCULADO");delay(3000);
							flgCadastrado_T_diferente = 1;
						}
					}

					if(flgQtdMax != 1 && flgCadastrado_T_diferente != 1)
					{
						positVetAlunos = searchFreeSpaceAlunos_REG(TAB_REGISTRO,1,positDisciplina);
						if(positVetAlunos != -1)
						{
							///JÁ QUE NÃO HÁ NINGUÉM CADASTRADO (== 0) VINCULA O ALUNO QUE FOI SOLICITADO
							TAB_REGISTRO[positDisciplina].alunos[0][positVetAlunos].ra = Vet_Interm_Cad_Alunos[k];

							/*****************************************************************************/
							/**    *   *   *   * VINCULA DISCIPLINA EM ALUNO(CAD) *  *   *   *  *       **/
							/*****************************************************************************/

							///INCREMENTA ANTES DE ENTRAR NO FOR PARA PROCURAR ESPAÇO NAS DISCIPLINAS CADASTRADAS
							CAD_alunos[positAluno].qtd_disciplinas_cursadas += 1;

							///PROCURA O ALUNO NO CADASTRO PELO RA DELE
							positAluno = SearchPositionAlunoByCode(Vet_Interm_Cad_Alunos[k],CAD_alunos);
							flgAchouespacoVetor = 0;

							///PROCURA ESPAÇO PARA CADASTRAR A DISCIPLINA COMO (CURSADA) PELO ALUNO (positALUNO)
							for (l = 0; l < CAD_alunos[positAluno].qtd_disciplinas_cursadas; l++)
							{
								if(flgAchouespacoVetor != 1)
								{
									///SE HOUVER ESPACO ELE ENTAO VINCULA NESSE VETOR O CODIGO INTERMEDIARIO///
									if(CAD_alunos[positAluno].cod_disciplinas_cursadas[l] == 0)
									{
										CAD_alunos[positAluno].cod_disciplinas_cursadas[l] = Vet_Interm_Cad_Disciplinas[j];
										flgAchouespacoVetor = 1;
									}
								}
							}
							flgQtdMax = 0;
						}
					}
				}
			}
		}
		if(escolheTurma == 2 && flgVinc_Desvinc == 1)
		{
			system("cls");
			///ITERADOR DE DISCIPLINA 1 A 15
			for (j = 0; j < i2; j++)
			{
				///PROCURA A DISCIPLINA NO REGISTRO GERAL
				positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[j]);

				for(k=0; k < i1; k++)
				{
					/*****************************************************************************/
					/**     *   *   *   *   VINCULA ALUNO EM DISCIPLINA  *  *   *   *   *       **/
					/*****************************************************************************/

					///VERIFICA SE O ALUNO NÃO ATINGIU O MÁXIMO DE DISCIPLINAS CURSADAS;
					positAluno = SearchPositionAlunoByCode(Vet_Interm_Cad_Alunos[k],CAD_alunos);

					if(CAD_alunos[positAluno].qtd_disciplinas_cursadas == 15)
					{
						system("cls");LF(9);printf("          ALUNO %s JA CURSA 15 DISCIPLINAS ! \nNAO VINCULADO",CAD_alunos[positAluno].nome);LF(1);printf("          AGUARDE...");delay(3000);
						flgQtdMax = 1;

					}
					for(l=0;l<MAX;l++)
					{
						if(Vet_Interm_Cad_Alunos[k] == TAB_REGISTRO[positDisciplina].alunos[0][l].ra)
						{
							system("cls");LF(9);printf("          O ALUNO %s JA ESTA CADASTRADO NA DISCIPLINA %s",CAD_alunos[positAluno].nome,TAB_REGISTRO[positDisciplina].nome);LF(1);printf("          TURMA 1");LF(1);printf("          NAO SERA VINCULADO");delay(3000);
							flgCadastrado_T_diferente = 1;
						}
					}

					if(flgQtdMax != 1 && flgCadastrado_T_diferente != 1)
					{
						positVetAlunos = searchFreeSpaceAlunos_REG(TAB_REGISTRO,2,positDisciplina);
						if(positVetAlunos != -1)
						{
							///JÁ QUE NÃO HÁ NINGUÉM CADASTRADO (== 0) VINCULA O ALUNO QUE FOI SOLICITADO
							TAB_REGISTRO[positDisciplina].alunos[1][positVetAlunos].ra = Vet_Interm_Cad_Alunos[k];

							/*****************************************************************************/
							/**    *   *   *   * VINCULA DISCIPLINA EM ALUNO(CAD) *  *   *   *  *       **/
							/*****************************************************************************/

							///INCREMENTA ANTES DE ENTRAR NO FOR PARA PROCURAR ESPAÇO NAS DISCIPLINAS CADASTRADAS
							CAD_alunos[positAluno].qtd_disciplinas_cursadas += 1;

							///PROCURA O ALUNO NO CADASTRO PELO RA DELE
							positAluno = SearchPositionAlunoByCode(Vet_Interm_Cad_Alunos[k],CAD_alunos);
							flgAchouespacoVetor = 0;

							///PROCURA ESPAÇO PARA CADASTRAR A DISCIPLINA COMO (CURSADA) PELO ALUNO (positALUNO)
							for (l = 0; l < CAD_alunos[positAluno].qtd_disciplinas_cursadas; l++)
							{
								if(flgAchouespacoVetor != 1)
								{
									///SE HOUVER ESPACO ELE ENTAO VINCULA NESSE VETOR O CODIGO INTERMEDIARIO///
									if(CAD_alunos[positAluno].cod_disciplinas_cursadas[l] == 0)
									{
										CAD_alunos[positAluno].cod_disciplinas_cursadas[l] = Vet_Interm_Cad_Disciplinas[j];
										flgAchouespacoVetor = 1;
									}
								}
							}
							flgQtdMax = 0;
						}
					}
				}
			}
		}
		if(escolheTurma == 1 && flgVinc_Desvinc == 2)
		{
			for (i = 0; i < i1; i++)
			{
				positAluno = SearchPositionAlunoByCode(Vet_Interm_Cad_Alunos[i],CAD_alunos);

				if(CAD_alunos[positAluno].qtd_disciplinas_cursadas != 0)
				{
					for(l = 0; l < i2; l++)
					{
						positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[l]);


						flgAchouAluno_REG = 0;
						for(equal = 0; equal < MAX; ++equal)
						{
							if(flgAchouAluno_REG != 1)
							{
								if(Vet_Interm_Cad_Alunos[i] == TAB_REGISTRO[positDisciplina].alunos[0][equal].ra)
								{
									///SE FOR IGUAL ENTÃO O ALUNO x ESTA CADASTRADO NA DISCIPLINA y
									printf("%d\n%d",Vet_Interm_Cad_Alunos[i],TAB_REGISTRO[positDisciplina].alunos[0][equal].ra);

									///Posição i+1 é o código do professor, se houver algo na posição [(i=2)+1][l] será professor 3 no cod da disciplina em l
									vet_AlunosDesvinculados[i][l] = Vet_Interm_Cad_Disciplinas[l];
									Desvincular_aluno(TAB_REGISTRO,CAD_alunos,positAluno,equal,positDisciplina,Vet_Interm_Cad_Disciplinas[l],1);
									flgDesvinculou = 1;
									flgAchouAluno_REG = 1;
								}
							}
						}
					}
				}
				else
				{
					system("cls");
					LF(9);printf("          ALUNO %s NAO CURSA NENHUMA DISCIPLINA !",CAD_alunos[positAluno].nome);
					LF(1);printf("          PORTANTO, NAO SERA DESVINCULADO.");
				}
			}
			if(flgDesvinculou == 1)
            {
				system("cls");
				gotoxy(lin+=1,0);printf(" _________________________________________________________________");
				gotoxy(lin+=1,0);printf(yellow" |                   LISTA DE VINCULOS DESFEITOS                 |"white,CAD_alunos[positAluno].nome);
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(" |                            TURMA 1                            |");
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(yellow" | NOME DO ALUNO                 | NOME DA DISCIPLINA            |"white);
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				///IMPRIMIR ALUNOES DESVINCULADOS E DE QUAIS DISCIPLINAS
				for(i = 0 ; i < MAX ; i++){
					for(l = 0; l < MAX ; l++){
						if(vet_AlunosDesvinculados[i][l] != 0){
							positAluno = SearchPositionAlunoByCode((i+1),CAD_alunos);
							positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,vet_AlunosDesvinculados[i][l]);
							gotoxy(lin+=1,0);printf(" | %-30s| %-30s|",CAD_alunos[positAluno].nome,TAB_REGISTRO[positDisciplina].nome);
						}
					}
				}
				gotoxy(lin+=1,0);printf(white" |__________________________________________________________|\n PARA VOLTAR PRESSIONE ENTER !");
				system("pause");
			}
		}
		if(escolheTurma == 2 && flgVinc_Desvinc == 2)
		{
			for (i = 0; i < i1; i++)
			{
				positAluno = SearchPositionAlunoByCode(Vet_Interm_Cad_Alunos[i],CAD_alunos);

				if(CAD_alunos[positAluno].qtd_disciplinas_cursadas != 0)
				{
					for(l = 0; l < i2; l++)
					{
						positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[l]);

						flgAchouAluno_REG = 0;
						for(equal = 0; equal < MAX; ++equal)
						{
							if(flgAchouAluno_REG != 1)
							{
								if(Vet_Interm_Cad_Alunos[i] == TAB_REGISTRO[positDisciplina].alunos[1][equal].ra)
								{
									///SE FOR IGUAL ENTÃO O ALUNO x ESTA CADASTRADO NA DISCIPLINA y
									printf("%d\n%d",Vet_Interm_Cad_Alunos[i],TAB_REGISTRO[positDisciplina].alunos[1][equal].ra);

									///Posição i+1 é o código do professor, se houver algo na posição [(i=2)+1][l] será professor 3 no cod da disciplina em l
									vet_AlunosDesvinculados[i][l] = Vet_Interm_Cad_Disciplinas[l];
									Desvincular_aluno(TAB_REGISTRO,CAD_alunos,positAluno,equal,positDisciplina,Vet_Interm_Cad_Disciplinas[l],2);
									flgDesvinculou = 1;
									flgAchouAluno_REG = 1;
								}
							}
						}
					}
				}
				else
				{
					system("cls");
					LF(9);printf("          ALUNO %s NAO CURSA NENHUMA DISCIPLINA !",CAD_alunos[positAluno].nome);
					LF(1);printf("          PORTANTO, NAO SERA DESVINCULADO.");
				}
                if(flgDesvinculou == 1)
                {
                    system("cls");
                    gotoxy(lin+=1,0);printf(" _________________________________________________________________");
                    gotoxy(lin+=1,0);printf(yellow" |                   LISTA DE VINCULOS DESFEITOS                 |"white,CAD_alunos[positAluno].nome);
                    gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
                    gotoxy(lin+=1,0);printf(" |                            TURMA 2                            |");
                    gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
                    gotoxy(lin+=1,0);printf(yellow" | NOME DO ALUNO                 | NOME DA DISCIPLINA            |"white);
                    gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
                    ///IMPRIMIR ALUNOES DESVINCULADOS E DE QUAIS DISCIPLINAS
                    for(i = 0 ; i < MAX ; i++)
                    {
                        for(l = 0; l < MAX ; l++)
                        {
                            if(vet_AlunosDesvinculados[i][l] != 0)
                            {
                                positAluno = SearchPositionAlunoByCode((i+1),CAD_alunos);
                                positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,vet_AlunosDesvinculados[i][l]);
                                gotoxy(lin+=1,0);printf(" | %-30s| %-30s|",CAD_alunos[positAluno].nome,TAB_REGISTRO[positDisciplina].nome);
                            }
                        }
                    }
                    gotoxy(lin+=1,0);printf(white" |__________________________________________________________|\n PARA VOLTAR PRESSIONE ENTER !");
                    system("pause");
                }
            }
		}
	}
	return 0;
}
///CONCLUÍDO
void Desvincular_aluno(DISCIPLINA TAB_REGISTRO[], ALUNO CAD_alunos[], int positAluno_CAD, int positAluno_REG, int positDisciplina, int codDisciplina, int turma)
{
	int positDisciplina_CAD_professor = 0;
	if(turma == 1)
	{
		/// O ALUNO É DESVINCULADO DO REGISTRO DE DISCIPLINAS
		TAB_REGISTRO[positDisciplina].alunos[0][positAluno_REG].ra = 0;
		/// PROCURA A POSIÇÃO DE UMA DISCIPLINA NO CADASTRO DE ALUNOES
		positDisciplina_CAD_professor = SearchPositionDisciplinaDeAlunoByCode_Disciplina(CAD_alunos, positAluno_CAD, codDisciplina);
		/// AGORA VAI NO CADASTRO E RETIRA A DISCIPLINA
		CAD_alunos[positAluno_CAD].cod_disciplinas_cursadas[positDisciplina_CAD_professor] = 0;
		/// DIMINUI UMA DISCIPLINA CURSADA
		CAD_alunos[positAluno_CAD].qtd_disciplinas_cursadas-=1;
	}
	if(turma == 2)
	{
		/// O ALUNO É DESVINCULADO DO REGISTRO DE DISCIPLINAS
		TAB_REGISTRO[positDisciplina].alunos[1][positAluno_REG].ra = 0;
		/// PROCURA A POSIÇÃO DE UMA DISCIPLINA NO CADASTRO DE ALUNOES
		positDisciplina_CAD_professor = SearchPositionDisciplinaDeAlunoByCode_Disciplina(CAD_alunos, positAluno_CAD, codDisciplina);
		/// AGORA VAI NO CADASTRO E RETIRA A DISCIPLINA
		CAD_alunos[positAluno_CAD].cod_disciplinas_cursadas[positDisciplina_CAD_professor] = 0;
		/// DIMINUI UMA DISCIPLINA CURSADA
		CAD_alunos[positAluno_CAD].qtd_disciplinas_cursadas-=1;
	}
}
#endif // GERENCIAMENTODEALUNOS_H_INCLUDED
