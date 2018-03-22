#include <bits/stdc++.h> // DAQUI A GENTE USA A FUNÇAO ABS() QUE DÁ O VALOR ABSOLUTO DO NUMERO... ( linha 30 )
#include <cmath> // PARA MAIS INFORMAÇOES, CONSULTE: http://www.cplusplus.com/reference/cmath/
#define EPSILON 0.0000000000001 // APROXIMACAO SUFICIENTE
#define PI 3.14159

using namespace std;


double func(double x)
{
    // aqui tu define a função, vai ter q receber do usuario pelo site la, a biblioteca cmath tem a porra toda (exponencial,cosseno,logaritmo,etc..)
    //return (pow(x,3) - pow(x,2) -1);
    return ((0.3*PI*pow(x,2)*(9-x))-1); // funcao que caiu na prova..
}

void bissecao(double a, double b)
{
    int count =1; // contador para contar iteraçoes
    // verifica se o intervalo inserido é valido, para ser valido essa multiplicacao tem que dar menor que 0;
    if ((func(a) * func(b)) >= 0)
    {
        cout << "Interalo invalido, nao temos raizes no intervalo ou podemos ter mais de uma raiz e isso causou um problema!.\n";
        return;
    }

    double c = a; // esse c é o intervalo de cima, vulgo a aproximacao da raiz..
    while ((b-a) >= EPSILON) // condicao de parada...
    {

        c = (a+b)/2; // pega o valor medio


        if (func(c) == 0.0) // verifica se é zero, se for zero já achou a raiz..
            break;


        else if (func(c)*func(a) < 0) // aqui faz a nova verificao para determinar o novo intervalo..
            b = c;
        else
            a = c;

    cout << "Iteracao numero:" << count << "   Raiz aproximada:" << setprecision(15) << c << endl;
    count++;
    }

}


int main()
{

    double a =0, b = 1; // aqui é definido os intervalos a e b, isso aqui tu pega do usuario..
    bissecao(a, b);
    return 0;
}
