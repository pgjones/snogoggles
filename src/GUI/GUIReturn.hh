////////////////////////////////////////////////////////////////////////
/// \class GUIReturn
///
/// \brief   
///
/// \author  Phil Jones <p.jones22@physics.ox.ac.uk>
///
/// REVISION HISTORY:\n
///     29/06/11 : P.Jones - First Revision, new file. \n
///
/// \detail  
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_GUIReturn__
#define __Viewer_GUIReturn__

namespace Viewer
{
class GUIReturn
{
public:
  GUIReturn() : fguiID( -1 ), fGlobalID( -1 ), fNULL( true ) { }
  inline GUIReturn( unsigned int guiID, unsigned int globalID );

  inline bool IsNULL();

  unsigned int fguiID;
  unsigned int fGlobalID;
  bool fNULL;
};

GUIReturn::GUIReturn( unsigned int guiID, unsigned int globalID )
  : fguiID( guiID ), fGlobalID( globalID ), fNULL( false )
{
  
}

bool
GUIReturn::IsNULL()
{
  return fNULL;
}

} // ::Viewer

#endif
