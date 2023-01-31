#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{

    ui->setupUi(this);
    setWindowTitle("JUEGO \"MUEVE EL CIRCULO\"");
    mImagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    mImagen->fill(Qt::white);
    mPainter = new QPainter(mImagen);
    mPainter->setRenderHint(QPainter::Antialiasing);
    mColor = Qt::blue;
    mAncho = 3;
    m_centro = ui->marco->geometry().center();
    m_circulo = new Circulo (50,50);
    //m_circulo->setX(m_centro.x());
    //m_circulo->setY(m_centro.y());

}

Juego::~Juego()
{
    delete ui;
    delete mPainter;
    delete mImagen;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pincel;
    pincel.setColor(mColor);
    pincel.setWidth(mAncho);
    pincel.setStyle(Qt::SolidLine);
    mPainter->setPen(pincel);
    mPainter->drawEllipse(m_centro, m_circulo->x(), m_circulo->y());
    painter.drawImage(0, 0, *mImagen);
    event->accept();
}



void Juego::on_btnArriba_released()
{

}


void Juego::on_btnAbajo_released()
{

}


void Juego::on_btnIzqueirda_released()
{

}


void Juego::on_btnDerecha_released()
{

}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

