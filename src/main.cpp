
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <node_editor/node_editor.hpp>

#include <iostream>

int main(int argc, char** argv)
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
   std::cout << "hola" << std::endl;
   Gtk::Window win;
   win.set_title("Cairomm Clock");
   win.set_default_size(600, 400);

   NodeEditor nodeEditor;
   win.add_events(Gdk::POINTER_MOTION_MASK);
   win.add_events(Gdk::KEY_PRESS_MASK);
   win.add(nodeEditor);
   win.show_all();

 
   return app->run(win);
}
