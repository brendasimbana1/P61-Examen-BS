#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPoint>

class Circulo : public QPoint
{
private:
    int x;
    int y;
    int alto;
    int ancho;
public:
    Circulo();
    Circulo(int xpos, int ypos, int hpos, int apos);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getAlto() const;
    void setAlto(int newAlto);
    int getAncho() const;
    void setAncho(int newAncho);
};

#endif // CIRCULO_H
