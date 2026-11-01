/** \file Reseau.cpp
 * \brief Définition de l'interface pour un reseau informatique
 * \author GLO-2100 & IFT-2008, Étudiant(e)
 * \version 0.1
 * \date Automne 2026
 *
 */

#include <algorithm>
#include "Reseau.h"

using namespace std;

/**
 * \brief Constructeur par défaut
 * \post Un réseau vide est instancié.
 */
Reseau::Reseau () { };

/**
 * \brief Constructeur à partir d'un fichier en entrée.
 * \param[in, out] p_fichierEntree fichierEntree un flux sur un fichier d'entrée
 * \pre Il y a assez de mémoire pour charger tous les routeur de la liste.
 * \pre	Le fichier p_fichierEntree est ouvert corectement.
 * \post Le fichier p_fichierEntree n'est pas fermé par la fonction.
 * Si les préconditions sont respectées, les données du réseau contenu
 * dans le fichier en entrée sont organisées dans un graphe en mémoire.

 */
Reseau::Reseau(std::ifstream& p_fichierEntree)
{
    //Lecture des données sur les routeurs
    string nom; //Pour le nom des routeurs
    string adresseIP;
    string localisation;
    int numero = 1;
    vector<string> tabNomRouteurs;

    bool sentinelle = false;

    while (!p_fichierEntree.eof () && sentinelle == false)
    {
        getline(p_fichierEntree, nom);
        cout << nom << "\n";
        if (nom == "$")//limite de la première partie du fichier
        {
            sentinelle = true;
        }
        else
        {
            getline(p_fichierEntree, adresseIP);
            getline(p_fichierEntree, localisation);
            Routeur lRouteur (nom, adresseIP, localisation);
            m_graphe.ajouterSommet(numero, lRouteur);
            ++numero;
            tabNomRouteurs.push_back(nom);
        }
    }

    int tempsTransmission;
    string nomD; //nom du routuer de destination
    int indiceSource;
    int indiceDestination;
    char buff[255];
    vector<string>::iterator location;
    while (!p_fichierEntree.eof())
    {
        p_fichierEntree.getline(buff, 100);
        nom = buff;
        location = find(tabNomRouteurs.begin (), tabNomRouteurs.end (), nom);
        indiceSource = location - tabNomRouteurs.begin ();
        p_fichierEntree.getline(buff, 100);
        nomD = buff;
        location = find(tabNomRouteurs.begin (), tabNomRouteurs.end (), nomD);
        indiceDestination = location - tabNomRouteurs.begin ();
        p_fichierEntree >> tempsTransmission;
        p_fichierEntree.ignore();

        m_graphe.ajouterArc(indiceSource + 1, indiceDestination + 1,
                             tempsTransmission);
    }

    cout << "********Graphe lu: ********" << "\n";
    cout << m_graphe;
    cout << "***************************" << "\n";

}

/**
 * \brief Affiche une liste de routeurs du réseau à l'ecran.
 * @param p_vRouteurs Une liste de routeurs dans un vector.
 * \post Le contenu de la liste v est affiché.
 */
void
Reseau::afficherRouteurs (std::vector<Routeur> & p_vRouteurs)
{
    if (p_vRouteurs.size () == 0)
    {
        std::cout << "La liste est vide\n";
        return;
    }

    for (unsigned int i = p_vRouteurs.size (); i > 0; i--)
    {
        std::cout << p_vRouteurs[i - 1] << "\n";
    }
}

/**
 * \brief Affiche la liste de tous les routeurs du réseau à l'écran
 * \pre	Le reseau est non vide
 * \post La liste de tous les routeurs du réseau sont affichées.
 */
void Reseau::afficherRouteurs() const
{
    std::vector<Routeur> lListeRouteur = m_graphe.listerEtiquetteSommets ();
    afficherRouteurs (lListeRouteur);
}

/**
 *
 * @param p_vRouteurs liste des routeurs enregistrés dans le réseau
 */
void
Reseau::reqRouteurs (std::vector<Routeur>& p_vRouteurs) const
{
    p_vRouteurs = m_graphe.listerEtiquetteSommets ();
}

bool Reseau::routeursAccessibles () const{

    return true;
}

std::vector<Routeur>
Reseau::determinerMinParcours (const Routeur& p_routeurOrigine, const Routeur& p_routeurDestination, int& p_nbSecondes)
{
    std::vector<Routeur> lChemin;
    p_nbSecondes = m_graphe.dijkstra (p_routeurOrigine, p_routeurDestination, lChemin);
    return lChemin;
}

std::vector<Routeur>
Reseau::reqRouteursCritiques() const{

    std::vector<Routeur> RCritiques;
    return RCritiques;
}