#ifndef ADDCLASSWINDOW_H
#define ADDCLASSWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QDialog>

#pragma once

class addClassWindow : public QDialog
{

Q_OBJECT

public:
    addClassWindow(QWidget *parent = nullptr);

    QString name() const;
    QString grade() const;
    QString multiplier() const;
    bool getCancelled();
    void editClass(const QString &name, const QString &grade, const QString &multiplier);

private:
    QLineEdit *nameText;
    QLineEdit *gradeText;
    QLineEdit *multiText;
    bool cancelled;

private slots:
    void setCancelled();



};

#endif // ADDCLASSWINDOW_H
