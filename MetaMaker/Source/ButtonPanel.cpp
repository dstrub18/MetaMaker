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
    
    copyButton -> setBounds(GUIDefines::initialButtonPanelWidth / 2 - GUIDefines::buttonWidth / 2,
                            GUIDefines::initialButtonPanelHeight / 2 - GUIDefines::buttonHeight / 2,
                            GUIDefines::buttonWidth,
                            GUIDefines::buttonHeight);
    copyButton -> changeWidthToFitText ();
    copyButton -> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 2 - copyButton -> getWidth() / 2,
                                     GUIDefines::initialButtonPanelHeight / 2 - GUIDefines::buttonHeight / 2 - 30);
    copyButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::blue);
    
    moveButton = std::make_unique<TextButton> ("Move File");
    //    copyButton -> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 2, GUIDefines::initialButtonPanelHeight / 2);
    //    copyButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    
    
    moveButton -> setBounds (GUIDefines::initialButtonPanelWidth / 2 - GUIDefines::buttonWidth / 2,
                            GUIDefines::initialButtonPanelHeight / 2 - GUIDefines::buttonHeight / 2,
                            GUIDefines::buttonWidth,
                            GUIDefines::buttonHeight);
    moveButton -> changeWidthToFitText ();
    moveButton -> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 2 - moveButton -> getWidth() / 2,
                                     GUIDefines::initialButtonPanelHeight / 2 - GUIDefines::buttonHeight / 2 );
    
    moveButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::darkmagenta);
    
    writeAndCoppyButton = std::make_unique<TextButton> ("WriteAndCopy");
    writeAndCoppyButton -> setBounds (GUIDefines::initialButtonPanelWidth / 2 - GUIDefines::buttonWidth / 2,
                                     GUIDefines::initialButtonPanelHeight / 2 + GUIDefines::buttonHeight / 2,
                                     GUIDefines::buttonWidth,
                                     GUIDefines::buttonHeight);
    writeAndCoppyButton -> changeWidthToFitText ();
    writeAndCoppyButton -> setTopLeftPosition (GUIDefines::initialButtonPanelWidth / 2 - writeAndCoppyButton -> getWidth() / 2,
                                     GUIDefines::initialButtonPanelHeight / 2 + GUIDefines::buttonHeight / 2);
    
    writeAndCoppyButton -> setColour (TextButton::ColourIds::buttonColourId, Colours::darkorange);
    
    addAndMakeVisible(*copyButton);
    addAndMakeVisible(*moveButton);
    addAndMakeVisible(*writeAndCoppyButton);
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
