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

#include "EditingPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EditingPanel::EditingPanel (int panelWidth, int panelHeight)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    editingLabel.reset (new Label ("Editing Label",
                                   TRANS("Editing Label")));
    addAndMakeVisible (editingLabel.get());
    editingLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    editingLabel->setJustificationType (Justification::centred);
    editingLabel->setEditable (true, true, false);
    editingLabel->setColour (Label::backgroundColourId, Colour (0xdbff0000));
    editingLabel->setColour (TextEditor::textColourId, Colours::black);
    editingLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    editingLabel->addListener (this);

    editingLabel->setBounds (125, 288, 150, 24);

    writeMetadataButton.reset (new TextButton ("Write MetadataButton"));
    addAndMakeVisible (writeMetadataButton.get());
    writeMetadataButton->setButtonText (TRANS("Write Metadata"));
    writeMetadataButton->addListener (this);

    writeMetadataButton->setBounds (125, 325, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1, 1);


    //[Constructor] You can add your own custom stuff here..

    setSize (panelWidth, panelHeight);

    //[/Constructor]
}

EditingPanel::~EditingPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    editingLabel = nullptr;
    writeMetadataButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EditingPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EditingPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EditingPanel::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == editingLabel.get())
    {
        //[UserLabelCode_editingLabel] -- add your label text handling code here..
        //[/UserLabelCode_editingLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void EditingPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == writeMetadataButton.get())
    {
        //[UserButtonCode_writeMetadataButton] -- add your button handler code here..
        //[/UserButtonCode_writeMetadataButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EditingPanel" componentName=""
                 parentClasses="public Component" constructorParams="int panelWidth, int panelHeight"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="1" initialHeight="1">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="Editing Label" id="1f7608345f36fbf8" memberName="editingLabel"
         virtualName="" explicitFocusOrder="0" pos="125 288 150 24" bkgCol="dbff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="Editing Label" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="Write MetadataButton" id="527d7a6fc5ac91bf" memberName="writeMetadataButton"
              virtualName="" explicitFocusOrder="0" pos="125 325 150 24" buttonText="Write Metadata"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

