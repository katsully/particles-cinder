//
//  ParticleSystem.h
//  ParticleSystem
//
//  Created by Kathleen Sullivan on 3/8/17.
//
//

#include "cinder/app/App.h"
#include "Particle.h"

class ParticleSystem {
public:
    ParticleSystem();
    ParticleSystem( cinder::vec2 location );
    
    void addParticle();
    void run();
    
    // FOURTH
    void applyForce(cinder::vec2 force);
        
private:
    cinder::vec2 mOrigin;
    std::vector<Particle> mParticles;
};