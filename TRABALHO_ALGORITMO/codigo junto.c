#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estrutura de Clientes
typedef struct{
    int codigo;
    char nome[50];
    char CPF[14];
    char telefone[12];
    char dataNasc[13];
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
} Compra;

// Protótipos das funções
int menuPrincipal();
void menuClientes();
void menuCompras();
void menuRelatorios();

// Funções de Cliente
void inserirCliente();
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
    do{
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
    }while(opc != 5);

    return 0;
}

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
    FILE *fc;
    char cpfNovo[14];
    int codigoNovo;
    Cliente novoCliente;

    printf("------------------------------------------\n");
    printf("           CADASTRO CLIENTE            \n");
    printf("------------------------------------------\n");
    printf("CPF (11 digitos): ");
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
    scanf("%d", &codigoNovo);

    // Verifica se o código é um número positivo
    if(codigoNovo <= 0){
        printf("Código inválido! O código deve ser um número positivo.\n");
        return;
    }

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
    printf("Rua: ");
    scanf("\n%[^\n]s", novoCliente.rua);
    printf("Numero: ");
    scanf("%d", &novoCliente.numero);
    printf("Bairro: ");
    scanf("\n%[^\n]s", novoCliente.bairro);
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
        return controle;
    else
        return -1;
}

int verificarCPFCliente(char *cpfDigitado) {
    Cliente clienteCpf;
    int controle = 0, encontrou = 0;
    FILE *fc;

    fc = fopen("Clientes.bin", "rb");
    if (fc == NULL) {
        return -1;
    }

    while (fread(&clienteCpf, sizeof(Cliente), 1, fc)) {
        if (strcmp(clienteCpf.CPF, cpfDigitado) == 0) {
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
    printf("           CLIENTES CADASTRADOS(ATIVOS)          \n");
    printf("------------------------------------------\n");

    int encontrou = 0; // Flag para verificar se pelo menos um cliente ativo foi encontrado
    while(fread(&cliente, sizeof (Cliente), 1, ptarq)){
        if(cliente.ativo == 1){
            encontrou = 1;
            printf("\nNome: %s\nCPF: %s\nCodigo: %d\nTelefone: %s\nData de Nascimento: %s\nEndereco: %s, %d, %s\n\n", cliente.nome, cliente.CPF, cliente.codigo, cliente.telefone, cliente.dataNasc, cliente.rua, cliente.numero, cliente.bairro);
        }
    }

    if(encontrou == 0) {
        printf("Nao existem clientes ativos.\n");
    }

    printf("------------------------------------------\n\n");
    fclose (ptarq);
}

void alterarDadosCliente(){
    int cod;
    Cliente clienteAlt;
    int controle;
    int opc;
    char novoCpf[14];

    printf("\n------------------------------------------\n");
    printf("           ALTERAR DADOS DO CLIENTE        \n");
    printf("------------------------------------------\n");
    printf("Codigo do cliente: ");
    scanf("%d", &cod);
    FILE *ptArq;
    ptArq = fopen("Clientes.bin", "r+b");
    if (ptArq == NULL) {
        printf("Nenhum registro está gravado no arquivo.\n");
        return;
    }
    controle = verificarCodigoCliente(&cod);
    if(controle != -1){
        fseek(ptArq, (controle)*sizeof(Cliente), SEEK_SET);
        fread(&clienteAlt, sizeof(Cliente), 1, ptArq);
        printf("\n\nDados Encontrados: \nNome: %s\nCPF: %s\nTelefone: %s\nData de Nascimento: %s\nEndereco: %s, %d, %s\n\n", clienteAlt.nome, clienteAlt.CPF, clienteAlt.telefone, clienteAlt.dataNasc, clienteAlt.rua, clienteAlt.numero, clienteAlt.bairro);
        printf("Qual dado do cliente você deseja alterar?\n");
        printf("1 - Nome\n");
        printf("2 - Telefone\n");
        printf("3 - Data de Nascimento\n");
        printf("4 - Rua\n");
        printf("5 - Numero\n");
        printf("6 - Bairro\n");
        printf("7 - CPF\n");
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
            printf("Digite a nova rua: ");
            scanf("\n%[^\n]", clienteAlt.rua);
            printf("Rua alterada com sucesso!\n");
        } else if (opc == 5) {
            printf("Digite o novo numero: ");
            scanf("%d", &clienteAlt.numero);
            printf("Numero alterado com sucesso!\n");
        } else if (opc == 6) {
            printf("Digite o novo bairro: ");
            scanf("\n%[^\n]", clienteAlt.bairro);
            printf("Bairro alterado com sucesso!\n");
        } else if (opc == 7) {
            printf("Digite o novo CPF (11 digitos): ");
            scanf("\n%[^\n]", novoCpf);

            if (validaCPF(novoCpf) == 0) {
                printf("CPF INVÁLIDO! (deve ter 11 dígitos e ser numérico)\n");
                fclose(ptArq);
                return;
            }
            if (verificarCPFCliente(novoCpf) != -1) {
                printf("O CPF digitado já está cadastrado no sistema!\n");
                fclose(ptArq);
                return;
            }
            strcpy(clienteAlt.CPF, novoCpf);
            printf("CPF alterado com sucesso!\n");
        } else{
            printf("Opcao inválida!\n");
            fclose(ptArq);
            return;
        }

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
    long int pos;
    Cliente clienteNovo;
    FILE *ptArq;

    printf("\n------------------------------------------\n");
    printf("        ATIVAR / DESATIVAR CLIENTE      \n");
    printf("------------------------------------------\n");
    printf("Digite o codigo do cliente: ");
    scanf("%d", &codNovo);

    ptArq = fopen("Clientes.bin", "r+b");
    if(ptArq == NULL){
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    while (fread(&clienteNovo, sizeof(Cliente), 1, ptArq)){
        if(clienteNovo.codigo == codNovo){
            encontrou = 1;
            pos = ftell(ptArq) - sizeof(Cliente);
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
    printf("           CADASTRO COMPRA            \n");
    printf("------------------------------------------\n");
    printf("Código do cliente associado a esta compra: ");
    scanf("%d", &codCliente);

    if (verificarCodigoCliente(&codCliente) == -1) {
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
    novaCompra.codigoCliente = codCliente; // Associar a compra ao cliente pelo código
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
    printf("           COMPRAS CADASTRADAS (ATIVAS)          \n");
    printf("------------------------------------------\n");
    while(fread(&compra, sizeof (Compra), 1, ptarq)){
        if(compra.ativo == 1)
            printf("\nData da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\nCodigo do Cliente: %d\n\n", compra.dataCompra, compra.valorTotal, compra.formaPag, compra.quitada, compra.codigoCliente);
    }
    printf("------------------------------------------\n\n");
    fclose (ptarq);
}

void alterarDadosCompra(){
    int codigoClienteNovo;
    Compra compraNovo;
    int encontrou = 0;
    int opcao;
    int count = 0;
    long int posicoes[100]; // Armazena as posições das compras encontradas
    Compra comprasEncontradas[100]; // Armazena as compras encontradas

    printf("\n------------------------------------------\n");
    printf("           ALTERAR DADOS DA COMPRA        \n");
    printf("------------------------------------------\n");
    printf("Código do cliente associado a compra: ");
    scanf("%d", &codigoClienteNovo);

    FILE *ptArq = fopen("Compras.bin", "r+b");
    if (ptArq == NULL) {
        printf("Nenhum registro está gravado no arquivo.\n");
        return;
    }

    while (fread(&compraNovo, sizeof(Compra), 1, ptArq)) {
        if (compraNovo.codigoCliente == codigoClienteNovo && compraNovo.ativo == 1) {
            encontrou = 1;
            posicoes[count] = ftell(ptArq) - sizeof(Compra);
            comprasEncontradas[count] = compraNovo;
            count++;
        }
    }

    if(encontrou){
        printf("\nCompras encontradas para o cliente %d:\n", codigoClienteNovo);
        for(int i = 0; i < count; i++){
            printf("\n--- Compra %d ---\n", i + 1);
            printf("Data da Compra: %s\nValor Total: %.2f\nForma de Pagamento: %s\nQuitada: %c\n", comprasEncontradas[i].dataCompra, comprasEncontradas[i].valorTotal, comprasEncontradas[i].formaPag, comprasEncontradas[i].quitada);
        }

        int escolha;
        printf("\nQual compra você deseja alterar? (1 a %d): ", count);
        scanf("%d", &escolha);
        escolha--; // Ajusta para o índice do array

        if(escolha >= 0 && escolha < count){
            compraNovo = comprasEncontradas[escolha];

            printf("\nQual dado da compra você deseja alterar\n");
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
            fseek(ptArq, posicoes[escolha], SEEK_SET);
            fwrite(&compraNovo, sizeof(Compra), 1, ptArq);
            printf("Dados atualizados com sucesso!\n");
        } else {
            printf("Opção de compra inválida!\n");
        }
    }
    else {
        printf("Nenhuma compra ativa encontrada para o cliente com código %d.\n", codigoClienteNovo);
    }
    fclose(ptArq);
}

void exclusaoLogicaCompra(){
    int codNovo, encontrou = 0, opc;
    long int pos;
    Compra compraNovo;
    FILE *ptArq;

    printf("\n------------------------------------------\n");
    printf("        ATIVAR / DESATIVAR COMPRA       \n");
    printf("------------------------------------------\n");
    printf("Digite o codigo do cliente da compra: ");
    scanf("%d", &codNovo);

    ptArq = fopen("Compras.bin", "r+b");
    if(ptArq == NULL){
        printf("Nenhuma compra cadastrada!\n");
        return;
    }

    while (fread(&compraNovo, sizeof(Compra), 1, ptArq)){
        if(compraNovo.codigoCliente == codNovo){
            encontrou = 1;
            pos = ftell(ptArq) - sizeof(Compra);
            break;
        }
    }

    if(encontrou){
        printf("\n\nCompra encontrada do cliente: %d\n", compraNovo.codigoCliente);
        printf("Valor: %2.f\n", compraNovo.valorTotal);
        printf("O que deseja fazer?\n");
        printf("1 - Ativar compra\n");
        printf("2 - Desativar compra\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opc);

        fseek(ptArq, pos, SEEK_SET);

        if (opc == 1) {
            if(compraNovo.ativo == 1){
                printf("Compra já está ativa!\n");
            }else{
                compraNovo.ativo = 1;
                fwrite(&compraNovo, sizeof(Compra), 1, ptArq);
                printf("Compra ativada com sucesso!\n");
            }
        }else if (opc == 2){
            if(compraNovo.ativo == 0){
                printf("Compra já está inativa!\n");
            }else{
                compraNovo.ativo = 0;
                fwrite(&compraNovo, sizeof(Compra), 1, ptArq);
                printf("Compra desativada com sucesso!\n");
            }
        } else {
            printf("Opção inválida!\n");
        }
    } else {
        printf("Registro não localizado!!!\n\n");
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
    ptarq = fopen("Clientes.bin", "rb");
    if(ptarq == NULL){
        printf("Nenhum cliente cadastrado!\n\n");
        return;
    }
    printf("\n------------------------------------------\n");
    printf("        CLIENTES COM CADASTRO INCOMPLETO     \n");
    printf("------------------------------------------\n");
    int encontrou = 0;
    while(fread(&cliente, sizeof(Cliente), 1, ptarq)){
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
