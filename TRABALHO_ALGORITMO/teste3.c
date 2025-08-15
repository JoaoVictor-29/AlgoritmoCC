#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>//usar caracteres da nossa liingua

//Estrutura de Clientes
typedef struct{
    int codigo;
    char nome[50];
    char CPF[14];
    char telefone[12];
    char dataNasc[13];
    char endereco[50];
    char rua[50];
    int numero;
    char bairro[50];
    int ativo;
} Cliente;

//Estrutura de Compras
typedef struct{
    char dataCompra[13];
    float valorTotal;
    char formaPag[25];
    char quitada;
    int codigoCliente;
    int ativo;
    int codigoCompra;
} Compra;

// Protótipos das funções
int menuPrincipal();
void menuClientes();
void menuCompras();
void menuRelatorios();

// Funções de Cliente
void inserirCliente();
int verificarCodigoCompra(int *codigoComp);
void listarDadosClientes();
void alterarDadosCliente();
void exclusaoLogicaCliente();
int verificarCodigoCliente(int *codigoDigitado);
int verificarCPFCliente(char *cpfDigitado);
int validaCPF(char *cpf);

// Funções de Compra
void inserirCompra();
void listarDadosCompras();
void alterarDadosCompra();
void exclusaoLogicaCompra();
void busca_compra_especifica();
void buscar_compra_porAno();
void listarTodasAsCompras();
void listarComprasNaoQuitadas();
void importarDadosExternos();
void listarClientesIncompletos();

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int opc;
    do{//loop que vai rodar o menu principal
        opc = menuPrincipal();
        if(opc == 1){
            menuClientes();
        }
        else if(opc == 2){
            menuCompras();
        }
        else if(opc == 3){
            menuRelatorios();
        }
        else if(opc == 4){
            importarDadosExternos();
        }
        else if(opc == 5){
            printf("\nEncerrando o programa...");
            exit(1);
        }
        else{
            printf("\nOpcao inválida!\n");
        }
    }while(opc != 3);

    return 0;
}

//funcao principal do sistema
//primeira que aparece
int menuPrincipal(){
    int opc;
    printf("------------------------------------------\n");
    printf("           MENU PRINCIPAL             \n");
    printf("------------------------------------------\n");
    printf("Digite o numero da opcao escolhida:\n");
    printf("1 - Clientes\n");
    printf("2 - Compras\n");
    printf("3 - Relatorios\n");
    printf("4 - Importar dados externos\n");
    printf("5 - Sair\n");
    printf("\nOpcao Escolhida: ");
    scanf("%d", &opc);
    return opc;
}

//menu se escolheu clientes
void menuClientes(){
    int opc;
    do{
        printf("------------------------------------------\n");
        printf("           MENU CLIENTES              \n");
        printf("------------------------------------------\n");
        printf("Digite o numero da opcao escolhida:\n");
        printf("1 - Inserir novo cliente\n");
        printf("2 - Listar clientes ativos\n");
        printf("3 - Alterar dados do cliente\n");
        printf("4 - Ativar / Desativar Cliente\n");
        printf("5 - Listar clientes com cadastros incompletos\n");
        printf("6 - Sair\n");
        printf("\nOpcao Escolhida: ");
        scanf("%d", &opc);

        if(opc == 1){
            inserirCliente();
        }
        else if(opc == 2){
            listarDadosClientes();
        }
        else if(opc == 3){
            alterarDadosCliente();
        }
        else if(opc == 4){
            exclusaoLogicaCliente();
        }
        else if(opc == 5){
             listarClientesIncompletos();
        }
        else if(opc == 6){
            printf("\nRetornando para o menu principal...\n\n");
        }
        else{
            printf("Opcao inválida!\n\n");
        }
    }while(opc != 6);
}
//menu se escolheu compras
void menuCompras(){
    int opc;
    do{
        printf("------------------------------------------\n");
        printf("           MENU COMPRAS               \n");
        printf("------------------------------------------\n");
        printf("Digite o numero da opcao escolhida:\n");
        printf("1 - Inserir nova compra\n");
        printf("2 - Listar compras ativas\n");
        printf("3 - Alterar dados da compra\n");
        printf("4 - Ativar / Desativar Compra\n");
        printf("5 - Sair\n");
        printf("\nOpcao Escolhida: ");
        scanf("%d", &opc);

        if(opc == 1){
            inserirCompra();
        }
        else if(opc == 2){
            listarDadosCompras();
        }
        else if(opc == 3){
            alterarDadosCompra();
        }
        else if(opc == 4){
            exclusaoLogicaCompra();
        }
        else if(opc == 5){
            printf("\nRetornando para o menu principal...\n\n");
        }
        else{
            printf("Opcao inválida!\n\n");
        }
    }while(opc != 5);
}

