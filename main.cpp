#include "juego.h"
/*Examen 2do Parcial
 * Nombre: Brenda Simbaña Gualavisí
 * Cédula: 175056818-8
 * */
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego w;
    w.show();
    return a.exec();
}
