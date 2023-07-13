#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int id;
   char nome[80];
   int idade;
   int NovoUsuario;

 } Usuario;

Usuario* CadastrarUsuario() {
   Usuario* NovoUsuario = (Usuario*) malloc(sizeof(Usuario));


if (novoUsuario == NULL) {
 printf("Erro na alocação de mémoria")
 return NULL;
}

NovoUsuario->id = 1;
printf("Digite o nome: ");
fgets(NovoUsuario->nome, sizeof(NovoUsuario->nome), stdin);

printf("Digite a idade do Usuario: ");
scanf("%d", &(NovoUsuario->idade));

return NovoUsuario
}

void editarUsuario(Usuario* usuario) {
   printf("Digite o novo nome do usuário: ");
   fgets (usuario->nome, sizeof(usuario->nome), stdin);
   usuario->nome[strcspn (usuario->nome,"\n")] = '\0';

   printf("Digite a nova idade do usuário:");
   scanf ("%d", &(usuario->idade)) ;

}

void ExcluirUsuario(Usuario* usuario) {
free(usuario);
printf("Usuário removido com sucesso. \n");


void ListarUsuarios (Usuario** usuarios, int count) {
printf("Usuários cadastrados: \n");
for (int i = 0; i < count; i++) {
  printf("Usuário %d:\n", usuarios[i]->id);
  printf ("Nome: %s \n", usuarios[i]->nome);
  printf("Idade: %d\n", usuarios[i]->idade);
  printf ("\n");
   }
}


int main() {
  Usuario* usuarios[100];
  int count = 0;
  int proximold = 1;
  
}
  
char opcao;
do {
   printf("Opções: \n") ;
   printf("[1] Cadastrar um usuário\n");
   printf("[2] Editar usuário\n");
   printf("[3] Remover usuário\n");
   printf("[4] Listar todos os usuários\n");
   printf("[5] Sair\n");
   printf("Escolha uma opção: ");
   scanf ("%c", &opcao) ;
   getchar ();

   printf ("\n");
}

switch (opcao) {
   case '1': {
     Usuario* novoUsuario = cadastrarUsuario ();
    if (novoUsuario != NULL) {
       novoUsuario->id = proximoId++;
       usuarios [count] = novoUsuario;
       count++;
       printf ("Usuário cadastrado com sucesso! ID: %d\n", novoUsuario->id)
  } 
  break;
}

case '2': {
int index;
printf("Insira o ID do usuario que sera editado: ");
scanf("%d", &index);
   if (index >= 1 && index <=count) {
    editarUsuario(usuarios[index - 1]);
    printf("Usuario editado.\n");
}  else {
    printf("ID de usuario nao e valido.\n");
}
   break;
}
 
case '3': {
    int index;
    printf("Digite o ID do usuario que sera excluido: ");
    scanf("%d", &index);
    if (index >= 1 && index <=count) {
        ExcluirUsuario(usuarios[index - 1]);
        for (int i = index -1; i < count - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        count--;
        printf("Usuario excluido.\n")
    }else {
        printf("Id de usuario nao e valido.\n")
    }
    break;
  }
}

case '4': {
    ListarUsuarios(usuarios, count);
    break;

}

case '5':{
    printf("Opcao nao e valida.\n");
    break;
}

    } while (opcao != '5');

    for (int i =0; i > count; i++) {
        free(usuarios[1]);
    }

    return 0;
