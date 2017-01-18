#include <drunk_player/Chrono.hpp>

Chrono::Chrono() : _isRunning(false) {
}

void Chrono::reset() {
	_t1 = _t0 = std::chrono::system_clock::now();
}

void Chrono::start() {
    reset();
    _isRunning = true;
}

void Chrono::stop() {
	_t1 = std::chrono::system_clock::now();
    _isRunning = false;
}

double Chrono::elapsed() {
    if (_isRunning) {
        _t1 = std::chrono::system_clock::now();
    }
    auto d = std::chrono::duration_cast<std::chrono::milliseconds>(_t1 - _t0);
	return 1e-3 * d.count();
}

