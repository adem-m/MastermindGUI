#include "helpwindow.h"

helpWindow::helpWindow() : QDialog()
{
    setWindowTitle("Aide");
    setWindowIcon(QIcon("icon.png"));
    texte = new QLabel("Bienvenue dans Mastermind.\n\nRègles du jeu:\nDans Mastermind, l'objectif est de réussir à trouver la combinaison secrète le plus rapidement possible.\nVous disposez d'un maximum de 12 tentatives.\nPour ce faire, vous pouvez faire des tentatives de 4 couleurs. Notez que celles-ci ne doivent pas contenir de doublons (couleurs identiques).\nÀ chacune de vos tentatives, le jeu vous indique:\n- Le nombre de couleurs présentes dans la combinaison secrète et qui sont correctement placées\n- Le nombre de couleurs présentes dans la combinaison secrète et qui ne sont pas correctement placées\n\nBonne chance !");
    boutonFermer = new QPushButton("Revenir au jeu");
    grille = new QGridLayout;

    grille->addWidget(texte, 1, 1, Qt::AlignCenter);
    grille->addWidget(boutonFermer, 2, 1, Qt::AlignCenter);

    setLayout(grille);

    connect(boutonFermer, SIGNAL(clicked()), this, SLOT(close()));
}
