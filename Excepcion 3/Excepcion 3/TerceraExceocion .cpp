#include <iostream>
#include <cmath>
#include <string>

using namespace std;
						//Declaracion de constantes en C
#define EDOMINIO 100//Para los numeros negativos
#define ERRANGO 101 //Pra el cero dentro del log


class ErroMath {
private:
	int motivo;//100 o 101
public:
	ErroMath(int m):motivo(m) {}
	const char* porque()const throw();


};

const char* ErroMath::porque() const throw()
{
	switch (motivo) {
	case EDOMINIO:return "Error de dominio";
		break;
	case ERRANGO:return "Error de Rango";
		break;
	default:return "";
	}

}

//----------------------------------------------------

double logaritmo(double n) {//n es el valor del que se quiere saber su logaritmo

	if (n < 0)
		throw (ErroMath(EDOMINIO));
	if (n == 0)throw (ErroMath(ERRANGO));

	return log(n);//Se retorna el logaritmo de manera natural

}


int main() {
	double r;
	bool f = true;
	char resp;
	do {

		cout << "Ingresar el valor para conocer su log";
		cin >> r;
		try {
			cout << "El resultado es " << logaritmo(r) << endl << endl;

		}
		catch (ErroMath& e) {
			cout << "ERROR" << endl;
			cout << e.porque() << endl;
			system("pause");

		}



		cout << "Desea continuar s/n";//Obligar a que sea una s o una n

		cin >> resp;

		if (resp == 'n' || resp == 'N') {
			f = false;
		}
	
	} while (f);
	
	cout << "Finalizado" << endl;
	return 0;

}