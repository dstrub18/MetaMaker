/*
  ==============================================================================

    SettingsWindow.cpp
    Created: 3 Apr 2020 9:18:39pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SettingsWindow.h"

//==============================================================================
SettingsWindow::SettingsWindow(int width, int height, String name, std::unique_ptr<SettingsWindowPanel> contentComponent)
                                                : DocumentWindow (name, Colours::turquoise, DocumentWindow::allButtons)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    sourceDirectoryLabel = std::make_unique<Label>();
    chooseDirectoryButton = std::make_unique<TextButton>("Choose Directory");
    
    centreWithSize (width, height);
    setVisible (false);
    m_isVisible = false;
    
    setContentOwned(contentComponent.get(), true);
    
    
}

SettingsWindow::~SettingsWindow()
{
}

    // DocumentWindow override
void SettingsWindow::closeButtonPressed()
{
    setVisible(false);
    m_isVisible = false;
}


const void SettingsWindow::setVisibiltyState (bool newState)
{
    m_isVisible = newState;
}

bool SettingsWindow::getVisibilityState () const
{
    return m_isVisible;
}

