#ifndef GERENCIAMENTODEPROFESSORES_H_INCLUDED
#define GERENCIAMENTODEPROFESSORES_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/

void Desvincular_professor(DISCIPLINA TAB_REGISTRO[], PROFESSOR CAD_professores[], int positProfessor, int positDisciplina, int codDisciplina, int turma);
void Vincular_Professores_a_Disciplinas(PROFESSOR CAD_professores[], DISCIPLINA TAB_REGISTRO[], int Vet_Interm_Cad_Professores[], int Vet_Interm_Cad_Disciplinas[], int Num_professores_Cadastrados, int Num_disciplinas_Cadastradas, int flgVinc_Desvinc);

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/

void Vincular_Professores_a_Disciplinas(PROFESSOR CAD_professores[], DISCIPLINA TAB_REGISTRO[], int Vet_Interm_Cad_Professores[], int Vet_Interm_Cad_Disciplinas[], int Num_professores_Cadastrados, int Num_disciplinas_Cadastradas, int flgVinc_Desvinc)
{
	system("mode con:cols=80 lines=30");        ///SETA O TAMANHO DO DOS

	int escolha;								///USADA PARA SAIR DO (DO WHILE)
	int escolheTurma;							///USADA PARA SELECIONAR (T1 ou T2)

	int ChkCadastrado_Professor;				///FLAG QUE INDICA SE DETERMINADO PROFESSOR  ESTA CADASTRADO
	int ChkCadastrada_disciplina;				///FLAG QUE INDICA SE DETERMINADA DISCIPLINA ESTA CADASTRADA

	int ChkCadastrado_ProfessorIntermediario;	///FLAG DIZ SE O PROFESSOR 	JÁ FOI LISTADO NO CONJUNTO
	int ChkCadastrada_disciplinaIntermediario;	///FLAG DIZ SE A DISCIPLINA JÁ FOI LISTADA NO CONJUNTO

	int auxiliar_Cad_CodProf;					///VARIAVEL GUARDA codProf 			ANTES DE LISTAR NO CONJUNTO
	int auxiliar_Cad_CodDisciplina;				///VARIAVEL GUARDA codDisciplina 	ANTES DE LISTAR NO CONJUNTO

	int flgAchouespacoVetor;					///QUANDO ACHA ESPAÇO VINCULA DISCIPLINA NO VETOR DE DISCIPLINAS DE ALUNO

	int i1;										///
	int i2;										///
	int lin = 2;
	int j;										///
	int i;										///ITERADOR COMUM AOS FOR DO SISTEMA (USO VÁRIAS VEZES QUANDO VOU ATIVAR FLAGS)
	int l;										///PRECISO DE MAIS UM ITERADOR PARA DESCOBRIR ONDE ESTÁ OS NOMES NO REGISTRO

	int positDisciplina;						///CONSIGO A POSIÇÃO DO REGISTRO GERAL DO CADASTRO DAQUELA DISCIPLINA
	int positProfessor;							///CONSIGO A POSIÇÃO NO CADASTRO CAD_professores DAQUELE PROFESSOR
	int prof_desvinculado;						///VAR AUXILIAR PARA GUARDAR A POSIÇÃO DO PROFESSOR A SER DESVINCULADO

	int vet_ProfDesvinculados[15][15];          ///GUARDO PARA MOSTRAR AO USUARIO QUAIS PROFESSORES
												///FORAM DESVINCULADOS E DE QUAIS DISCIPLINAS

	if (Num_disciplinas_Cadastradas == 0 || Num_professores_Cadastrados == 0)
	{
		if(Num_disciplinas_Cadastradas == 0 && Num_professores_Cadastrados == 0)
		{
			system("cls");LF(9);printf("          NENHUMA DISCIPLINA NEM PROFESSOR CADASTRADO(A) !");delay(2000);
		}
		else{
			if(Num_disciplinas_Cadastradas == 0){system("cls");LF(9);printf("          NENHUMA DISCIPLINA CADASTRADA !");delay(2000);}
			if(Num_professores_Cadastrados == 0){system("cls");LF(9);printf("          NENHUM PROFESSOR CADASTRADO !");delay(2000);}
		}
	}
	else
	{

		i1 = 0, i2 = 0;
		i = 0, j = 0;
		escolha = 1,escolheTurma = 0;
		ChkCadastrado_Professor = 0, ChkCadastrada_disciplina = 0;
		ChkCadastrado_ProfessorIntermediario = 0, ChkCadastrada_disciplinaIntermediario = 0;
		flgAchouespacoVetor = 0;

		//INICIA O VETOR INTERMEDIÁRIO COM ZERO
		for(i = 0 ; i < MAX ; i++){
			Vet_Interm_Cad_Professores[i] = 0;
			Vet_Interm_Cad_Disciplinas[i] = 0;
			for(j=0; j < MAX; j++){vet_ProfDesvinculados[i][j] = 0;}
		}
		do
		{
			ChkCadastrado_ProfessorIntermediario = 0;
			ChkCadastrado_Professor = 0;

			system("cls");
			Imprimir_Professores_CAD(CAD_professores, Num_professores_Cadastrados);

			printf("\nPARA SAIR DIGITE (-1)");
			if(flgVinc_Desvinc == 1){ printf("\nDIGITE O RP DO PROFESSOR QUE DESEJA VINCULAR: ");}
			if(flgVinc_Desvinc == 2){ printf("\nDIGITE O RP DO PROFESSOR QUE DESEJA DESVINCULAR: ");}
			scanf("%d", &auxiliar_Cad_CodProf);
			fflush(stdin);

			if(auxiliar_Cad_CodProf == -1){return 0;}
			else if(auxiliar_Cad_CodProf != 0)
			{
				///VERIFICA SE O COD DO PROFESSOR EXISTE
				for(j = 0 ; j < Num_professores_Cadastrados ; j++){
					if(CAD_professores[j].rp == auxiliar_Cad_CodProf){
						ChkCadastrado_Professor = 1;///FLAG QUE DIZ SE O PROFESSOR EXISTE NO CADASTRO
					}
				}
				///VERIFICA SE O PROFESSOR JÁ NÃO FOI LISTADO PARA VINCULAR COM DISCIPLINA
				for(i = 0 ; i < i1 ; i++){
					if(Vet_Interm_Cad_Professores[i] == auxiliar_Cad_CodProf){
						ChkCadastrado_ProfessorIntermediario = 1;///FLAG DE VERIFICAÇÃO SE JÁ FOI LISTADO NO CONJUNTO
					}
				}
				if(ChkCadastrado_Professor != 1){
					system("cls");LF(9);printf("          PROFESSOR NAO CADASTRADO");LF(2);printf("          DIGITE OUTRO");LF(1);printf("          AGUARDE...");delay(1500);
				}
				else if(ChkCadastrado_ProfessorIntermediario == 1){
					system("cls");LF(9);printf("          PROFESSOR JA LISTADO");LF(2);printf("          DIGITE OUTRO");LF(1);printf("          AGUARDE...");delay(1500);
				}
				else if(ChkCadastrado_Professor == 1 && ChkCadastrado_ProfessorIntermediario != 1){
					Vet_Interm_Cad_Professores[i1] = auxiliar_Cad_CodProf;
					i1++;
					system("cls");
					if(i1 < Num_professores_Cadastrados){
						LF(9);printf("          DESEJA LISTAR MAIS UM PROFESSOR?");LF(2);printf("          1 - SIM");LF(1);printf("          2 - NAO");
						scanf("%d", &escolha);fflush(stdin);
					}
				}
			}
		}
		while( i1 < Num_professores_Cadastrados && escolha == 1);

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
				///VERIFICA SE A DISCIPLINA JÁ NÃO FOI LISTADA PARA VINCULAR COM PROFESSOR
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

		///ESCOLHE EM QUAL TURMA VAI VINCULAR O PROFESSOR
		system("cls");LF(9);printf("          EM QUAL TURMA?");LF(2);printf("          1 - TURMA 1");LF(1);printf("          2 - TURMA 2");
		scanf("%d", &escolheTurma);fflush(stdin);

		j=0;
		positDisciplina = 0;
		positProfessor = 0;
		int flgDesvinculou = 0;

		if(escolheTurma == 1 && flgVinc_Desvinc == 1)
		{
			system("cls");
			///ITERADOR DE DISCIPLINA 1 A 15
			for (j = 0; j < i2; j++)
			{
				///PROCURA A DISCIPLINA NO REGISTRO GERAL
				positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[j]);

				/*****************************************************************************/
				/**     *   *   *   *   VINCULA PROFESSOR EM DISCIPLINA  *  *   *   *   *   **/
				/*****************************************************************************/

				///VERIFICA SE O PROFESSOR NÃO ATINGIU O MÁXIMO DE DISCIPLINAS MINISTRADAS;
				positProfessor = SearchPositionProfessorByCode(Vet_Interm_Cad_Professores[i1-1],CAD_professores);

				if(CAD_professores[positProfessor].qtd_disciplinas_ministradas == 15){
					system("cls");LF(9);printf("          PROFESSOR %s JA MINISTRA 15 DISCIPLINAS ! NAO VINCULADO",CAD_professores[positProfessor].nome);LF(1);printf("          AGUARDE...");delay(3000);
				}
				else if(Vet_Interm_Cad_Professores[i1-1] == TAB_REGISTRO[positDisciplina].professores[1][0].rp){
					system("cls");LF(9);printf("          O PROFESSOR %s JA ESTA CADASTRADO NA TURMA 2",CAD_professores[positProfessor].nome);LF(1);printf("          DA DISCIPLINA %s",TAB_REGISTRO[positDisciplina].nome);LF(1);printf("          NAO SERA VINCULADO");delay(3000);
				}
				else
				{
					///SE HOUVER PROFESSOR JA CADASTRADO NO REGISTRO ENTÃO TIRA O PROFESSOR NO REGISTRO E A DISCIPLINA DO CADASTRO
					///SE NÃO FOR ZERO TEM ALGUÉM CADASTRADO
					if(TAB_REGISTRO[positDisciplina].professores[0][0].rp != 0)
					{
						prof_desvinculado = SearchPositionProfessorByCode(TAB_REGISTRO[positDisciplina].professores[0][0].rp,CAD_professores);
						Desvincular_professor(TAB_REGISTRO,CAD_professores,prof_desvinculado,positDisciplina,Vet_Interm_Cad_Disciplinas[j],1);
					}
					///JÁ QUE NÃO HÁ NINGUÉM CADASTRADO (== 0) VINCULA O PROFESSOR QUE FOI SOLICITADO
					TAB_REGISTRO[positDisciplina].professores[0][0].rp = Vet_Interm_Cad_Professores[i1-1];

					/*****************************************************************************/
					/**    *   *   *   * VINCULA DISCIPLINA EM PROFESSOR(CAD) *  *   *   *  *   **/
					/*****************************************************************************/

					///INCREMENTA ANTES DE ENTRAR NO FOR PARA PROCURAR ESPAÇO NAS DISCIPLINAS CADASTRADAS
					CAD_professores[positProfessor].qtd_disciplinas_ministradas += 1;
					///PROCURA O PROFESSOR NO CADASTRO PELO RP DELE
					positProfessor = SearchPositionProfessorByCode(Vet_Interm_Cad_Professores[i1-1],CAD_professores);
					flgAchouespacoVetor = 0;
					///PROCURA ESPAÇO PARA CADASTRAR A DISCIPLINA COMO (MINISTRADA) PELO PROFESSOR (positPROFESSOR)
					for (l = 0; l < MAX; l++)
					{
						if(flgAchouespacoVetor != 1)
						{
							///SE HOUVER ESPACO ELE ENTAO VINCULA NESSE VETOR O CODIGO INTERMEDIARIO///
							if(CAD_professores[positProfessor].cod_disciplinas_ministradas[l] == 0)
							{
								CAD_professores[positProfessor].cod_disciplinas_ministradas[l] = Vet_Interm_Cad_Disciplinas[j];
								flgAchouespacoVetor = 1;
							}
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

				/*****************************************************************************/
				/**     *   *   *   *   VINCULA PROFESSOR EM DISCIPLINA  *  *   *   *   *   **/
				/*****************************************************************************/
				///VERIFICA SE O PROFESSOR NÃO ATINGIU O MÁXIMO DE DISCIPLINAS MINISTRADAS;
				positProfessor = SearchPositionProfessorByCode(Vet_Interm_Cad_Professores[i1-1],CAD_professores);

				if(CAD_professores[positProfessor].qtd_disciplinas_ministradas == 15){
					system("cls");
					LF(9);printf("          PROFESSOR %s JA MINISTRA 15 DISCIPLINAS ! NAO VINCULADO",CAD_professores[positProfessor].nome);
					LF(1);printf("          AGUARDE...");
					delay(3000);
				}
				else if(Vet_Interm_Cad_Professores[i1-1] == TAB_REGISTRO[positDisciplina].professores[0][0].rp){
					system("cls");
					LF(9);printf("          O PROFESSOR %s JA ESTA CADASTRADO NA TURMA 1",CAD_professores[positProfessor].nome);
					LF(1);printf("          DA DISCIPLINA %s",TAB_REGISTRO[positDisciplina].nome);
					LF(1);printf("          NAO SERA VINCULADO");
					delay(3000);
				}
				else
				{
					///SE HOUVER PROFESSOR JA CADASTRADO NO REGISTRO ENTÃO TIRA O PROFESSOR NO REGISTRO E A DISCIPLINA DO CADASTRO
					///SE NÃO FOR ZERO TEM ALGUÉM CADASTRADO
					if(TAB_REGISTRO[positDisciplina].professores[1][0].rp != 0){
						prof_desvinculado = SearchPositionProfessorByCode(TAB_REGISTRO[positDisciplina].professores[1][0].rp,CAD_professores);
						Desvincular_professor(TAB_REGISTRO,CAD_professores,prof_desvinculado,positDisciplina,Vet_Interm_Cad_Disciplinas[j],2);
					}
					///JÁ QUE NÃO HÁ NINGUÉM CADASTRADO (== 0) VINCULA O PROFESSOR QUE FOI SOLICITADO
					TAB_REGISTRO[positDisciplina].professores[1][0].rp = Vet_Interm_Cad_Professores[i1-1];

					/*****************************************************************************/
					/**    *   *   *   * VINCULA DISCIPLINA EM PROFESSOR(CAD) *  *   *   *  *   **/
					/*****************************************************************************/

					///INCREMENTA ANTES DE ENTRAR NO FOR PARA PROCURAR ESPAÇO NAS DISCIPLINAS CADASTRADAS
					CAD_professores[positProfessor].qtd_disciplinas_ministradas += 1;

					///PROCURA O PROFESSOR NO CADASTRO PELO RP DELE
					positProfessor = SearchPositionProfessorByCode(Vet_Interm_Cad_Professores[i1-1],CAD_professores);
					flgAchouespacoVetor = 0;

					///PROCURA ESPAÇO PARA CADASTRAR A DISCIPLINA COMO (MINISTRADA) PELO PROFESSOR (positPROFESSOR)
					for (l = 0; l < MAX; l++){
						if(flgAchouespacoVetor != 1){
							///SE HOUVER ESPACO ELE ENTAO VINCULA NESSE VETOR O CODIGO INTERMEDIARIO///
							if(CAD_professores[positProfessor].cod_disciplinas_ministradas[l] == 0){
								CAD_professores[positProfessor].cod_disciplinas_ministradas[l] = Vet_Interm_Cad_Disciplinas[j];
								flgAchouespacoVetor = 1;
							}
						}
					}
				}
			}
		}
		if(escolheTurma == 1 && flgVinc_Desvinc == 2)
		{
			for (i = 0; i < i1; i++)
			{
				positProfessor = SearchPositionProfessorByCode(Vet_Interm_Cad_Professores[i],CAD_professores);
				if(CAD_professores[positProfessor].qtd_disciplinas_ministradas != 0)
				{
					for(l = 0; l < i2; l++)
					{
						positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[l]);
						///SE FOR IGUAL ENTÃO O ALUNO x ESTA CADASTRADO NA DISCIPLINA y
						printf("%d\n%d",Vet_Interm_Cad_Professores[i],TAB_REGISTRO[positDisciplina].professores[0][0].rp);
						if(Vet_Interm_Cad_Professores[i] == TAB_REGISTRO[positDisciplina].professores[0][0].rp)
						{
							vet_ProfDesvinculados[i][l] = Vet_Interm_Cad_Disciplinas[l];
							Desvincular_professor(TAB_REGISTRO,CAD_professores,positProfessor,positDisciplina,Vet_Interm_Cad_Disciplinas[l],1);
							flgDesvinculou = 1;
						}
						system("pause");
					}
				}
				else
				{
					system("cls");
					LF(9);printf("          PROFESSOR %s NAO MINISTRA NENHUMA DISCIPLINA !",CAD_professores[positProfessor].nome);
					LF(1);printf("          PORTANTO, NAO SERA DESVINCULADO.");
					system("pause");
				}
			}
			if(flgDesvinculou == 1){
				system("cls");
				gotoxy(lin+=1,0);printf(" _________________________________________________________________");
				gotoxy(lin+=1,0);printf(yellow" |                   LISTA DE VINCULOS DESFEITOS                 |"white,CAD_professores[positProfessor].nome);
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(" |                             TURMA 1   				    	  |");
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
		  gotoxy(lin+=1,0);printf(yellow" | NOME DO PROFESSOR             | NOME DA DISCIPLINA            |"white);
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				///IMPRIMIR PROFESSORES DESVINCULADOS E DE QUAIS DISCIPLINAS
				for(i = 0 ; i < MAX ; i++)
				{
					for(l = 0; l < MAX ; l++)
					{
						if(vet_ProfDesvinculados[i][l] != 0)
						{
							positProfessor = SearchPositionProfessorByCode((i+1),CAD_professores);
							positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,vet_ProfDesvinculados[i][l]);
							gotoxy(lin+=1,0);
							printf(" | %-30s| %-30s|",CAD_professores[positProfessor].nome,TAB_REGISTRO[positDisciplina].nome);
						}
					}
				}
				gotoxy(lin+=1,0);printf(white" |_______________________________________________________________|\n PARA VOLTAR PRESSIONE ENTER !\n\n\n");
				system("pause");
			}
		}
		if(escolheTurma == 2 && flgVinc_Desvinc == 2)
		{
			for (i = 0; i < i1; i++)
			{
				positProfessor = SearchPositionProfessorByCode(Vet_Interm_Cad_Professores[i],CAD_professores);
				if(CAD_professores[positProfessor].qtd_disciplinas_ministradas > 0)
				{
					for(l = 0; l < i2; l++)
					{
						positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,Vet_Interm_Cad_Disciplinas[l]);
						///SE FOR IGUAL ENTÃO O ALUNO x ESTA CADASTRADO NA DISCIPLINA y
						if(Vet_Interm_Cad_Professores[i] == TAB_REGISTRO[positDisciplina].professores[1][0].rp)
						{
							vet_ProfDesvinculados[i][l] = Vet_Interm_Cad_Disciplinas[l];
							Desvincular_professor(TAB_REGISTRO,CAD_professores,positProfessor,positDisciplina,Vet_Interm_Cad_Disciplinas[l],2);
							flgDesvinculou = 1;
						}
					}
				}
				else
				{
					system("cls");
					LF(9);
					printf("          PROFESSOR %s NAO MINISTRA NENHUMA DISCIPLINA !",CAD_professores[positProfessor].nome);
					LF(1);
					printf("          PORTANTO, NAO SERA DESVINCULADO.");
				}
			}
			if(flgDesvinculou == 1)
			{
				system("cls");
				gotoxy(lin+=1,0);printf(" _________________________________________________________________");
				gotoxy(lin+=1,0);printf(yellow" |                   LISTA DE VINCULOS DESFEITOS                 |"white,CAD_professores[positProfessor].nome);
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(" |                             TURMA 2   				    	  |");
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				gotoxy(lin+=1,0);printf(yellow" | NOME DO PROFESSOR             | NOME DA DISCIPLINA            |"white);
				gotoxy(lin+=1,0);printf(" |---------------------------------------------------------------|");
				///IMPRIMIR PROFESSORES DESVINCULADOS E DE QUAIS DISCIPLINAS
				for(i = 0 ; i < MAX ; i++)
				{
					for(l = 0; l < MAX ; l++)
					{
						if(vet_ProfDesvinculados[i][l] != 0)
						{
							positProfessor = SearchPositionProfessorByCode((i+1),CAD_professores);
							positDisciplina = SearchPositionDisciplinaByCode(TAB_REGISTRO,vet_ProfDesvinculados[i][l]);
							gotoxy(lin+=1,0);
							printf(" | %-30s| %-30s|",CAD_professores[positProfessor].nome,TAB_REGISTRO[positDisciplina].nome);
						}
					}
				}
				gotoxy(lin+=1,0);printf(white" |_______________________________________________________________|\n PARA VOLTAR PRESSIONE ENTER !\n\n\n");
				system("pause");
			}
		}
	}
}
///CONCLUÍDO
void Desvincular_professor(DISCIPLINA TAB_REGISTRO[], PROFESSOR CAD_professores[], int positProfessor, int positDisciplina, int codDisciplina, int turma)
{
	int positDisciplina_CAD_professor = 0;
	if(turma == 1)
	{
		/// O PROFESSOR É DESVINCULADO DO REGISTRO DE DISCIPLINAS
		TAB_REGISTRO[positDisciplina].professores[0][0].rp = 0;
		/// PROCURA A POSIÇÃO DE UMA DISCIPLINA NO CADASTRO DE PROFESSORES
		positDisciplina_CAD_professor = SearchPositionDisciplinaDeProfessorByCode_Disciplina(CAD_professores, positProfessor, codDisciplina);
		/// AGORA VAI NO CADASTRO E RETIRA A DISCIPLINA
		CAD_professores[positProfessor].cod_disciplinas_ministradas[positDisciplina_CAD_professor] = 0;
		/// DIMINUI UMA DISCIPLINA MINISTRADA
		CAD_professores[positProfessor].qtd_disciplinas_ministradas-=1;
	}
	if(turma == 2)
	{
		/// O PROFESSOR É DESVINCULADO DO REGISTRO DE DISCIPLINAS
		TAB_REGISTRO[positDisciplina].professores[1][0].rp = 0;
		/// PROCURA A POSIÇÃO DE UMA DISCIPLINA NO CADASTRO DE PROFESSORES
		positDisciplina_CAD_professor = SearchPositionDisciplinaDeProfessorByCode_Disciplina(CAD_professores, positProfessor, codDisciplina);
		/// AGORA VAI NO CADASTRO E RETIRA A DISCIPLINA
		CAD_professores[positProfessor].cod_disciplinas_ministradas[positDisciplina_CAD_professor] = 0;
		/// DIMINUI UMA DISCIPLINA MINISTRADA
		CAD_professores[positProfessor].qtd_disciplinas_ministradas-=1;
	}
}
#endif /// GERENCIAMENTODEPROFESSORES_H_INCLUDED
