#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui -> textEdit);
    ui -> statusbar -> showMessage("My Note-Pad Application.");
    ui -> statusbar -> addPermanentWidget(ui -> label_2);
    ui -> statusbar -> addPermanentWidget(ui -> label_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionnew_triggered()
{
    FilePath = " ";
    ui -> textEdit -> setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open files");
    QFile file(fileName);
    FilePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        ui -> statusbar -> showMessage("No text file created.......!",7000);
        return;
    }
    else{
        QTextStream outputFile(&file);
        QString text = outputFile.readAll();
        ui -> textEdit -> setText(text);
        file.close();
    }
}


void MainWindow::on_actionSave_triggered()
{

    QFile file(FilePath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        ui -> statusbar -> showMessage("No text file created.......!",7000);
        return;
    }
    else{
        QTextStream outputFile(&file);
        QString text = ui -> textEdit -> toPlainText();
        outputFile  << text;
        outputFile.flush();
        file.close();
    }
}


void MainWindow::on_actionSave_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Open files");
    QFile file(fileName);
    FilePath = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        ui -> statusbar -> showMessage("No text file created.......!",7000);
        return;
    }
    else{
        QTextStream outputFile(&file);
        QString text = ui -> textEdit -> toPlainText();
        outputFile  << text;
        outputFile.flush();
        file.close();
    }
}


void MainWindow::on_actionCut_triggered()
{
    ui -> textEdit -> cut();
}


void MainWindow::on_actionCopy_triggered()
{
 ui -> textEdit -> copy();
}


void MainWindow::on_actionPast_triggered()
{
 ui -> textEdit -> paste();
}


void MainWindow::on_actionRedo_triggered()
{
 ui -> textEdit -> redo();
}


void MainWindow::on_actionUndo_triggered()
{
 ui -> textEdit -> undo();
}


void MainWindow::on_actionAbout_me_triggered()
{
 QMessageBox::information(this, "About Me.","My name is Emmanuel chibuike victor. \nMy aim of builing this product is to anable people write.");
}


void MainWindow::on_actionAbout_notePad_triggered()
{
 QApplication::aboutQt();
}


void MainWindow::on_actionClose_triggered()
{
 QMessageBox::information(this,"....",("Thank you for using vic Note-Pad!"));
    QApplication:: quit();
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok){
        ui -> textEdit -> setFont(font);
    }
    else
        return;
}


void MainWindow::on_actioncolor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose color.");
    if(color.isValid()){
        ui -> textEdit -> setTextColor(color);
    }
    else
        return;
}


void MainWindow::on_actiontext_background_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Choose color.");
    if(color.isValid()){
        ui -> textEdit -> setTextBackgroundColor(color);
    }
    else
        return;
}


void MainWindow::on_actionBackgroung_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose color.");
    if (color.isValid()) {
        QString styleSheet = QString("background-color: %1;").arg(color.name());
        ui->textEdit->setStyleSheet(styleSheet);
    }
    else {
        return;
    }
}



void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Evictor printers");
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec() == QDialog::Rejected)
        return;
    ui -> textEdit -> print(&printer);
}

