/*
  ==============================================================================

    SettingsWindowPanel.cpp
    Created: 4 Apr 2020 8:49:26pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SettingsWindowPanel.h"

//==============================================================================
SettingsWindowPanel::SettingsWindowPanel(int width, int height)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    setSize (width, height);
    
    sourcePathLabel = std::make_unique<Label>();
    chooseFileButton = std::make_unique<TextButton>("Choose Directory");
    showOnStartToggle = std::make_unique<ToggleButton>("Show on Start");
    
    
    sourcePathLabel -> setSize(100, 20 );
    sourcePathLabel -> setTopLeftPosition(100, 20);
    
    chooseFileButton -> setSize(50, 20);
    chooseFileButton -> changeWidthToFitText();
    chooseFileButton -> setTopLeftPosition( 100, 50);
    
    showOnStartToggle -> setSize(50, 20);
    showOnStartToggle -> changeWidthToFitText();
    showOnStartToggle -> setTopLeftPosition(100, 750);
    
    sourcePathLabel -> setColour(Label::backgroundColourId, Colours::blue);
    sourcePathLabel -> setText("Label Label Label", Defines::noNotification);
    
    addAndMakeVisible(*sourcePathLabel);
    addAndMakeVisible(*chooseFileButton);
    addAndMakeVisible(*showOnStartToggle);
    

}

SettingsWindowPanel::~SettingsWindowPanel()
{
}

void SettingsWindowPanel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("SettingsWindowPanel", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void SettingsWindowPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
