//
//  Particle.h
//  ParticleSystem
//
//  Created by Kathleen Sullivan on 3/8/17.
//
//

#include "cinder/app/App.h"

class Particle {
public:
    Particle();
    Particle( cinder::vec2 location );
    
    void run();
    void update();
    void display();
    bool isDead();
    
    // FOURTH
    void applyForce(cinder::vec2 force);
    
private:
    cinder::vec2 mLocation;
    cinder::vec2 mAcceleration;
    cinder::vec2 mVelocity;
    float mLifespan;
};