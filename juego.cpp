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
    QColor colorIni(165,29,45);
    m_color = colorIni;
    m_ancho = 3;
    m_radio = 50;
    //m_centro = ui->marco->geometry().center();
    m_circulo = new Circulo(13,34,m_radio,m_radio);
    //m_circulo = new Circulo(455,34,50,50);
    //m_circulo->setX(m_centro.x());
    //m_circulo->setY(m_centro.y());
    dibujarCirculo(m_circulo);
}

Juego::~Juego()
{
    delete ui;
    delete mPainter;
    delete mImagen;
}

void Juego::paintEvent(QPaintEvent *event)
{
    // Crear el painter de la ventana principal
    QPainter painter(this);
    // Dibujar la imagen
    painter.drawImage(0, 0, *mImagen);
    // Aceptar el evento
    event->accept();
    //dibujarCirculo();
}

void Juego::dibujarCirculo(Circulo *)
{
   // QPainter painter(this);
    QPen pincel;
    pincel.setColor(m_color);
    pincel.setWidth(m_ancho);
    pincel.setStyle(Qt::SolidLine);
    mPainter->setPen(pincel);
    mPainter->drawEllipse(m_circulo->getX(), m_circulo->getY(), m_circulo->getAlto(), m_circulo->getAncho());
   // painter.drawImage(0, 0, *mImagen);
    update();
}



void Juego::on_btnArriba_released()
{
    mImagen->fill(Qt::white);
    if(m_circulo->getY() == 34)
        QMessageBox::warning(this,"ADVERTENCIA","Ha llegando al límite");
    else
        m_circulo->setY(m_circulo->getY()-10);

    dibujarCirculo(m_circulo);
}


void Juego::on_btnAbajo_released()
{
    mImagen->fill(Qt::white);
    if(m_circulo->getY() > 374)
        QMessageBox::warning(this,"ADVERTENCIA","Ha llegando al límite");
    else
        m_circulo->setY(m_circulo->getY()+10);
    dibujarCirculo(m_circulo);
}


void Juego::on_btnIzqueirda_released()
{
    mImagen->fill(Qt::white);

    if(m_circulo->getX() == 13)
        QMessageBox::warning(this,"ADVERTENCIA","Ha llegando al límite");
    else
        m_circulo->setX(m_circulo->getX()-10);
    dibujarCirculo(m_circulo);
}


void Juego::on_btnDerecha_released()
{
    mImagen->fill(Qt::white);
    if(m_circulo->getX() > 455)
        QMessageBox::warning(this,"ADVERTENCIA","Ha llegando al límite");
    else
        m_circulo->setX(m_circulo->getX()+10);
    dibujarCirculo(m_circulo);


}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        mImagen->fill(Qt::white);
        m_color = config->color().name();
        config->setColor(m_color);
        config->setWidgetColor();
        m_radio = config->dimension();
        m_circulo->setAlto(m_radio*10);
        m_circulo->setAncho(m_radio*10);
        dibujarCirculo(m_circulo);
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

