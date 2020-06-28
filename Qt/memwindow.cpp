#include <QtWidgets>


#include "memwindow.h"

MemWindow::MemWindow(QWidget* parent) {
    isHidden = true;
//    QWidget window;
    this->setParent(parent);
    this->resize(320, 480);
//    window.show();

    QLabel *imageLabel = new QLabel();
    QImage image("happyguy.png");
    imageLabel->setPixmap(QPixmap::fromImage(image));

//scrollArea = new QScrollArea;
    QScrollArea scrollArea;
    scrollArea.setParent(this);
    scrollArea.setBackgroundRole(QPalette::Dark);
    scrollArea.setWidget(imageLabel);
    scrollArea.show();

    //QCheckBox *checkbox = new QCheckBox("Case sensitive", reinterpret_cast<QWidget *>(this));
    QCheckBox checkbox;
    checkbox.setParent(this);
    checkbox.show();

//    QListWidget *listWidget = new QListWidget(reinterpret_cast<QWidget *>(this));
    QListWidget listWidget;
    listWidget.addItem(QString('item1'));
    listWidget.addItem(QString('item2'));
    listWidget.addItem(QString('item3'));
    listWidget.setParent(this);
    listWidget.show();

    this->show();
    isHidden = false;
}

void MemWindow::toggleVisible(){
    if (isHidden) {
        this->show();
        isHidden = false;
    } else {
        this->hide();
        isHidden = true;
    }
}

void MemWindow::InitGuiElements(){

}

MemWindow::~MemWindow() = default;
