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
    
    copyButton = std::make_unique<TextButton> ("Copy File");
    copyButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    copyButton -> changeWidthToFitText ();
    copyButton -> setTopLeftPosition(0,0);
    copyButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::blue);
    
    
    moveButton = std::make_unique<TextButton> ("Move File");
    moveButton -> setSize (GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    moveButton -> changeWidthToFitText ();
    moveButton -> setTopLeftPosition(0, GUIDefines::buttonHeight);
    moveButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::darkmagenta);
    
    
    writeAndCoppyButton = std::make_unique<TextButton> ("WriteAndCopy");
    writeAndCoppyButton -> setSize (GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    writeAndCoppyButton -> changeWidthToFitText ();
    writeAndCoppyButton -> setTopLeftPosition (0, GUIDefines::buttonHeight * 2);
    writeAndCoppyButton -> setColour (TextButton::ColourIds::buttonColourId, Colours::darkorange);
    
    
    replaceMetadataButton = std::make_unique<TextButton> ("Replace");
    replaceMetadataButton -> setSize (GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    replaceMetadataButton -> changeWidthToFitText ();
    replaceMetadataButton -> setTopLeftPosition (0, GUIDefines::buttonHeight * 3);
    replaceMetadataButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::green);
    
    
    openSettingsButton = std::make_unique<TextButton>("Open Settings");
    openSettingsButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    openSettingsButton -> changeWidthToFitText();
    openSettingsButton-> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 4, GUIDefines::initialButtonPanelHeight - GUIDefines::buttonHeight);
    
    addAndMakeVisible (*copyButton);
    addAndMakeVisible (*moveButton);
    addAndMakeVisible (*writeAndCoppyButton);
    addAndMakeVisible (*replaceMetadataButton);
    addAndMakeVisible(*openSettingsButton);
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
