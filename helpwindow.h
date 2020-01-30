#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class helpWindow : public QDialog
{
    Q_OBJECT
public:
    helpWindow();

signals:

private:
    QLabel *texte;
    QGridLayout *grille;
    QPushButton *boutonFermer;

};

#endif // HELPWINDOW_H
