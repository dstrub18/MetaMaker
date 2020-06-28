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
    fileNameLabel->setColour (Label::backgroundColourId, Colours::grey);
    fileNameLabel->setColour (TextEditor::textColourId, Colours::black);
    
    fileNameLabel->setBounds (panelWidth / 2 - 150 / 2, 72, 150, 24);
    
    
    fileNameTitle.reset (new Label ("File Name"));
    fileNameTitle -> setText("File Name", Defines::noNotification);
    fileNameTitle -> setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileNameTitle->setJustificationType (Justification::centredLeft);
    fileNameTitle->setEditable (false, false, false);
    
    fileNameTitle -> setColour(Label::backgroundColourId, Colours::red);
    
    
    fileNameTitle -> attachToComponent(fileNameLabel.get(), GUIDefines::attachAbove);
    fileNameTitle -> setSize (fileNameTitle -> getFont().getStringWidth(fileNameTitle -> getText ()), GUIDefines::labelHeight);
    
//===================
    
    artistLabel.reset (new Label ("artistLabel",
                                  TRANS("")));
    addAndMakeVisible (artistLabel.get());
    artistLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    artistLabel->setJustificationType (Justification::centredLeft);
    artistLabel->setEditable (false, true, false);
    artistLabel->setColour (Label::backgroundColourId, Colours::grey);
    artistLabel->setColour (TextEditor::textColourId, Colours::black);
    
    artistLabel->setBounds (panelWidth / 2 - 150 / 2, 72 + GUIDefines::propertyLabelDistance, GUIDefines::labelWidth, GUIDefines::labelHeight);
    
    
    artistTitle.reset(new Label ("Artist"));
    artistTitle -> setText("Artist", Defines::noNotification);
    addAndMakeVisible(artistTitle.get());
    artistTitle->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    artistTitle->setJustificationType (Justification::centredLeft);
    artistTitle->setEditable (false, false, false);
    artistTitle->setColour (Label::backgroundColourId, Colours::red);
    
    artistTitle -> attachToComponent(artistLabel.get(), GUIDefines::attachAbove);
    artistTitle -> setSize (artistTitle -> getFont().getStringWidth(artistTitle -> getText ()), GUIDefines::labelHeight);
    
    
//===================
    
    fileCreationDateLabel.reset (new Label ("fileCreationDate",
                                            TRANS("")));
    addAndMakeVisible (fileCreationDateLabel.get());
    fileCreationDateLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileCreationDateLabel->setJustificationType (Justification::centredLeft);
    fileCreationDateLabel->setEditable (false, true, false);
    fileCreationDateLabel->setColour (Label::backgroundColourId, Colours::grey);
    fileCreationDateLabel->setColour (TextEditor::textColourId, Colours::black);
    
    
    fileCreationDateLabel->setBounds (panelWidth / 2 - 150 / 2, 72 + GUIDefines::propertyLabelDistance * 2, GUIDefines::labelWidth, GUIDefines::labelHeight);

    
    
    fileCreationDateTitle.reset(new Label ("Creation Date"));
    fileCreationDateTitle -> setText("Creation Date", Defines::noNotification);
    addAndMakeVisible(fileCreationDateTitle.get());
    fileCreationDateTitle->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileCreationDateTitle->setJustificationType (Justification::centredLeft);
    fileCreationDateTitle->setEditable (false, false, false);
    fileCreationDateTitle->setColour (Label::backgroundColourId, Colours::red);
    
    fileCreationDateTitle -> attachToComponent(fileCreationDateLabel.get(), GUIDefines::attachAbove);
    fileCreationDateTitle -> setSize (artistTitle -> getFont().getStringWidth(fileCreationDateTitle -> getText ()), GUIDefines::labelHeight);
    
//===================
    
    descriptionLabel.reset (new Label ("descriptionLabel",
                                       TRANS("")));
    addAndMakeVisible (descriptionLabel.get());
    descriptionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    descriptionLabel->setJustificationType (Justification::centredLeft);
    descriptionLabel->setEditable (false, true, false);
    descriptionLabel->setColour (Label::backgroundColourId, Colours::grey);
    descriptionLabel->setColour (TextEditor::textColourId, Colours::black);
    
    descriptionLabel->setBounds (panelWidth / 2 - 150 / 2, 72 + GUIDefines::propertyLabelDistance * 3, GUIDefines::labelWidth, GUIDefines::labelHeight);
    
    setSize (panelWidth, panelHeight);
    
    
    descriptionTitle.reset(new Label ("Creation Date"));
    descriptionTitle -> setText("BWAV Description", Defines::noNotification);
    addAndMakeVisible(fileCreationDateTitle.get());
    descriptionTitle->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    descriptionTitle->setJustificationType (Justification::centredLeft);
    descriptionTitle->setEditable (false, false, false);
    descriptionTitle->setColour (Label::backgroundColourId, Colours::red);
    
    descriptionTitle -> attachToComponent(descriptionLabel.get(), GUIDefines::attachAbove);
    descriptionTitle -> setSize (artistTitle -> getFont().getStringWidth(descriptionTitle -> getText ()), GUIDefines::labelHeight);
    

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
    fileCreationDateLabel   -> setEditable(false, false, false);
    descriptionLabel        -> setEditable(false, false, false);
    
}

const void FileInfoPanel::enableLabelEditing ()
{
    fileNameLabel           -> setEditable(false, true, false);
    artistLabel             -> setEditable(false, true, false);
    fileCreationDateLabel   -> setEditable(false, true, false);
    descriptionLabel        -> setEditable(false, true, false);
}



void FileInfoPanel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.fillAll (Colours::blue);
}

void FileInfoPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}



