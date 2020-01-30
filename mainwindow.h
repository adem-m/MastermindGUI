#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "helpwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow();
    QString genererCombinaison();
    int nbChiffresMalPlaces(QString tentative);
    int nbChiffresBienPlaces(QString tentative);
    bool aucunDoublon(QString tentative);

signals:

public slots:
    void effacer();
    void ajouter1();
    void ajouter2();
    void ajouter3();
    void ajouter4();
    void ajouter5();
    void ajouter6();
    void ajouter7();
    void ajouter8();
    void tentative();
    void ouvrirFenetreAide();
    void rejouer();

private:
    QPushButton *boutons[8];
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
    QPushButton *bouton5;
    QPushButton *bouton6;
    QPushButton *bouton7;
    QPushButton *bouton8;
    QPushButton *boutonEffacer;
    QPushButton *boutonValider;
    QPushButton *boutonAide;
    QHBoxLayout *layoutHorizBoutons;
    QGridLayout *grille;
    QTextEdit *affichageCombinaisonNonValidee;
    QLabel *affichageNbTour;
    QLabel *presentation;
    QLabel *texteVide;

    QVector<QString> listeCheminsCouleurs;
    QVector<int> couleursEntreesInt;
    QVector<QString> couleursEntreesQString;
    QString combinaisonATrouver;
    int tour;
    int nbCouleursTapees;
    bool peutJouer;

    helpWindow *fenetreAide;
};

#endif // MAINWINDOW_H
