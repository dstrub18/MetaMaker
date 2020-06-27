/*
  ==============================================================================

    FileInfoPanel.cpp
    Created: 26 Jun 2020 7:02:57pm
    Author:  Strue Audio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FileInfoPanel.h"

//==============================================================================
FileInfoPanel::FileInfoPanel(int panelWidth, int panelHeight)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    
    fileNameLabel.reset (new Label ("fileNameLabel",
                                    TRANS("")));
    addAndMakeVisible (fileNameLabel.get());
    fileNameLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileNameLabel->setJustificationType (Justification::centredLeft);
    fileNameLabel->setEditable (false, true, false);
    fileNameLabel->setColour (Label::backgroundColourId, Colour (0xffe41713));
    fileNameLabel->setColour (TextEditor::textColourId, Colours::black);
    fileNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    fileNameLabel->setBounds (panelWidth / 2 - 150 / 2, 72, 150, 24);
    
    artistLabel.reset (new Label ("artistLabel",
                                  TRANS("")));
    addAndMakeVisible (artistLabel.get());
    artistLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    artistLabel->setJustificationType (Justification::centredLeft);
    artistLabel->setEditable (false, true, false);
    artistLabel->setColour (TextEditor::textColourId, Colours::black);
    artistLabel->setColour (Label::backgroundColourId, Colours::violet);
    
    artistLabel->setBounds (panelWidth / 2 - 150 / 2, 104, 150, 24);
    
    fileCreationDateLabel.reset (new Label ("fileCreationDate",
                                            TRANS("")));
    addAndMakeVisible (fileCreationDateLabel.get());
    fileCreationDateLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileCreationDateLabel->setJustificationType (Justification::centredLeft);
    fileCreationDateLabel->setEditable (false, true, false);
    fileCreationDateLabel->setColour (Label::backgroundColourId, Colours::blue);
    fileCreationDateLabel->setColour (TextEditor::textColourId, Colours::black);
    
    
    fileCreationDateLabel->setBounds (panelWidth / 2 - 150 / 2, 136, 150, 24);
    
    descriptionLabel.reset (new Label ("descriptionLabel",
                                       TRANS("")));
    addAndMakeVisible (descriptionLabel.get());
    descriptionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    descriptionLabel->setJustificationType (Justification::centredLeft);
    descriptionLabel->setEditable (false, true, false);
    descriptionLabel->setColour (Label::backgroundColourId, Colours::green);
    descriptionLabel->setColour (TextEditor::textColourId, Colours::black);
    
    descriptionLabel->setBounds (panelWidth / 2 - 150 / 2, 168, 150, 24);
    
    
    
    
    setSize (panelWidth, panelHeight);

}

FileInfoPanel::~FileInfoPanel()
{
    fileNameLabel = nullptr;
    artistLabel = nullptr;
    fileCreationDateLabel = nullptr;
    descriptionLabel = nullptr;
}


const void FileInfoPanel::disableLabelEditing ()
{
    fileNameLabel           -> setEditable(false, false, false);
    artistLabel             -> setEditable(false, false, false);
    fileCreationDateLabel        -> setEditable(false, false, false);
    descriptionLabel        -> setEditable(false, false, false);
    
}

const void FileInfoPanel::enableLabelEditing ()
{
    fileNameLabel           -> setEditable(false, true, false);
    artistLabel             -> setEditable(false, true, false);
    fileCreationDateLabel        -> setEditable(false, true, false);
    descriptionLabel        -> setEditable(false, true, false);
}



void FileInfoPanel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.fillAll (Colours::coral);
}

void FileInfoPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}



