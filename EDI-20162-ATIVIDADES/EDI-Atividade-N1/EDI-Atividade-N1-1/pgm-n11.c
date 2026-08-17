#include <stdio.h>

// Diretiva de pré-processador: Define o tamanho fixo da turma
#define TAMANHO_TURMA 5

// Funções
void exibirCabecalho(void);
float calcularMedia(float vetor[], int tamanho);
void simularAjuste(float notaOriginal, float bonus);
void aplicarBonus(float *nota, float bonus);

// Implementação da função sem passagem de parâmetros
void exibirCabecalho(void) {
    printf("=================================\n");
    printf("SISTEMA DE NOTAS - TURMA ADS\n");
    printf("=================================\n");
}

// Implementação da função com passagem de parâmetro (vetor/percurso)
float calcularMedia(float vetor[], int tamanho) {
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma / tamanho;
}

// Implementação da função com passagem por valor
void simularAjuste(float notaOriginal, float bonus) {
    float resultado = notaOriginal + bonus;
    printf("Simulacao para o aluno 1: %.2f + %.2f = %.2f (nao aplicado ainda)\n", notaOriginal, bonus, resultado);
}

// Implementação da função com passagem por referência (ponteiro)
void aplicarBonus(float *nota, float bonus) {
    *nota = *nota + bonus;
}

int main()
{
    // Declaração do vetor com a constante simbólica definida.
    float notas[TAMANHO_TURMA];
    float bonus;
    // Chamada da função de cabeçalho
    exibirCabecalho();
    
    // Preenchimento do vetor interativamente
    for (int i = 0; i < TAMANHO_TURMA; i++) {
        printf("Nota do Aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    // Entrada do valor de bônus
    printf("Informe o valor do bonus a aplicar: ");
    scanf("%f", &bonus);
    printf("\n");
    
    // Cálculo e exibição da média original
    float mediaAntes = calcularMedia(notas, TAMANHO_TURMA);
    printf("--- Media da turma antes do ajuste ---\n");
    printf("Media inicial: %.2f\n\n", mediaAntes);
    
    // Simulação do ajuste (Passagem por Valor)
    printf("--- Simulacao do ajuste (passagem por valor) ---\n");
    simularAjuste(notas[0], bonus);
    printf("Nota do aluno 1 apos a simulacao (inalterada): %.2f\n\n", notas[0]);
    
    // Aplicação do bônus (Passagem por Referência)
    printf("--- Aplicacao real do bonus (passagem por referencia) ---\n");
    for (int i = 0; i < TAMANHO_TURMA; i++) {
        aplicarBonus(&notas[i], bonus);
    }
    printf("Bonus de %.2f aplicado a todas as notas da turma.\n\n", bonus);
    
    // Percurso final para notas atualizadas
    printf("--- Notas finais da turma ---\n");
    for (int i = 0; i < TAMANHO_TURMA; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }
    printf("\n");
    
    // Cálculo e exibição da média após o ajuste
    float mediaDepois = calcularMedia(notas, TAMANHO_TURMA);
    printf("--- Media da turma apos o ajuste ---\n");
    printf("Media final: %.2f\n", mediaDepois);

    return 0;
}