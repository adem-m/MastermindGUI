#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    combinaisonATrouver = genererCombinaison();
    // combinaisonATrouver="1234";
    tour=1;
    nbCouleursTapees=0;
    peutJouer=true;

    setWindowTitle("Mastermind");
    setWindowIcon(QIcon("icon.png"));

    presentation = new QLabel("Vos tentatives apparaîtront ci-dessous", this);

    listeCheminsCouleurs.push_back("couleurs\\rouge.png");
    listeCheminsCouleurs.push_back("couleurs\\jaune.png");
    listeCheminsCouleurs.push_back("couleurs\\bleu.png");
    listeCheminsCouleurs.push_back("couleurs\\violet.png");
    listeCheminsCouleurs.push_back("couleurs\\blanc.png");
    listeCheminsCouleurs.push_back("couleurs\\orange.png");
    listeCheminsCouleurs.push_back("couleurs\\rose.png");
    listeCheminsCouleurs.push_back("couleurs\\vert.png");

    layoutHorizBoutons = new QHBoxLayout;

    for(int i=0; i<8; i++)
    {
        boutons[i]= new QPushButton;
        boutons[i]->setIcon(QIcon(listeCheminsCouleurs[i]));
        boutons[i]->setFixedSize(35,35);
        layoutHorizBoutons->addWidget(boutons[i]);
    }

    boutonEffacer = new QPushButton("&Effacer");
    boutonEffacer->setMinimumHeight(35);
    layoutHorizBoutons->addWidget(boutonEffacer);
    boutonValider = new QPushButton("&Valider");
    boutonValider->setAutoDefault(true);
    boutonValider->setMinimumHeight(50);
    boutonAide = new QPushButton("&Aide");

    affichageNbTour = new QLabel("\n\nTour 1");
    texteVide = new QLabel("");

    affichageCombinaisonNonValidee = new QTextEdit;
    affichageCombinaisonNonValidee->setReadOnly(true);
    affichageCombinaisonNonValidee->setMaximumSize(110, 35);

    grille = new QGridLayout(this);
    grille->addWidget(presentation, 1, 0);
    grille->addWidget(boutonAide, 1, 1, Qt::AlignRight);
    grille->addWidget(texteVide, 2, 0);
    grille->addWidget(affichageNbTour, 15, 0);
    grille->addWidget(affichageCombinaisonNonValidee, 16, 0);
    grille->addLayout(layoutHorizBoutons, 17, 0, 1, 2);
    grille->addWidget(boutonValider, 18, 0, 1, 2);
    grille->setColumnMinimumWidth(2, grille->columnMinimumWidth(1));

    connect(boutonEffacer, SIGNAL(clicked()), this, SLOT(effacer()));
    connect(boutons[0], SIGNAL(clicked()), this, SLOT(ajouter1()));
    connect(boutons[1], SIGNAL(clicked()), this, SLOT(ajouter2()));
    connect(boutons[2], SIGNAL(clicked()), this, SLOT(ajouter3()));
    connect(boutons[3], SIGNAL(clicked()), this, SLOT(ajouter4()));
    connect(boutons[4], SIGNAL(clicked()), this, SLOT(ajouter5()));
    connect(boutons[5], SIGNAL(clicked()), this, SLOT(ajouter6()));
    connect(boutons[6], SIGNAL(clicked()), this, SLOT(ajouter7()));
    connect(boutons[7], SIGNAL(clicked()), this, SLOT(ajouter8()));
    connect(boutonValider, SIGNAL(clicked()), this, SLOT(tentative()));
    connect(boutonAide, SIGNAL(clicked()), this, SLOT(ouvrirFenetreAide()));