void menuRelatorios(){
     int opc;
    do{
        printf("------------------------------------------\n");
        printf("          MENU RELATORIOS             \n");
        printf("------------------------------------------\n");
        printf("Digite o numero da opcao escolhida:\n");
        printf("1 - Listar todas as compras\n");
        printf("2 - Compras de um cliente especifico\n");
        printf("3 - Compras em um ano especifico\n");
        printf("4 - Compras nao quitadas\n");
        printf("5 - Sair\n");
        printf("\nOpcao Escolhida: ");
        scanf("%d", &opc);

        if(opc == 1){
            listarTodasAsCompras();
        }
        else if(opc == 2){
            busca_compra_especifica();
        }
        else if(opc == 3){
            buscar_compra_porAno();
        }
        else if(opc == 4){
            listarComprasNaoQuitadas();
        }
        else if(opc == 5){
            printf("\nRetornando para o menu principal...\n\n");
        }
        else{
            printf("Opcao inválida!\n\n");
        }
    }while(opc != 5);
}

void inserirCliente() {
    FILE *fc;//ponteiro para o arquivo de clientes
    char cpfNovo[14];
    int codigoNovo;
    Cliente novoCliente;// guardar os dados antes de salvar

    printf("------------------------------------------\n");
    printf("          CADASTRO CLIENTE            \n");
    printf("------------------------------------------\n");
    printf("CPF: ");
    scanf("\n%[^\n]s", cpfNovo);

	//checar se o cpf é valido
    if (validaCPF(cpfNovo) == 0) {
        printf("CPF INVÁLIDO! (deve ter 11 dígitos e ser numérico)\n");
        return;
    }
    //checa se já existe o cpf
    if (verificarCPFCliente(cpfNovo) != -1) {
        printf("O CPF digitado já está cadastrado no sistema!\n");
        return;
    }
    strcpy(novoCliente.CPF, cpfNovo);
    printf("Código: ");
    scanf("\n%d", &codigoNovo);

    //checa se já existe o código
    if(verificarCodigoCliente(&codigoNovo) != - 1){
		printf("Código já está cadastrado no sistema!\n");
		return;
	}
	novoCliente.codigo = codigoNovo;// aqui atribui o código a estrutura

    printf("Nome: ");
    scanf("\n%[^\n]s", novoCliente.nome);
    printf("Telefone: ");
    scanf("\n%[^\n]s", novoCliente.telefone);
    printf("Data de Nascimento: ");
    scanf("\n%[^\n]s", novoCliente.dataNasc);
    printf("Endereco: ");
    scanf("\n%[^\n]s", novoCliente.endereco);
    novoCliente.ativo = 1;

    // Grava dados no arquivo
    //Aqui tenta abrir o arquivo adicionando com "ab"
    //se nao existir um arquivo ele cria
    fc = fopen("Clientes.bin", "ab");
    if (fc != NULL) {
        fwrite(&novoCliente, sizeof(Cliente), 1, fc);//escreve
        fclose(fc);
        printf("Cliente cadastrado com sucesso!\n");
    }
    else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

int verificarCodigoCliente(int *codigoDigitado) {
    Cliente clienteCod;
    //O controle serve pra saber a posição do cliente no arquivo e encontrou é uma flag
    int controle = 0, encontrou = 0;
    FILE *fc;

    fc = fopen("Clientes.bin", "rb");
    if (fc == NULL) {
        return -1;
    }

	//loop para ler cada cliente no arquivo
    while (fread(&clienteCod, sizeof(Cliente), 1, fc)){
        if(clienteCod.codigo == *codigoDigitado){
            encontrou = 1;
            break;
        }
        controle++;//Aumenta o contador pra outra posição se nao encontrou
    }
    fclose(fc);
    if(encontrou == 1)
        return controle;
    else
        return -1;
}

int verificarCPFCliente(char *cpfDigitado) {
    Cliente clienteCpf;//Estrutura pra leitura
    //Contador de posição e flag
    int controle = 0, encontrou = 0;
    FILE *fc;

    fc = fopen("Clientes.bin", "rb");
    if (fc == NULL) {
        return -1;
    }
	//loop pra percorrer o arquivo
    while (fread(&clienteCpf, sizeof(Cliente), 1, fc)){
        if (strcmp(clienteCpf.CPF, cpfDigitado) == 0){//compara o cpf lido com o cpf que esta a procura
            encontrou = 1;
            break;
        }
        controle++;
    }
    fclose(fc);
    if(encontrou == 1)
        return controle;
    else
        return -1;
}

int validaCPF(char *cpf) {
    int cont = 0;// contador para os dgitos
    //esse for percorre cada caracter do cpf ate \0
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9'){// aqui ve se o caracter é numero
            cont++;
        } else {
            return 0;//cpf invalido
        }
    }
    return cont == 11;
}
void listarDadosClientes() {
    FILE *ptarq = fopen("Externo.txt", "r");
    if (ptarq == NULL) {
        printf("Arquivo Externo.txt não encontrado!\n\n");
        return;
    }

    printf("\n------------------------------------------\n");
    printf("          CLIENTES CADASTRADOS          \n");
    printf("------------------------------------------\n");

    char linha[256];
    char chave[50];
    char valor[200];
    Cliente clienteTemp;

    // Inicializar a estrutura temporária
    memset(&clienteTemp, 0, sizeof(Cliente));

    while (fgets(linha, sizeof(linha), ptarq) != NULL) {
        // Ignora linhas vazias
        if (strlen(linha) <= 1) {
            // Fim do registro, imprime se tiver dados de cliente
            if (clienteTemp.nome[0] != '\0') {
                printf("\nNome: %s\nCódigo: %d\n", clienteTemp.nome, clienteTemp.codigo);
                if (clienteTemp.rua[0] != '\0') printf("Endereço: %s", clienteTemp.rua);
                if (clienteTemp.numero != 0) printf(", %d", clienteTemp.numero);
                if (clienteTemp.bairro[0] != '\0') printf(", %s", clienteTemp.bairro);
                if (clienteTemp.telefone[0] != '\0') printf("\nTelefone: %s", clienteTemp.telefone);
                printf("\n\n");
            }
            // Limpa a estrutura para o próximo registro
            memset(&clienteTemp, 0, sizeof(Cliente));
            continue;
        }

        // Lê a chave e o valor da linha
        sscanf(linha, "%[^:]: %[^\n]", chave, valor);

        // Remove espaços em branco iniciais
        char *ptr = valor;
        while (*ptr == ' ') ptr++;

        if (strcmp(chave, "Nome") == 0) {
            strcpy(clienteTemp.nome, ptr);
        } else if (strcmp(chave, "Código do Cliente") == 0) {
            clienteTemp.codigo = atoi(ptr);
        } else if (strcmp(chave, "Rua") == 0) {
            strcpy(clienteTemp.rua, ptr);
        } else if (strcmp(chave, "Número") == 0) {
            clienteTemp.numero = atoi(ptr);
        } else if (strcmp(chave, "Bairro") == 0) {
            strcpy(clienteTemp.bairro, ptr);
        } else if (strcmp(chave, "Telefone") == 0) {
            strcpy(clienteTemp.telefone, ptr);
        }
    }

   
    if (clienteTemp.nome[0] != '\0') {
        printf("\nNome: %s\nCódigo: %d\n", clienteTemp.nome, clienteTemp.codigo);
        if (clienteTemp.rua[0] != '\0') printf("Endereço: %s", clienteTemp.rua);
        if (clienteTemp.numero != 0) printf(", %d", clienteTemp.numero);
        if (clienteTemp.bairro[0] != '\0') printf(", %s", clienteTemp.bairro);
        if (clienteTemp.telefone[0] != '\0') printf("\nTelefone: %s", clienteTemp.telefone);
        printf("\n\n");
    }

    printf("------------------------------------------\n\n");
    fclose(ptarq);
}


