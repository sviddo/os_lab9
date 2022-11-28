#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();
    Ui::ClientWindow *ui;

private slots:
    void on_subscribeButton_clicked();
    void on_unsubscribeButton_clicked();
};
#endif // CLIENTWINDOW_H
