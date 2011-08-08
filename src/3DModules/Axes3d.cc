#include <Viewer/Axes3d.hh>
#include <Viewer/Colour.hh>
#include <Viewer/ColourPalette.hh>
#include <Viewer/GUIManager.hh>
#include <Viewer/CheckBoxLabel.hh>
#include <Viewer/ConfigTableUtils.hh>

#include <SFML/OpenGL.hpp>

namespace Viewer {
namespace Frames {

Axes3d::Axes3d( double length ) 
{ 
	fDisplay = true;
	fDisplayGUI = NULL;

    fXColour = ColourPalette::gPalette->GetPrimaryColour( eRed );
    fYColour = ColourPalette::gPalette->GetPrimaryColour( eGreen );
    fZColour = ColourPalette::gPalette->GetPrimaryColour( eBlue );

    fXPoint = length * TVector3( 1, 0, 0 );
    fYPoint = length * TVector3( 0, 1, 0 );
    fZPoint = length * TVector3( 0, 0, 1 );
}

void Axes3d::CreateGUIObjects( GUIManager& g, const sf::Rect< double >& optionsArea )
{
	sf::Rect< double > rect = optionsArea;
	fDisplayGUI = g.NewGUI< GUIs::CheckBoxLabel >( rect );
	fDisplayGUI->SetState( fDisplay );
	fDisplayGUI->SetLabel( "Display Axes" );
}

void Axes3d::LoadConfiguration( ConfigurationTable* configTable )
{
	ConfigTableUtils::SetBoolean( configTable, "Display", fDisplay );
}

void Axes3d::SaveConfiguration( ConfigurationTable* configTable )
{
	ConfigTableUtils::GetBooleanSafe( configTable, "Display", fDisplay );
}

void Axes3d::EventLoop()
{
	if( fDisplayGUI != NULL )
		fDisplay = fDisplayGUI->GetState();
}

void Axes3d::RenderAxes( )
{
	if( fDisplay == true )
	{
    	RenderAxis( fXPoint, fXColour );
    	RenderAxis( fYPoint, fYColour );
    	RenderAxis( fZPoint, fZColour);
	}
}

void Axes3d::RenderAxis( const TVector3& p, Colour& colour )
{
    glDisable( GL_DEPTH_TEST );
    glPushAttrib( GL_COLOR );
    colour.SetOpenGL();

    glBegin( GL_LINES );
    glVertex3f( 0, 0, 0 );
    glVertex3f( p.X(), p.Y(), p.Z() );
    glEnd();

    glPopAttrib();
    glEnable( GL_DEPTH_TEST );
}

}; // namespace Frames
}; // namespace Viewer