void alterarDadosCliente(){
    int cod;//codigo do cliente
    Cliente clienteAlt;//estrutura
    int controle;//guarda a posicao do cliente no arquivo
    int opc;//opcao

    printf("\n------------------------------------------\n");
    printf("          ALTERAR DADOS DO CLIENTE           \n");
    printf("------------------------------------------\n");
    printf("Codigo do cliente: ");
    scanf("\n%d", &cod);
    FILE *ptArq;//ponteiro para o arquivo
    ptArq = fopen("Clientes.bin", "r+b");//abre o arquivo para leitura e escrita
    if (ptArq == NULL) {
        printf("Nenhum registro está gravado no arquivo.\n");
        return;
    }

    //aqui busca o cliente e pega a posicao
    controle = verificarCodigoCliente(&cod);
    if(controle != -1){
		//se o cliente foi encontrado posiciona o ponteeiro do arquivo
		//no inicio do registro do cliente
        fseek(ptArq, (controle)*sizeof(Cliente), SEEK_SET);
        fread(&clienteAlt, sizeof(Cliente), 1, ptArq);//le os dados atuais
        printf("\n\nDados Encontrados: \nNome: %s\nCPF: %s\nTelefone: %s\nData de Nascimento: %s\nEndereco: %s\n\n", clienteAlt.nome, clienteAlt.CPF, clienteAlt.telefone, clienteAlt.dataNasc, clienteAlt.endereco);
        printf("Qual dado do cliente você deseja alterar\n");
        printf("1 - Nome\n");
        printf("2 - Telefone\n");
        printf("3 - Data de Nascimento\n");
        printf("4 - Endereco\n");
        printf("5 - CPF\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("Digite o novo nome: ");
            scanf("\n%[^\n]", clienteAlt.nome);
            printf("Nome alterado com sucesso!\n");
        } else if (opc == 2) {
            printf("Digite o novo telefone: ");
            scanf("\n%[^\n]", clienteAlt.telefone);
            printf("Telefone alterado com sucesso!\n");
        } else if (opc == 3) {
            printf("Digite a nova data de nascimento: ");
            scanf("\n%[^\n]", clienteAlt.dataNasc);
            printf("Data de Nascimento alterada com sucesso!\n");
        } else if (opc == 4) {
            printf("Digite o novo endereco: ");
            scanf("\n%[^\n]", clienteAlt.endereco);
            printf("Endereco alterado com sucesso!\n");
		}else if(opc == 5) {
			printf("Digite o novo CPF: ");
			scanf("\n%[^\n]", clienteAlt.CPF);
        }else{
            printf("Opcao inválida!\n");
        }

        //volta o ponteiro do arquivo para a posicao certa e escreve os dados atualizados
        //e com isso sobrescreve o registro antigo
        fseek(ptArq, controle * sizeof(Cliente), SEEK_SET);
        fwrite (&clienteAlt, sizeof(Cliente), 1, ptArq);
        printf("Dados atualizados com sucesso!\n");
    }
    else {
        printf("Registro não localizado!!!\n\n");
    }
    fclose(ptArq);
}

