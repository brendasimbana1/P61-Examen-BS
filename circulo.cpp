#include "circulo.h"

int Circulo::getX() const
{
    return x;
}

void Circulo::setX(int newX)
{
    x = newX;
}

int Circulo::getY() const
{
    return y;
}

void Circulo::setY(int newY)
{
    y = newY;
}

int Circulo::getAlto() const
{
    return alto;
}

void Circulo::setAlto(int newAlto)
{
    alto = newAlto;
}

int Circulo::getAncho() const
{
    return ancho;
}

void Circulo::setAncho(int newAncho)
{
    ancho = newAncho;
}

Circulo::Circulo()
{
    this->x = 0;
    this->y = 0;
    this->alto = 0;
    this->ancho = 0;
}

Circulo::Circulo(int xpos, int ypos, int hpos, int apos)
{
    this->x = xpos;
    this->y = ypos;
    this->alto = hpos;
    this->ancho = apos;
}
