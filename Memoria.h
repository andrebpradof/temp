#pragma once
#include "Head.h"
#include "PaginaDeDisco.h"
class Memoria
{
private:
	int capacidade_pag_disco;
public:
	int ocupacao;
	int capacidade_bytes;
	list<PaginaDeDisco> lista_paginas_de_disco;
	Memoria();
	Memoria(int cap_bytes);
	void mostrarStatus();
	int getCapPagDisco();
};

