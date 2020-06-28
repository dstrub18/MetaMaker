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
    sourcePathLabel -> setEditable(false);
    
    chooseSourcePathButton = std::make_unique<TextButton>("Choose Source Path");
    showOnStartToggle = std::make_unique<ToggleButton>("Show on Start");
    
    
    sourcePathLabel -> setSize(200, 20 );
    sourcePathLabel -> setTopLeftPosition(100, 20);
    
    chooseSourcePathButton -> setSize(50, 20);
    chooseSourcePathButton -> changeWidthToFitText();
    chooseSourcePathButton -> setTopLeftPosition( 100, 50);
    
    showOnStartToggle -> setSize(50, 20);
    showOnStartToggle -> changeWidthToFitText();
    showOnStartToggle -> setTopLeftPosition(100, 75);
    
    outputPathLabel = std::make_unique<Label>();
    chooseOutputPathButton = std::make_unique<TextButton>("Choose Output Path");

    outputPathLabel -> setSize(200, 20);
    outputPathLabel -> setTopLeftPosition(100, 100);
    
    chooseOutputPathButton -> setSize(50, 20);
    chooseOutputPathButton -> changeWidthToFitText();
    chooseOutputPathButton -> setTopLeftPosition(100, 120);
    
    
    
    sourcePathLabel -> setColour(Label::backgroundColourId, Colours::blue);
    sourcePathLabel -> setText("", Defines::noNotification);
    
    outputPathLabel -> setColour(Label::backgroundColourId, Colours::red);
    
    // Listener assignments
    
    chooseSourcePathButton -> addListener(this);
    chooseOutputPathButton -> addListener(this);
    
    
    // and and make visibles
    addAndMakeVisible(*sourcePathLabel);
    addAndMakeVisible(*chooseSourcePathButton);
    addAndMakeVisible(*showOnStartToggle);
    
    addAndMakeVisible(*outputPathLabel);
    addAndMakeVisible(*chooseOutputPathButton);
    
}

SettingsWindowPanel::~SettingsWindowPanel()
{
    
    
}



void SettingsWindowPanel::buttonClicked (Button* button)
{
    if (button == chooseSourcePathButton.get())
    {
        FileChooser chooser ("Choose Source Directory", File(), Defines::allFiletypesAllowed, true, false, nullptr);
        
        if (chooser.browseForDirectory())
        {
            sourcePathLabel -> setText(chooser.getResult().getFullPathName(), sendNotification);
        }
    }
    
    if (button == chooseOutputPathButton.get())
    {
        
        FileChooser chooser ("Choose Output Directory", File(), Defines::allFiletypesAllowed, true, false, nullptr);
        
        if (chooser.browseForDirectory())
        {
            outputPathLabel -> setText(chooser.getResult().getFullPathName(), sendNotification);
        }
        
        Logger::writeToLog(getOutputPath());
    }
    
    
    
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
}

void SettingsWindowPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
