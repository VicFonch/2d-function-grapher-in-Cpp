#include <graphics.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define pi M_PI

using namespace std;

int lado = 600;
int origen[2] = {lado / 2, lado / 2};

POINT click_point;
POINT cursor_point;

int desplazamiento = 24; // Se vuela la barra blanca
int zoom_cont = 1;
int dx, dy;

string x_cursor_char, y_cursor_char;
float x_cursor, y_cursor;
double x_eval_cursor;




void IMPUT(double *a, double *b, double *Fa); //Obtener los extremos 'a' y 'b'
void Ejes(int to_X, int to_Y, int draw_X, int draw_Y, int color);  //Dibuja los ejes
double Function(double *x); //Evalua la funcion. Cambiar en caso de necesitar otra
void graficar(double a, double b, double Fa, float escala_x, float escala_y); //Traza rectas entre las imagenes de la funcion
int eje_x_zoom(); //Reconoce el zoom y dibuja el eje X en el nuevo sistema de coordenadas
int eje_y_zoom(); //Reconoce el zoom y dibuja el eje Y en el nuevo sistema de coordenadas
void L_click(double a, double b, double Fa, int escala_x, int escala_y);//Detecta el clic izquierdo y manda a dibujar los ejes y graficar
void R_click(double a, double b, double Fa, int escala_x, int escala_y);//Detecta el clic derecho y dibuja el sistema de coordenadas original y el grafico
void coordenadas(float *escala_x); //Pinta (x, f(x)) en la esquina de la pantalla





int main(){

    double a, b, Fa, temp;

    IMPUT(&a, &b, &Fa);

    initwindow(lado, lado);

    Ejes(0, origen[1], lado, origen[1], WHITE);
    Ejes(origen[0], 0, origen[0], lado, WHITE);


    float escala_x = lado / min((b - a), (double) lado);
    float escala_y = lado / min((b - a), (double) lado);

    graficar(a, b, Fa, escala_x, escala_y);

    while(true){

        coordenadas(&escala_x);

        if(ismouseclick(WM_LBUTTONUP)){

            L_click(a, b, Fa, escala_x, escala_y);
            clearmouseclick(WM_LBUTTONUP);

        }else if(ismouseclick(WM_RBUTTONUP)){

            R_click(a, b, Fa, escala_x, escala_y);
            clearmouseclick(WM_RBUTTONUP);

        }

    }

    return 0;
}


/////Funciones

void IMPUT(double *a, double *b, double *Fa){

    double temp;

    printf("Entre los puntos extremos A < B separados por un espacio en blanco\n");
    scanf("%lf %lf", a, b);

    if(*a > *b){
        temp = *a; *a = *b; *b = temp;
    }

    *Fa = Function(a);

    return;
}


void Ejes(int to_X, int to_Y, int draw_X, int draw_Y, int color){

    moveto(to_X, to_Y);
    setcolor(color);
    setlinestyle(DOTTED_LINE, 0, 1);
    lineto(draw_X, draw_Y);

    return;
}

double Function(double *x){

    double f;

    //f = pow(*x, 3) - 21 * pow(*x, 2) + 120 * (*x) - 100;
    //f = 0.99 * pow(*x, 3) - 21 * pow(*x, 2) + 120 * (*x) - 100;
    //f = 1.01 * pow(*x, 3) - 21 * pow(*x, 2) + 120 * (*x) - 100;

    //f = 2 - log(*x) / *x;

    //f = log(pow(*x, 2) + 1) - exp(0.4*(*x))*cos(pi*(*x));

    //f = pow(*x, 3) + pow(*x, 2) + 1;
    //f = sin(10*(*x));
    //f = 1/(*x + 1);
    f = (*x)*(*x) + *x;

    return f;
}

void graficar(double a, double b, double Fa, float escala_x, float escala_y){


    double x, y;

    moveto(origen[0] + (a * escala_x * zoom_cont), origen[1] - (Fa * escala_y * zoom_cont));

    setcolor(3);
    setlinestyle(SOLID_LINE, 0, 2);

    for(x = a; x <= b; x += 0.01){

        y = Function(&x);
        lineto(origen[0] + (x * escala_x * zoom_cont) , origen[1] - (y * escala_y * zoom_cont));

    }

    return;
}


int eje_x_zoom(){

    int d = origen[1] - (click_point.y - 150);

    //if(origen[0] > click_point.y - 150 && origen[0] < click_point.y + 150)
    Ejes(0, 2*(d + desplazamiento), lado, 2*(d + desplazamiento), WHITE);

    return d;
}


int eje_y_zoom(){

    int d = origen[0] - (click_point.x - 150);

    //if(origen[1] > click_point.x - 150  && origen[1] < click_point.x + 150)
    Ejes(2*d, 0, 2*d, lado, WHITE);

    return d;
}



void L_click(double a, double b, double Fa, int escala_x, int escala_y){

    if(zoom_cont == 4){

        zoom_cont = 1;
        origen[0] = lado / 2;
        origen[1] = lado / 2;

        cleardevice();

        Ejes(0, origen[1], lado, origen[1], WHITE);
        Ejes(origen[0], 0, origen[0], lado, WHITE);

        graficar(a, b, Fa, escala_x, escala_y);

    }else{

        GetCursorPos(&click_point);

        zoom_cont += 1;

        cleardevice();
        dy = eje_x_zoom();
        dx = eje_y_zoom();

        origen[0] = 2*dx;
        origen[1] = 2*(dy + 24);

        graficar(a, b, Fa, escala_x, escala_y);

    }

    return;
}

void R_click(double a, double b, double Fa, int escala_x, int escala_y){

    zoom_cont = 1;
    origen[0] = lado / 2;
    origen[1] = lado / 2;

    cleardevice();

    Ejes(0, origen[1], lado, origen[1], WHITE);
    Ejes(origen[0], 0, origen[0], lado, WHITE);

    graficar(a, b, Fa, escala_x, escala_y);

    return;
}

void coordenadas(float *escala_x){

    GetCursorPos(&cursor_point);

    x_eval_cursor = (cursor_point.x - origen[0]) / (zoom_cont*(*escala_x));
    x_cursor = (float) x_eval_cursor;
    y_cursor = (float) Function(&x_eval_cursor);


    x_cursor_char = to_string(x_cursor);
    y_cursor_char = to_string(y_cursor);
    string coma = " , ";
    string character = x_cursor_char + coma + y_cursor_char;
    char* c = const_cast<char*>(character.c_str());


    setcolor(3);
    outtextxy(lado - 150, 30, c);
    delay(100);
    setcolor(0);
    outtextxy(lado - 150, 30, c);


    return;
}








