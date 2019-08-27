/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "FileInfoWindow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FileInfoWindow::FileInfoWindow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    fileNameLabel.reset (new Label ("fileNameLabel",
                                    TRANS("File Name")));
    addAndMakeVisible (fileNameLabel.get());
    fileNameLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileNameLabel->setJustificationType (Justification::centredLeft);
    fileNameLabel->setEditable (false, false, false);
    fileNameLabel->setColour (Label::backgroundColourId, Colour (0xffe41713));
    fileNameLabel->setColour (TextEditor::textColourId, Colours::black);
    fileNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    fileNameLabel->setBounds (24, 64, 150, 24);

    bwavOriginatorLabel.reset (new Label ("artistLabel",
                                  TRANS("Artist label")));
    addAndMakeVisible (bwavOriginatorLabel.get());
    bwavOriginatorLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    bwavOriginatorLabel->setJustificationType (Justification::centredLeft);
    bwavOriginatorLabel->setEditable (false, false, false);
    bwavOriginatorLabel->setColour (TextEditor::textColourId, Colours::black);
    bwavOriginatorLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    bwavOriginatorLabel->setBounds (24, 96, 150, 24);

    fileCreationDateLabel.reset (new Label ("fileCreationDate",
                                       TRANS("File Creation Date")));
    addAndMakeVisible (fileCreationDateLabel.get());
    fileCreationDateLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fileCreationDateLabel->setJustificationType (Justification::centredLeft);
    fileCreationDateLabel->setEditable (false, false, false);
    fileCreationDateLabel->setColour (TextEditor::textColourId, Colours::black);
    fileCreationDateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    fileCreationDateLabel->setBounds (24, 128, 150, 24);

    descriptionLabel.reset (new Label ("descriptionLabel",
                                       TRANS("Description")));
    addAndMakeVisible (descriptionLabel.get());
    descriptionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    descriptionLabel->setJustificationType (Justification::centredLeft);
    descriptionLabel->setEditable (false, false, false);
    descriptionLabel->setColour (Label::backgroundColourId, Colours::green);
    descriptionLabel->setColour (TextEditor::textColourId, Colours::black);
    descriptionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    descriptionLabel->setBounds (24, 160, 150, 24);
    
    
    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FileInfoWindow::~FileInfoWindow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    fileNameLabel = nullptr;
    bwavOriginatorLabel = nullptr;
    fileCreationDateLabel = nullptr;
    descriptionLabel = nullptr;
    debugLabel = nullptr;

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FileInfoWindow::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FileInfoWindow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FileInfoWindow" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="200" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="fileNameLabel" id="e2a9cce2df4c6527" memberName="fileNameLabel"
         virtualName="" explicitFocusOrder="0" pos="24 64 150 24" bkgCol="ffe41713"
         edTextCol="ff000000" edBkgCol="0" labelText="File Name" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="artistLabel" id="ebaf385d731b9325" memberName="artistLabel"
         virtualName="" explicitFocusOrder="0" pos="24 96 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Artist label" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="fileCreationDate" id="97a6b6f0912d21ed" memberName="fileCreationDate"
         virtualName="" explicitFocusOrder="0" pos="24 128 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="File Creation Date" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="descriptionLabel" id="c099da4c3f67f9bd" memberName="descriptionLabel"
         virtualName="" explicitFocusOrder="0" pos="24 160 150 24" bkgCol="ff008000"
         edTextCol="ff000000" edBkgCol="0" labelText="File Creation Date"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

