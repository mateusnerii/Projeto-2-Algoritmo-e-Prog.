#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MILUSUARIOS 1000
#define CARACTERESNOME 50
#define CARACTERESEMAIL 40
#define CARACTERESEND 100

typedef struct {
    int id;
    char nome[CARACTERESNOME];
    char email[CARACTERESEMAIL];
    char sexo[CARACTERESNOME];
    char endereco[CARACTERESEND];
    double altura;
    int vacinado;
} Usuario;

Usuario usuarios[MILUSUARIOS];
int numCadastros = 0;

int IDnumero() {
    return rand() % 10001 + 5;
}

int VerificarEmail(const char* email) {
    return strchr(email, '@') != NULL;
}

int VerificarGenero(const char* gender) {
    return strcmp(gender, "F") == 0 || strcmp(gender, "M") == 0 || strcmp(gender, "I") == 0;
}

int ValidacaoAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}

int ValidacaoVacina(int vacina) {
    return vacina == 0 || vacina == 1;
}

void adicionarusuario() {
    if (numCadastros >= MILUSUARIOS) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.id = IDnumero();

    printf("Insira seu nome: ");
    fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Insira seu email: ");
    fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
    novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';

    while (!VerificarEmail(novoUsuario.email)) {
        printf("Email inválido. Digite novamente: ");
        fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
        novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';
    }

    printf("Qual seu sexo? (M, F ou I): ");
    fgets(novoUsuario.sexo, sizeof(novoUsuario.sexo), stdin);
    novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';

    while (!VerificarGenero(novoUsuario.sexo)) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(novoUsuario.sexo, sizeof(novoUsuario.sexo), stdin);
        novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';
    }

    printf("Digite o endereço: ");
    fgets(novoUsuario.endereco, sizeof(novoUsuario.endereco), stdin);
    novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario.altura);

    while (!ValidacaoAltura(novoUsuario.altura)) {
        printf("Apenas valores entre 1 e 2 metros. Digite novamente: ");
        scanf("%lf", &novoUsuario.altura);
    }

    printf("Informe se o usuário está vacinado (0 = não vacinado ou 1 = vacinado): ");
    scanf("%d", &novoUsuario.vacinado);

    while (!ValidacaoVacina(novoUsuario.vacinado)) {
        printf("Opção inválida. Digite novamente (0 = não vacinado ou 1 = vacinado): ");
        scanf("%d", &novoUsuario.vacinado);
    }

    usuarios[numCadastros] = novoUsuario;
    numCadastros++;
    printf("Usuário adicionado com sucesso.\n");
}

void exibirusuarios() {
    if (numCadastros == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    printf("ID\tNome\tEmail\tSexo\tEndereço\tAltura\tVacinado\n");

    for (int i = 0; i < numCadastros; i++) {
        Usuario usuario = usuarios[i];
        printf("%d\t%s\t%s\t%s\t%s\t%.2f\t%d\n", usuario.id, usuario.nome, usuario.email, usuario.sexo, usuario.endereco, usuario.altura, usuario.vacinado);
    }
}

int main() {
    int opcao;

    do {
        printf("==== Menu ====\n");
        printf("1 - Adicionar usuário\n");
        printf("2 - Exibir usuários cadastrados\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarusuario();
                break;
            case 2:
                exibirusuarios();
                break;
            case 0:
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}