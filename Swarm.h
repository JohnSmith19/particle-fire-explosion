//
// Created by jerom on 2018-06-10 0010.
//

#ifndef PARTICLE_SWARM_H
#define PARTICLE_SWARM_H

#include "Particle.h"

class Swarm {
public:
    const static int NPARTICLES = 5000;
private:
    Particle* m_pParticles;
    int lastTime;
public:
    Swarm();
    virtual ~Swarm();

    const Particle* const getParticles() { return m_pParticles; };
    void update(int elapsed);
};

#endif //PARTICLE_SWARM_H
