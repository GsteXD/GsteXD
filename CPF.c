#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int calculaDigito(int cpf[], int mult[], int N)
{   int i, soma=0;
	for(i=0; i<N; i++){
	    soma = soma + cpf[i]*mult[i];
	}
	int resto = ((soma*10) % 11)%10;
	return resto;
}

bool verificaNAORepetido(int cpf[]) {
    for(int i=1;i<11;i++){
        if (cpf[0] != cpf[i]) {
            return false;
        }
    }
    return true;
}

void OrigemCPF(int cpf[]){
    char regioes[10][100] = //matriz de caracteres determinando as 10 regiões e o números de caracteres máximo(100)
    {
        "* 0 Rio Grande do Sul",
        "* 1 Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins",
        "* 2 Amazonas, Pará, Roraima, Amapá, Acre e Rondônia",
        "* 3 Ceará, Maranhão e Piauí",
        "* 4 Paraíba, Pernambuco, Alagoas e Rio Grande do Norte",
        "* 5 Bahia e Sergipe",
        "* 6 Minas Gerais",
        "* 7 Rio de Janeiro e Espírito Santo",
        "* 8 São Paulo",
        "* 9 Paraná e Santa Catarina",
    };
    printf("\n%s", regioes[ cpf[8] ]);
}

int main() {
    
    int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i, j=0, tam, menu;
	char entrada[50]; //Define o máximo de caracteres permitidos na variável "entrada"
	//Lembrete: O programa sabe que uma string chegou no seu último caracter pois ele lê todos os valores que são diferentes de 0.
	//Ou seja, ao encontrar "0", acaba o programa.
	printf("Informe a operação que deseja realizar: \n1-CPF\n2-CNPJ\nResposta: ");
	scanf("%i", &menu);
	fflush(stdin); //limpa os inputs de scanf

	switch(menu){
		case 1:
			printf("Entre com os 11 digitos do CPF:");
			fgets(entrada, 50, stdin); //Scanf para strings, lembrar de usar "fgets" invés de "gets", pois gets não possui um limitador de array
			//stdin significa que o programa está pegando inputs do teclado
			tam = strlen(entrada); //Atribuí o tamanho da string em "entrada" e guarda em "tam"
			for(i=0;i<tam;i++){
				if(entrada[i] >= 48 && entrada[i] <= 57){ //Verifica se os valores apresentados correspondem com os números de 0 a 9 da tabela ASCII.
					cpf[j] = entrada[i]-48; //Pega o valor convertido pela "entrada" em ASCII e subtraí 48 para dar o valor em decimal
					j++; //passa para a próxima posição de CPF
				}
			}
			
			if(calculaDigito(cpf, m1, 9) == cpf[9] && calculaDigito(cpf, m2, 10) == cpf[10] && verificaNAORepetido(cpf) == false){
				printf("\nCPF válido.");
				OrigemCPF(cpf);
			}
			else printf("\nErro no CPF");
			return 0;

		case 2:
		default:
			break;	
	}
	
}


