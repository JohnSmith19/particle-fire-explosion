//
// Created by jerom on 2018-06-10 0010.
//

#include "Swarm.h"

Swarm::Swarm() {
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}
