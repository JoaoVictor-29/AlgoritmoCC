#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    int codigo;
    char nome[50];
    char CPF[14];
    char telefone[12];
    char dataNasc[13];
    char endereco[50];
    int ativo;
} Cliente;

typedef struct{
    char dataCompra[13];
    float valorTotal;
    char formaPag[25];
    char quitada;
    int codigoCliente;
    int ativo;
} Compra;

// Protótipos das funções
int menuPrincipal();
void menuClientes();
void menuCompras();

// Funções de Cliente
void inserirCliente();
void listarDadosClientes();
void alterarDadosCliente();
int verificarCodigoCliente(int *codigoDigitado);
int verificarCPFCliente(char *cpfDigitado);
int validaCPF(char *cpf);

// Funções de Compra
void inserirCompra();
void listarDadosCompras();
void alterarDadosCompra();

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int opc;
    do{
        opc = menuPrincipal();
        if(opc == 1){
            menuClientes();
        }
        else if(opc == 2){
            menuCompras();
        }
        else if(opc == 3){
            printf("\nEncerrando o programa...");
            exit(1);
        }
        else{
            printf("\nOpcao inválida!\n");
        }
    }while(opc != 3);

    return 0;
}

int menuPrincipal(){
    int opc;
    printf("------------------------------------------\n");
    printf("          MENU PRINCIPAL           \n");
    printf("------------------------------------------\n");
    printf("Digite o numero da opcao escolhida:\n");
    printf("1 - Clientes\n");
    printf("2 - Compras\n");
    printf("3 - Sair\n");
    printf("\nOpcao Escolhida: ");
    scanf("%d", &opc);
    return opc;
}

void menuClientes(){
    int opc;
    do{
        printf("------------------------------------------\n");
        printf("          MENU CLIENTES           \n");
        printf("------------------------------------------\n");
        printf("Digite o numero da opcao escolhida:\n");
        printf("1 - Inserir novo cliente\n");
        printf("2 - Listar\n");
        printf("3 - Alterar dados do cliente\n");
        printf("4 - Sair\n");
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
            printf("\nRetornando para o menu principal...\n\n");
        }
        else{
            printf("Opcao inválida!\n\n");
        }
    }while(opc != 4);
}

void menuCompras(){
    int opc;
    do{
        printf("------------------------------------------\n");
        printf("          MENU COMPRAS           \n");
        printf("------------------------------------------\n");
        printf("Digite o numero da opcao escolhida:\n");
        printf("1 - Inserir nova compra\n");
        printf("2 - Listar\n");
        printf("3 - Alterar dados da compra\n");
        printf("4 - Sair\n");
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
            printf("\nRetornando para o menu principal...\n\n");
        }
        else{
            printf("Opcao inválida!\n\n");
        }
    }while(opc != 4);
}

void inserirCliente() {
    FILE *fc;
    char cpfNovo[14];
    int codigoNovo;
    Cliente novoCliente;

    printf("------------------------------------------\n");
    printf("          CADASTRO CLIENTE            \n");
    printf("------------------------------------------\n");
    printf("CPF: ");
    scanf("\n%[^\n]s", cpfNovo);

    if (validaCPF(cpfNovo) == 0) {
        printf("CPF INVÁLIDO! (deve ter 11 dígitos e ser numérico)\n");
        return;
    }
    if (verificarCPFCliente(cpfNovo) != -1) {
        printf("O CPF digitado já está cadastrado no sistema!\n");
        return;
    }
    strcpy(novoCliente.CPF, cpfNovo);
    printf("Código: ");
    scanf("\n%d", &codigoNovo);
    
    if(verificarCodigoCliente(&codigoNovo) != - 1){
		printf("Código já está cadastrado no sistema!\n");
		return;
	}
	novoCliente.codigo = codigoNovo;

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
    fc = fopen("Clientes.bin", "ab");
    if (fc != NULL) {
        fwrite(&novoCliente, sizeof(Cliente), 1, fc);
        fclose(fc);
        printf("Cliente cadastrado com sucesso!\n");
    }
    else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

int verificarCodigoCliente(int *codigoDigitado) {
    Cliente clienteCod;
    int controle = 0, encontrou = 0;
    FILE *fc;

    fc = fopen("Clientes.bin", "rb");
    if (fc == NULL) {
        return -1;
    }

    while (fread(&clienteCod, sizeof(Cliente), 1, fc)){
        if(clienteCod.codigo == *codigoDigitado){
            encontrou = 1;
            break;
        }
        controle++;
    }
    fclose(fc);
    if(encontrou == 1)
        return clienteCod.codigo;
    else
        return -1;
}

int verificarCPFCliente(char *cpfDigitado) {
    Cliente clienteTemp;
    int controle = 0, encontrou = 0;
    FILE *fc;

    fc = fopen("Clientes.bin", "rb");
    if (fc == NULL) {
        return -1;
    }

    while (fread(&clienteTemp, sizeof(Cliente), 1, fc)) {
        if (strcmp(clienteTemp.CPF, cpfDigitado) == 0) {
            encontrou = 1;
            break;
        }
        controle++;
    }
    fclose(fc);
    if(encontrou == 1)
        return clienteTemp.codigo;
    else
        return -1;
}

int validaCPF(char *cpf) {
    int cont = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cont++;
        } else {
            return 0;
        }
    }
    return cont == 11;
}

