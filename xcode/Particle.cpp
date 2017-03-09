//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Kathleen Sullivan on 3/8/17.
//
//

#include "cinder/app/App.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Particle::Particle()
{
    
}

Particle::Particle( cinder::vec2 location )
{
    // Fill all variables
    mAcceleration = vec2( 0.0, 0.05 );
    mVelocity = vec2( randFloat( -1, 1 ), randFloat( -1.0, 0.0 ) );
    mLocation = location;
    mLifespan = 255.0;
}

void Particle::run()
{
    update();
    display();
}

// Method to update location
void Particle::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    if(mLifespan >= 2.0){
        mLifespan -= 2.0;
    }
}

// Method to display
void Particle::display()
{
    gl::color( ColorA8u( 127, 127, 127, mLifespan ) );
    gl::drawSolidEllipse( mLocation, 12.0, 12.0 );
    
    gl::color( ColorA8u( 0, 0, 0, mLifespan ) );
    glLineWidth( 2.0 );
    gl::drawStrokedEllipse( mLocation, 12.0, 12.0 );
}

// Is the particle still useful?
bool Particle::isDead()
{
    if (mLifespan <= 2.0) {
        return true;
    }
    else {
        return false;
    }
}

// FOURTH
void Particle::applyForce( vec2 force )
{
    mAcceleration += force;
}
