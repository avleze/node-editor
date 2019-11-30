#ifndef NODE_HPP
#define NODE_HPP

#include <cairomm/context.h>


class Node {
public:
  Node(double positionX, double positionY, double width, double height);
  void draw(const Cairo::RefPtr<Cairo::Context>& cr);
protected:
  double _pX;
  double _pY;
  double _width;
  double _height;
};

#endif // NODE_HPP
