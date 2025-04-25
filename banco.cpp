#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

void mostrarSaldo(double saldo);
double deposito ();
double retirar(double saldo);
void limpiarCodigoPrevio();


int main () {

    double saldo = 500;
    int opc = 0;

    do {
       std::cout << "-------------------" << std::endl;
       std::cout << "    BANCO INTERBANK \n";
       std::cout << "-------------------" << std::endl;
       std::cout << "1. Mostrar saldo \n";
       std::cout << "2. Depositar dinero \n";
       std::cout << "3. Retirar dinero \n";
       std::cout << "4. Salir \n";
       std::cout << "-------------------" << std::endl;
       std::cout << "OPCION: "; std::cin >> opc;

        if (!std::cin) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Entrada no valida! Intente de nuevo. \n";
          continue;
        }
       

       limpiarCodigoPrevio();

        switch (opc) {
            case 1:
              mostrarSaldo(saldo);
              break;
            case 2:
              saldo += deposito();
              mostrarSaldo(saldo);
              break;
            case 3:
              saldo -= retirar(saldo);
              mostrarSaldo(saldo);
              break;
            case 4:
              std::cout << "Gracias por confiar en Interbank!! \n";
              break;
            default:
              std::cout << "Opcion no valida, Seleccione una opcion correcta";
              break;
            break;
        }  

    } while (opc != 4);
    
    return 0;

}

void mostrarSaldo (double saldo) {
    std::cout << "Su balance es: $" << saldo << std::setprecision(2) << std::fixed << saldo << std::endl;

}

double deposito () {
    double monto = 0;

    std::cout << "Ingrese el monto a depositar: "; std::cin >> monto;

    return ((monto > 0) ? monto : 0);
}

double retirar (double saldo) {
    double monto = 0;

    std::cout << "Ingrese el monto a retirar: "; std::cin >> monto;

    if (monto > saldo) {
        std::cout << "Fondos insuficientes! \n";
        return 0;
    }else if (monto < 0) {
        std::cout << "Esa no es una cantidad valida \n";
        return 0;
    } else {
        return monto;
    }
    
}

void limpiarCodigoPrevio() {
    #ifdef  _WIN32
           system("cls");
    #else 
           system("clear");
    #endif
}