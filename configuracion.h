#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion();

    const QColor &color() ;
    int dimension() ;

    void setColor(const QColor &newColor);
    void setDimension(int newDimension);
    void setWidgetColor();

private slots:
    void on_btnColor_released();

    void on_inDimension_sliderReleased();

protected:
    Ui::Configuracion *ui;
    QColor m_color;
    int m_dimension;


};

#endif // CONFIGURACION_H
