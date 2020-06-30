#pragma once
#include "Head.h"
#include "Memoria.h"
#include "Processo.h"
class MemoriaVirtual
{
private:
	int alocaMemoria(int pid, int tamanho, Memoria *memoria);

public:
	int num_pag_disco;
	int tam_total;
	int ocupacao;
	Memoria ram;
	Memoria disco;
	vector<Processo> lista_processos_ativos;

	MemoriaVirtual();
	int alocarProcesso(int pid, int tamanho);
	int matarProcesso(int pid);
	void imprimeProcesso(int pid);
	void imprimeProcessosAtivos();
	int io(int pid, int endereco);
	int wr(int pid, int endereco);
	void imprimeMemoriaVirtual();
	Processo* consultaProcesso(int pid);
};

