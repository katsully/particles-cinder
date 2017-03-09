#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ParticleSystemApp : public App {
  public:
    // FIRST
    void prepareSettings( Settings *settings );
    
    void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    // SECOND
    ParticleSystem ps;
    
    // THRID
//    std::vector<ParticleSystem> mParticleSystems;
    
    // FOURTH
    void mouseMove( MouseEvent e );
    vec2 mousePos;
};

void ParticleSystemApp::prepareSettings(Settings *settings)
{
    // FIRST
    settings->setWindowSize( 640, 360 );
}

void ParticleSystemApp::setup()
{
    // SECOND
    ps = ParticleSystem( vec2( getWindowWidth() / 2, 50.0 ) );
    
    // THIRD
//    mParticleSystems.push_back(ParticleSystem( vec2( getWindowWidth() / 2, 50.0 ) ));

}

void ParticleSystemApp::mouseDown( MouseEvent event )
{
    // THIRD
//    mParticleSystems.push_back(ParticleSystem(vec2(event.getX(), event.getY())));
}

// FOURTH
void ParticleSystemApp::mouseMove( MouseEvent e )
{
    mousePos = e.getPos();
}

void ParticleSystemApp::update()
{
}

void ParticleSystemApp::draw()
{
    // FIRST
    gl::clear( Color::white() );
    
    // FOURTH
    // Calculate a "wind" force based on mouse horizontal position
    float dx = lmap( mousePos.x, 0.0f, float( getWindowWidth() ), -0.02f, 0.02f );
    vec2 wind = vec2( dx, .001 );
    ps.applyForce(wind);
    
    // FOURTH
    for( int i = 0; i < 2; i++ ){
        ps.addParticle();
    }
    ps.run();
    
    // THIRD
//    for( vector<ParticleSystem>::iterator it = mParticleSystems.begin(); it != mParticleSystems.end(); ++it ) {
//        it->addParticle();
//        it->run();
//    }
    
    // SECOND
//    ps.addParticle();
//    ps.run();
}

CINDER_APP( ParticleSystemApp, RendererGl )
