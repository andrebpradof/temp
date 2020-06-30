#include "MemoriaVirtual.h"


MemoriaVirtual::MemoriaVirtual() {
	this->ocupacao = 0;
	this->tam_total = TAM_DISCO + TAM_RAM;
	this->ram.ocupacao = 0;
	this->ram.tamanho = TAM_RAM;
	this->disco.ocupacao = 0;
	this->disco.tamanho = TAM_DISCO;
	this->num_pag_disco = TAM_DISCO / TAM_PAGE;
	this->num_pag_ram = TAM_RAM / TAM_PAGE;
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
		if (this->ram.ocupacao < this->num_pag_ram) {
			PaginaDeDisco pagina_nova(cont, pid, TAM_PAGE);
			this->ram.lista_paginas_de_disco.push_back(pagina_nova);
			this->ocupacao++;
			num_paginas--;
			cont++;
		}
		else {

		}
	}
	
	this->num_pag_disco += num_paginas;
}

int MemoriaVirtual::swapping(int num_paginas) {
	if (num_paginas <= this->num_pag_ram) { // Cabe totalmente na RAM
		int num_subs = num_paginas - (this->num_pag_ram - this->ram.ocupacao); // Numero de substituicoes necessarias
		while (num_paginas != 0) {
			if (this->ram.lista_paginas_de_disco.front().r == 0) {
				this->disco.lista_paginas_de_disco.push_back(this->ram.lista_paginas_de_disco.front());
				this->ram.lista_paginas_de_disco.pop_front;
				num_paginas--;
			}
			else {
				this->ram.lista_paginas_de_disco.front().r = 0;
				this->ram.lista_paginas_de_disco.push_back(ram.lista_paginas_de_disco.front);
				this->lista_processos_ativos.pop_front();
			}
		}	
	}
	else {

	}
	return 1;
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