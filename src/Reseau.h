/**
* \file Reseau.h
 * \brief interface pour un reseau informatique
 * \author GLO-2100 & IFT-2008, Étudiant(e)
 * \version 0.1
 * \date Automne 2026
 *
 */

#ifndef RESEAU_H_
#define RESEAU_H_

#include <fstream>		// Pour les fichiers
#include <stdexcept>
#include <string>
#include <vector>
#include "Graphe.h"
#include "Routeur.h"

class Reseau
{
public:

    Reseau();
    Reseau(std::ifstream& p_fichierEntree);
    
    static void afficherRouteurs(std::vector<Routeur>& p_vRouteurs);
    void afficherRouteurs() const;

    bool routeursAccessibles() const;
    std::vector<Routeur> reqRouteursCritiques() const;
    std::vector<Routeur> determinerMinParcours(const Routeur& p_routeurOrigine,
                                               const Routeur& p_routeurDestination, int& nbSec);
    void reqRouteurs(std::vector<Routeur>& p_vRouteurs) const;

private:

    Graphe<Routeur> m_graphe; //< Le graphe du réseau
};

#endif // RESEAU_H_
