#pragma once
#include "head.h"
#include "Processo.h"

class AdmProcesso
{
public:
	std::list<Processo> lista_processos_ativos;
	std::list<Processo> lista_processos_inativos;
	AdmProcesso();
	void statusProcessosAtivos();
	void statusProcessosInativos();
};

