/*
  ==============================================================================

    SettingsWindow.h
    Created: 3 Apr 2020 9:18:39pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SettingsWindow    : public DocumentWindow
{
public:
    SettingsWindow (int width, int height, String name);
    ~SettingsWindow();
    
    const void setVisibiltyState (bool newState);
    bool getVisibilityState () const;

private:
    
    void closeButtonPressed() override;
    
    const int m_styleFlags =    ComponentPeer::StyleFlags::windowIsResizable +
                                ComponentPeer::StyleFlags::windowHasTitleBar +
                                ComponentPeer::StyleFlags::windowHasCloseButton +
                                ComponentPeer::StyleFlags::windowHasMinimiseButton +
                                ComponentPeer::StyleFlags::windowHasMaximiseButton;
    
    bool m_isVisible {false};
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsWindow)
};
