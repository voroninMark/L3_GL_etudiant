#include "Ui.hpp"

Ui::Ui(Net & net) : _net(net)
{
    set_size_request(640, 480); 
    add(_box); 

    _textView.set_editable(false);
    _box.pack_start(_textView);

    _entry.add_events(Gdk::KEY_RELEASE_MASK);
    _box.pack_start(_entry, Gtk::PACK_SHRINK);

    show_all(); 
    _entry.grab_focus();

    // connect textview for receiving data from server
    auto fLoopReceive = [this] () { while (true) this->handleReceive(); };
    _receiveThread = std::move(boost::thread(fLoopReceive));

    // connect entry for sending data to server
    _entry.signal_key_release_event().connect(
            sigc::mem_fun(*this, &Ui::handleSend));                
}

void Ui::handleReceive()
{
    // wait and receive message from server
    std::string message = _net.receive();

    // display message in textview
    auto textBuffer = _textView.get_buffer();
    textBuffer->insert(textBuffer->end(), message);
}

bool Ui::handleSend(GdkEventKey * event)
{
    // after "return" key is pressed, send text to server and reset
    if (event->keyval == GDK_KEY_Return)
    {
        _net.send(_entry.get_text());
        _entry.set_text("");
    }
    return true;
}

