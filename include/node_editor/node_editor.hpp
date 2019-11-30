#ifndef NODE_EDITOR_HPP
#define NODE_EDITOR_HPP

#include <gtkmm/frame.h>
#include <gtkmm/box.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/scale.h>
#include <node_viewer/node_viewer.hpp>

class NodeEditor : public Gtk::Frame {
    public:
        NodeEditor();
        virtual ~NodeEditor();

    protected:
       NodeViewer nodeViewer;
       Gtk::Box vBox;
};

#endif //NODE_EDITOR_HPP