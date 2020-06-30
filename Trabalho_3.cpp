#include "head.h"
#include "MemoriaVirtual.h"

int main(int argc, char const* argv[])
{
	char comandos = '0';
	int tamanho, pid, endereco;
	MemoriaVirtual* memoria = new MemoriaVirtual();

	printf("\t\tSIMULADOR DE GERENCIADOR DE MOMORIA VIRTUAL\n");

	printf("Configuracoes da mamoria: \n");
	printf("Tamnho das memorias:\n");
	printf("\tMemoria primaria: %02d \tMemoria secundaria: %02d\n", TAM_RAM, TAM_DISCO);
	printf("Tamnho da pagina de disco: %02d", TAM_PAGE);


	while (comandos == 's') {
		pid = tamanho = endereco = 0;
		cout << "Entre com o comando: " << endl;
		cin >> comandos;

		switch (tolower(comandos))
		{
		case 'c':
			cin >> pid >> tamanho;
			break;
		case 'w':
			cin >> pid >> endereco;
			break;
		case 'r':
			cin >> pid >> endereco;
			break;
		case 'i':
			cin >> pid >> endereco;
			break;
		case 'o':
			cin >> pid >> endereco;
			break;
		case 'b':
			cin >> pid;
			break;
		case 'a':
			
			break;
		case 'e':

			break;
		case 'm':
			cin >> pid;
			break;
		case 'v':

			break;
		case 'h':
			cout << "\n##########\t AJUDA \t##########" << endl;
			cout << "Comandos:" << endl;
			cout << "\tC: [cria um novo processo]                - C pid tamanho" << endl;
			cout << "\tW: [gravacao]			                 - W pid endereco" << endl;
			cout << "\tR: [Leitura]                              - R pid endereco" << endl;
			cout << "\tI: [Input]                                - I pid endereco" << endl;
			cout << "\tO: [Output]                               - O pid endereco" << endl;
			cout << "\tB: [Busca as inforcoes de um processo]    - B pid" << endl;
			cout << "\tA: [Printa os processos ativos]           - A"<< endl;
			cout << "\tE: [Exibe a lista de processos em espera] - E" << endl;
			cout << "\tM: [Mata o processo referente ao pid]     - M pid" << endl;
			cout << "\tV: [Printa a memoria virtual]             - V" << endl;
			cout << "\tH: [Ajuda]                                - H" << endl;
			cout << "\tQ: [Encerrar programa]                    - Q" << endl;

		default:
			break;
		}
	}

	return 0;
}
