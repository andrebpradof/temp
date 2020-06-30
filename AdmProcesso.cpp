#include "AdmProcesso.h"

AdmProcesso::AdmProcesso() {

}

void AdmProcesso::statusProcessosAtivos(){
	for (Processo processo : lista_processos_ativos) {
		printf("# Pid: %02d \t Tamanho: %02d Bytes\n", processo.pid, processo.tamanho);
	}
}

void AdmProcesso::statusProcessosInativos() {
	for (Processo processo : lista_processos_inativos) {
		printf("# Pid: %02d \t Tamanho: %02d Bytes\n", processo.pid, processo.tamanho);
	}
}