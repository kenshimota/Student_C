#include "stdio.h"

/**
 * Imprime un mensaje de bienvenida pare el usuario.
 */
void print_welcome_message(){
    printf("Hola, esta es su calculadora mota 1.0\n");
    printf("\n");
}

/**
 * Imprime las instrucciones de como utilizar la calculadora.
 */
void print_instructions(){
    printf("1)sumar\n");
    printf("2)restar\n");
    printf("3)multiplicar\n");
    printf("4)dividir\n");
    printf("5)salir de la aplicacion\n");
    printf("Presione el numero de la opcion: ");
}

/**
 * Lee un entero de la entrada estandar.
 *
 * La funcion continuara pidiendo un numero al usuario mientras el "input" sea
 * invalido.
 */
int read_int(){
    while(1){
        int num = 0;
        // scanf regersa el numero de caracteres leidos
        int read_count = scanf("%d", &num);
        getchar();
        if(read_count == 1){
            // si el numero de caracteres leidos es 1, quiere decir que hemos
            // obtenido un valor que corresponde con el formato %d, o sea, un
            // entero.
            // Regresamos ese numero.
            return num;
        } else {
            // si read_count es diferente de 1, quiere decir que scanf no pudo leer
            // un valor que corresponda con el formato %d. En ese caso,
            // volveremos a pedir al usuario que ingrese un valor valido.
            printf("El valor ingresado no es valido.\n");
            printf("Por favor, ingrese un numero: ");
        }
    }
}

/**
 * Interactua con el usuario para realizar una adicion
 */
void addition(){
    printf("ingrese el primer numero a sumar: ");
    int num1 = read_int();

    printf("ingrese el segundo numero a sumar: ");
    int num2 = read_int();
    
    printf("el resultado de la suma es: %d \n", num1 + num2);
    getchar();
}

/**
 * Interactua con el usuario para realizar una substraccion
 */
void subtraction(){
    printf("ingrese el primer numero a restar: ");
    int num1 = read_int();

    printf("numero de restar: ");
    int num2 = read_int();

    printf("el resultado de la resta es: %d \n", num1 - num2);
    getchar();
}

/**
 * Interactua con el usuario para realizar una multiplicacion
 */
void multiplication(){
    printf("ingrese el primer numero a multiplicar: ");
    int num1 = read_int();

    printf("ingrese el segundo numero a multiplicar: ");
    int num2 = read_int();

    printf("el resultado de la multiplicar es: %d \n", num1 * num2);
    getchar();
}

/**
 * Interactua con el usuario para realizar una division
 */
void division(){
    printf("ingrese el primer numero a dividir: ");
    int num1 = read_int();

    printf("numero divisor: ");
    int num2 = read_int();

    if(num2 != 0) {
        printf("el resultado de la division es: %d \n", num1 / num2);
    } else {
        printf("No es posible dividir por cero.\n");  
    }
    getchar();
}

/**
 * Imprime un mensaje explicando que la opcion seleccionada no es valida.
 */
void print_invalid_option_message(){
    printf("\n");
    printf("La opcion que ha seleccionado no es valida.\n");
    printf("\n");
}

/**
 * Imprime un mensaje de despedida para el usario.
 */
void print_exit_message(){
    printf("\n");
    printf("Gracias por usar la calculadora mota 1.0.\n");
    printf("Que pase un feliz dia.\n");
    printf("Presione una tecla para salir \n");
    getchar();
}

/**
 * Calculadora interactiva
 */
void calculator(){
    while(1){
        print_instructions();
        
        int option;
        scanf("%d",&option);
        getchar();

        switch(option) {
        case 1: addition(); break;
        case 2: subtraction(); break;
        case 3: multiplication(); break;
        case 4: division(); break;
        case 5: return;
        default: print_invalid_option_message(); break;
        }
    }
}

/**
 * Main
 */
int main() {
    
    print_welcome_message();

    calculator();

    print_exit_message();

    return 0;
}
