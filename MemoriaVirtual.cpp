#include "MemoriaVirtual.h"


MemoriaVirtual::MemoriaVirtual(){
	// Memoria Virtual
	this->ocupacao = 0; // Em paginas de disco
	this->tam_total = TAM_DISCO + TAM_RAM; // Em Bytes

	Memoria ram(TAM_RAM);
	this->ram = ram;

	Memoria disco(TAM_DISCO);
	this->disco = disco;

	this->ram.ocupacao = 0; // Em paginas de disco
	this->ram.capacidade_bytes = TAM_RAM; // Em Bytes
	this->disco.ocupacao = 0; // Em paginas de disco
	this->disco.capacidade_bytes = TAM_DISCO; // Em Bytes
}

int MemoriaVirtual::alocarProcesso(int pid, int tamanho) {
	
	Processo temp(pid, tamanho);    //Variavel temporaria para processos

	if (consultaProcesso(pid) != NULL) {    //Antes de alocar, consulta se o processo ja existe
		cout << "Processo ja existe!";
		return 0;
	}

	if ((this->ocupacao + tamanho) > this->tam_total) {     //Verifica se ha espaco suficiente para o processo na memoria virtual
		cout << "Nao ha memoria suficiente para o processo!" <<endl;
		return 0;
	}
	else {      //Se houver espaço na memoria, o processo e inserido na lista de processos ativos
		lista_processos_ativos.push_back(temp);
		alocaMemoria(pid, tamanho);
	}
	return 1;
}

int MemoriaVirtual::alocaMemoria(int pid, int tamanho){
	int num_paginas = 0;
	int ocupacao = 0;
	int cont = 0;

	num_paginas = (int)tamanho / TAM_PAGE; // calcula quantas paginas de disco serao alocadas
	if ((tamanho % TAM_PAGE) != 0) {
		num_paginas++;
	}
	
	while (num_paginas != 0) { 
		PaginaDeDisco pagina_nova(cont, pid, TAM_PAGE);
		if (this->ram.ocupacao < this->num_pag_ram) { // Cabe na RAM sem a necessidade de swapping
			this->ram.lista_paginas_de_disco.push_back(pagina_nova);
			this->ram.ocupacao++;
			this->ocupacao++;
			num_paginas--;
			cont++;
		}
		else { // Precisa realizar swapping
			while (true) { // Busca ate encontrar uma pagina de disco com r = 0
				if (this->ram.lista_paginas_de_disco.front().r == 0) {
					// Colocara a pagina com o bit r = 0 no disco
					this->disco.lista_paginas_de_disco.push_back(this->ram.lista_paginas_de_disco.front());
					this->ram.lista_paginas_de_disco.pop_front; // remove da RAM
					this->ram.lista_paginas_de_disco.push_back(pagina_nova); // aloca a nova pagina
					num_paginas--;
					this->ocupacao++;
					this->disco.ocupacao++;
					cont++;
					break;
				}
				else { // Coloca 0 para o bit r e aponta pra o proximo da lista
					this->ram.lista_paginas_de_disco.front().r = 0;
					this->ram.lista_paginas_de_disco.push_back(ram.lista_paginas_de_disco.front);
					this->lista_processos_ativos.pop_front();
				}
			}
		}
	}
}

int MemoriaVirtual::swapping(int num_paginas) {
	
}

int MemoriaVirtual::matarProcesso(int pid) {
    return 1;
}

void MemoriaVirtual::imprimeProcesso(int pid) {     //Procura o processo na lista de processos ativos e imprime os dados desse processo na tela
	for (Processo p : lista_processos_ativos) {
        if(p.pid == pid) {
			printf("# Pid: %02d \t Tamanho: %02d Bytes\n", p.pid, p.tamanho);
            break;
        }
	}
}

void MemoriaVirtual::imprimeProcessosAtivos() {     //Consulta todos os processos da lista de processos ativos e imprime cada um na tela
	for (Processo processo : lista_processos_ativos) {
		printf("# Pid: %02d \t Tamanho: %02d Bytes\n", processo.pid, processo.tamanho);
	}
}

int MemoriaVirtual::io(int pid, int endereco) {
    return 1;
}

int MemoriaVirtual::wr(int pid, int endereco) {
    return 1;
}


void MemoriaVirtual::imprimeMemoriaVirtual() {      //Percorre toda a memoria virtual imprimindo suas paginas de disco na tela
    printf("# RAM \n");
    for(PaginaDeDisco p : ram.lista_paginas_de_disco) {     //Imprime as paginas de disco da RAM
        printf("# Endereco: %02d \t Pid: %02d \t Ocupacao: %02d \t r: %02d \n", p.endereco, p.pid, p.ocupacao, p.r);
    }
    printf("# DISCO \n");
    for(PaginaDeDisco p : disco.lista_paginas_de_disco) {   //Imprime as paginas de disco do disco
        printf("# Endereco: %02d \t Pid: %02d \t Ocupacao: %02d \t r: %02d \n", p.endereco, p.pid, p.ocupacao, p.r);
    }
}

Processo* MemoriaVirtual::consultaProcesso(int pid) {   //Consulta um dado processo na lista de processos ativos
    Processo* f;
	for (Processo p : lista_processos_ativos) {
        if(p.pid == pid) {
            (*f) = p;
			return f;
        }
	}
	return NULL;
}