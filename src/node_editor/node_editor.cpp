#include <node_editor/node_editor.hpp>
#include <gtkmm/box.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/scale.h>

NodeEditor::NodeEditor() : 

vBox (Gtk::Box(Gtk::ORIENTATION_VERTICAL))
{

    vBox.pack_start(nodeViewer);

    this->add(vBox);
    
}

NodeEditor::~NodeEditor() {

}
