//
// Created by jerom on 2018-06-10 0010.
//

#ifndef PARTICLE_H
#define PARTICLE_H


struct Particle {
    double m_x;
    double m_y;

    //double m_xspeed;
    //double m_yspeed;

    double m_speed;
    double m_direction;

public:
    Particle();
    virtual ~Particle();
    void update();
};

#endif //PARTICLE_H