void listarDadosClientes(){
    Cliente cliente;
    FILE *ptarq;
    ptarq = fopen ("Clientes.bin", "rb");
    if (ptarq == NULL) {
        printf("Nenhum cliente cadastrado!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("          CLIENTES CADASTRADOS           \n");
    printf("------------------------------------------\n");
    while(fread(&cliente, sizeof (Cliente), 1, ptarq)){
        printf("\nNome: %s\nCPF: %s\nTelefone: %s\nData de Nascimento: %s\nEndereco: %s\n\n", cliente.nome, cliente.CPF, cliente.telefone, cliente.dataNasc, cliente.endereco);
    }
    printf("------------------------------------------\n\n");
    fclose (ptarq);
}


void alterarDadosCliente(){
    int codTemp;
    Cliente clienteTemp;
    int controle;
    int opcaoTemp;

    printf("\n------------------------------------------\n");
    printf("          ALTERAR DADOS DO CLIENTE           \n");
    printf("------------------------------------------\n");
    printf("Codigo do cliente: ");
    scanf("\n%d", &codTemp);
    FILE *ptArq;
    ptArq = fopen("Clientes.bin", "r+b");
    if (ptArq == NULL) {
        printf("Nenhum registro está gravado no arquivo.\n");
        return;
    }
    controle = verificarCodigoCliente(&codTemp);
    if(controle != -1){
        fseek(ptArq, (controle)*sizeof(Cliente), SEEK_SET);
        fread(&clienteTemp, sizeof(Cliente), 1, ptArq);
        printf("\n\nDados Encontrados: \nNome: %s\nCPF: %s\nTelefone: %s\nData de Nascimento: %s\nEndereco: %s\n\n", clienteTemp.nome, clienteTemp.CPF, clienteTemp.telefone, clienteTemp.dataNasc, clienteTemp.endereco);
        printf("Qual dado do cliente você deseja alterar (exceto CPF)\n");
        printf("1 - Nome\n");
        printf("2 - Telefone\n");
        printf("3 - Data de Nascimento\n");
        printf("4 - Endereco\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoTemp);

        if (opcaoTemp == 1) {
            printf("Digite o novo nome: ");
            scanf("\n%[^\n]", clienteTemp.nome);
            printf("Nome alterado com sucesso!\n");
        } else if (opcaoTemp == 2) {
            printf("Digite o novo telefone: ");
            scanf("\n%[^\n]", clienteTemp.telefone);
            printf("Telefone alterado com sucesso!\n");
        } else if (opcaoTemp == 3) {
            printf("Digite a nova data de nascimento: ");
            scanf("\n%[^\n]", clienteTemp.dataNasc);
            printf("Data de Nascimento alterada com sucesso!\n");
        } else if (opcaoTemp == 4) {
            printf("Digite o novo endereco: ");
            scanf("\n%[^\n]", clienteTemp.endereco);
            printf("Endereco alterado com sucesso!\n");
        } else{
            printf("Opcao inválida!\n");
        }
        fseek(ptArq, controle * sizeof(Cliente), SEEK_SET);
        fwrite (&clienteTemp, sizeof(Cliente), 1, ptArq);
        printf("Dados atualizados com sucesso!\n");
    }
    else {
        printf("Registro não localizado!!!\n\n");
    }
    fclose(ptArq);
}

void inserirCompra() {
    FILE *fcomp;
    Compra novaCompra;
    int codCliente;

    printf("------------------------------------------\n");
    printf("          CADASTRO COMPRA            \n");
    printf("------------------------------------------\n");
    printf("Código do cliente associado a esta compra: ");
    scanf("\n%d", &codCliente);

    int clienteCodigo = verificarCodigoCliente(&codCliente);
    if (clienteCodigo == -1) {
        printf("Cliente com o código %d não encontrado. Cadastre o cliente primeiro.\n", codCliente);
        return;
    }

    // Preencher os dados da compra
    printf("Data da Compra (DD/MM/AAAA): ");
    scanf("\n%[^\n]s", novaCompra.dataCompra);
    printf("Valor Total: ");
    scanf("%f", &novaCompra.valorTotal);
    printf("Forma de Pagamento: ");
    scanf("\n%[^\n]s", novaCompra.formaPag);
    printf("A compra está quitada? (S/N): ");
    scanf("\n%c", &novaCompra.quitada);
    novaCompra.codigoCliente = clienteCodigo; // Associar a compra ao cliente pelo código
    novaCompra.ativo = 1;

    // Grava dados no arquivo
    fcomp = fopen("Compras.bin", "ab");
    if (fcomp != NULL) {
        fwrite(&novaCompra, sizeof(Compra), 1, fcomp);
        fclose(fcomp);
        printf("Compra cadastrada com sucesso!\n");
    }
    else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

void listarDadosCompras(){
    Compra compra;
    FILE *ptarq;
    ptarq = fopen ("Compras.bin", "rb");
    if (ptarq == NULL) {
        printf("Nenhuma compra cadastrada!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("          COMPRAS CADASTRADAS           \n");
    printf("------------------------------------------\n");
    while(fread(&compra, sizeof (Compra), 1, ptarq)){
        printf("\nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", compra.dataCompra, compra.valorTotal, compra.formaPag, compra.quitada, compra.codigoCliente);
    }
    printf("------------------------------------------\n\n");
    fclose (ptarq);
}


void alterarDadosCompra(){
    int codigoClienteTemp;
    Compra compraTemp;
    int controle = -1;
    int opcaoTemp;

    printf("\n------------------------------------------\n");
    printf("          ALTERAR DADOS DA COMPRA           \n");
    printf("------------------------------------------\n");
    printf("Código do cliente associado a compra: ");
    scanf("%d", &codigoClienteTemp);
    FILE *ptArq;
    ptArq = fopen("Compras.bin", "r+b");
    if (ptArq == NULL) {
        printf("Nenhum registro está gravado no arquivo.\n");
        return;
    }

    int pos = -1;
    while (fread(&compraTemp, sizeof(Compra), 1, ptArq)) {
        if (compraTemp.codigoCliente == codigoClienteTemp) {
            controle = 0;
            pos = ftell(ptArq) - sizeof(Compra);
            break;
        }
    }

    if(controle != -1){
        printf("\n\nDados Encontrados: \nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", compraTemp.dataCompra, compraTemp.valorTotal, compraTemp.formaPag, compraTemp.quitada, compraTemp.codigoCliente);
        printf("Qual dado da compra você deseja alterar\n");
        printf("1 - Data da Compra\n");
        printf("2 - Valor Total\n");
        printf("3 - Forma de Pagamento\n");
        printf("4 - Quitada\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoTemp);

        if (opcaoTemp == 1) {
            printf("Digite a nova data da compra: ");
            scanf("\n%[^\n]", compraTemp.dataCompra);
            printf("Data da Compra alterada com sucesso!\n");
        } else if (opcaoTemp == 2) {
            printf("Digite o novo valor total: ");
            scanf("%f", &compraTemp.valorTotal);
            printf("Valor Total alterado com sucesso!\n");
        } else if (opcaoTemp == 3) {
            printf("Digite a nova forma de pagamento: ");
            scanf("\n%[^\n]", compraTemp.formaPag);
            printf("Forma de Pagamento alterada com sucesso!\n");
        } else if (opcaoTemp == 4) {
            printf("A compra está quitada? (S/N): ");
            scanf("\n%c", &compraTemp.quitada);
            printf("Status de quitada alterado com sucesso!\n");
        } else{
            printf("Opcao inválida!\n");
        }
        fseek(ptArq, pos, SEEK_SET);
        fwrite (&compraTemp, sizeof(Compra), 1, ptArq);
        printf("Dados atualizados com sucesso!\n");
    }
    else {
        printf("Registro não localizado!!!\n\n");
    }
    fclose(ptArq);
}
