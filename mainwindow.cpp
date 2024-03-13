#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QQuickWidget>
#include <QQmlContext>

void MainWindow::showToDoList() {
    QQuickWidget *qmlWidget = new QQuickWidget(this);
    qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qmlWidget->setSource(QUrl(QStringLiteral("qrc:/mainwindow.qml")));
    ui->verticalLayout->addWidget(qmlWidget); // make sure `verticalLayout` exists in your ui file
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::on_addTaskButton_clicked);
    connect(ui->removeTaskButton, &QPushButton::clicked, this, &MainWindow::on_removeTaskButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTaskButton_clicked() {
    QString task = ui->taskLineEdit->text();
    ui->taskListWidget->addItem(task);
    ui->taskLineEdit->clear();
}

void MainWindow::on_removeTaskButton_clicked() {
    delete ui->taskListWidget->currentItem();
}
