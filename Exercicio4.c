#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

struct Livro{
    char titulo[100];
    char autor[50];
    int ano;
};

typedef struct Livro Livro;
int main(){

    //Inicialização de Variáveis:
    Livro livro[5] = { {"Cem Anos de Solidao", "Gabriel Garcia", 1967},{"1984", "George Orwell", 1949}, 
                       {"Memorias Postumas", "Machado de Assis", 1881},
                       {"Dom Casmurro", "Machado de Assis", 1899}, {"Orgulho e Preconceito", "Jane Austen", 1813} };
    int i, j;
    char autor[50];
    char autoresExi[5][50];
    int contagem = 0;
    int encontrou = 0;
    
    //Listagem de Autores Únicos (sem repetição):
    printf("Todos os autores disponiveis:\n\n");

    for(i = 0; i < 5; i++){
        int jamostrado = 0;

        // Verifica se o autor já foi mostrado.
        for(j = 0; j < contagem; j++){
            if(strcmp(livro[i].autor, autoresExi[j]) == 0){
                jamostrado = 1;
                break;
            }
        }
        
        // Se não foi mostrado, imprime e salva no vetor.
        if(!jamostrado){
        printf("\tNome do autor:\n \t%s.\n", livro[i].autor);
        printf("-------------------------------\n");

        strcpy(autoresExi[contagem], livro[i].autor);
        contagem++;
        }
    }
    
    //Entrada do Nome do Autor:
    printf("Escreva o nome de algum deles e veja suas obras: \n");
    fgets(autor, 50, stdin);
    fflush(stdin);
    
    //Remoção do \n do Nome Digitado:
    autor[strcspn(autor, "\n")] = '\0';

    system("cls");

    // Busca e Exibição dos Livros do Autor:
    for(i = 0; i < 5; i++){

    if(strcasecmp(autor, livro[i].autor) == 0){ //São iguais independente de maiusculas e minusculas.
    
        if(encontrou == 0){
        printf("\nObras cadastradas do(a) autor(a) %s:\n", livro[i].autor);
    }
        printf("\nTitulo do livro: %s.\n", livro[i].titulo);
        printf("Ano de lancamento: %d.\n", livro[i].ano);
        printf("-------------------------------");
        encontrou = 1;
        }
      }
    
    //Mensagem Caso Nenhum Livro Seja Encontrado
    if(encontrou == 0){
        printf("Nao foi encontrado nada relacionado a esse autor...");
        return 0;
    }
    return 0;
}