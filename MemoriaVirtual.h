#pragma once
#include "Head.h"
#include "Memoria.h"
#include "AdmProcesso.h"
class MemoriaVirtual
{
public:
	int num_pag_disco;
	int tam_total;
	int ocupacao;
	Memoria ram;
	Memoria disco;
	MemoriaVirtual();
};

