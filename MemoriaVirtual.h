#pragma once
#include "Head.h"
#include "Memoria.h"
#include "Processo.h"
#include "PaginaDeDisco.h"
class MemoriaVirtual
{
private:
	int alocaMemoria(int pid, int tamanho);
	int swapping(int num_paginas);

public:
	int tam_total; // Em Bytes
	int ocupacao; // Em paginas de disco
	int pont_relogio;
	Memoria ram;
	Memoria disco;
	list<Processo> lista_processos_ativos;

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

