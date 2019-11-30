#include <node_viewer/node_viewer.hpp>
#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include <node_viewer/node.hpp>
#include <iostream>




NodeViewer::NodeViewer() : _translateX(0), _translateY(0), onGrab(false)
{
    this->add_events(Gdk::POINTER_MOTION_MASK);
    this->add_events(Gdk::BUTTON_PRESS_MASK);
        this->add_events(Gdk::BUTTON_RELEASE_MASK);

    this->signal_button_press_event().connect(sigc::mem_fun(*this, &NodeViewer::on_button_press_event));
    this->signal_button_release_event().connect(sigc::mem_fun(*this, &NodeViewer::on_button_release_event));

    this->signal_motion_notify_event().connect(sigc::mem_fun(*this, &NodeViewer::on_motion));
}

NodeViewer::~NodeViewer()
{
}

bool NodeViewer::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  cr->translate(_translateX,_translateY);
  cr->set_line_width(1);
  cr->save();
  
  double x = 25.6;
  double y = 25.6;
  double width = 50;
  double height = 50;
  double aspect = 1.0;
  double radius = 10.0;
  for(; x < 1000; x+=70)
    for(y = 1000; y > 0; y-=70)
      Node(x, y, width, height).draw(cr);
  
return true;
}

void NodeViewer::moveToX(double x) {
  if(x != _translateX)
  {
    this->_translateX = x;
    this->queue_draw();
  }
}

void NodeViewer::moveToY(double y) {
  if(y != _translateY)
  {
    this->_translateY = y;
    this->queue_draw();
  }}


bool NodeViewer::on_motion(GdkEventMotion* eventMotion)
{
    if(onGrab)
    {
      std::cout << "=========== MOTION EVENT =============" << std::endl;
      std::cout << "motion x " << eventMotion->x << std::endl;
      std::cout << "motion y " << eventMotion->y << std::endl;
      std::cout << "======================================" << std::endl;

      _translateX = eventMotion->x - initX;
      _translateY = eventMotion->y - initY;

      if(_translateX < 0)
        _translateX = 0;
      if(_translateY < 0)
        _translateY = 0;

      std::cout << "========================" << std::endl;
      std::cout << "translate x " << _translateX << std::endl;
      std::cout << "translate y " << _translateY << std::endl;
      std::cout << "========================" << std::endl;

      this->queue_draw();
   

    }
    

    return true;
}

bool NodeViewer::on_button_press_event(GdkEventButton* key_event)
{  
  initX = key_event->x - _translateX;
  initY = key_event->y - _translateY;

  std::cout << "=========== BUTTON PRESS EVENT =============" << std::endl;
  std::cout << "init x " << initX << std::endl;
  std::cout << "init y " << initY << std::endl;
  std::cout << "============================================" << std::endl;

  onGrab = true;
  this->get_window()->set_cursor(Gdk::Cursor::create(Gdk::CursorType::SB_H_DOUBLE_ARROW));
  return true;
}

bool NodeViewer::on_button_release_event(GdkEventButton* e)
{  
  onGrab = false;
  _translateX = e->x - initX;
  _translateY = e->y - initY;
  this->get_window()->set_cursor(Gdk::Cursor::create(Gdk::CursorType::ARROW));
  return true;
}