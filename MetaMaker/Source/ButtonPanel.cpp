/*
  ==============================================================================

    ButtonPanel.cpp
    Created: 8 Feb 2020 7:36:34pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ButtonPanel.h"
#include "Defines.h"

//==============================================================================
ButtonPanel::ButtonPanel(const int& panelWidth, const int& panelHeight)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    
    setSize(panelWidth, panelHeight);

    
    replaceMetadataButton = std::make_unique<TextButton> ("Replace");
    replaceMetadataButton -> setSize (GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    replaceMetadataButton -> changeWidthToFitText ();
    replaceMetadataButton -> setTopLeftPosition (0, GUIDefines::buttonHeight * 3);
    replaceMetadataButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::green);
    
    
    openSettingsButton = std::make_unique<TextButton>("Open Settings");
    openSettingsButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    openSettingsButton -> changeWidthToFitText();
    openSettingsButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 4, GUIDefines::initialButtonPanelHeight - GUIDefines::buttonHeight);
    
    
    transportPlayButton = std::make_unique<TextButton>("Play");
    transportPlayButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    transportPlayButton -> changeWidthToFitText();
    transportPlayButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 4, 0);
    transportPlayButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::green);
    
    transportStopButton = std::make_unique<TextButton>("Stop");
    transportStopButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    transportStopButton -> changeWidthToFitText();
    transportStopButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 4, 0 + GUIDefines::buttonHeight);
    transportStopButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::red);
    
    
    timerStartButton = std::make_unique<TextButton>("Start Timer");
    timerStartButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    timerStartButton -> changeWidthToFitText();
    timerStartButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 3 + timerStartButton -> getWidth(), 0 );
    timerStartButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::orange);
    
    timerStopButton = std::make_unique<TextButton>("Stop Timer");
    timerStopButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    timerStopButton -> changeWidthToFitText();
    timerStopButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 3 + timerStopButton -> getWidth(), 0 + GUIDefines::buttonHeight);
    timerStopButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::darkblue);
    
    exportButton = std::make_unique<TextButton>("Export");
    exportButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    exportButton -> changeWidthToFitText();
    exportButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 3 + timerStopButton -> getWidth(), 0 + 2 * GUIDefines::buttonHeight);
    exportButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::deeppink);
    
    
    addAndMakeVisible (*replaceMetadataButton);
    
    addAndMakeVisible(*openSettingsButton);
    
    addAndMakeVisible(*transportPlayButton);
    addAndMakeVisible(*transportStopButton);
    
    addAndMakeVisible(*timerStartButton);
    addAndMakeVisible(*timerStopButton);
    
    addAndMakeVisible(*exportButton);
}

ButtonPanel::~ButtonPanel()
{
}

void ButtonPanel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::crimson);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

}

void ButtonPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
