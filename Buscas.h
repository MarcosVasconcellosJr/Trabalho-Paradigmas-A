#ifndef BUSCAS_H_INCLUDED
#define BUSCAS_H_INCLUDED

/*****************************************************************************/
/**     *   *   *   *                PROTÓTIPOS          *  *   *   *   *   **/
/*****************************************************************************/
int SearchPositionProfessorByCode(int,PROFESSOR []);
int SearchPositionAlunoByCode(int,ALUNO []);
int SearchPositionDisciplinaByCode(DISCIPLINA [],int );
int SearchPositionDisciplinaDeAlunoByCode_Disciplina(ALUNO [],int ,int );
int SearchPositionDisciplinaDeProfessorByCode_Disciplina(PROFESSOR [],int,int );
int SearchPositionAlunoDeDisciplinaByCode_Aluno(DISCIPLINA [],int,int,int );
int searchFreeSpaceAlunos_REG(DISCIPLINA [],int,int);

/*****************************************************************************/
/**     *   *   *   *                FUNÇÕES             *  *   *   *   *   **/
/*****************************************************************************/
int SearchPositionProfessorByCode(int CodigoDeBusca,PROFESSOR CAD_professores[])
{
	int i;
	for(i = 0 ; i < MAX ; i++)
	{
		if(CAD_professores[i].rp == CodigoDeBusca)
		{
			return i;
		}
	}
	return -1;
}
int SearchPositionAlunoByCode(int CodigoDeBusca,ALUNO CAD_alunos[])
{
	int i;
	for(i = 0 ; i < MAX ; i++)
	{
		if(CAD_alunos[i].ra == CodigoDeBusca)
		{
			return i;
		}
	}
	return -1;
}
int SearchPositionDisciplinaByCode(DISCIPLINA TAB_REGISTRO[], int CodigoDeBusca)
{
	int i;
	for(i = 0; i < MAX ; i++)
	{
		if(TAB_REGISTRO[i].cod == CodigoDeBusca)
		{
			return i;
		}
	}
	return -1;
}
int SearchPositionDisciplinaDeAlunoByCode_Disciplina(ALUNO CAD_alunos[], int positAluno, int codDisciplina)
{
	int i;

	for(i = 0 ; i <  MAX; i++)
	{
		if(CAD_alunos[positAluno].cod_disciplinas_cursadas[i] == codDisciplina)
		{
			return i;
		}
	}
	return -1;
}
int SearchPositionDisciplinaDeProfessorByCode_Disciplina(PROFESSOR CAD_professores[],int positProfessor, int codDisciplina)
{
	int i;

	for(i = 0 ; i <  MAX; i++)
	{
		if(CAD_professores[positProfessor].cod_disciplinas_ministradas[i] == codDisciplina)
		{
			return i;
		}
	}
	return -1;
}
int SearchPositionAlunoDeDisciplinaByCode_Aluno(DISCIPLINA TAB_REGISTRO[], int positDisciplina, int codAluno, int turma)
{
	int i;

	if(turma == 1)
	{
		for(i = 0 ; i < MAX ; i++)
		{
			if(TAB_REGISTRO[positDisciplina].alunos[0][i].ra == codAluno)
			{
				return i;
			}
		}
	}
	if(turma == 2)
	{
		for(i = 0 ; i < MAX ; i++)
		{
			if(TAB_REGISTRO[positDisciplina].alunos[1][i].ra == codAluno)
			{
				return i;
			}
		}
	}
	return -1;
}
int searchFreeSpaceAlunos_REG(DISCIPLINA TAB_REGISTRO[],int turma, int positDisciplina)
{
	int i;

	if(turma == 1)
	{
		for(i = 0 ; i < MAX ; i++)
		{
			if(TAB_REGISTRO[positDisciplina].alunos[0][i].ra == 0)
			{
				return i;
			}
		}
	}
	if(turma == 2)
	{
		for(i = 0 ; i < MAX ; i++)
		{
			if(TAB_REGISTRO[positDisciplina].alunos[1][i].ra == 0)
			{
				return i;
			}
		}
	}
	return -1;
}
#endif // BUSCAS_H_INCLUDED
