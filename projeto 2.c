#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100

typedef struct {
    int id;
    char nome[50];
    char email[50];
    char sexo[2];
    char endereco[100];
    double altura;
    int vacinado;
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int numCadastros = 0;

int VerificarEmail(const char *email) {
   
    return 1;
}

int VerificarGenero(const char *genero) {
 
    return 1;
}

int ValidacaoAltura(double altura) {
 
    return 1;
}

int ValidacaoVacina(int vacinado) {

    return 1;
}

void cadastrarusuario() {
    if (numCadastros == MAX_USUARIOS) {
        printf("Limite de usuários atingido.\n");
        return;
    }

    Usuario usuario;

    printf("Digite o ID: ");
    scanf("%d", &usuario.id);

    printf("Digite o nome: ");
    getchar();
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(usuario.email, sizeof(usuario.email), stdin);
    usuario.email[strcspn(usuario.email, "\n")] = '\0';

    while (!VerificarEmail(usuario.email)) {
        printf("Email inválido. Digite novamente: ");
        fgets(usuario.email, sizeof(usuario.email), stdin);
        usuario.email[strcspn(usuario.email, "\n")] = '\0';
    }

    printf("Digite o sexo (M, F ou I): ");
    fgets(usuario.sexo, sizeof(usuario.sexo), stdin);
    usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';

    while (!VerificarGenero(usuario.sexo)) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(usuario.sexo, sizeof(usuario.sexo), stdin);
        usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';
    }

    printf("Digite o endereço: ");
    fgets(usuario.endereco, sizeof(usuario.endereco), stdin);
    usuario.endereco[strcspn(usuario.endereco, "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &usuario.altura);

    while (!ValidacaoAltura(usuario.altura)) {
        printf("Apenas valores entre 1 e 2 metros. Digite novamente: ");
        scanf("%lf", &usuario.altura);
    }

    printf("Você foi vacinado? (0 = não vacinado, 1 = vacinado): ");
    scanf("%d", &usuario.vacinado);

    while (!ValidacaoVacina(usuario.vacinado)) {
        printf("Opção inválida. Digite novamente (0 = não vacinado ou 1 = vacinado): ");
        scanf("%d", &usuario.vacinado);
    }

    usuarios[numCadastros] = usuario;
    numCadastros++;

    printf("Usuário cadastrado com sucesso.\n");
}

void listarusuarios() {
    if (numCadastros == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    printf("Lista de Usuários:\n");
    for (int i = 0; i < numCadastros; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf metros\n", usuarios[i].altura);
        printf("Situação de vacinação: %s\n", usuarios[i].vacinado ? "Vacinado" : "Não vacinado");
        printf("\n");
    }
}

void editarusuario() {
    int id;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < numCadastros; i++) {
        if (usuarios[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuário com o ID %d não encontrado.\n", id);
        return;
    }

    Usuario usuario = usuarios[indice];

    printf("Editando usuário:\n");
    printf("ID: %d\n", usuario.id);
    printf("Nome atual: %s\n", usuario.nome);
    printf("Novo nome: ");
    getchar();
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

    printf("Email atual: %s\n", usuario.email);
    printf("Novo email: ");
    fgets(usuario.email, sizeof(usuario.email), stdin);
    usuario.email[strcspn(usuario.email, "\n")] = '\0';

    while (!VerificarEmail(usuario.email)) {
        printf("Email inválido. Digite novamente: ");
        fgets(usuario.email, sizeof(usuario.email), stdin);
        usuario.email[strcspn(usuario.email, "\n")] = '\0';
    }

    printf("Sexo atual: %s\n", usuario.sexo);
    printf("Novo sexo (M, F ou I): ");
    fgets(usuario.sexo, sizeof(usuario.sexo), stdin);
    usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';

    while (!VerificarGenero(usuario.sexo)) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(usuario.sexo, sizeof(usuario.sexo), stdin);
        usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';
    }

    printf("Endereço atual: %s\n", usuario.endereco);
    printf("Novo endereço: ");
    fgets(usuario.endereco, sizeof(usuario.endereco), stdin);
    usuario.endereco[strcspn(usuario.endereco, "\n")] = '\0';

    printf("Altura atual: %.2lf metros\n", usuario.altura);
    printf("Nova altura (entre 1 e 2 metros): ");
    scanf("%lf", &usuario.altura);

    while (!ValidacaoAltura(usuario.altura)) {
        printf("Apenas valores entre 1 e 2 metros. Digite novamente: ");
        scanf("%lf", &usuario.altura);
    }

    printf("Situação de vacinação atual: %s\n", usuario.vacinado ? "Vacinado" : "Não vacinado");
    printf("Nova situação de vacinação (0 = não vacinado, 1 = vacinado): ");
    scanf("%d", &usuario.vacinado);

    while (!ValidacaoVacina(usuario.vacinado)) {
        printf("Opção inválida. Digite novamente (0 = não vacinado ou 1 = vacinado): ");
        scanf("%d", &usuario.vacinado);
    }

    usuarios[indice] = usuario;

    printf("Usuário editado com sucesso.\n");
}

void excluirusuario() {
    int id;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < numCadastros; i++) {
        if (usuarios[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuário com o ID %d não encontrado.\n", id);
        return;
    }

    for (int i = indice; i < numCadastros - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }

    numCadastros--;

    printf("Usuário excluído com sucesso.\n");
}

void buscarUsuarioPeloEmail() {
    char email[50];
    printf("Digite o email do usuário que deseja buscar: ");
    getchar();
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    int encontrados = 0;
    for (int i = 0; i < numCadastros; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf metros\n", usuarios[i].altura);
            printf("Situação de vacinação: %s\n", usuarios[i].vacinado ? "Vacinado" : "Não vacinado");
            printf("\n");

            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum usuário encontrado com o email '%s'.\n", email);
    }
}

int main() {
    int opcao;

    do {
        printf("----- MENU -----\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Listar usuários\n");
        printf("3 - Editar usuário\n");
        printf("4 - Excluir usuário\n");
        printf("5 - Buscar usuário pelo email\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarusuario();
                break;
            case 2:
                listarusuarios();
                break;
            case 3:
                editarusuario();
                break;
            case 4:
                excluirusuario();
                break;
            case 5:
                buscarUsuarioPorEmail();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}