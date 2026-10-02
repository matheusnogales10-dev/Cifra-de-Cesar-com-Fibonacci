#include <stdio.h>
#include <string.h>

// Matheus Nogales dos Santos, RGM: 47810629
// Carlos Eduardo ALves Lopes da Silva, RGM: 48465097
// Lucas Gabriel de Oliveira Castro, RGM: 47627891
// Karoline Almeida de Araújo, RGM: 48379867

int main() {
    char palavra_secreta[15];
    char palavra_criptografada[15];
    int shift = 0;
    int i;

    // Leitura dos dados de entrada
    printf("Digite uma palavra (sem acentos): ");
    scanf("%14s", palavra_secreta); // Leitura correta para string
    
    printf("Digite um valor de SHIFT: ");
    scanf("%d", &shift);

    int tam = strlen(palavra_secreta);

    // Inicialização da Série de Fibonacci (1, 1, 2, 3, 5, 8, ...)
    int fib1 = 1, fib2 = 1, fib_atual;

    // Processamento da Criptografia por caractere
    for (i = 0; i < tam; i++) {
        // Determina o termo atual da sequência de Fibonacci
        if (i == 0) {
            fib_atual = 1;
        } else if (i == 1) {
            fib_atual = 1;
        } else {
            fib_atual = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib_atual;
        }

        // Deslocamento total = SHIFT + termo de Fibonacci
        int deslocamento = shift + fib_atual;

        // Processa letras minúsculas ('a' até 'z')
        if (palavra_secreta[i] >= 'a' && palavra_secreta[i] <= 'z') {
            palavra_criptografada[i] = 'a' + (palavra_secreta[i] - 'a' + deslocamento) % 26;
        } 
        // Processa letras maiúsculas ('A' até 'Z')
        else if (palavra_secreta[i] >= 'A' && palavra_secreta[i] <= 'Z') {
            palavra_criptografada[i] = 'A' + (palavra_secreta[i] - 'A' + deslocamento) % 26;
        } 
        // Mantém outros caracteres inalterados
        else {
            palavra_criptografada[i] = palavra_secreta[i];
        }
    }
    palavra_criptografada[tam] = '\0'; // Finaliza a string

    // Exibe o resultado no console
    printf("\nPalavra criptografada: %s\n", palavra_criptografada);

    // Gravação no arquivo resultado_criptografia.txt
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: Fibonacci | Letras: %d\n", 
                palavra_criptografada, shift, tam);
        fclose(arquivo);
        printf("Resultado salvo em 'resultado_criptografia.txt' com sucesso!\n");
    } else {
        printf("Erro ao criar o arquivo de saída.\n");
    }

    return 0;
}
