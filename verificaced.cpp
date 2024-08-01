



#include <iostream>
using namespace std;

bool CedulaCorrecta(int cedula[], int total)
{
    int sumapar=0, sumaimpar=0;
    for(int k=0; k<total-1; k++)
    {
        int num = cedula[k];
        if (k % 2 == 0)
        {
            num *= 2; // multiplicar posiciones pares por 2
            if(num >= 10)
                num -= 9; // si el resultado es >= 10, se resta 9
            sumapar += num;
        }
        else // posiciones impares
        {
            sumaimpar += cedula[k];
        }
    }

    int suma = sumapar + sumaimpar;

    // aplicamos modulo 10
    int resto = suma % 10;
    int digitoVer = (resto == 0) ? 0 : 10 - resto;

    // validamos si el digito coincide con el ultimo numero de la cedula
    return digitoVer == cedula[total-1];
}

int main()
{
    int cedula[]= {}
    int total = sizeof(cedula)/sizeof(cedula[0]);
    if(CedulaCorrecta(cedula, total))
        cout << "La cedula es correcta" << endl;
    else
        cout << "La cedula no es correcta" << endl;

    return 0;
}