void exclusaoLogicaCliente(){
	int codNovo, encontrou = 0, opc;
	long int pos;//vai guardar a posicao do cliente no arquivo
	Cliente clienteNovo;
	FILE *ptArq;

	printf("\n------------------------------------------\n");
    printf("        ATIVAR / DESATIVAR CLIENTE         \n");
    printf("------------------------------------------\n");
    printf("Digite o codigo do cliente: ");
    scanf("%d", &codNovo);

    ptArq = fopen("Clientes.bin", "r+b");//abre o arquivo p/leitura-escrita
    if(ptArq == NULL){
		printf("Nenhum cliente cadastrado!\n");
		return;
	}
	//percorre o arquivo
	while (fread(&clienteNovo, sizeof(Cliente), 1, ptArq)){
        if(clienteNovo.codigo == codNovo){
            encontrou = 1;//flag
            pos = ftell(ptArq) - sizeof(Cliente);//aqui calcula a posicao dele no arquivo
            break;
        }
    }

    if(encontrou){
        printf("\n\nCliente encontrado: \n%s\n", clienteNovo.nome);
        printf("O que deseja fazer?\n");
        printf("1 - Ativar cliente\n");
        printf("2 - Desativar cliente\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opc);

		//volta o ponteiro para a posicao do cliente
		fseek(ptArq, pos, SEEK_SET);

        if (opc == 1) {
			if(clienteNovo.ativo == 1){
				printf("Cliente já está ativo!\n");
			}else{
				clienteNovo.ativo = 1;
				fwrite(&clienteNovo, sizeof(Cliente), 1, ptArq);
				printf("Cliente ativado com sucesso!\n");
			}
        }else if (opc == 2){
			if(clienteNovo.ativo == 0){
				printf("Cliente já está inativo!\n");
			}else{
				clienteNovo.ativo = 0;
				fwrite(&clienteNovo, sizeof(Cliente), 1, ptArq);
				printf("Cliente desativado com sucesso!\n");
			}
		}
	}

    fclose(ptArq);

}


void inserirCompra() {
    FILE *fcomp;
    Compra novaCompra;
    int codCliente;
    int codigoNovo;

    printf("------------------------------------------\n");
    printf("          CADASTRO COMPRA            \n");
    printf("------------------------------------------\n");
    printf("Código do cliente associado a esta compra: ");
    scanf("\n%d", &codCliente);

	//verifica se o cliente com codigo existe
    int clienteCodigo = verificarCodigoCliente(&codCliente);
    if (clienteCodigo == -1) {
        printf("Cliente com o código %d não encontrado. Cadastre o cliente primeiro.\n", codCliente);
        return;
    }

    // Preencher os dados da compra
    printf("Código da compra: ");
    scanf("\n%d", &codigoNovo);

    if(verificarCodigoCompra(&codigoNovo) != - 1){
		printf("Código já está cadastrado no sistema!\n");
		return;
	}

	novaCompra.codigoCompra = codigoNovo;// aqui atribui o código a estrutura

    printf("Data da Compra (DD/MM/AAAA): ");
    scanf("\n%[^\n]s", novaCompra.dataCompra);
    printf("Valor Total: ");
    scanf("%f", &novaCompra.valorTotal);
    printf("Forma de Pagamento: ");
    scanf("\n%[^\n]s", novaCompra.formaPag);
    printf("A compra está quitada? (S/N): ");
    scanf("\n%c", &novaCompra.quitada);
    novaCompra.codigoCliente = clienteCodigo; // Associar a compra ao cliente pelo código
    novaCompra.ativo = 1;//a compra  já comeca como ativa

    // Grava dados no arquivo
    fcomp = fopen("Compras.bin", "ab");
    if (fcomp != NULL) {
        fwrite(&novaCompra, sizeof(Compra), 1, fcomp);//escreve no arquivo
        fclose(fcomp);
        printf("Compra cadastrada com sucesso!\n");
    }
    else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

int verificarCodigoCompra(int *codigoComp){
    Compra compraCod;
    //O controle serve pra saber a posição do cliente no arquivo e encontrou é uma flag
    int controle = 0, encontrou = 0;
    FILE *fc;

    fc = fopen("Compras.bin", "rb");
    if (fc == NULL) {
        return -1;
    }

	//loop para ler cada cliente no arquivo
    while (fread(&compraCod, sizeof(Compra), 1, fc)){
        if(compraCod.codigoCompra == *codigoComp){
            encontrou = 1;
            break;
        }
        controle++;//Aumenta o contador pra outra posição se nao encontrou
    }
    fclose(fc);
    if(encontrou == 1)
        return controle;
    else
        return -1;
}

void listarDadosCompras(){
    Compra compra;//estrutura
    FILE *ptarq;//ponteiro arquivo
    ptarq = fopen ("Compras.bin", "rb");//abre para leitura binaria
    if (ptarq == NULL) {
        printf("Nenhuma compra cadastrada!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("          COMPRAS CADASTRADAS           \n");
    printf("------------------------------------------\n");
    //loop para mostrar as compras
    while(fread(&compra, sizeof (Compra), 1, ptarq)){
		if(compra.ativo == 1)
			printf("\nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\nCodigo da compra: %d\n\n", compra.dataCompra, compra.valorTotal, compra.formaPag, compra.quitada, compra.codigoCliente, compra.codigoCompra);
    }
    printf("------------------------------------------\n\n");
    fclose (ptarq);
}


void alterarDadosCompra(){
    int codigoCompraNovo;
    Compra compraNovo;//estrutura
    int controle = -1;//flag
    int opcao;

    printf("\n------------------------------------------\n");
    printf("          ALTERAR DADOS DA COMPRA           \n");
    printf("------------------------------------------\n");
    printf("Código da compra: ");
    scanf("%d", &codigoCompraNovo);
    FILE *ptArq;//ponteiro para o arquivo
    ptArq = fopen("Compras.bin", "r+b");//abre pra leitura e escrita binaria
    if (ptArq == NULL) {
        printf("Nenhum registro está gravado no arquivo.\n");
        return;
    }

    int pos = -1;//guarda a posicao da compra no arquivo
    while (fread(&compraNovo, sizeof(Compra), 1, ptArq)) {
        if (compraNovo.codigoCompra == codigoCompraNovo) {
            controle = 0;
            pos = ftell(ptArq) - sizeof(Compra);//calcular a posicao
            break;
        }
    }

    if(controle != -1){
        printf("\n\nDados Encontrados: \nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", compraNovo.dataCompra, compraNovo.valorTotal, compraNovo.formaPag, compraNovo.quitada, compraNovo.codigoCliente);
        printf("Qual dado da compra você deseja alterar\n");
        printf("1 - Data da Compra\n");
        printf("2 - Valor Total\n");
        printf("3 - Forma de Pagamento\n");
        printf("4 - Quitada\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite a nova data da compra: ");
            scanf("\n%[^\n]", compraNovo.dataCompra);
            printf("Data da Compra alterada com sucesso!\n");
        } else if (opcao == 2) {
            printf("Digite o novo valor total: ");
            scanf("%f", &compraNovo.valorTotal);
            printf("Valor Total alterado com sucesso!\n");
        } else if (opcao == 3) {
            printf("Digite a nova forma de pagamento: ");
            scanf("\n%[^\n]", compraNovo.formaPag);
            printf("Forma de Pagamento alterada com sucesso!\n");
        } else if (opcao == 4) {
            printf("A compra está quitada? (S/N): ");
            scanf("\n%c", &compraNovo.quitada);
            printf("Status de quitada alterado com sucesso!\n");
        } else{
            printf("Opcao inválida!\n");
        }
        fseek(ptArq, pos, SEEK_SET);//volta o ponteiro para a posicao da compra
        fwrite (&compraNovo, sizeof(Compra), 1, ptArq);//escreve os novos dados
        printf("Dados atualizados com sucesso!\n");
    }
    else {
        printf("Registro não localizado!!!\n\n");
    }
    fclose(ptArq);
}

void exclusaoLogicaCompra(){
	int codNovo, encontrou = 0, opc;
	long int pos;
	Compra compraNovo;
	FILE *ptArq;

	//Aqui a gente pede pro usuário o código do cliente da compra
	printf("\n------------------------------------------\n");
    printf("        ATIVAR / DESATIVAR COMPRA         \n");
    printf("------------------------------------------\n");
    printf("Digite o codigo da compra: ");
    scanf("%d", &codNovo);

    //Tenta abrir o arquivo de compras.bin para ler e escrever
    //r+b tem a função de ler e escrever em bináario
    ptArq = fopen("Compras.bin", "r+b");
    if(ptArq == NULL){
		printf("Nenhuma compra cadastrado!\n");
		return;
	}

	//Aqui vai andar pelo arquivo, lendo as compras
	//até encontrar o código
	while (fread(&compraNovo, sizeof(Compra), 1, ptArq)){
        if(compraNovo.codigoCompra == codNovo){
            encontrou = 1;//Marca como encontrado (1)
            //Aí calcula a posição da compra no arquivo com o ftell
            //ftell diz onde o ponteiro está, e a gente subtrai o tam da compra
            //pra voltar no início dela
            pos = ftell(ptArq) - sizeof(Compra);
            break;
        }
    }

	// Aqui se encontrou
    if(encontrou){
        printf("\n\nCompra encontrada: \n%2.f\n", compraNovo.valorTotal);
        printf("O que deseja fazer?\n");
        printf("1 - Ativar compra\n");
        printf("2 - Desativar compra\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opc);

		//Ai aqui volta o ponteiro pra posição da compra que achou
		fseek(ptArq, pos, SEEK_SET);

        if (opc == 1) {
			if(compraNovo.ativo == 1){
				printf("Cliente já está ativo!\n");
			}else{
				compraNovo.ativo = 1;
				fwrite(&compraNovo, sizeof(Compra), 1, ptArq);
				printf("Cliente ativado com sucesso!\n");
			}
        }else if (opc == 2){
			if(compraNovo.ativo == 0){
				printf("Cliente já está inativo!\n");
			}else{
				compraNovo.ativo = 0;
				fwrite(&compraNovo, sizeof(Compra), 1, ptArq);
				printf("Cliente desativado com sucesso!\n");
			}
		}
	}

    fclose(ptArq);

}

// Funçao de busca por codigo do cliente
void busca_compra_especifica(){
    FILE *pont_arq;
    int cod_cliente, encontrou = 0;
    Compra cod_cmp;
    pont_arq = fopen("Compras.bin","rb");

    printf("\n------------------------------------------\n");
    printf("        BUSCAR COMPRA ESPECIFICA      \n");
    printf("------------------------------------------\n");
    printf("Digite o codigo do cliente da compra: ");
    scanf("%d", &cod_cliente);

    if(pont_arq == NULL){
        printf("Nenhuma compra cadastrada!\n");
        return;
    }

    while (fread(&cod_cmp, sizeof(Compra), 1, pont_arq)){
        if(cod_cmp.codigoCliente == cod_cliente){
            encontrou = 1;
            printf("\n\nDados Encontrados: \nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", cod_cmp.dataCompra, cod_cmp.valorTotal, cod_cmp.formaPag, cod_cmp.quitada, cod_cmp.codigoCliente);
        }
    }

    if(!encontrou){
        printf("Nenhuma compra encontrada para o cliente com codigo %d.\n", cod_cliente);
    }

    fclose(pont_arq);
}

// Funcao de busca por ano
void buscar_compra_porAno(){
    FILE *pont_arq;
    int encontrou = 0;
    char ano_compra[5];
    Compra compra;
    pont_arq = fopen("Compras.bin","rb");

    printf("\n------------------------------------------\n");
    printf("        BUSCAR COMPRA POR ANO         \n");
    printf("------------------------------------------\n");
    printf("Digite o ano das compras (AAAA): ");
    scanf("\n%[^\n]s", ano_compra);

    if(pont_arq == NULL){
        printf("Nenhuma compra cadastrada!\n");
        return;
    }

    while (fread(&compra, sizeof(Compra), 1, pont_arq)){
        char ano_da_compra[5];
        strncpy(ano_da_compra, compra.dataCompra + 6, 4);
        ano_da_compra[4] = '\0';
        if(strcmp(ano_da_compra, ano_compra) == 0){
            encontrou = 1;
            printf("\n\nDados Encontrados: \nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", compra.dataCompra, compra.valorTotal, compra.formaPag, compra.quitada, compra.codigoCliente);
        }
    }
    if(!encontrou){
        printf("Nenhuma compra encontrada para o ano %s.\n", ano_compra);
    }
    fclose(pont_arq);
}

// Função para listar todas as compras, incluindo as inativas
void listarTodasAsCompras(){
    Compra compra;
    FILE *ptarq;
    ptarq = fopen ("Compras.bin", "rb");
    if (ptarq == NULL) {
        printf("Nenhuma compra cadastrada!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("        TODAS AS COMPRAS CADASTRADAS        \n");
    printf("------------------------------------------\n");
    while(fread(&compra, sizeof (Compra), 1, ptarq)){
        printf("\nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\nAtivo: %s\n\n", compra.dataCompra, compra.valorTotal, compra.formaPag, compra.quitada, compra.codigoCliente, compra.ativo == 1 ? "Sim" : "Nao");
    }
    printf("------------------------------------------\n\n");
    fclose (ptarq);
}

// Função para listar compras não quitadas
void listarComprasNaoQuitadas(){
    Compra compra;
    FILE *ptarq;
    ptarq = fopen ("Compras.bin", "rb");
    if (ptarq == NULL) {
        printf("Nenhuma compra cadastrada!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("        COMPRAS NAO QUITADAS        \n");
    printf("------------------------------------------\n");
    while(fread(&compra, sizeof (Compra), 1, ptarq)){
        if(compra.quitada == 'N' || compra.quitada == 'n'){
            printf("\nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", compra.dataCompra, compra.valorTotal, compra.formaPag, compra.quitada, compra.codigoCliente);
        }
    }
    printf("------------------------------------------\n\n");
    fclose (ptarq);
}

// Função para listar clientes com cadastros incompletos
void listarClientesIncompletos(){
    Cliente cliente;
    FILE *ptarq;
    char linha[256];
    //char chave[50];
    //char valor[200];
    ptarq = fopen("Externo.txt", "r");
    if(ptarq == NULL){
        printf("Nenhum cliente cadastrado!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("        CLIENTES COM CADASTRO INCOMPLETO     \n");
    printf("------------------------------------------\n");
    int encontrou = 0;

    memset(&cliente, 0, sizeof(Cliente));
    while(fgets(linha, sizeof(linha), ptarq)){
        // Corrigido para verificar se o primeiro caractere da string é nulo
        if(cliente.nome[0] == '\0' || cliente.CPF[0] == '\0' || cliente.dataNasc[0] == '\0' || cliente.rua[0] == '\0' || cliente.bairro[0] == '\0' || cliente.numero == 0 || cliente.telefone[0] == '\0'){
            encontrou = 1;
            printf("\nNome: %s\nCPF: %s\nCodigo: %d\nTelefone: %s\nData de Nascimento: %s\nEndereco: %s, %d, %s\n\n", cliente.nome, cliente.CPF, cliente.codigo, cliente.telefone, cliente.dataNasc, cliente.rua, cliente.numero, cliente.bairro);
        }
    }
    if(!encontrou){
        printf("Nenhum cliente com cadastro incompleto encontrado.\n");
    }
    printf("------------------------------------------\n\n");
    fclose(ptarq);
}

void importarDadosExternos() {
    FILE *ftxt, *fclientes, *fcompras;
    char linha[256];
    char chave[50];
    char valor[200];
    Cliente clienteImportado;
    Compra compraImportada;
    int novoCliente = 1;

    ftxt = fopen("Externo.txt", "r");
    if (ftxt == NULL) {
        printf("Erro ao abrir o arquivo Externo.txt. Certifique-se de que ele existe.\n");
        return;
    }

    fclientes = fopen("Clientes.bin", "ab");
    fcompras = fopen("Compras.bin", "ab");
    if (fclientes == NULL || fcompras == NULL) {
        printf("Erro ao abrir arquivos binários para escrita.\n");
        fclose(ftxt);
        if (fclientes) fclose(fclientes);
        if (fcompras) fclose(fcompras);
        return;
    }

    // Inicializa as estruturas uma única vez no início
    memset(&compraImportada,0, sizeof(Compra));
    memset(&clienteImportado,0, sizeof(Cliente));
    compraImportada.ativo = 1;
    clienteImportado.ativo = 1;


    while (fgets(linha, sizeof(linha), ftxt) != NULL) {
        if (strlen(linha) <= 1) continue;

        sscanf(linha, "%[^:]: %[^\n]", chave, valor);

        char *ptr = valor;
        while (*ptr == ' ') ptr++;

        if (strcmp(chave, "Data") == 0) {
            // Se um registro de compra anterior estava sendo preenchido, salve-o agora
            if (compraImportada.codigoCliente != 0) {
                fwrite(&compraImportada, sizeof(Compra), 1, fcompras);
                printf("Compra importada: Cliente %d, Data %s\n", compraImportada.codigoCliente, compraImportada.dataCompra);


                if(clienteImportado.codigo != 0 && novoCliente){
                    fwrite(&clienteImportado, sizeof(Cliente), 1, fclientes);
                    printf(">>> Novo cliente importado: %s (Codigo: %d)\n", clienteImportado.nome, clienteImportado.codigo);
                }

            }
            memset(&compraImportada, 0, sizeof(Compra));
            memset(&clienteImportado, 0, sizeof(Cliente));
            compraImportada.ativo = 1;
            clienteImportado.ativo = 1;
            novoCliente = 1;

            strcpy(compraImportada.dataCompra, ptr);

        } else if (strcmp(chave, "Valor") == 0) {
            compraImportada.valorTotal = atof(ptr);
        } else if (strcmp(chave, "Forma de Pagamento") == 0) {
            strcpy(compraImportada.formaPag, ptr);
        } else if (strcmp(chave, "Quitada") == 0) {
            compraImportada.quitada = ptr[0];
        } else if (strcmp(chave, "Codigo do Cliente") == 0) {
            int codigoAtual = atoi(ptr);
            compraImportada.codigoCliente = codigoAtual;
            clienteImportado.codigo = codigoAtual;


            if(verificarCodigoCliente(&codigoAtual) != -1) {
                novoCliente = 0; // Cliente já existe, não é novo
            } else {
                novoCliente = 1; // Cliente não foi encontrado, é novo
            }
        } else if (strcmp(chave, "Nome") == 0 && novoCliente) {
            strcpy(clienteImportado.nome, ptr);
        } else if (strcmp(chave, "Rua") == 0 && novoCliente) {
            strcpy(clienteImportado.rua, ptr);
        } else if (strcmp(chave, "Numero") == 0 && novoCliente) {
            clienteImportado.numero = atoi(ptr);
        } else if (strcmp(chave, "Bairro") == 0 && novoCliente) {
            strcpy(clienteImportado.bairro, ptr);
        } else if (strcmp(chave, "Telefone") == 0 && novoCliente) {
            strcpy(clienteImportado.telefone, ptr);
        } else if (strcmp(chave, "CPF") == 0 && novoCliente) {
            strcpy(clienteImportado.CPF, ptr);
        }
    }
    if (compraImportada.codigoCliente != 0) {
        fwrite(&compraImportada, sizeof(Compra), 1, fcompras);
        printf("Compra importada: Cliente %d, Data %s\n", compraImportada.codigoCliente, compraImportada.dataCompra);
        if(clienteImportado.codigo != 0 && novoCliente){
            fwrite(&clienteImportado, sizeof(Cliente), 1, fclientes);
            printf(">>> Novo cliente importado: %s (Codigo: %d)\n", clienteImportado.nome, clienteImportado.codigo);
        }
    }

    printf("\nImportação concluída com sucesso!\n");
    fclose(ftxt);
    fclose(fclientes);
    fclose(fcompras);
}
