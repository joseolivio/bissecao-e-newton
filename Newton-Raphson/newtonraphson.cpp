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

// Funcao(progamacao) que deriva a funcao(matematica)
double derivFunc(double x)
{
    double barril;
    barril = ((func(x+EPSILON) - func(x))/EPSILON); // calcula a derivada, lembra quando a gente calculava derivada pelo limite em calculo 1?
    return barril;
}


void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x); // variavel h apenas para facilitar a visualizacao ( nao fui eu que fiz essa porra )
    int c=1;

    while (abs(h) >= EPSILON) // LAÇO DE REPETIÇÃO, CONDIÇÃO DE PARADA,:o valor de h seja menor que o epsilon...
    {
        h = func(x)/derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x) <--- formula de Newton Raphson
        x = x - h;
        // Aumentei a precisao do x ( setprecision() ) para ter uma visao mais nitida da diferenca da raiz nas ultimas iteraçoes...
        cout << "Iteracao numero:" << c << "   Raiz aproximada: " << setprecision(15)<< x << endl;
        c++;
    }

}

int main()
{
    double x0 = 1.5; // VALOR INICIAL, NECESSARIO NO METODO DE NEWTON RAPHSON, TU TEM Q PEGAR DO USUARIO ISSO AQUI TAMBEM..
    newtonRaphson(x0);
    return 0;
}
