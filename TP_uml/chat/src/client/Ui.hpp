#ifndef UI_HPP_
#define UI_HPP_

#include "Net.hpp"

#include <boost/thread/thread.hpp>
#include <gtkmm.h>

class Ui : public Gtk::Window 
{
    private:
        Gtk::VBox _box;
        Gtk::TextView _textView;
        Gtk::Entry _entry;

        Net & _net;
        boost::thread _receiveThread;

    public:
        Ui(Net & net); 

    protected:
        bool handleSend(GdkEventKey * event);
        void handleReceive();
};

#endif