//    connect(boutonAide, SIGNAL(clicked()), this, SLOT(rejouer()));
}
void mainWindow::effacer()
{
    if(couleursEntreesQString.size()>0)
    {
        nbCouleursTapees--;
        couleursEntreesQString.pop_back();
        affichageCombinaisonNonValidee->clear();
        for(int i=0; i<nbCouleursTapees; i++)
        {
            affichageCombinaisonNonValidee->setHtml(affichageCombinaisonNonValidee->toHtml() + "<img src=" + couleursEntreesQString[i] + " alt=\"\"/>");
        }
        boutons[couleursEntreesInt[couleursEntreesInt.size()-1]-1]->setEnabled(true);
        couleursEntreesInt.pop_back();

    }
}
void mainWindow::ajouter1()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[0]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[0] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(1);
        nbCouleursTapees++;
        boutons[0]->setEnabled(false);
    }
}
void mainWindow::ajouter2()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[1]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[1] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(2);
        nbCouleursTapees++;
        boutons[1]->setEnabled(false);
    }
}
void mainWindow::ajouter3()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[2]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[2] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(3);
        nbCouleursTapees++;
        boutons[2]->setEnabled(false);
    }
}
void mainWindow::ajouter4()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[3]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[3] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(4);
        nbCouleursTapees++;
        boutons[3]->setEnabled(false);
    }
}
void mainWindow::ajouter5()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[4]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[4] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(5);
        nbCouleursTapees++;
        boutons[4]->setEnabled(false);
    }
}
void mainWindow::ajouter6()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[5]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[5] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(6);
        nbCouleursTapees++;
        boutons[5]->setEnabled(false);
    }
}
void mainWindow::ajouter7()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[6]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[6] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(7);
        nbCouleursTapees++;
        boutons[6]->setEnabled(false);
    }
}
void mainWindow::ajouter8()
{
    if(nbCouleursTapees<4 && peutJouer)
    {
        couleursEntreesQString.push_back(listeCheminsCouleurs[7]);
        QString chaine = affichageCombinaisonNonValidee->toHtml() + "<img src=" + listeCheminsCouleurs[7] + " alt=\"\"/>";
        affichageCombinaisonNonValidee->setHtml(chaine);
        couleursEntreesInt.push_back(8);
        nbCouleursTapees++;
        boutons[7]->setEnabled(false);
    }
}
void mainWindow::tentative()
{
    if(tour<13 && nbCouleursTapees==4)
    {
        QString combi=QString::number(couleursEntreesInt[0])+QString::number(couleursEntreesInt[1])+QString::number(couleursEntreesInt[2])+QString::number(couleursEntreesInt[3]);
        if(aucunDoublon(combi))
        {
            QString plurielBP;
            QString plurielMP;

            if(nbChiffresBienPlaces(combi)>1)
            {
                plurielBP="s";
            }
            else
            {
                plurielBP.clear();
            }
            if(nbChiffresMalPlaces(combi)>1)
            {
                plurielMP="s";
            }
            else
            {
                plurielMP.clear();
            }
            QLabel *couleur1;
            QLabel *couleur2;
            QLabel *couleur3;
            QLabel *couleur4;

            couleur1 = new QLabel;
            couleur2 = new QLabel;
            couleur3 = new QLabel;
            couleur4 = new QLabel;

            couleur1->setPixmap(QPixmap(listeCheminsCouleurs[couleursEntreesInt[0]-1]));
            couleur2->setPixmap(QPixmap(listeCheminsCouleurs[couleursEntreesInt[1]-1]));
            couleur3->setPixmap(QPixmap(listeCheminsCouleurs[couleursEntreesInt[2]-1]));
            couleur4->setPixmap(QPixmap(listeCheminsCouleurs[couleursEntreesInt[3]-1]));

            QHBoxLayout *bite;
            bite = new QHBoxLayout;
            bite->addWidget(couleur1);
            bite->addWidget(couleur2);
            bite->addWidget(couleur3);
            bite->addWidget(couleur4);

            QLabel *indice;
            indice = new QLabel;

            grille->addLayout(bite, tour+2, 0, Qt::AlignRight);

            if(nbChiffresBienPlaces(combi)==4)
            {
                indice->setText("Félicitations !\nVous avez trouvé la combinaison secrète !");
                peutJouer=false;
                grille->addWidget(indice, tour+2, 1);
            }
            else
            {
                if(tour==12)
                {
                    indice->setText("Game over");
                    tour++;
                    peutJouer=false;
                }
                else
                {
                    indice->setText("Couleur" + plurielBP + " bien placée" + plurielBP + ": " + QString::number(nbChiffresBienPlaces(combi)) + "\nCouleur" + plurielMP + " mal placée" + plurielMP + ": " + QString::number(nbChiffresMalPlaces(combi)));
                    tour++;
                    affichageNbTour->setText("\n\nTour " + QString::number(tour));
                }
                grille->addWidget(indice, tour+1, 1);
            }
            affichageCombinaisonNonValidee->clear();
            couleursEntreesInt.clear();
            couleursEntreesQString.clear();
            nbCouleursTapees=0;

            for(int i=0; i<8; i++)
            {
                boutons[i]->setEnabled(true);
            }
        }
    }
}
QString mainWindow::genererCombinaison()
{
    QString chaine;

    srand (time(NULL));

    int ordre[8];
    std::vector <int> combinaison;
    int random=0;
    unsigned long long n=0;

    for (int i=0; i<8; i++)
    {
        combinaison.push_back(9);
    }

    for (int i=0; i<8; i++)
    {
        ordre[i]=i+1;
    }

    while (n<8)
    {
        random = rand()%8;
        if (combinaison[random]==9)
        {
            combinaison[random] = ordre[n];
            n++;
        }
    }

    for (int i=0; i<4; i++)
    {
        combinaison.pop_back();
        chaine += '0' + combinaison[i];
    }

    return chaine;
}
int mainWindow::nbChiffresMalPlaces(QString tentative)
{
    int chiffresMalPlaces=0;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(combinaisonATrouver[i]==tentative[j] && i!=j)
            {
                chiffresMalPlaces++;
            }
        }
    }
    return chiffresMalPlaces;
}
int mainWindow::nbChiffresBienPlaces(QString tentative)
{
    int chiffresBienPlaces=0;
    for (int i=0; i<4; i++)
    {
        if(combinaisonATrouver[i]==tentative[i])
        {
            chiffresBienPlaces++;
        }
    }
    return chiffresBienPlaces;
}
bool mainWindow::aucunDoublon(QString tentative)
{
    bool bi=false;
    if(tentative[0]!=tentative[1] && tentative[0]!=tentative[2] && tentative[0]!=tentative[3] && tentative[1]!=tentative[2] && tentative[1]!=tentative[3] && tentative[2]!=tentative[3])
    {
        bi=true;
    }

    return bi;
}
void mainWindow::ouvrirFenetreAide()
{
    fenetreAide = new helpWindow;
    fenetreAide->exec();
}
void mainWindow::rejouer()
{
//    delete grille->takeAt(1);
}
