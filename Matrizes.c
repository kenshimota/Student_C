#include <stdio.h>
#include <stdlib.h>

/**
* Esta es el numero de matrizes registradas por ser el inicio no hay ninguna matriz
*/
int num_matrix = 0;

/**
* Esta estructura estara encargada de dar a conocer los datos de la matriz creada
*/
struct Vmatrix{
    char name[30+1];
    int x;
    int y;
    int values[100][100];
}matrix[10000];

/**
* Esta es la funcion encargada de contar el numero de elementos de una cadena de texto
*/
int strlen(char s[])
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

/**
* Funcion encargada de borrar la pantalla no se puede usar esta funcion tanto en windows como linux
*/
void screen_clear()
{
    if(system("cls"))
        system("clear");
}

/**
* Esta es la funcion encargada de imprimir las opciones
*/
void print_options()
{
    printf("1)Crear una Matriz\n");
    printf("2)Mostrar Matrizes\n");
    printf("3)Agregar Valores a una Matriz\n");
    printf("4)Sumar 2 Matrizes\n");
    printf("5)Salir de ");
}

/**
* funcion que se encarga de obtener un nombre
*/
int read_name()
{
    int i;
    char name[31];
    while(1)
    {
        scanf("%s",name);
        getchar();
        if(strlen(name) >= 3 && strlen(name) < 30)
        {
            for(i=0; name[i] != '\0'; i++)
                matrix[num_matrix].name[i] = name[i];
            return 0;
        }
        else
            printf("Por favor ingrese un  nombre de mas de 2 caracteres y menos de 30...\nIngrese un nuevo nombre: ");
    }
}

/**
* Esta funcion se encarga de obtener le nombre
* y de ir a la funcion leer_nombre para que
* lea el nombre antes de crear la matriz tal y como va
*/
int get_name_matrix()
{
    printf("Ingrese un nombre de la matriz: ");
    read_name();
}


/**
* Funcion encargada de dar un tamaño a las columnas y las filas
*/
int read_size_matrix()
{
    while(1)
    {
        int num,n;
        n = scanf("%d",&num);
        getchar();

        /**
        * Esta funcion se encarga de hacer un ciclo infinito
        * Debido a que n obtendra si el valor ingresado por el
        * usuario es numerico solo si n = 1;
        */
        if(n == 1 && num > 0 && num < 100)
            return num;
        else
            printf("El valor ingresado no es numerico...\nIngrese un numero positivo no mayor de 100: ");
    }
}

/**
* Esta funcion se encarga de pedir el espacio de memoria para poder crear una matriz bidimensional
*/
int get_size_matrix()
{
    int i;

    printf("\nIngrese el numero de filas: ");
    matrix[num_matrix].x = read_size_matrix();

    printf("\nIngrese el numero de columnas: ");
    matrix[num_matrix].y = read_size_matrix();

    return 0;
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
            printf("\nEl valor ingresado no es valido.\n");
            printf("\nPor favor, ingrese un numero: ");
        }
    }
}

/**
* Esta funcion se encarga de dar los valores a las filas y columnas de la matriz
*/
int get_values_matrix(int n)
{
    int i,j;

    for(i=0; i < matrix[n].x; i++)
    {
        for(j=0; j < matrix[n].y; j++)
        {
            printf("\nIngrese el Valor de %s[%d][%d]: ",matrix[n].name,i,j);
            matrix[n].values[i][j] = read_int();
        }
    }
}

/**
* Esta funcion se encarga de organizar como se creara la matriz
*/
int create_matrix()
{
    get_name_matrix();

    get_size_matrix();

    get_values_matrix(num_matrix);

    num_matrix++;

    return 0;
}

int add_values_matrix()
{
    if(num_matrix > 0)
    {
        int num;

        show_all_matrix();

        printf("De acuerdo a su numero eliga una matrix: ");

        do{
            num = read_int();
            if(num > num_matrix)
                printf("Ingrese un numero que no supere %d por favor...\n",num_matrix);
        }while(num > num_matrix);

        get_values_matrix(num - 1);

    }
    else
    {
        printf("No hay datos de una matriz existente\nPreione enter para volver al menu principal...\n");
        getchar();
        return 0;
    }
}

/**
* Esta funcion se encarga de mostrar las matrizes hechas
*/
int show_all_matrix()
{
    int i;
    printf("________________________________\n");
    printf("| N | Nombre | Filas | Columnas |\n");
    printf("________________________________\n");
    if(num_matrix == 0)
        printf("           Sin Datos        \n");
    for(i=0; i < num_matrix; i++)
    {
        printf("| %d | %s | %d | %d |\n",(i+1),matrix[i].name,matrix[i].x,matrix[i].y);
        printf("_____________________________\n");
    }
}

int addition_2_matrix(int matrix_a,int matrix_b)
{
    int i,j;
    printf("El resultado de la suma de las matrices\n");
    printf("      %s+%s\n",matrix[matrix_a].name,matrix[matrix_b].name);
    for(i=0; i < matrix[matrix_a].x; i++)
    {
        printf("|");
        for(j=0; j < matrix[matrix_a].y; j++)
        {
            printf(" (%d)",(matrix[matrix_a].values[i][j]+matrix[matrix_b].values[i][j]));
        }
        printf("|\n");
    }

    getchar();
    return 0;
}

int addition_of_matrix()
{
    if(num_matrix > 0)
    {
        int p[2];

        show_all_matrix();

        printf("Ingrese el numero de la primera matrix a sumar: ");

        do
        {
            p[0] = read_int();
            if(p[0] > num_matrix)
                printf("Ingrese un numero que no supere %d por favor...\n",num_matrix);
        }while(p[0] > num_matrix);

        printf("Ingrese el numero de la segunda matriz a sumar: ");

        do
        {
            p[1] = read_int();
            if(p[1] > num_matrix)
                printf("Ingrese un numero que no supere %d por favor...\n",num_matrix);
        }while(p[1] > num_matrix);

        if(matrix[(p[0] - 1)].x == matrix[(p[1] - 1)].x && matrix[(p[0] - 1)].y == matrix[(p[1] - 1)].y)
        {
            addition_2_matrix(p[0]-1,p[1]-1);
        }
        else
        {
            printf("Disculpe pero selecciono dos matrizes de numero de filas y columnas distintas\n");
            printf("de forma que no se pueden sumar\n");
            printf("Presione Enter para volver a menu principal...\n");
            getchar();
            return 0;
        }

    }
    else
    {
        printf("No hay datos de una matriz existente\nPreione enter para volver al menu principal...\n");
        getchar();
        return 0;
    }

}

/**
* Esta funcion se encarga de leer la opciones escogidad por el usuario
*/
int read_option()
{
    while(1)
    {
        int option,n;
        printf("\n\nEliga una opcion: ");
        scanf("%d",&option);
        getchar();

        switch(option)
        {
            case 1:
                screen_clear();
                create_matrix();
                screen_clear();
                return 0;
            break;
            case 2:
                screen_clear();
                show_all_matrix();
                getchar();
                screen_clear();
                return 0;
            break;
            case 3:
                screen_clear();
                add_values_matrix();
                screen_clear();
                return 0;
            break;
            case 4:
                screen_clear();
                addition_of_matrix();
                screen_clear();
                return 0;
            break;
            case 5:
                screen_clear();
                printf("Presione enter para salir...\n");
                getchar();
                exit(1);
            break;
            default:
                printf("Ingrese una opcion valida...\n\n");
            break;
        }
    }
}

/**
* Esta es la funcion principal
*/
int main()
{
    while(1)
    {
            print_options();
            read_option();
    }
}
