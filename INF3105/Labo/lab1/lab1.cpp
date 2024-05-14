/************************************************
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://ericbeaudry.ca/INF3105/lab1/
*************************************************/

#include <iostream>
#include <vector>

#include "point.h"

/************************************************************************
INSTRUCTIONS:
   Suivez rigoureusement les tâches à http://ericbeaudry.ca/INF3105/lab1/.
   NE sautez PAS d'étape !
   Si vous sautez une étape ou tentez d'aller trop rapidement,
   alors vous risquez d'introduire des bogues!
*************************************************************************/

/*
int main1(int argc, const char** args)
{
  std::cout << "Bienvenue au cours INF3105 en C++ !" << std::endl;
  return 0;
}


int main2(int argc, const char** args)
{
  Point point(9, 108);
  std::cout << point;
  std::cout << std::endl; // fin de ligne
  return 0;
}

int main3(int argc, const char** args)
{
  Point point(1.2,5.7);
  std::cout << "point.x=" << point.x << "\tpoint.y=" << point.y << std::endl;
  return 0;
}

int main4(int argc, const char** args)
{
  Point point;
  std::cout << "Entrez un point:" << std::endl;
  std::cin >> point;
  std::cout << "Revoici votre point:" << std::endl;
  std::cout << point << std::endl;
  return 0;
}


int main5(int argc, const char** args)
{
  Point a(0,0);
  Point b(4,3);
  double d = a.distance(b);
  std::cout << "Distance("<< a << "," << b << ")=" << d << std::endl;
  return 0;
}
*/


int main(int argc, const char** args)
{
  int nb;
  std::cin >> nb;

  std::vector<Point> points;
  Point temp;

  for (int i = 0 ; i < nb ; i++) {
    std::cin >> temp;
    points.push_back(temp);
  }

  for (const Point& p : points) {
        std::cout << p << std::endl;
    }

  Point closestP1, closestP2;
  double minDistance;

  findClosestPoints(points, closestP1, closestP2, minDistance);

  std::cout << "Les deux points les plus proches sont: " << closestP1 << " et " << closestP2 << std::endl;
  std::cout << "La distance entre eux est: " << minDistance << std::endl;


  return 0;
}