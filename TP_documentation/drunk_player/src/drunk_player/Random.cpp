#include <drunk_player/Random.hpp>

Random::Random() : 
    _engine(std::random_device{}()),
    _distribution(0, 1) 
{}

double Random::operator()() {
    return _distribution(_engine);
}

int Random::operator()(int n) {
    return std::min(n-1, int(n*_distribution(_engine)));
}

