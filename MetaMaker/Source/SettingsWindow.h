/*
  ==============================================================================

    SettingsWindow.h
    Created: 3 Apr 2020 9:18:39pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SettingsWindowPanel.h"

//==============================================================================
/*
*/
class SettingsWindow    : public DocumentWindow
{
public:
    SettingsWindow (const int& width, const int& height, String&& name, Component* contentComponent);
    ~SettingsWindow();
    
    const void setVisibiltyState (bool newState);
    bool getVisibilityState () const;

private:
    
    // DocumentWindow override
    void closeButtonPressed() override;
    
    // ButtonListener override
    //void buttonClicked(Button* button) override;
    
    const int m_styleFlags =    ComponentPeer::StyleFlags::windowIsResizable +
                                ComponentPeer::StyleFlags::windowHasTitleBar +
                                ComponentPeer::StyleFlags::windowHasCloseButton +
                                ComponentPeer::StyleFlags::windowHasMinimiseButton +
                                ComponentPeer::StyleFlags::windowHasMaximiseButton;
    
    bool m_isVisible {false};
    
    SettingsWindowPanel contentComponent;
    
    std::unique_ptr<Label> sourceDirectoryLabel;
    std::unique_ptr<TextButton> chooseDirectoryButton;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsWindow)
};
