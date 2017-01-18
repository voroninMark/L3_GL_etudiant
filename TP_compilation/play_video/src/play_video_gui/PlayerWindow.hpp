#ifndef _PLAYERWINDOW_HPP_
#define _PLAYERWINDOW_HPP_

#include <gtkmm.h>
#include <vlc/vlc.h>
#include <string>
#include <vector>

class PlayerWindow : public Gtk::Window {

    private:
        Gtk::DrawingArea _drawingArea;

        libvlc_instance_t *_ptrInstance;
        libvlc_media_list_player_t *_ptrListPlayer;
        libvlc_media_player_t *_ptrPlayer;

        void onDrawingAreaRealize() ;

    public:
        PlayerWindow(const std::vector<std::string> & files);
        ~PlayerWindow();
};

#endif

