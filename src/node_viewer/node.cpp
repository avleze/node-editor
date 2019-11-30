#include <node_viewer/node.hpp>
#include <cairomm/context.h>

Node::Node(double positionX, double positionY, double width, double height)
  : _pX(positionX) , _pY(positionY), _width(width), _height(height) { }

void Node::draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  double degrees = M_PI / 180.0;
  double radius = 2.0;
  
  cr->begin_new_sub_path();
  cr->set_source_rgb(0.2,0.3,0.4);
  cr->arc(_pX + _width - radius, _pY + radius, radius, -90 * degrees, 0 * degrees);
  cr->arc(_pX + _width - radius, _pY + _height - radius, radius, 0 * degrees, 90 * degrees);
  cr->arc(_pX + radius, _pY + _height - radius, radius, 90 * degrees, 180 * degrees);
  cr->arc(_pX + radius, _pY + radius, radius, 180 * degrees, 270 * degrees);
  cr->close_path();
  cr->fill();
  cr->stroke();
}
