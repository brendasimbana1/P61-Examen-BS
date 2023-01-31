#include "configuracion.h"
#include "ui_configuracion.h"
#include <QDebug>

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
    m_color.setRgb(165,29,45);
    setWidgetColor();
}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::on_btnColor_released()
{
    m_color = QColorDialog::getColor(m_color, this,
                                     "Color de la circunferencia");
    setColor(m_color);
    setWidgetColor();
}

void Configuracion::setColor(const QColor &newColor)
{
    m_color = newColor;
}

void Configuracion::setDimension(int newDimension)
{
    m_dimension = newDimension;
}

void Configuracion::setWidgetColor()
{

    int r = m_color.red();
    int g = m_color.green();
    int b = m_color.blue();
    QString style = "background-color: rgb(" + QString::number(r) + ", " + QString::number(g) + ", " + QString::number(b) + ")";
    ui->wigetColor->setStyleSheet(style);
}

const QColor &Configuracion::color()
{
    return m_color;
}

int Configuracion::dimension()
{
    return m_dimension;
}


void Configuracion::on_inDimension_sliderReleased()
{
    int dimen = ui->inDimension->value();
    setDimension(dimen);
    qDebug()<< m_dimension;
    qDebug()<<dimen;
    qDebug()<<dimension();
}



