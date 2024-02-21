#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCut_triggered();

    void on_actionnew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_2_triggered();

    void on_actionCopy_triggered();

    void on_actionPast_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_me_triggered();

    void on_actionAbout_notePad_triggered();

    void on_actionClose_triggered();

    void on_actionFont_triggered();

    void on_actioncolor_triggered();

    void on_actiontext_background_color_triggered();

    void on_actionBackgroung_color_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MainWindow *ui;
    QString FilePath;
};
#endif // MAINWINDOW_H
