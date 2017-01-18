#include "PlayerWindow.hpp"
#include <gdk/gdkx.h>

void PlayerWindow::onDrawingAreaRealize() {
    // attach media player to drawing area
    uint32_t id = GDK_WINDOW_XID(Glib::unwrap(_drawingArea.get_window()));
    libvlc_media_player_set_xwindow(_ptrPlayer, id);
    // start playing media list
    libvlc_media_list_player_play(_ptrListPlayer);
}

PlayerWindow::PlayerWindow(const std::vector<std::string> & files) {

    // init libvlc
    _ptrInstance = libvlc_new(0, nullptr);
    // list player
    libvlc_media_list_t *ml = libvlc_media_list_new(_ptrInstance);
    for (const std::string & file : files) {
        libvlc_media_t *md = libvlc_media_new_path(_ptrInstance, file.c_str());
        libvlc_media_list_add_media(ml, md);
        libvlc_media_release(md);
    }
    _ptrListPlayer = libvlc_media_list_player_new(_ptrInstance);
    libvlc_media_list_player_set_media_list(_ptrListPlayer, ml);
    // media player
    _ptrPlayer = libvlc_media_player_new(_ptrInstance);
    libvlc_media_list_player_set_media_player(_ptrListPlayer, _ptrPlayer);

    // init gtk
    set_default_size(640, 480);
    add(_drawingArea);
    _drawingArea.signal_realize().connect(
            sigc::mem_fun(*this, &PlayerWindow::onDrawingAreaRealize));
    show_all();
}

PlayerWindow::~PlayerWindow() {
    libvlc_media_player_release(_ptrPlayer);
    libvlc_release(_ptrInstance);
}


