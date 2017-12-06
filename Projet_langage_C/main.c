#include <stdio.h>

{
	int resultat;
	resultat=-1;
	if(n >= 0)
	{
		resultat = 0;
		for(int i = 0; i <= n ; i = i + 1)
		{
			resultat=resultat+i;
		}
	}
	return resultat;
}
int somme_recursif(int n)
{
	if (n<0)
	{
		return -1;
	}
	if (n==1)
	{
		return 1;
	}
	else
		return n+somme_recursif(n-1);
}
int somme_recursif_bis(int n,int somme)
{
	if (n<0)
	{
		return -1;
	}
	if (n==0)
	{
		return somme;
	}
	else
	{
		somme = somme + n;
		return somme_recursif_bis(n-1, somme);
	}
}
int fibonacci_iteratif(int n)
{
	int resultat_fibo = -1;
	int resultat_fibo_2 = 0;
	if (n < 0)
		{resultat_fibo = -1;}
	else if (n == 0)
		{resultat_fibo = 0;}
	else if(n > 0) {
		resultat_fibo = 1;
		int variable_tampon;
		for (int i = 0 ; i < n ; i = i + 1) {
			if(i != 0) {
				variable_tampon = resultat_fibo;
				resultat_fibo = resultat_fibo + resultat_fibo_2;
				resultat_fibo_2 = variable_tampon;
			}
		}
	}

	return resultat_fibo;
}
int  fibonacci_recursif(int n)
{
	if (n<0)
		return -1;
	if (n==0||n==1)
		return n;
	
	return fibonacci_recursif(n-1) + fibonacci_recursif(n-2);
}
void fibonacci_recursif_bis(int rang, int nombre_1, int nombre_2, int somme)
{
	if (nombre_1==1)
		return nombre_1;
	if (nombre_2==1)
		return nombre_2;
	return fibonacci_recursif_bis(nombre_1,somme)
}
void exo_1()
{
	printf("Entrez un nombre svp : ");
	int n;
	scanf ("%d", &n);
	int resultat;
	printf("\nla valeur entiere est : %d\n",n);
	resultat = somme_iteratif(n);
	printf("la somme iterative est : %d\n",resultat);
	resultat = somme_recursif(n);
	printf("la somme recursive est : %d\n",resultat);

}
void exo_2()
{
	printf("Entrez un nombre svp : ");
	int n;
	scanf ("%d", &n);
	int resultat;
	printf("\nla valeur entiere est : %d\n",n);
	resultat = somme_iteratif(n);
	printf("la somme iterative est : %d\n",resultat);
	resultat = somme_recursif(n);
	printf("la somme recursive est : %d\n",resultat);
}
void exo_3()
{
	printf("Entrez un nombre svp : ");
	int n;
	scanf ("%d", &n);
	int resultat;
	printf("\nla valeur entiere est : %d\n",n);
	resultat = somme_iteratif(n);
	printf("la somme iterative est : %d\n",resultat);
	resultat = somme_recursif(n);
	printf("la somme recursive est : %d\n",resultat);
	resultat = somme_recursif_bis(n,0);
	printf("la 2e somme recursive est : %d\n",resultat);
}
void exo_4()
{
	printf("Choisissez le rang de la suite de Fibonacci que vous voulez connaitre :  ");
	int n;
	scanf ("%d", &n);
		int resultat = fibonacci_iteratif(n) ;
		printf("\nle %de rang de la suite de Fibonacci par methode iterative est : %d\n",n,resultat);
		resultat = fibonacci_recursif(n);
		printf("\nle %de rang de la suite de Fibonacci par methode recursive est : %d\n\n\n",n,resultat);
}
void exo_5()
{
}


int main(int argc, char **argv)
{
	/*exo_1();
	exo_2();
	exo_3();*/
	exo_4();
	return 0;
}
