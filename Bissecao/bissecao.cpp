#include<iostream>
#include<cmath>

using namespace std;
#define EPSILON 0.01
#define PI 3,14159


double funcao(float x) // AQUI TU DETERMINA A FUNÇAO, A BIBLIOTECA CMATH TEM A PORRA TODA, EXPONENCIAL, LOG,ETC.. http://www.cplusplus.com/reference/cmath/
{
    /*float abc;
    abc = (((0.3*PI*x*x)*(9-x)) - 1);
    cout << abc << endl;*/
    return ((0.3*PI*pow(x,2)*(9-x)) -1); // TEM QUE DEFINIR A FUNÇÃO AQUI
}


void bissecao(float a, float b) // INTERVALOS A e B
{
    if (funcao(a) * funcao(b) >= 0)
    {
        cout << "Não existe raiz nesse intervalo \n";
        return;
    }

    float c = a;
    while ((b-a) >= EPSILON)
    {
        // ACHA O PONTO MEDIO
        c = (a+b)/2;

        // VERIFICA SE O PONTO MEDIO JA É A RAIZ
        if (funcao(c) == 0.0)
            break;

        // VE QUAL SERA O NOVO INTERVALO
        else if (funcao(c)*funcao(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}


int main()
{
    // intervalos
    float a = 0.3, b = 0.5;
    bissecao(a, b);
    return 0;
}
