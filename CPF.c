#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int
calculaDigito (int cpf[], int mult[], int N)
{
  int i, soma = 0;
  for (i = 0; i < N; i++)
	{
	  soma = soma + cpf[i] * mult[i];
	}
  int resto = ((soma * 10) % 11) % 10;
  return resto;
}

bool
verificaNAORepetido (int cpf[])
{
  for (int i = 1; i < 11; i++)
	{
	  if (cpf[0] != cpf[i])
		{
		  return false;
		}
	}
  return true;
}

void
OrigemCPF (int cpf[])
{
  char regioes[10][100] =		//matriz de caracteres determinando as 10 regiC5es e o nC:meros de caracteres mC!ximo(100)
  {
	"* 0 Rio Grande do Sul",
	"* 1 Distrito Federal, GoiC!s, Mato Grosso, Mato Grosso do Sul e Tocantins",
	"* 2 Amazonas, ParC!, Roraima, AmapC!, Acre e RondC4nia",
	"* 3 CearC!, MaranhC#o e PiauC-",
	"* 4 ParaC-ba, Pernambuco, Alagoas e Rio Grande do Norte",
	"* 5 Bahia e Sergipe",
	"* 6 Minas Gerais",
	"* 7 Rio de Janeiro e EspC-rito Santo",
	"* 8 SC#o Paulo",
	"* 9 ParanC! e Santa Catarina",
  };
  printf ("\n%s", regioes[cpf[8]]);
}

int
main ()
{

  int cpf[11];
  int m1[9] = { 10, 9, 8, 7, 6, 5, 4, 3, 2 };
  int m2[10] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };
  int i, j = 0, tam;
  char entrada[50];				//Define o mC!ximo de caracteres permitidos na variC!vel "entrada"
  //Lembrete: O programa sabe que uma string chegou no seu C:ltimo caracter pois ele lC* todos os valores que sC#o diferentes de 0.
  //Ou seja, ao encontrar "0", acaba o programa.
  printf ("Entre com os 11 digitos do CPF:");
  fgets (entrada, 50, stdin);	//Scanf para strings, lembrar de usar "fgets" invC)s de "gets", pois gets nC#o possui um limitador de array
  //stdin significa que o programa estC! pegando inputs do teclado
  tam = strlen (entrada);		//AtribuC- o tamanho da string em "entrada" e guarda em "tam"
  for (i = 0; i < tam; i++)
	{
	  if (entrada[i] >= 48 && entrada[i] <= 57)
		{						//Verifica se os valores apresentados correspondem com os nC:meros de 0 a 9 da tabela ASCII.
		  cpf[j] = entrada[i] - 48;	//Pega o valor convertido pela "entrada" em ASCII e subtraC- 48 para dar o valor em decimal
		  j++;					//passa para a prC3xima posiC'C#o de CPF
		}
	}

  if (calculaDigito (cpf, m1, 9) == cpf[9]
	  && calculaDigito (cpf, m2, 10) == cpf[10]
	  && verificaNAORepetido (cpf) == false)
	{
	  printf ("\nCPF vC!lido.");
	  OrigemCPF (cpf);
	}
  else
	printf ("\nErro no CPF");
  return 0;
}