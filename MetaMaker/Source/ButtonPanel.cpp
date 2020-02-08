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
    
    copyButton = std::make_unique<TextButton>("CopyButton");
//    copyButton -> setTopLeftPosition(GUIDefines::initialButtonPanelWidth / 2, GUIDefines::initialButtonPanelHeight / 2);
//    copyButton -> setSize(GUIDefines::buttonWidth, GUIDefines::buttonHeight);
    copyButton -> setBounds(GUIDefines::initialButtonPanelWidth / 2 - GUIDefines::buttonWidth / 2,
                            GUIDefines::initialButtonPanelHeight / 2 - GUIDefines::buttonHeight / 2,
                            GUIDefines::buttonWidth,
                            GUIDefines::buttonHeight);
    copyButton -> setColour(TextButton::ColourIds::buttonColourId, Colours::yellowgreen);
    copyButton -> changeWidthToFitText();
    
    addAndMakeVisible(*copyButton);
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
