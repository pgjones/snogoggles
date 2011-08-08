#include <cstddef>
#include <Viewer/Configuration.hh>
#include <Viewer/ConfigurationTable.hh>
#include <Viewer/SerializableFactory.hh>
#include <Viewer/Polyhedron.hh>
#include <Viewer/ColourPalette.hh>
#include <Viewer/GeodesicSphere.hh>

namespace Viewer {

GeodesicSphere* GeodesicSphere::fInstance = NULL;

GeodesicSphere* GeodesicSphere::GetInstance()
{
	if( fInstance == NULL )
		fInstance = new GeodesicSphere();

	return fInstance;
}

GeodesicSphere::GeodesicSphere()
	: fColour( ColourPalette::gPalette->GetPrimaryColour( eGrey ) )
{
	Configuration config = Configuration( "data/geodesic.xml", false );
	std::vector< ConfigurationTable* >::iterator itr;
    itr = config.GetTableBegin();
	ConfigurationTable* volumeTable = (*itr)->GetTable( "volume" );
	fPolyhedron = SerializableFactory::GetInstance()->NewPtr< Polyhedron >( volumeTable, "polyhedron" );
}

const Polyhedron& GeodesicSphere::GetPolyhedron()
{
	return *fPolyhedron;
}

const Colour& GeodesicSphere::GetColour()
{
	return fColour;
}

}; // namespace Viewer