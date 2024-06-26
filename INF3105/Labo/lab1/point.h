/************************************************
 * hello
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://ericbeaudry.ca/INF3105/lab1/
  
INSTRUCTIONS:
  Vous devez compléter ce fichier.
*************************************************/

// Les deux lignes suivantes sont directives pour le préprocesseur.
// Elles visent à éviter d'inclure plusieurs fois le fichier point.h à la compilation.
#if !defined(__POINT_H__)
#define __POINT_H__
// Attention: Il faut toujours fermer le #if par un #endif à la toute fin. Voir dernière ligne.

#include <iostream>
#include <vector>


class Point {
  public:
    Point(){}
    Point(double x, double y);
    Point(const Point&);

    double distance(const Point&) const;

  private: // ne pas décommenter tout de suite
    double x;
    //double a;
    double y;

  friend std::ostream& operator << (std::ostream&, const Point&);
  friend std::istream& operator >> (std::istream&, Point&);
};

void findClosestPoints(const std::vector<Point>& points, Point& closestP1, Point& closestP2, double& minDistance);

#endif // fin du #if plus haut

