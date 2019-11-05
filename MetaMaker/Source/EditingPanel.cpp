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
                                   TRANS("Text goes here")));
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

    writeMetadataButton->setBounds (24, 368, 150, 24);

    createnewLabelButton.reset (new TextButton ("createnewLabelButton"));
    addAndMakeVisible (createnewLabelButton.get());
    createnewLabelButton->setButtonText (TRANS("Create new label"));
    createnewLabelButton->addListener (this);
    createnewLabelButton->setColour (TextButton::buttonColourId, Colours::blue);

    createnewLabelButton->setBounds (224, 368, 150, 24);

    fullLabel.reset (new Label ("fullLabel",
                                String()));
    addAndMakeVisible (fullLabel.get());
    fullLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    fullLabel->setJustificationType (Justification::centred);
    fullLabel->setEditable (false, false, false);
    fullLabel->setColour (Label::backgroundColourId, Colour (0xffff00b5));
    fullLabel->setColour (TextEditor::textColourId, Colours::black);
    fullLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    fullLabel->setBounds (24, 424, 350, 24);

    
    
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
    createnewLabelButton = nullptr;
    fullLabel = nullptr;
    
    

    //[Destructor]. You can add your own custom destruction code here..
    
    clearEditingLabels();   // Deletes all objects, that the elements in the vector are pointing at.
    
    
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
    else if (buttonThatWasClicked == createnewLabelButton.get())
    {
        //[UserButtonCode_createnewLabelButton] -- add your button handler code here..

        Label* label = new Label("label","emptylabel");
        //label.reset(new Label("label","emptylabel"));
        addAndMakeVisible(label);
        label -> setEditable(Defines::IS_EDITABLE);
        
        label -> setColour( Label::backgroundColourId, Colours::darkgreen);
        label -> setBounds(125, 10, GUIDefines::labelWidth, GUIDefines::labelHeight); // Change position later!!
        
        label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        label->setJustificationType (Justification::centred);
        
        
        editingLabels.emplace_back(label);
        
        std::cout << "Vector size: " + (String) editingLabels.size() << " \n";
        
        //[/UserButtonCode_createnewLabelButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

const void EditingPanel::clearEditingLabels(){
    
    for (auto i = editingLabels.begin(); i < editingLabels.end(); i++)
    {
        delete *i;
        std::cout << "Deleting element in vector! Size = " <<(String) editingLabels.size() << "\n";
        // Size of vector doesn't change? Investigate!!
        
    }
    
}

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
         edTextCol="ff000000" edBkgCol="0" labelText="Text goes here"
         editableSingleClick="1" editableDoubleClick="1" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <TEXTBUTTON name="Write MetadataButton" id="527d7a6fc5ac91bf" memberName="writeMetadataButton"
              virtualName="" explicitFocusOrder="0" pos="24 368 150 24" buttonText="Write Metadata"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="createnewLabelButton" id="5d285aa66433309c" memberName="createnewLabelButton"
              virtualName="" explicitFocusOrder="0" pos="224 368 150 24" bgColOff="ff0000ff"
              buttonText="Create new label" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="fullLabel" id="97b5bc3ffd6e4c8e" memberName="fullLabel"
         virtualName="" explicitFocusOrder="0" pos="24 424 350 24" bkgCol="ffff00b5"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

