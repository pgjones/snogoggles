#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
using namespace std;

#include <Viewer/MasterUI.hh>
#include <Viewer/NewFrameButton.hh>
#include <Viewer/FrameFactory.hh>
#include <Viewer/FrameManager.hh>
using namespace Viewer;
using namespace Frames;

MasterUI::MasterUI( FrameManager* manager )
  : fFrameManager( manager )
{
  FrameFactory a;
  fFrameNames = a.GetNames();
  for( unsigned int uLoop = 0; uLoop < fFrameNames.size(); uLoop++ )
    {
      double width = 1.0 / ( 1.5 * (double)fFrameNames.size() );
      sf::Rect<double> pos( 1.5 * width * (double)uLoop, 0.1, width, 0.9 );
      GUIs::NewFrameButton* button = fGUIManager.NewGUI<GUIs::NewFrameButton>( pos );
      button->SetTitle( fFrameNames[uLoop] );
      fButtons.push_back( button );
    }
}

void 
MasterUI::EventLoop()
{
  while( !fEvents.empty() )
    {
      GUIReturn event = fEvents.front();
      if( !fButtons[event.fguiID]->GetState() )
	fFrameManager->NewFrame( fFrameNames[fEvents.front().fguiID] );
      fEvents.pop();
    }
}