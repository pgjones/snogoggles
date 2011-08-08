#include <SFML/Graphics/Rect.hpp>

#include <string.h>
using namespace std;

#include <Viewer/PixelImage.hh>
#include <Viewer/Rect.hh>
#include <Viewer/Colour.hh>
#include <Viewer/GUIColourPalette.hh>
using namespace Viewer;

void 
PixelImage::Clear( Rect& rect )
{
  fRect = rect;
  sf::Rect<double> size = fRect.GetResolutionRect();
  fWidth = size.Width;
  fHeight = size.Height;
  int pixelSize = fWidth * fHeight * 4;
  if( fPixels != NULL )
    delete fPixels;
  fPixels = new sf::Uint8[ pixelSize ];
  fWidth--; // Allows [0,1] rather than [0,1)
  fHeight--; // Allows [0,1] rather than [0,1)
  memset( fPixels, ~0, pixelSize * sizeof( sf::Uint8 ) );
  Colour bgColour = GUIColourPalette::gPalette->GetBGColour( eBase );
  for( int iPixel = 0; iPixel < pixelSize; iPixel+=4 )
    {
      fPixels[iPixel] = bgColour.r;
      fPixels[iPixel + 1] = bgColour.g;
      fPixels[iPixel + 2] = bgColour.b;
      fPixels[iPixel + 3] = bgColour.a;      
    }
}

sf::Sprite
PixelImage::ToSprite()
{
  fImage.LoadFromPixels( fWidth, fHeight, fPixels );
  sf::Sprite sprite;
  sprite.SetImage( fImage );
  sf::Rect<double> rect = fRect.GetResolutionRect(); 
  sprite.SetPosition( rect.Left, rect.Top );
  sprite.Resize( rect.Width, rect.Height );
  return sprite;
}
