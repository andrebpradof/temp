#pragma once
#include "Head.h"
#include "PaginaDeDisco.h"
class Memoria
{
public:
	int ocupacao;
	int tamanho;
	list<PaginaDeDisco> lista_paginas_de_disco;
	Memoria();
	void mostrarStatus();
};

