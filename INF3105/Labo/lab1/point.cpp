/************************************************
 * Hello
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://ericbeaudry.ca/INF3105/lab1/
  
INSTRUCTIONS:
  Vous devez compléter ce fichier.
*************************************************/

#include <cassert>
#include <cmath>
#include "point.h"

Point::Point(const Point& point)
  : x(point.x), y(point.y) 
{
}

Point::Point(double _x, double _y) 
  : x(_x), y(_y)
{
}


double Point::distance(const Point& other) const {
    double dx = this->x - other.x;  // Différence des abscisses
    double dy = this->y - other.y;  // Différence des ordonnées
    return sqrt(dx * dx + dy * dy);  // Calcul de la distance euclidienne
}

void findClosestPoints(const std::vector<Point>& points, Point& closestP1, Point& closestP2, double& minDistance) {
    int size = points.size();
    minDistance = std::numeric_limits<double>::max();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            double dist = points[i].distance(points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestP1 = points[i];
                closestP2 = points[j];
            }
        }
    }
}

std::ostream& operator << (std::ostream& os, const Point& point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}

std::istream& operator >> (std::istream& is, Point& point) {
  char po, vir, pf;
  is >> po;
  if(is){
    is >> point.x >> vir >> point.y >> pf;
    assert(po=='(');
    assert(vir==',');
    assert(pf==')');
  }
  return is;
}


