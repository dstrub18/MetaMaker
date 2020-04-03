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
SettingsWindow::SettingsWindow(int width, int height, String name)
                                                : DocumentWindow (name,
                                                    Colours::grey,
                                                    DocumentWindow::allButtons)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    centreWithSize (width, height);
    setVisible (false);
}

SettingsWindow::~SettingsWindow()
{
}

// DocumentWindow overrides

void SettingsWindow::closeButtonPressed()
{
    setVisible(false);
    m_isVisible = false;
}

// Custom functions

const void SettingsWindow::setVisibiltyState (bool newState)
{
    m_isVisible = newState;
}

bool SettingsWindow::getVisibilityState () const
{
    return m_isVisible;
}

