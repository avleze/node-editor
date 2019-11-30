#ifndef NODE_VIEWER_HPP
#define NODE_VIEWER_HPP

#include <gtkmm/drawingarea.h>

class NodeViewer : public Gtk::DrawingArea
{
public:
  NodeViewer();
  virtual ~NodeViewer();
  void moveToX(double x);
  void moveToY(double y);
protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

  double _translateX;
  double _translateY;
  bool on_motion(GdkEventMotion* eventMotion);
  bool on_button_press_event(GdkEventButton* key_event);
  bool on_button_release_event(GdkEventButton* key_event);

  double initX;
  double initY;
  gboolean onGrab;
};

#endif // NODE_VIEWER_HPP
