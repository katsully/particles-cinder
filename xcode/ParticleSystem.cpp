//
//  ParticleSystem.cpp
//  ParticleSystem
//
//  Created by Kathleen Sullivan on 3/8/17.
//
//

#include "ParticleSystem.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;
using namespace std;

ParticleSystem::ParticleSystem()
{
    
}

ParticleSystem::ParticleSystem( cinder::vec2 location )
{
    mOrigin = location;
    mParticles = vector<Particle>();
}

void ParticleSystem::addParticle()
{
    mParticles.push_back( Particle( mOrigin ) );
}

void ParticleSystem::run()
{
    for( vector<Particle>::iterator it = mParticles.begin(); it != mParticles.end(); ++it ) {
        if ( it->isDead() ) {
            // must provide iterator in the erase function
            mParticles.erase( it );
        }
        it->run();
    }
}

// FOURTH
void ParticleSystem::applyForce( vec2 force )
{
    for( vector<Particle>::iterator it = mParticles.begin(); it != mParticles.end(); ++it ) {
        it->applyForce( force );
    }
}